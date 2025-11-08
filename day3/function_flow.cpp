/*//=========understood concepts=====//
ok lets see in day 3 we  gona learn about how function flow  and where it stays and how it call and pause and then return
fuctions are runs in a sequence of stacks frames which is created and destroyed in the memory itself


things u should know before program 
1)function call satck==>the system's way of tracking which fucntion is running now and where it is runnig then where it should return after it finishes the execution
2)stack frames==>it is like a function calls where each functions gets its own mini workspace and memory or paramters, variables and return addresses to store
3)recursion==>basic thing to know when a function calls itself again and agian it builts a multiple stack frames which is carried out one per call 
4)base case and unwinding==>this is how we stops the recusion function from base case, and from the unwinding we reverse the executation step by step
5)stack overflow==>this haapens when too many recusion or recursive function calls are made at a time by that memory limited given for a stack extended then the memory leak happens 

project about:
project name=function flow visualizer

this projects prints live calls stack simulation each time a fuction wanters or exits,
it lets you see recursion unfolding step by step, with indentation tp represent in depth

*/
#include<iostream>//for Input output
#include<thread>
#include<chrono>//to measure compileation time
using namespace std;

//recusive function to visualize call flow
void visualizeFlow(int level,int maxLevel){
    //indent output to show recursion dept
    for(int i=0;i<level;i++){
        cout<<"\t";
        cout<<"Entering Level"<<level<<"||address of current level:"
        <<&level<<endl;
    }
        //simulate compuataion delay(to visulize timing)
     this_thread::sleep_for(chrono::milliseconds(400));

     //base case:stop when level reached maxLevel
     if(level==maxLevel){
        for(int i=0;i<level;i++)
        cout<< " \t";
        cout<<"Base case reached at level"<<level<<"||the address of current level:"<<&level<<endl;
        
     }else{visualizeFlow(level+1,maxLevel);//recursive call
    
    }
    //exiting phase(when recursion unwinds)
    for(int i=0;i<level;i++){
        
            cout<< "\t  ";
            cout<<"returning from level"<<level<<"||cureent addres:"<<&level<<endl;
        }
    }


int main(){
    cout<<"function flow visualizer-understanding the call stack\n";
    cout<<"enter recursion dept(recommended 3-6):";//if its more than 6 recirsion becomes too much and its takes time + memory chances of getting stack overflow

    int depth;
    cin>>depth;

    cout<<"\nstarting recursion...\n\n";
    visualizeFlow(1,depth);

    cout<<"\n recursion completed, \neach level entered and exitedd in reverse order\n";

  return 0;
}
