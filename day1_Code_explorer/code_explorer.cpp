//this is day 1 learning main concepts with c++
//so today here how actually c++ runs 
//when we run 
/*
1->preprrocessing here preproce the program like all # include and all files are called first hereinto ur file 
2->compilation ("convert the human readable code to machine understandable language low level instructions")
3->assembly("the assembly file is then converted to object file which is binary machine code not yet runaable")
4->linking("all the object files and the system libries which called first are likend if u missi someting like; } here the error generated then once all linked the make one final executable file ")
5->execution("it load te binary and executable file into CPU then allocated memory and executes instruction by instruction ")



 mini project 1       -----Code explorer ------
 about project : this is a simple console utility that  takes an.cpp file 
                 then  runs each stages like(preprrocessing,compile,link),
                 then measure time taken for each step and display the file sixes and satge results
*/

#include<iostream> //for I/O
#include<chrono> //to measure compilation time
#include<filesystem>//for file size tracking
#include<cstdlib>//to run terminal commands
#include<string>//define std::string and c_str()
using namespace std;  //not to call std again and again
 namespace fs=std::filesystem; ////assinging variable to call file system to fs cant elobrate again and again

              //----helper function--->
//fuction to executes a sheel command and measures time and print waring if comilation fails 
double runCommand(const string &cmd){
    auto start =chrono::high_resolution_clock::now();
   int result =system(cmd.c_str());
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double>diff=end-start;

    //this above whole thing i as fuction that takes the cmd dronf the termainalthen start time and end time to complet the stage is calculated here

    if(result!=0){
        cerr<<"Command failed:"<<cmd<<endl;
    }
    return diff.count();
}

//main program
int main(){
    string filename;
    cout<<"enter C++ file name... like hello.cpp";
   cin>>filename;

   if (!fs::exists(filename)){
    cerr<<"File not found"<<endl;
    return 1;

   }
   cout<<"\n Starting code explorer...\n";


//------------build commands -----------//
double t1 = runCommand("cl /EP " + filename + " > preprocessed.cpp");
cout << " Preprocessing done.\n";

double t2 = runCommand("cl /FA /c " + filename + " /Fo:object.obj");
cout << " Compilation + Assembly done.\n";

double t3 = runCommand("link object.obj /OUT:final_exe.exe");
cout << "Linking done.\n";

cout << "Preprocessing done in " << t1 << " sec\n";
cout << "Compilation + Assembly done in " << t2 << " sec\n";
cout << "Linking done in " << t3 << " sec\n";

cout << "\n File Sizes (KB):\n";
cout << " - Preprocessed: " << fs::file_size("preprocessed.cpp") / 1024.0 << "\n";
cout << " - Object:       " << fs::file_size("object.obj") / 1024.0 << "\n";
cout << " - Executable:   " << fs::file_size("final_exe.exe") / 1024.0 << "\n";


cout<<"\n Program ready! run ./Final_exe to execute.\n";
return 0;
   
}