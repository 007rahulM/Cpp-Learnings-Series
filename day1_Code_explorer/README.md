🧠 DAY 1 — CODE EXPLORER (C++ COMPILATION VISUALIZER)

📘 OVERVIEW
Code Explorer is a simple C++ console tool that demonstrates how a C++ program is built step-by-step — from source code to an executable file.
It shows the stages of preprocessing, compilation, assembly, and linking, while also measuring how long each stage takes and displaying the size of generated files.

This is the first project in a hands-on learning journey designed to help build a strong foundation in system-level programming and debugging.

-------------------------------------------------------------

⚙️ FEATURES
- Stage-by-stage compilation using Microsoft’s C++ compiler (cl.exe)
- Timing each phase using the <chrono> library
- Displays file sizes after each build stage
- Error detection and handling for failed compiler commands
- Helps understand how compilers transform source code into executables

-------------------------------------------------------------

🧩 PROJECT STRUCTURE
Day1_CodeExplorer/
 ├── code_explorer.cpp   → Main tool that runs compiler stages and tracks progress
 ├── hello.cpp           → Simple C++ test file for demonstration
 ├── README.txt          → Documentation for the project
 └── .gitignore          → Excludes build and system files from Git

-------------------------------------------------------------

🧰 REQUIREMENTS
- Windows 10 or 11
- Microsoft Visual C++ Build Tools (2019 or 2022)
- Developer Command Prompt (comes with MSVC)
- VS Code or any text editor

-------------------------------------------------------------

🚀 HOW TO RUN THE PROJECT

1. Open the “Developer Command Prompt for VS 2019/2022” from your Start menu.

2. Navigate to your project folder:
   cd "C:\Users\YourName\Desktop\learning\Day1_CodeExplorer"

3. Compile the tool:
   cl /EHsc /std:c++17 code_explorer.cpp

4. Run the tool:
   code_explorer

5. When prompted, enter your test file name:
   hello.cpp

6. Run the generated program:
   final_exe.exe

-------------------------------------------------------------

🧠 EXAMPLE OUTPUT
🧠 Starting Code Explorer...
✅ Preprocessing done in 0.10 sec
✅ Compilation + Assembly done in 0.08 sec
✅ Linking done in 0.05 sec

📊 File Sizes (KB):
 - Preprocessed: 4.2
 - Object: 6.3
 - Executable: 15.1

🎉 Program ready! Run final_exe.exe to execute.

-------------------------------------------------------------

🧩 TEST FILE (hello.cpp)
#include <iostream>
using namespace std;

int main() {
    cout << "Hello from hello.cpp 👋" << endl;
    cout << "This file is used to test the Code Explorer project." << endl;
    cout << "It will be compiled, assembled, and linked step by step!" << endl;
    return 0;
}

-------------------------------------------------------------

💡 CONCEPTS DEMONSTRATED
- Preprocessing: Expands #include and macros before compilation.
- Compilation: Converts source code to assembly.
- Assembly: Converts assembly to binary machine code (.obj).
- Linking: Joins objects and libraries into an executable (.exe).
- Execution: CPU loads and runs the compiled binary.
- Timing: Using chrono to measure duration of each stage.
- File Tracking: Using filesystem to check file sizes dynamically.

-------------------------------------------------------------

⚙️ TECHNICAL DETAILS
- Language: C++17
- Compiler: Microsoft Visual C++ (cl.exe)
- OS: Windows 10/11
- Libraries: iostream, chrono, filesystem, cstdlib

-------------------------------------------------------------

🧱 COMMON ISSUES & FIXES
1. 'g++' is not recognized → Windows does not have g++; use MSVC (cl.exe).
2. identifier "system" is undefined → IntelliSense not configured; fix compilerPath in VS Code.
3. cout output missing → Add endl or flush for output buffering.
4. Linker error LNK1181 → Wrong object file name; use object.obj instead of object.o.
5. Warning C4530 (EHsc) → Add /EHsc to enable standard exception handling.

-------------------------------------------------------------

🎯 WHY THIS PROJECT MATTERS
Many people use “Run” in IDEs without understanding what happens underneath.
This project visualizes each step, helping you see how your code is actually transformed into a runnable binary.

You learn:
- How compilers and linkers work
- How to read build logs and debug errors
- How to measure compile-time performance
- How to automate build processes

-------------------------------------------------------------

🧭 NEXT STEP
Day 2 — Memory Detective
Visualize the difference between stack and heap memory and see how variables live and die in real time.

-------------------------------------------------------------

🏷️ TAGS
C++, Compiler Visualization, MSVC, Beginner Friendly, Learning Project

-------------------------------------------------------------

🧑‍💻 AUTHOR
Rahul M
Learning Systems Programming & AI Development
Day 1 of Programming Mastery Journey

-------------------------------------------------------------

🪄 LICENSE
This project is for educational and learning purposes.
You can reuse, modify, and share it with credit.
