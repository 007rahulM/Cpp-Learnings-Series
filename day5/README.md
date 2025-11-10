
🔥  DAY 5 — COMPETITIVE PROGRAMMING & ALGORITHMIC LOGIC


Author: Rahul M  
Project: CodeArena — Algorithm Battle Simulator  
Language: C++17  
Folder: day5/

----------------------------------------------------------
📘  PROJECT OVERVIEW
----------------------------------------------------------
CodeArena is a console-based platform that demonstrates how
different algorithms solve the same logical problem using
different approaches — basic vs optimized — and compares
their execution time.

Each “battle” helps you understand how small code changes
affect performance and complexity.  This marks the beginning
of competitive programming and algorithmic problem-solving.

----------------------------------------------------------
🎯  OBJECTIVE
----------------------------------------------------------
• Understand Time & Space Complexity (Big O notation)  
• Compare algorithm efficiency and runtime  
• Learn to measure performance using <chrono>  
• Strengthen logical and mathematical reasoning  
• Prepare foundation for data structures and AI logic

----------------------------------------------------------
🧠  THEORY SUMMARY
----------------------------------------------------------
Every algorithm has two main costs:

1️⃣  Time Complexity — how fast it runs  
2️⃣  Space Complexity — how much memory it consumes  

We represent efficiency using **Big O** notation:
O(1)  constant | O(log n)  logarithmic  
O(n)  linear | O(n log n)  semi-linear | O(n²)  quadratic  

Efficient code is not only about getting the correct output
but about doing it within minimal time and space.

----------------------------------------------------------
🔍  CHALLENGES INCLUDED
----------------------------------------------------------

1. FIND MAXIMUM ELEMENT  
   • Basic: manual loop → O(n)  
   • Optimized: STL `max_element()` → O(n) with CPU-level tuning  

2. REVERSE STRING  
   • Basic: build new string from end → O(n)  
   • Optimized: STL `reverse()` → in-place reversal  

3. SORTING COMPARISON  
   • Basic: selection sort → O(n²)  
   • Optimized: STL `sort()` (IntroSort) → O(n log n)  

4. COUNTING PRIMES  
   • Basic: check divisibility for each → O(n√n)  
   • Optimized: Sieve of Eratosthenes → O(n log log n)  

5. BINARY SEARCH  
   • Recursive vs Iterative — both O(log n)  
   • Demonstrates recursion overhead vs loop efficiency  

6. FREQUENCY COUNTER  
   • Basic: nested loops → O(n²)  
   • Optimized: `unordered_map` → O(n) average  

7. SORTING 10 000 ELEMENTS  
   • Visualizes runtime difference between O(n²) and O(n log n)

----------------------------------------------------------
🧩  CODE STRUCTURE
----------------------------------------------------------
• Uses `<chrono>` to measure execution time in milliseconds.  
• `measure_time()` — generic template function that runs any
  algorithm and prints its runtime.  
• Each challenge has two versions:
     - basic (loop-based or manual)
     - optimized (STL or algorithmic improvement)  
• Menu system lets you select a challenge interactively.

----------------------------------------------------------
🧱  LEARNING IMPACT
----------------------------------------------------------
✔  Builds algorithmic intuition and pattern recognition  
✔  Reinforces practical Big O understanding  
✔  Trains optimization and debugging skills  
✔  Prepares you for competitive coding and AI pipelines  

----------------------------------------------------------
📊  COMPLEXITY & ANALYSIS TABLE
----------------------------------------------------------
| Challenge           | Basic Approach       | Optimized Approach | Time Complexity      |
|---------------------|---------------------|--------------------|----------------------|
| Find Max            | For loop            | STL max_element    | O(n)                |
| Reverse String       | Manual append       | STL reverse        | O(n)                |
| Sorting              | Selection Sort      | STL Sort (Intro)   | O(n²) → O(n log n)  |
| Count Primes         | Divisibility check  | Sieve Algorithm    | O(n√n) → O(n log log n) |
| Binary Search        | Recursive Calls     | Iterative Loop     | O(log n)            |
| Frequency Counter    | Nested loops        | Hash Map           | O(n²) → O(n)        |
| Sort 10 000 Elements | Manual vs STL Sort  | —                  | Runtime comparison  |

----------------------------------------------------------
⚙️  HOW TO RUN
----------------------------------------------------------
1️⃣  Open PowerShell or CMD in the day5 directory.  
2️⃣  Compile using Visual C++ or g++:

     cl /std:c++17 code_arena.cpp
     or
     g++ -std=c++17 code_arena.cpp -o code_arena

3️⃣  Run executable:

     ./code_arena

4️⃣  Choose any challenge from the menu (1–7).

----------------------------------------------------------
💡  SAMPLE OUTPUT SNIPPET
----------------------------------------------------------
===========================================
🔥  CodeArena — Algorithm Battles 🔥

1. Binary Search Battle  
2. Frequency Counter Battle  
3. Sorting 10 000 Numbers  
4. Exit  
Enter choice: 3

--- Sorting 10 000 Numbers ---
Basic Sort (O(n²)) took 412.4 ms  
STL Sort (O(n log n)) took 5.7 ms  

--- End of Session ---


--------------------------------------------------------

==========================================================
