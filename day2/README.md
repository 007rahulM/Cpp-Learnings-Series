🧠 DAY 2 – MEMORY DETECTIVE (STACK VS HEAP VISUALIZER)

📘 OVERVIEW
Memory Detective is a C++ console-based visualization tool that helps you understand how memory works in a running program. 
It demonstrates the difference between stack memory (temporary, managed automatically) and heap memory (manual, dynamic), 
while also showing variable addresses, pointers, function calls, and memory leaks in real time.

This project is built as a continuation of Day 1 (Code Explorer) and shifts the focus from how code is compiled to where it actually lives in memory.

-------------------------------------------------------------

🧩 FEATURES
- Visualizes stack and heap memory usage during program execution.
- Demonstrates pointers, memory addresses, and variable lifetimes.
- Simulates a memory leak for observation in Task Manager.
- Prints memory addresses for arrays, variables, and stack frames.
- Builds real understanding of C++ memory management.

-------------------------------------------------------------

🧰 PROJECT STRUCTURE
day2/
 ├── memory_detective.cpp   → Main source code
 ├── memory_detective.exe   → Compiled executable
 ├── memory_detective.obj   → Object file created during compilation
 └── README.txt             → Documentation file (this file)

-------------------------------------------------------------

⚙️ HOW TO RUN (USING DEVELOPER COMMAND PROMPT)
1. Open "Developer Command Prompt for VS 2019/2022".
2. Navigate to the project folder:
   cd "C:\Users\Rahul M\Desktop\c++ learning\mini_projects\learning\day2"
3. Compile the program:
   cl /EHsc /std:c++17 memory_detective.cpp
4. Run the program:
   memory_detective

-------------------------------------------------------------

🧠 CONCEPTS YOU LEARN
STACK MEMORY:
- Automatically allocated by the compiler for local variables and functions.
- Released automatically when functions end.
- Fast but limited in size.

HEAP MEMORY:
- Allocated manually using 'new' and released with 'delete'.
- Larger and persistent until freed.
- Used for dynamic data structures and runtime memory control.

POINTERS:
- Store and manipulate memory addresses.
- The foundation of dynamic allocation and low-level memory access.

MEMORY LEAKS:
- Occur when heap memory is allocated but never released.
- Causes gradual increase in memory usage until the program exits.

STACK FRAMES:
- Represent each function call on the call stack.
- Show how parameters and variables exist only within their scope.

-------------------------------------------------------------

💻 SAMPLE OUTPUT

🧠 Memory Detective — Advanced Version

[Main Function]
 Address of x: 0x61ff0c
 Address of y: 0x61ff08

[Stack Function]
 Address of a: 0x61fed0
 Address of b: 0x61fec8
 Address of sum: 0x61fec4

[Array Memory Addresses]
 Element 0 at address: 0x61feb4 | value: 10
 Element 1 at address: 0x61feb8 | value: 20
 Element 2 at address: 0x61febc | value: 30
 Element 3 at address: 0x61fec0 | value: 40
 Element 4 at address: 0x61fec4 | value: 50

[Stack Frame Address Shifts]
 Call #1
  Address of a: 0x61feac
 Call #2
  Address of a: 0x61fe90
 Call #3
  Address of a: 0x61fe74

[Memory Leak Loop]
 Leaked 0 integers so far. Address: 0x1428d0
 Leaked 10000 integers so far. Address: 0x1848d0
 Leaked 20000 integers so far. Address: 0x1a48d0
 Leaked 30000 integers so far. Address: 0x1c48d0
 Leaked 40000 integers so far. Address: 0x1e48d0
 Loop finished. Check Task Manager (memory usage increased).

-------------------------------------------------------------

🧩 MINI CHALLENGES
1. MEMORY LEAK LOOP:
   - Increase the loop count in leakMemoryLoop() and watch memory usage grow in Task Manager.
   - Observe how memory never decreases because no delete operation occurs.

2. ARRAY MEMORY LAYOUT:
   - Print array element addresses.
   - Notice that they appear in sequential order, showing contiguous memory allocation.

3. STACK FRAME REPETITION:
   - Call stackFunction() multiple times.
   - See how each function call has slightly different variable addresses as new stack frames are created.

-------------------------------------------------------------

🧠 WHY THIS PROJECT MATTERS
This project helps visualize how C++ memory actually behaves instead of treating it as an abstract idea. 
You’ll see how stack and heap behave differently, how dynamic memory persists, and how poor memory management causes leaks and instability.

By understanding this, you’ll:
- Write efficient and bug-free programs.
- Debug segmentation faults and crashes faster.
- Build the mental model needed for system-level and AI memory management later.

-------------------------------------------------------------

⚙️ KEY TECHNICAL DETAILS
Language: C++17
Compiler: Microsoft Visual C++ (cl.exe)
Platform: Windows 10/11
IDE: Visual Studio Code or Developer Command Prompt
Libraries Used: iostream, iomanip
Concepts: Pointers, Stack Frames, Heap Allocation, Memory Lifetime

-------------------------------------------------------------

🧑‍💻 AUTHOR
Rahul M
Learning Systems Programming & AI Development
Day 2 of Programming Mastery Journey

-------------------------------------------------------------

🪄 LICENSE
This project is created for educational and learning purposes. 
You may reuse, modify, and share it with proper credit.

-------------------------------------------------------------
