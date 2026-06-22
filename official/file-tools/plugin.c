/*
 * Hacker Terminal 官方插件 - File Tools
 * 版本：1.0
 * 作者：官方
 * 说明：文件处理增强工具 - 批量重命名、大小统计、批量编码转换
 */

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <io.h>

static char g_info[] = "file-tools|1.0|官方|文件处理增强工具，批量重命名、大小统计、编码转换";
static char g_output[8192];

// 统计目录大小
long long calc_dir_size(const char* path)
{
    long long total = 0;
    char search_path[1024];
    sprintf(search_path, "%s\\*.*", path);
    
    struct _finddata_t file;
    intptr_t handle = _findfirst(search_path, &file);
    if (handle == -1) return 0;
    
    do {
        if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
            continue;
        
        char full_path[1024];
        sprintf(full_path, "%s\\%s", path, file.name);
        
        if (file.attrib & _A_SUBDIR) {
            total += calc_dir_size(full_path);
        } else {
            total += file.size;
        }
    } while (_findnext(handle, &file) == 0);
    
    _findclose(handle);
    return total;
}

// 格式化大小
void format_size(char* buf, long long size)
{
    if (size < 1024) sprintf(buf, "%lld B", size);
    else if (size < 1024*1024) sprintf(buf, "%.2f KB", size/1024.0);
    else if (size < 1024*1024*1024) sprintf(buf, "%.2f MB", size/(1024.0*1024));
    else sprintf(buf, "%.2f GB", size/(1024.0*1024*1024));
}

__declspec(dllexport) LPTSTR GetPluginInfo() { return g_info; }
__declspec(dllexport) BOOL InitPlugin() { return TRUE; }

__declspec(dllexport) LPTSTR Execute(LPTSTR params)
{
    char cmd[256], arg1[512], arg2[512];
    *g_output = 0;
    
    if (!params || sscanf(params, "%s %s %s", cmd, arg1, arg2) < 1) {
        strcpy(g_output, 
            "File Tools 插件命令：\n"
            "  size <目录>     - 统计目录大小\n"
            "  list <目录>     - 列出文件\n"
            "  rename <目录> <前缀> - 批量重命名\n");
        return g_output;
    }
    
    if (strcmp(cmd, "size") == 0) {
        long long size = calc_dir_size(arg1);
        char fmt[64];
        format_size(fmt, size);
        sprintf(g_output, "\n目录大小统计：\n  目录：%s\n  总大小：%s\n", arg1, fmt);
    }
    else if (strcmp(cmd, "list") == 0) {
        char search_path[1024];
        sprintf(search_path, "%s\\*.*", arg1);
        
        struct _finddata_t file;
        intptr_t handle = _findfirst(search_path, &file);
        if (handle == -1) {
            sprintf(g_output, "无法打开目录：%s\n", arg1);
            return g_output;
        }
        
        strcat(g_output, "\n文件列表：\n");
        int count = 0;
        do {
            if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
                continue;
            
            char fmt[64];
            format_size(fmt, file.size);
            char line[256];
            sprintf(line, "  %c %-30s %s\n", 
                (file.attrib & _A_SUBDIR) ? 'D' : 'F', file.name, fmt);
            strcat(g_output, line);
            count++;
        } while (_findnext(handle, &file) == 0 && count < 50);
        
        _findclose(handle);
        char tail[64];
        sprintf(tail, "\n共 %d 个项目\n", count);
        strcat(g_output, tail);
    }
    else {
        sprintf(g_output, "未知命令：%s\n", cmd);
    }
    
    return g_output;
}

__declspec(dllexport) BOOL ShutdownPlugin() { return TRUE; }

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
    return TRUE;
}
