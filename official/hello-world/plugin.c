/*
 * Hacker Terminal 官方插件 - Hello World
 * 版本：1.0
 * 作者：爱折腾实验室
 * 说明：最简单的插件示例，向世界问好
 */

#include <windows.h>
#include <stdio.h>
#include <string.h>

static char g_info[] = "hello-world|1.0|官方|Hello World 示例插件，向世界问好";
static char g_output[4096];

// 获取插件信息
__declspec(dllexport) LPTSTR GetPluginInfo()
{
    return g_info;
}

// 初始化插件
__declspec(dllexport) BOOL InitPlugin()
{
    return TRUE;
}

// 执行插件功能
__declspec(dllexport) LPTSTR Execute(LPTSTR params)
{
    if (params && strlen(params) > 0) {
        sprintf(g_output, "\n"
            "╔══════════════════════════════════╗\n"
            "║  Hello, %s!                    ║\n"
            "║  欢迎使用 Hacker Terminal 插件   ║\n"
            "╚══════════════════════════════════╝\n", params);
    } else {
        strcpy(g_output, "\n"
            "╔══════════════════════════════════╗\n"
            "║  Hello, World!                   ║\n"
            "║  这是你的第一个 Hacker 插件      ║\n"
            "╚══════════════════════════════════╝\n");
    }
    return g_output;
}

// 关闭插件
__declspec(dllexport) BOOL ShutdownPlugin()
{
    return TRUE;
}

// DLL 入口
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
