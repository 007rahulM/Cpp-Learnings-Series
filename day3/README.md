⚙️ DAY 3 – FUNCTION FLOW VISUALIZER (UNDERSTANDING THE CALL STACK)

📘 OVERVIEW
The Function Flow Visualizer is a C++ console project that demonstrates how functions call and return 
through the call stack. It’s designed to show the hidden process of recursion — how each function call 
creates a new “stack frame” with its own variables, executes, and then unwinds when returning.

By visualizing recursion step by step, this project builds a deeper mental model of program execution flow.

-------------------------------------------------------------

🧩 FEATURES
- Prints visual call hierarchy with indentation for each recursion level.
- Simulates the “enter” and “return” phases of recursion.
- Shows how stack frames expand and contract.
- Includes optional address printing to reveal stack memory movement.
- Helps visualize recursion depth and base cases clearly.

-------------------------------------------------------------

🧰 PROJECT STRUCTURE
day3/
 ├── function_flow.cpp     → Main program source
 ├── function_flow.exe     → Compiled executable
 ├── function_flow.obj     → Object file created during compilation
 └── README.txt            → Documentation file (this file)

-------------------------------------------------------------

⚙️ HOW TO RUN (USING DEVELOPER COMMAND PROMPT)
1. Open “Developer Command Prompt for VS 2019/2022”.
2. Navigate to the project directory:
   cd "C:\Users\Rahul M\Desktop\c++ learning\mini_projects\learning\day3"
3. Compile the program:
   cl /EHsc /std:c++17 function_flow.cpp
4. Run the executable:
   function_flow
5. Enter recursion depth (try 3–6 for visual clarity).

-------------------------------------------------------------

💻 SAMPLE OUTPUT

⚙️ Function Flow Visualizer — Understanding the Call Stack
Enter recursion depth (recommended 3–6): 4

Starting recursion...

↳ Entering level 1
  ↳ Entering level 2
    ↳ Entering level 3
      ↳ Entering level 4
      🟢 Base case reached at level 4
      ⬆ Returning from level 4
    ⬆ Returning from level 3
  ⬆ Returning from level 2
⬆ Returning from level 1

✅ Recursion completed. Each level entered and exited in reverse order.

-------------------------------------------------------------

🧠 CONCEPTS YOU LEARNED

FUNCTION CALL STACK:
Each function call pushes a new frame containing local variables, parameters, and the return address.
When the function ends, its frame is popped off.

STACK FRAMES:
Temporary regions of memory that store the function’s state. 
New frames are created on each call and destroyed on return.

RECURSION:
When a function calls itself, multiple stack frames exist simultaneously.
Execution goes deeper until the base case is reached, then unwinds back up.

STACK OVERFLOW:
When recursion depth exceeds available stack space, causing the program to crash. 
That’s why base cases are essential.

MEMORY ADDRESSES:
Printing &level shows stack memory movement — addresses decrease as recursion goes deeper, 
proving the stack grows downward in memory.

-------------------------------------------------------------

💻 OPTIONAL EXPERIMENTS (HOMEWORK)

1. Modify the function to print the address of ‘level’ using:
   cout << "Address of level " << level << ": " << &level << endl;

2. Try different depths:
   - depth = 3 → Safe recursion
   - depth = 10 → Notice deeper call chain
   - depth = 1000 → Stack overflow (shows system limit)

3. Convert recursion into an iterative loop:
   Replace the recursive call with a for loop and compare output.

-------------------------------------------------------------

🧠 WHY THIS PROJECT MATTERS
Understanding the function call stack is critical for debugging, memory optimization, and algorithm design.  
This project transforms recursion from an abstract idea into something you can actually visualize, 
preparing you for algorithms, backtracking, and tree recursion in AI and data structures.

-------------------------------------------------------------

⚙️ KEY TECHNICAL DETAILS
Language: C++17
Compiler: Microsoft Visual C++ (cl.exe)
Platform: Windows 10/11
Libraries: iostream, thread, chrono
Concepts: Recursion, Stack Frames, Memory Addresses, Base Cases, Function Calls

-------------------------------------------------------------

🧑‍💻 AUTHOR
Rahul M  
Learning Systems Programming & AI Development  
Day 3 of Programming Mastery Journey

-------------------------------------------------------------

🪄 LICENSE
This project is created for educational and learning purposes.  
You may reuse, modify, and share it with proper credit.

-------------------------------------------------------------
