# OOP C++ Lab Solutions

This repository contains my Object-Oriented Programming (OOP) lab work in C++ for BSE (FAST-NUCES).  
It is organized by lab number and includes:

- C++ source code solutions for each task
- Explanation files for selected labs
- Screenshots of outputs where required

The main goal of this repo is to help students understand OOP concepts through practical, task-based implementations.

## Why This Repository Exists

Many students struggle with turning OOP theory into compilable, testable C++ programs.  
This repo aims to provide clean references for common lab topics such as:

- Classes and objects
- Constructors and destructors
- Encapsulation
- Inheritance
- Polymorphism
- File organization for lab submissions

If you are currently taking OOP and want examples that are easy to navigate by lab/task, this repository is built for that purpose.

## Repository Structure

Current top-level structure:

```text
Lab/
├── Lab 1/
│   ├── LAB01-TASK01.cpp ... LAB01-TASK08.cpp
│   └── screenshots/
├── Lab 2/
│   ├── solution/
│   │   ├── LAB02-TASK01.cpp ... LAB02-TASK06.cpp
│   │   └── screenshots/
│   └── explainations/
├── Lab 3/
│   ├── solution/
│   └── explaination/
├── Lab 5/
│   ├── LAB05-TASK01.cpp
│   └── screenshots/
└── Lab 6/
    ├── LAB06-TASK01.cpp
    └── screenshots/
```

Notes:

- Folder and file naming follows lab-task patterns for quick lookup.
- Some folder names use the existing spellings `explaination` / `explainations` to match current repository history.

## How to Compile and Run

You can compile any `.cpp` file with `g++`.

Example:

```bash
g++ "Lab 2/solution/LAB02-TASK01.cpp" -o task01
./task01
```

Or for a file in another lab:

```bash
g++ "Lab 6/LAB06-TASK01.cpp" -o lab6_task1
./lab6_task1
```

If your compiler supports C++11 or later, this is usually enough.  
If needed, compile with an explicit standard:

```bash
g++ -std=c++17 "Lab 3/solution/LAB03-TASK01.cpp" -o lab3_task1
```

## Who Can Use This

- OOP beginners learning C++ class design
- FAST-NUCES BSE students reviewing past lab patterns
- Anyone who wants short, focused task implementations

You can use this repo to:

- Compare your approach with a working reference
- Understand alternative class/logic design decisions
- Practice debugging by modifying existing tasks

## Contribution Guidelines

Contributions are welcome and appreciated.

If you want to contribute:

1. Fork the repository
2. Create a new branch
3. Add or improve solutions/explanations/screenshots
4. Keep naming consistent with existing lab/task patterns
5. Open a pull request with a clear description

Please follow these quality rules:

- Keep code readable and formatted
- Avoid unnecessary complexity
- Prefer clear variable/class names
- Ensure code compiles before submitting
- Do not remove existing valid solutions unless replacing with a better version and explaining why

Good contribution ideas:

- Add missing tasks for existing labs
- Improve explanation markdown files
- Fix typos and naming inconsistencies
- Add better screenshots/output proof
- Improve README with clearer setup/testing instructions

## Pull Request Checklist

Before opening a PR, verify:

- [ ] The code compiles locally
- [ ] File names follow lab-task naming
- [ ] You did not break existing files
- [ ] Changes are scoped and clearly explained
- [ ] Screenshots are added when relevant

## Support the Repository

If this repository helped you in your OOP labs, please support it:

## Star This Repo

Starring the repository helps more students discover it and encourages continued updates.

If you found value here, please take a moment to click the **Star** button on GitHub.

It directly motivates more lab uploads, cleaner explanations, and better organization for everyone.

## Issues and Feedback

If you find:

- A bug in any solution
- A wrong output screenshot
- A confusing explanation
- A missing task file

Open an issue and include:

- Lab number and task number
- What you expected
- What happened instead
- (Optional) Suggested fix

Constructive feedback is always useful.

## Academic Integrity Note

This repository is intended for learning and reference.  
Please do not submit copied code directly as your own coursework.

Use these solutions to understand concepts and build your own implementations.

## License

This project is licensed under the terms defined in the [LICENSE](LICENSE) file.
