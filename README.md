# BaselineLens
**Feature support, decoded. Decisions, simplified.**

BaselineLens is a modular C++ CLI tool that scans HTML, CSS, and JavaScript files to detect usage of modern web features. It validates each feature against Baseline data to determine cross-browser support, flags risky or unsupported features, and suggests fallback alternatives—helping developers ship with confidence.

---

## 🔧 Features

- 🔍 Feature extraction from HTML/CSS/JS
- ✅ Baseline support validation using preloaded JSON
- 🛡️ Trust badges: ✅ Supported, ⚠️ Unknown, ❌ Unsupported
- ↪ Fallback suggestions for risky features
- 📄 Markdown report output (optional)
- 🧩 Modular C++ architecture for clarity and speed

---

## 🚀 Usage

```bash
./baselinelens validate sample.html
```
Output:
• grid → ✅ Supported
• :has( → ❌ Unsupported
  ↪ Fallback: Avoid complex selectors; restructure DOM

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
├── LICENSE                   # Open-source license (MIT)
└── Makefile                  # Build instructions

---

## 📄 License
Licensed under the Apache License 2.0.

---




