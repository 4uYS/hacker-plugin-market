# Hacker Plugin Market

> Hacker Terminal 官方插件市场 —— 扩展你的终端能力

<div align="center">

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: Hacker Terminal](https://img.shields.io/badge/Platform-Hacker%20Terminal-blue.svg)]()
[![Status: Active](https://img.shields.io/badge/Status-Active-green.svg)]()
[![Version: v1.0](https://img.shields.io/badge/Version-v1.0-orange.svg)]()

[中文](README.md) | [English](README.en.md)

</div>

---

## 📖 项目简介

Hacker Plugin Market 是 [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native) 的官方插件市场，为 Hacker Terminal 用户提供丰富的插件资源和开发工具。通过插件系统，你可以无限扩展 Hacker Terminal 的功能，打造专属的终端 AI 助手。

### 为什么使用插件市场？

- 🚀 **一键安装**：在 Hacker Terminal 中一键安装官方插件
- ✅ **安全可靠**：官方插件经过安全审核，放心使用
- 🛠️ **开发友好**：提供完整的开发模板和文档
- 📦 **打包工具**：一键编译、校验、打包插件
- 🌐 **社区驱动**：欢迎社区开发者提交插件

---

## ✨ 特性

### 核心特性

| 特性 | 说明 |
|------|------|
| **官方插件** | 经过安全审核的官方认证插件 |
| **开发模板** | 基础/高级两套插件开发模板 |
| **完整文档** | 接口规范、开发指南、发布指南 |
| **工具脚本** | 编译、校验、打包一站式工具 |
| **版本管理** | 规范的版本管理和发布流程 |
| **社区贡献** | 支持用户提交插件到官方市场 |

### 插件分类

| 分类 | 说明 | 示例 |
|------|------|------|
| **工具增强** | 增强现有工具功能 | file-tools, network-pro |
| **系统管理** | 系统管理相关插件 | system-info-pro |
| **开发工具** | 开发者工具插件 | 待添加 |
| **娱乐趣味** | 趣味娱乐插件 | 待添加 |
| **其他** | 其他类型插件 | hello-world |

---

## 📂 目录结构

```
hacker-plugin-market/
├── official/              # 官方插件目录
│   ├── hello-world/       # 示例：Hello World 插件
│   │   ├── plugin.c       # 插件源码
│   │   ├── plugin.h       # 插件头文件
│   │   ├── README.md      # 插件说明
│   │   └── build.bat      # 编译脚本
│   ├── file-tools/        # 文件处理增强插件
│   ├── network-pro/       # 网络工具增强插件
│   └── system-info-pro/   # 系统信息增强插件
├── user-templates/        # 用户插件开发模板
│   ├── basic-template/    # 基础插件模板（适合新手）
│   │   ├── plugin.c       # 基础插件源码模板
│   │   ├── README.md      # 说明文档模板
│   │   └── build.bat      # 编译脚本模板
│   └── advanced-template/ # 高级插件模板（功能完整）
│       ├── plugin.c       # 高级插件源码模板
│       ├── plugin.h       # 头文件模板
│       ├── README.md      # 说明文档模板
│       ├── build.bat      # 编译脚本模板
│       └── test.bat       # 测试脚本模板
├── docs/                  # 开发文档
│   ├── PLUGIN_SPEC.md     # 插件接口规范（必读）
│   ├── DEVELOP_GUIDE.md   # 开发指南（详细教程）
│   └── PUBLISH_GUIDE.md   # 发布指南（提交到市场）
├── tools/                 # 工具脚本
│   ├── build-plugin.bat   # 插件编译脚本
│   ├── check-plugin.bat   # 插件校验脚本（安全检查）
│   └── package-plugin.bat # 插件打包脚本（生成发布包）
├── README.md              # 中文说明文档
└── README.en.md           # 英文说明文档
```

---

## 🚀 快速开始

### 安装插件

#### 方式一：一键安装（推荐）

在 Hacker Terminal 中执行：

```
/plugin install <插件名>
```

示例：
```
/plugin install hello-world
```

#### 方式二：手动安装

1. 下载插件 DLL 文件
2. 放到 Hacker Terminal 的 `plugins/official/` 或 `plugins/user/` 目录
3. 重启 Hacker Terminal
4. 执行 `/plugin enable <插件名>` 启用插件

### 使用插件

```
/plugin list              # 列出所有插件
/plugin info <插件名>      # 查看插件详情
/plugin run <插件名> [参数] # 执行插件
/plugin disable <插件名>   # 禁用插件
/plugin uninstall <插件名> # 卸载插件
```

---

## 🛠️ 开发你的第一个插件

### 1. 获取模板

复制 `user-templates/basic-template/` 到你的工作目录：

```bash
cp -r user-templates/basic-template/ my-first-plugin
```

### 2. 了解插件接口

插件 DLL 必须导出以下 4 个函数：

```c
// 获取插件信息，返回格式：name|version|author|description
__declspec(dllexport) LPTSTR GetPluginInfo();

// 初始化插件，返回 TRUE 表示成功
__declspec(dllexport) BOOL InitPlugin();

// 执行插件功能，传入参数字符串，返回结果字符串
__declspec(dllexport) LPTSTR Execute(LPTSTR params);

// 关闭插件，返回 TRUE 表示成功
__declspec(dllexport) BOOL ShutdownPlugin();
```

### 3. 编写插件代码

编辑 `plugin.c`，实现你的插件功能。

### 4. 编译插件

使用 MinGW 编译：

```bash
gcc -shared -o plugin.dll plugin.c -luser32
```

或使用工具脚本：

```cmd
tools\build-plugin.bat <插件目录>
```

### 5. 测试插件

在 Hacker Terminal 中加载并测试你的插件。

### 详细文档

- [插件接口规范](docs/PLUGIN_SPEC.md) - 完整的接口定义
- [开发指南](docs/DEVELOP_GUIDE.md) - 详细开发教程
- [发布指南](docs/PUBLISH_GUIDE.md) - 提交到官方市场

---

## 📋 官方插件列表

| 插件名 | 版本 | 作者 | 分类 | 说明 |
|--------|------|------|------|------|
| hello-world | 1.0 | 官方 | 其他 | Hello World 示例插件 |
| file-tools | 1.0 | 官方 | 工具增强 | 文件处理增强工具 |
| network-pro | 1.0 | 官方 | 工具增强 | 网络工具增强 |
| system-info-pro | 1.0 | 官方 | 系统管理 | 系统信息增强 |

> 更多插件持续更新中...

---

## 📝 提交你的插件

欢迎提交你的插件到官方市场！

### 提交流程

1. **Fork 本仓库** - 点击右上角 Fork 按钮
2. **开发插件** - 在 `user-templates/` 基础上开发你的插件
3. **自测通过** - 使用 `tools/check-plugin.bat` 进行安全校验
4. **提交 PR** - 提交 Pull Request 到本仓库
5. **审核通过** - 官方审核通过后将移入 `official/` 目录

### 审核标准

- ✅ 代码安全，无恶意行为
- ✅ 功能完整，文档齐全
- ✅ 遵循插件接口规范
- ✅ 有明确的用途和价值
- ✅ 不侵犯他人知识产权

### 详细指南

请参考 [发布指南](docs/PUBLISH_GUIDE.md) 了解完整的提交流程和审核标准。

---

## ⚠️ 安全说明

### 官方插件

- ✅ 经过安全审核，可放心使用
- ✅ 源码公开，可自行审查
- ✅ 定期更新维护

### 用户插件

- ⚠️ 请自行甄别安全性
- ⚠️ 建议仅从可信来源获取
- ⚠️ 安装前可使用 `tools/check-plugin.bat` 校验

### 安全建议

1. 优先使用官方插件
2. 安装前检查插件源码
3. 定期更新插件到最新版本
4. 如发现安全问题请及时反馈

---

## 🛠️ 工具脚本使用

### build-plugin.bat - 插件编译

```cmd
tools\build-plugin.bat <插件目录>
```

自动编译插件源码，生成 DLL 文件。

### check-plugin.bat - 插件校验

```cmd
tools\check-plugin.bat <插件DLL路径>
```

对插件进行安全校验，包括：
- 导出函数检查
- 导入函数检查
- 基本安全扫描

### package-plugin.bat - 插件打包

```cmd
tools\package-plugin.bat <插件目录>
```

打包插件为发布格式，包含：
- DLL 文件
- README 文档
- 版本信息

---

## 📚 文档资源

| 文档 | 说明 | 适合人群 |
|------|------|---------|
| [PLUGIN_SPEC.md](docs/PLUGIN_SPEC.md) | 插件接口规范 | 所有开发者（必读） |
| [DEVELOP_GUIDE.md](docs/DEVELOP_GUIDE.md) | 开发指南 | 新手开发者 |
| [PUBLISH_GUIDE.md](docs/PUBLISH_GUIDE.md) | 发布指南 | 想提交插件的开发者 |

---

## 🎯 路线图

### 已完成 ✅

- ✅ 插件接口规范
- ✅ 基础/高级开发模板
- ✅ Hello World 示例插件
- ✅ 编译/校验/打包工具
- ✅ 完整的开发文档

### 开发中 ⏳

- ⏳ 更多官方插件
- ⏳ 插件市场网页版
- ⏳ 插件评分系统
- ⏳ 插件依赖管理

### 未来计划 🔮

- [ ] 插件自动更新
- [ ] 插件商店集成
- [ ] 插件分类搜索
- [ ] 插件评论系统
- [ ] 开发者激励计划

---

## ❓ 常见问题

### Q: 插件和技能有什么区别？

A: 技能是基于脚本的轻量级扩展，适合简单任务；插件是编译后的 DLL，功能更强大，性能更好，适合复杂功能。

### Q: 开发插件需要什么知识？

A: 基础的 C 语言编程知识即可。我们提供了完整的模板和文档，新手也能快速上手。

### Q: 插件可以调用 Hacker Terminal 的内部功能吗？

A: 目前插件是独立运行的，可以通过 Win32 API 与系统交互。未来会开放更多内部接口。

### Q: 如何报告插件问题或建议？

A: 可以在 GitHub 提交 Issue，或在对应插件的仓库中反馈。

### Q: 可以用其他语言开发插件吗？

A: 理论上任何能编译成标准 DLL 的语言都可以，但我们只提供 C 语言的模板和文档。

---

## 🤝 贡献

欢迎参与 Hacker Plugin Market 的建设！

### 贡献方式

1. **开发插件** - 开发有趣实用的插件并提交到市场
2. **完善文档** - 改进开发文档，添加示例
3. **反馈问题** - 提交 Bug 报告或功能建议
4. **代码贡献** - 改进工具脚本，修复 Bug
5. **分享推广** - 分享给更多人

### 贡献指南

1. Fork 本仓库
2. 创建你的特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交你的更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

---

## 📄 许可证

MIT License

---

## 🔗 相关项目

- [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native) - 终端 AI 助手主程序
- [Hacker Skill Lib](https://github.com/4uYS/hacker-skill-lib) - 技能资源库
- [Hacker Install Wizard](https://github.com/4uYS/hacker-install-wizard) - 安装向导制作工具
- [HyperMark](https://github.com/4uYS/HyperMark) - 增强版 Markdown 标记语言

---

<div align="center">

**Made with ❤️ by 爱折腾的实验室**

*专注于创造有趣且实用的技术项目*

</div>
