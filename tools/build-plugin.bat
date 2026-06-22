@echo off
REM ============================================
REM Hacker Terminal 插件编译脚本
REM 用法：build-plugin.bat <插件源码目录>
REM ============================================

setlocal

if "%1"=="" (
    echo 用法：build-plugin.bat ^<插件目录^>
    echo 示例：build-plugin.bat official\hello-world
    goto :eof
)

set PLUGIN_DIR=%1
set SRC_FILE=%PLUGIN_DIR%\plugin.c
set OUT_FILE=%PLUGIN_DIR%\plugin.dll

if not exist "%SRC_FILE%" (
    echo 错误：找不到源码文件 %SRC_FILE%
    goto :eof
)

echo 正在编译插件...
echo 源码：%SRC_FILE%
echo 输出：%OUT_FILE%
echo.

gcc -shared -o "%OUT_FILE%" "%SRC_FILE%" -luser32 -s -Os

if %errorlevel% equ 0 (
    echo.
    echo ✅ 编译成功！
    echo 输出文件：%OUT_FILE%
) else (
    echo.
    echo ❌ 编译失败！
)

endlocal
