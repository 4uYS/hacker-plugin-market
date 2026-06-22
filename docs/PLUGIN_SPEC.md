# 插件接口规范 v1.0

本文档定义 Hacker Terminal 插件的标准接口规范。

---

## 一、插件格式

- 插件为标准 Windows DLL 文件
- 文件名：`plugin.dll`
- 放置在独立目录中，目录名为插件 ID

---

## 二、必须导出的函数

所有插件必须导出以下 4 个函数：

### 1. GetPluginInfo()

```c
__declspec(dllexport) LPTSTR GetPluginInfo();
```

**功能**：返回插件基本信息

**返回格式**：`name|version|author|description`

**示例**：
```
hello-world|1.0|官方|Hello World 示例插件
```

**字段说明**：
- `name`：插件名（英文，唯一标识）
- `version`：版本号（建议语义化版本 x.y.z）
- `author`：作者名
- `description`：插件描述（中文，简短说明）

---

### 2. InitPlugin()

```c
__declspec(dllexport) BOOL InitPlugin();
```

**功能**：初始化插件

**调用时机**：插件加载时调用

**返回值**：
- `TRUE`：初始化成功
- `FALSE`：初始化失败，插件将被标记为错误状态

**注意事项**：
- 在这里做初始化工作（加载配置、连接数据库等）
- 不要在这里做耗时操作，会影响启动速度
- 初始化失败时请确保资源已释放

---

### 3. Execute(LPTSTR params)

```c
__declspec(dllexport) LPTSTR Execute(LPTSTR params);
```

**功能**：执行插件功能

**参数**：
- `params`：用户传入的参数字符串（可能为 NULL）

**返回值**：执行结果字符串（会显示在终端上）

**注意事项**：
- 返回的字符串必须是持久的（静态变量或全局变量）
- 不要返回栈上的临时字符串
- 输出建议使用终端友好的格式（边框、对齐等）
- 参数解析由插件自行处理

---

### 4. ShutdownPlugin()

```c
__declspec(dllexport) BOOL ShutdownPlugin();
```

**功能**：关闭插件

**调用时机**：插件卸载时调用

**返回值**：
- `TRUE`：关闭成功
- `FALSE`：关闭失败（仅作记录，不影响卸载）

**注意事项**：
- 在这里做清理工作（保存配置、释放资源等）
- 确保所有资源都已释放
- 不要在这里做耗时操作

---

## 三、DLL 入口函数

```c
BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD   ul_reason_for_call,
    LPVOID  lpReserved
) {
    return TRUE;
}
```

一般不需要修改，保持默认即可。

---

## 四、编译方法

### 使用 MinGW

```bash
gcc -shared -o plugin.dll plugin.c -luser32
```

### 使用 MSVC

```cmd
cl /LD plugin.c user32.lib
```

---

## 五、目录结构

```
插件目录/
├── plugin.dll      # 插件主文件（必须）
├── README.md       # 插件说明（推荐）
├── config.ini      # 配置文件（可选）
└── data/           # 数据目录（可选）
```

---

## 六、命名规范

### 插件 ID（目录名）
- 全小写英文
- 单词间用连字符 `-` 分隔
- 简洁有意义

**示例**：
- ✅ `hello-world`
- ✅ `file-tools`
- ❌ `HelloWorld`
- ❌ `hello_world`

### 函数名
- 严格按照本文档定义的函数名
- 大小写敏感

---

## 七、安全规范

1. **权限检查**：涉及系统操作的插件应检查权限等级
2. **输入验证**：对用户输入的参数进行验证，防止注入
3. **危险操作**：执行危险操作前应提示用户确认
4. **数据安全**：不要明文存储敏感信息
5. **网络安全**：网络请求应使用 HTTPS

---

## 八、版本号规范

建议使用语义化版本：`主版本.次版本.修订号`

- **主版本**：不兼容的 API 改动
- **次版本**：向下兼容的功能性新增
- **修订号**：向下兼容的问题修正

**示例**：`1.0.0`、`1.2.3`、`2.0.0`

---

## 九、错误处理

插件执行出错时，应在返回的字符串中明确说明错误原因，格式建议：

```
[错误] 具体错误信息
```

或使用红色文字（如果终端支持）。

---

**文档版本**：v1.0  
**最后更新**：2026-06-23
