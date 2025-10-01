# BaselineLens  
**Feature support, decoded. Decisions, simplified.**

BaselineLens is a modular C++ CLI tool that scans HTML, CSS, and JavaScript files to detect usage of modern web features. It validates each feature against Baseline data to determine cross-browser support, flags risky or unsupported features, and suggests fallback alternatives—helping developers ship with confidence.

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
<summary> 📦 Requirements </summary>

- C++17 or higher  
- nlohmann/json (included as single-header)  
- MSYS2 or Linux-compatible build environment  
- Make (for compilation)

</details>

---

## 📦 Installation

```bash
git clone https://github.com/Sunidhi-Sourabh/BaselineLens.git
cd BaselineLens
make
```

---
## 🚀 Usage
```
./baselinelens validate examples/sample.html --export --html --demo --score
```
---

## 🔤 Flag Descriptions
| --export | Saves results to report.md     | 
| --html   | Saves results to report.html   | 
| --json   | Outputs results in JSON format | 
| --quiet  | Suppresses terminal output     | 
| --demo   | Adds emojis and style polish   | 
| --score  | Shows % of supported features  | 

---

## 📁 Project Structure 
BaselineLens/
├── src/
│   ├── main.cpp              # CLI entry point
│   ├── scanner.cpp/h         # Parses HTML/CSS/JS files
│   ├── validator.cpp/h       # Compares features with Baseline data
│   ├── fallback.cpp/h        # Suggests alternatives
│   ├── json_loader.cpp/h     # Loads and parses Baseline JSON
├── data/
│   └── baseline_features.json # Preprocessed Baseline data
├── examples/
│   └── sample.html           # Test input file
├── output/
│   └── report.md             # Optional output report
├── README.md                 # Project overview
├── LICENSE                   # Open-source license
└── Makefile                  # Build instructions

---

## 📄License
Licensed under the Apache License 2.0.

---

## 📊 Sample Report Attached
See output/report.md for a full scan summary with trust badges, fallback suggestions, and score breakdown.

---

## 🎥 YouTube Demo
Watch the full walkthrough: Youtube Demo[https://youtu.be/Ld2yHYwZd9E]

---

## 🌐 Connect With Us
Devpost[https://devpost.com/sunidhi-sourabh] | Discord[]

---

BaselineLens is built for clarity, speed, and reviewer impact. Whether you're shipping production code or demoing at a hackathon, it helps you validate with confidence.

---

## 📜 Copyright
© 2025 Sunidhi Sourabh. All rights reserved.
BaselineLens is an open-source project licensed under the Apache License 2.0.  
You are free to use, modify, and distribute this tool under the terms of that license.  
Attribution is appreciated. Commercial use permitted with proper credit.

---
