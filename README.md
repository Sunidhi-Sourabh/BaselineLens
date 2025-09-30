# BaselineLens  
**Feature support, decoded. Decisions, simplified.**

BaselineLens is a modular C++ CLI tool that scans HTML, CSS, and JavaScript files to detect usage of modern web features. It validates each feature against Baseline data to determine cross-browser support, flags risky or unsupported features, and suggests fallback alternatives—helping developers ship with confidence.

---

## 🧠 Tagline  
**Feature support, decoded. Decisions, simplified.**

---

## 🛠️ Tool Overview

BaselineLens helps developers:
- Detect modern web features in HTML/CSS/JS
- Validate support against Baseline data
- Flag risky or unsupported features
- Suggest fallback alternatives
- Export scan results in Markdown, HTML, or JSON
- Auto-launch reports for reviewer clarity

---

## 🔧 Features

- 🔍 Feature extraction from HTML/CSS/JS
- ✅ Baseline support validation using preloaded JSON
- 🛡️ Trust badges: ✅ Supported, ⚠️ Unknown, ❌ Unsupported
- ↪ Fallback suggestions for risky features
- 📄 Markdown and HTML report output
- 🧠 Score summary for reviewer clarity
- 🧩 Modular C++ architecture for clarity and speed
- 🎯 Flags for demo polish: `--export`, `--html`, `--json`, `--quiet`, `--demo`, `--score`

---
<details>
<summary>📦 Requirements</summary>

- C++17 or higher  
- nlohmann/json (included as single-header)  
- MSYS2 or Linux-compatible build environment  
- Make (for compilation)

</details>

---

## 📦 Installation

```bash
git clone https://github.com/yourusername/BaselineLens.git
cd BaselineLens
make
```
