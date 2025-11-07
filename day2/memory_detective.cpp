//=========understood explnation=====

// //day 2 about the memory detection on a program
// // of how the memory is managed in the code we use here stack and heap and stack vs heap

// understand how varibales are stored  and how functions manages memory and how pointer connect everything

// stack memory-->automatically managed memory used for fucntion call and local variables
//heap memory-->dynamically allocated memory that you control manually using new and delete keywrods
//pointer and references-->here the actuall adress of a variables are define  and this is how c++ connects memory and logic
//if i define mmeory direectly using pointer  with new key word then its a heap memory and it is persentant memory once it define the memory allocated will be there until it deleted  manually so bcz to controll the meomry leak we use the modifed pointer like unique_ptr and shared_ptr this pointers are deletied automatically once program ends
//memory leaks-->it happens when u forget to realse or delelte the alocatted heap memory

//adress tracking--> using & opertaor to inspect where the values or variables are live stored can be seen
//dynamic allocation--> dynamicaly allocating the memory using new adn dleted and manage the objects at runtime

//====== then code the program===
#include<iostream>
#include<iomanip>//inupt output manipulators
//it helps  us to foramt these outputs consistently and clearly

using namespace std;

//a function to demonstrate the stack memory
void stackFunction(int a,int b){
    int sum=a+b;
    cout<<"\n[Stck Fuction]"<<endl;
    cout<<"Adress of a:"<<&a<<endl;
    cout<<"Adress of b:"<<&b<<endl;
    cout<<"Adress of sum:"<<&sum<<endl;

}

////fucntion to demonstrate heap memory
void heapFunction(){
    int *ptr1=new int(100);
    int *ptr2=new int(200);
    cout<<"\n[heap function]"<<endl;
    cout<<"ptr1 points to adress:"<<ptr1<<"|value"<<*ptr1<<endl;
    cout<<"ptr2 points to adress:"<<ptr2<<"|value"<<*ptr2<<endl;

delete ptr1; //free heap memory
//intentionally forgettin delete for ptr2 to show leak    

}

//mini challenge 1----for the memory leak loop
void leakMemoryLoop(int count){
    cout<<"\nMemory leak loop"<<endl;
    for(int i=0;i<count;i++){
        int *leak=new int[i];//lets allocate but never deleted it 
        if(i%10000==0)
        cout<<"leaked"<<i<<"integers so far .Adress:"<<leak<<endl;

    }
    cout<<"loop finsihed here and check task manager(memory usage have been increased)"<<endl;
}
//mini task 2 --- array memory adresses
void arrayMemory(){
    cout<<"\nArray memory adresses"<<endl;
    int arr[5]={10,20,30,40,50};
    for(int i=0;i<5;i++){
        cout<<"index"<<i<<"at adress:"<<&arr[i]<<"value"<<arr[i]<<endl;
    }
}

//mini task 3 ---stack fucntion repetition
void testStackMemory(){
    cout<<"\nStack frame adress shifts"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Call#"<<i+1<<endl;
        stackFunction(i,i*2);
    }
}


int main(){
    cout<<fixed<<showbase;
    cout<<"memory detection --stack vs heap visualizer\n";

    int x=10;
    int y=20;

    cout<<"\n[main function]"<<endl;
    cout<<"adress of x:"<<&x<<endl;
    cout<<"adress of y:"<<&y<<endl;

    stackFunction(x,y);
    heapFunction();
    arrayMemory();
    testStackMemory();


    //in leap memory dont pass large numbers
    leakMemoryLoop(10);



  
    cout << "\nProgram finished. Check addresses above \n— stack vars change per call;\n heap vars persist.\n";
    return 0;
}

