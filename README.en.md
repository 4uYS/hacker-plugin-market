# Hacker Plugin Market

Official plugin market for Hacker Terminal — extend your terminal capabilities

[中文](README.md) | English

---

## 📦 About

This repository is the official plugin market for [Hacker Terminal](https://github.com/4uYS/hacker-terminal-native), including:

- ✅ Official certified plugin source code
- ✅ User plugin development templates
- ✅ Plugin development documentation
- ✅ Plugin packaging/installation tools
- ✅ Plugin version management specifications

---

## 📂 Directory Structure

```
hacker-plugin-market/
├── official/              # Official plugins directory
│   ├── hello-world/       # Example: Hello World plugin
│   ├── file-tools/        # File processing enhancement plugin
│   ├── network-pro/       # Network tools enhancement plugin
│   └── system-info-pro/   # System info enhancement plugin
├── user-templates/        # User plugin development templates
│   ├── basic-template/    # Basic plugin template
│   └── advanced-template/ # Advanced plugin template
├── docs/                  # Development documentation
│   ├── PLUGIN_SPEC.md     # Plugin interface specification
│   ├── DEVELOP_GUIDE.md   # Development guide
│   └── PUBLISH_GUIDE.md   # Publishing guide
└── tools/                 # Tool scripts
    ├── build-plugin.bat   # Plugin build script
    ├── check-plugin.bat   # Plugin verification script
    └── package-plugin.bat # Plugin packaging script
```

---

## 🚀 Quick Installation

Execute in Hacker Terminal:

```
/plugin install <plugin-name>
```

Or manual installation:

1. Download the plugin DLL
2. Place it in `plugins/official/` or `plugins/user/` directory
3. Restart Hacker Terminal
4. Execute `/plugin enable <plugin-name>` to enable

---

## 🛠️ Develop Your First Plugin

### 1. Get Template

Copy `user-templates/basic-template/` to your working directory

### 2. Implement Interface

Plugin DLL must export the following 4 functions:

```c
// Get plugin info: name|version|author|description
__declspec(dllexport) LPTSTR GetPluginInfo();

// Initialize plugin
__declspec(dllexport) BOOL InitPlugin();

// Execute plugin function
__declspec(dllexport) LPTSTR Execute(LPTSTR params);

// Close plugin
__declspec(dllexport) BOOL ClosePlugin();
```

### 3. Compile and Test

```cmd
build-plugin.bat
```

---

## 📦 Official Plugins

| Plugin | Description | Version |
|--------|-------------|---------|
| hello-world | Hello World example plugin | v1.0 |
| file-tools | File processing enhancement | v1.0 |
| network-pro | Network tools enhancement | v1.0 |
| system-info-pro | System information enhancement | v1.0 |

---

## 📚 Documentation

- [Plugin Specification](docs/PLUGIN_SPEC.md) - Plugin interface specification
- [Development Guide](docs/DEVELOP_GUIDE.md) - Plugin development guide
- [Publishing Guide](docs/PUBLISH_GUIDE.md) - Plugin publishing guide

---

## 🤝 Contributing

Welcome to contribute plugins, report issues, or suggest improvements!

### How to Contribute

1. **Submit Plugins**: Develop plugins and submit Pull Requests
2. **Report Issues**: Report bugs, suggest new features
3. **Improve Docs**: Improve documentation, add examples
4. **Share Ideas**: Share your plugin ideas

### Submission Process

1. Fork this repository
2. Create your plugin directory
3. Submit Pull Request
4. Wait for review and merge

---

## 📄 License

MIT License

---

## 👥 About

**AI Agent Lab (AAL) / 爱折腾AI实验室**

We are a group of developers who love technology and enjoy tinkering, dedicated to creating interesting and practical tools and projects with AI technology.

- 🌐 Explore cutting-edge technology
- 🛠️ Build practical tools
- 📚 Share technical experience

---

**Made with ❤️ by AI Agent Lab (AAL) / 爱折腾AI实验室**
