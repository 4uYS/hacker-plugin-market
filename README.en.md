# Hacker Plugin Market

> Official plugin market for Hacker Terminal — extend your terminal capabilities

<div align="center">

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: Hacker Terminal](https://img.shields.io/badge/Platform-Hacker%20Terminal-blue.svg)]()
[![Status: Active](https://img.shields.io/badge/Status-Active-green.svg)]()
[![Version: v1.0](https://img.shields.io/badge/Version-v1.0-orange.svg)]()

[English](README.en.md) | [中文](README.md)

</div>

---

## 📖 Introduction

Hacker Plugin Market is the official plugin market for [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native), providing rich plugin resources and development tools for Hacker Terminal users. Through the plugin system, you can infinitely extend Hacker Terminal's functionality and create your own terminal AI assistant.

### Why Use the Plugin Market?

- 🚀 **One-Click Install**: Install official plugins with one command in Hacker Terminal
- ✅ **Safe & Reliable**: Official plugins are security audited, use with confidence
- 🛠️ **Developer-Friendly**: Complete development templates and documentation
- 📦 **Packaging Tools**: One-click compile, verify, and package plugins
- 🌐 **Community-Driven**: Community developers are welcome to submit plugins

---

## ✨ Features

### Core Features

| Feature | Description |
|---------|-------------|
| **Official Plugins** | Security-audited official certified plugins |
| **Dev Templates** | Two sets of plugin templates: basic and advanced |
| **Complete Docs** | Interface spec, development guide, publishing guide |
| **Tool Scripts** | One-stop tools for compile, verify, and package |
| **Version Management** | Standardized version management and release process |
| **Community Contribution** | Support user plugin submissions to official market |

### Plugin Categories

| Category | Description | Examples |
|----------|-------------|----------|
| **Tool Enhancement** | Enhance existing tool functionality | file-tools, network-pro |
| **System Management** | System management related plugins | system-info-pro |
| **Dev Tools** | Developer tool plugins | Coming soon |
| **Entertainment** | Fun and entertainment plugins | Coming soon |
| **Other** | Other types of plugins | hello-world |

---

## 📂 Directory Structure

```
hacker-plugin-market/
├── official/              # Official plugins directory
│   ├── hello-world/       # Example: Hello World plugin
│   │   ├── plugin.c       # Plugin source code
│   │   ├── plugin.h       # Plugin header file
│   │   ├── README.md      # Plugin documentation
│   │   └── build.bat      # Build script
│   ├── file-tools/        # File processing enhancement plugin
│   ├── network-pro/       # Network tools enhancement plugin
│   └── system-info-pro/   # System info enhancement plugin
├── user-templates/        # User plugin development templates
│   ├── basic-template/    # Basic plugin template (for beginners)
│   │   ├── plugin.c       # Basic plugin source template
│   │   ├── README.md      # Documentation template
│   │   └── build.bat      # Build script template
│   └── advanced-template/ # Advanced plugin template (full features)
│       ├── plugin.c       # Advanced plugin source template
│       ├── plugin.h       # Header template
│       ├── README.md      # Documentation template
│       ├── build.bat      # Build script template
│       └── test.bat       # Test script template
├── docs/                  # Development documentation
│   ├── PLUGIN_SPEC.md     # Plugin interface specification (must read)
│   ├── DEVELOP_GUIDE.md   # Development guide (detailed tutorial)
│   └── PUBLISH_GUIDE.md   # Publishing guide (submit to market)
├── tools/                 # Tool scripts
│   ├── build-plugin.bat   # Plugin build script
│   ├── check-plugin.bat   # Plugin verification script (security check)
│   └── package-plugin.bat # Plugin packaging script (generate release)
├── README.md              # Chinese documentation
└── README.en.md           # English documentation
```

---

## 🚀 Quick Start

### Installing Plugins

#### Method 1: One-Click Install (Recommended)

Execute in Hacker Terminal:

```
/plugin install <plugin-name>
```

Example:
```
/plugin install hello-world
```

#### Method 2: Manual Install

1. Download the plugin DLL file
2. Place it in Hacker Terminal's `plugins/official/` or `plugins/user/` directory
3. Restart Hacker Terminal
4. Execute `/plugin enable <plugin-name>` to enable the plugin

### Using Plugins

```
/plugin list              # List all plugins
/plugin info <name>       # View plugin details
/plugin run <name> [args] # Execute plugin
/plugin disable <name>    # Disable plugin
/plugin uninstall <name>  # Uninstall plugin
```

---

## 🛠️ Develop Your First Plugin

### 1. Get Template

Copy `user-templates/basic-template/` to your working directory:

```bash
cp -r user-templates/basic-template/ my-first-plugin
```

### 2. Understand Plugin Interface

Plugin DLL must export the following 4 functions:

```c
// Get plugin information, return format: name|version|author|description
__declspec(dllexport) LPTSTR GetPluginInfo();

// Initialize plugin, return TRUE on success
__declspec(dllexport) BOOL InitPlugin();

// Execute plugin function, pass parameter string, return result string
__declspec(dllexport) LPTSTR Execute(LPTSTR params);

// Shutdown plugin, return TRUE on success
__declspec(dllexport) BOOL ShutdownPlugin();
```

### 3. Write Plugin Code

Edit `plugin.c` to implement your plugin functionality.

### 4. Compile Plugin

Compile with MinGW:

```bash
gcc -shared -o plugin.dll plugin.c -luser32
```

Or use tool script:

```cmd
tools\build-plugin.bat <plugin-directory>
```

### 5. Test Plugin

Load and test your plugin in Hacker Terminal.

### Detailed Documentation

- [Plugin Specification](docs/PLUGIN_SPEC.md) - Complete interface definition
- [Development Guide](docs/DEVELOP_GUIDE.md) - Detailed development tutorial
- [Publishing Guide](docs/PUBLISH_GUIDE.md) - Submit to official market

---

## 📋 Official Plugin List

| Plugin | Version | Author | Category | Description |
|--------|---------|--------|----------|-------------|
| hello-world | 1.0 | Official | Other | Hello World example plugin |
| file-tools | 1.0 | Official | Tool Enhancement | File processing enhancement tools |
| network-pro | 1.0 | Official | Tool Enhancement | Network tools enhancement |
| system-info-pro | 1.0 | Official | System Management | System information enhancement |

> More plugins coming soon...

---

## 📝 Submit Your Plugin

Welcome to submit your plugin to the official market!

### Submission Process

1. **Fork this repository** - Click the Fork button in the top right
2. **Develop plugin** - Develop your plugin based on `user-templates/`
3. **Self-test passed** - Use `tools/check-plugin.bat` for security verification
4. **Submit PR** - Submit Pull Request to this repository
5. **Review passed** - After official review, it will be moved to `official/` directory

### Review Criteria

- ✅ Code is safe, no malicious behavior
- ✅ Complete functionality, full documentation
- ✅ Follows plugin interface specification
- ✅ Has clear purpose and value
- ✅ Does not infringe on others' intellectual property

### Detailed Guide

Please refer to the [Publishing Guide](docs/PUBLISH_GUIDE.md) for the complete submission process and review criteria.

---

## ⚠️ Security Notes

### Official Plugins

- ✅ Security audited, safe to use
- ✅ Source code public, can review yourself
- ✅ Regularly updated and maintained

### User Plugins

- ⚠️ Please verify security on your own
- ⚠️ Recommended to only obtain from trusted sources
- ⚠️ Can use `tools/check-plugin.bat` to verify before installation

### Security Recommendations

1. Prioritize using official plugins
2. Check plugin source code before installation
3. Regularly update plugins to latest version
4. Please report promptly if you find security issues

---

## 🛠️ Tool Scripts Usage

### build-plugin.bat - Plugin Compilation

```cmd
tools\build-plugin.bat <plugin-directory>
```

Automatically compiles plugin source code and generates DLL file.

### check-plugin.bat - Plugin Verification

```cmd
tools\check-plugin.bat <plugin-dll-path>
```

Performs security verification on plugins, including:
- Export function check
- Import function check
- Basic security scan

### package-plugin.bat - Plugin Packaging

```cmd
tools\package-plugin.bat <plugin-directory>
```

Packages plugin into release format, including:
- DLL file
- README documentation
- Version information

---

## 📚 Documentation Resources

| Document | Description | Target Audience |
|----------|-------------|-----------------|
| [PLUGIN_SPEC.md](docs/PLUGIN_SPEC.md) | Plugin interface specification | All developers (must read) |
| [DEVELOP_GUIDE.md](docs/DEVELOP_GUIDE.md) | Development guide | Beginner developers |
| [PUBLISH_GUIDE.md](docs/PUBLISH_GUIDE.md) | Publishing guide | Developers who want to submit plugins |

---

## 🎯 Roadmap

### Completed ✅

- ✅ Plugin interface specification
- ✅ Basic/advanced development templates
- ✅ Hello World example plugin
- ✅ Compile/verify/package tools
- ✅ Complete development documentation

### In Development ⏳

- ⏳ More official plugins
- ⏳ Plugin market web version
- ⏳ Plugin rating system
- ⏳ Plugin dependency management

### Future Plans 🔮

- [ ] Plugin auto-update
- [ ] Plugin store integration
- [ ] Plugin category search
- [ ] Plugin comment system
- [ ] Developer incentive program

---

## ❓ FAQ

### Q: What's the difference between plugins and skills?

A: Skills are script-based lightweight extensions, suitable for simple tasks; plugins are compiled DLLs with more powerful functionality and better performance, suitable for complex features.

### Q: What knowledge do I need to develop plugins?

A: Basic C programming knowledge is sufficient. We provide complete templates and documentation, beginners can get started quickly.

### Q: Can plugins call Hacker Terminal's internal functions?

A: Currently plugins run independently and can interact with the system through Win32 API. More internal interfaces will be opened in the future.

### Q: How to report plugin issues or suggestions?

A: You can submit an Issue on GitHub, or provide feedback in the corresponding plugin repository.

### Q: Can I develop plugins in other languages?

A: Theoretically any language that can compile into standard DLL works, but we only provide C language templates and documentation.

---

## 🤝 Contributing

Welcome to participate in building Hacker Plugin Market!

### How to Contribute

1. **Develop Plugins** - Develop interesting and practical plugins and submit to the market
2. **Improve Docs** - Improve development documentation, add examples
3. **Report Issues** - Submit bug reports or feature suggestions
4. **Code Contributions** - Improve tool scripts, fix bugs
5. **Share & Promote** - Share with more people

### Contribution Guide

1. Fork this repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

MIT License

---

## 🔗 Related Projects

- [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native) - Terminal AI assistant main program
- [Hacker Skill Lib](https://github.com/4uYS/hacker-skill-lib) - Skill resource library
- [Hacker Install Wizard](https://github.com/4uYS/hacker-install-wizard) - Installation wizard creation tool
- [HyperMark](https://github.com/4uYS/HyperMark) - Enhanced Markdown markup language

---

<div align="center">

**Made with ❤️ by Ai Zhe Teng Lab**

*Focused on creating interesting and practical tech projects*

</div>
