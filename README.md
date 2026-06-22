# Hacker Plugin Market

Hacker Terminal 官方插件市场 —— 扩展你的终端能力

---

## 📦 仓库说明

本仓库是 [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native) 的官方插件市场，包含：

- ✅ 官方认证插件源码
- ✅ 用户插件开发模板
- ✅ 插件开发文档
- ✅ 插件打包/安装工具
- ✅ 插件版本管理规范

---

## 📂 目录结构

```
hacker-plugin-market/
├── official/              # 官方插件目录
│   ├── hello-world/       # 示例：Hello World 插件
│   ├── file-tools/        # 文件处理增强插件
│   ├── network-pro/       # 网络工具增强插件
│   └── system-info-pro/   # 系统信息增强插件
├── user-templates/        # 用户插件开发模板
│   ├── basic-template/    # 基础插件模板
│   └── advanced-template/ # 高级插件模板
├── docs/                  # 开发文档
│   ├── PLUGIN_SPEC.md     # 插件接口规范
│   ├── DEVELOP_GUIDE.md   # 开发指南
│   └── PUBLISH_GUIDE.md   # 发布指南
└── tools/                 # 工具脚本
    ├── build-plugin.bat   # 插件编译脚本
    ├── check-plugin.bat   # 插件校验脚本
    └── package-plugin.bat # 插件打包脚本
```

---

## 🚀 快速安装

在 Hacker Terminal 中执行：

```
/plugin install <插件名>
```

或手动安装：

1. 下载插件 DLL
2. 放到 `plugins/official/` 或 `plugins/user/` 目录
3. 重启 Hacker Terminal
4. 执行 `/plugin enable <插件名>` 启用

---

## 🛠️ 开发你的第一个插件

### 1. 获取模板

复制 `user-templates/basic-template/` 到你的工作目录

### 2. 实现接口

插件 DLL 必须导出以下 4 个函数：

```c
// 获取插件信息：name|version|author|description
__declspec(dllexport) LPTSTR GetPluginInfo();

// 初始化插件
__declspec(dllexport) BOOL InitPlugin();

// 执行插件功能
__declspec(dllexport) LPTSTR Execute(LPTSTR params);

// 关闭插件
__declspec(dllexport) BOOL ShutdownPlugin();
```

### 3. 编译

使用 MinGW 编译：

```bash
gcc -shared -o plugin.dll plugin.c -luser32
```

详细文档请查看 [docs/DEVELOP_GUIDE.md](docs/DEVELOP_GUIDE.md)

---

## 📋 官方插件列表

| 插件名 | 版本 | 作者 | 说明 |
|--------|------|------|------|
| hello-world | 1.0 | 官方 | Hello World 示例插件 |
| file-tools | 1.0 | 官方 | 文件处理增强工具 |
| network-pro | 1.0 | 官方 | 网络工具增强 |
| system-info-pro | 1.0 | 官方 | 系统信息增强 |

---

## 📝 提交你的插件

欢迎提交你的插件到官方市场！

1. Fork 本仓库
2. 在 `user-templates/` 基础上开发你的插件
3. 提交 Pull Request
4. 审核通过后将移入 `official/` 目录

---

## ⚠️ 安全说明

- 官方插件经过安全审核，可放心使用
- 用户插件请自行甄别安全性
- 建议仅从可信来源获取插件
- 安装前可使用 `tools/check-plugin.bat` 校验

---

## 📄 许可证

MIT License

---

**Hacker Terminal Plugin Market** · 爱折腾实验室 · 豆包 AI Agent Lab
