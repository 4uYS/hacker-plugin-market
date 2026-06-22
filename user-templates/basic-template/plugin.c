/*
 * Hacker Terminal 插件开发模板 - 基础版
 * 
 * 使用方法：
 * 1. 复制本目录到你的工作目录
 * 2. 修改插件信息和功能实现
 * 3. 用 MinGW 编译：gcc -shared -o plugin.dll plugin.c -luser32
 * 4. 放到 Hacker Terminal 的 plugins/user/ 目录
 */

#include <windows.h>
#include <stdio.h>
#include <string.h>

// ============================================
// 插件基本信息（请修改为你的插件信息）
// 格式：插件名|版本|作者|描述
// ============================================
static char g_plugin_info[] = "my-plugin|1.0|你的名字|我的第一个 Hacker 插件";

// 输出缓冲区（根据需要调整大小）
static char g_output[4096];

// ============================================
// 必须导出的 4 个函数（不要改函数名）
// ============================================

/**
 * 获取插件信息
 * 返回格式：name|version|author|description
 */
__declspec(dllexport) LPTSTR GetPluginInfo()
{
    return g_plugin_info;
}

/**
 * 初始化插件
 * 插件加载时调用，在这里做初始化工作
 * 返回 TRUE 表示成功，FALSE 表示失败
 */
__declspec(dllexport) BOOL InitPlugin()
{
    // TODO: 在这里添加你的初始化代码
    // 例如：加载配置、初始化数据库、检查依赖等
    
    return TRUE;
}

/**
 * 执行插件功能
 * params: 用户传入的参数字符串
 * 返回：执行结果字符串（会显示在终端上）
 */
__declspec(dllexport) LPTSTR Execute(LPTSTR params)
{
    // TODO: 在这里实现你的插件功能
    
    // 示例：回显参数
    if (params && strlen(params) > 0) {
        sprintf(g_output, "你好！你传入的参数是：%s\n", params);
    } else {
        strcpy(g_output, 
            "这是我的第一个 Hacker Terminal 插件！\n"
            "传入参数试试吧～\n");
    }
    
    return g_output;
}

/**
 * 关闭插件
 * 插件卸载时调用，在这里做清理工作
 * 返回 TRUE 表示成功
 */
__declspec(dllexport) BOOL ShutdownPlugin()
{
    // TODO: 在这里添加你的清理代码
    // 例如：保存配置、释放资源、关闭数据库等
    
    return TRUE;
}

// ============================================
// DLL 入口（一般不需要修改）
// ============================================
BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD   ul_reason_for_call,
    LPVOID  lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
