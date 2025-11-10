/*
here in this day4 we are larning about thealgoritms by using the recursion and call stack  
here we will use math annd, compare itterative vs recursive thinking
then  how to choose btwn recursion, iteration or divide and conqure  and dry run the big O reasoning
this things gonna do in the mini task

project name = algorithm logic builder

about projec: a console app that lets you pick algoritms(factorial,fibonacci,gcd,binary search)
and then show how each runs recursively and itteratively

*/

#include<iostream>
#include<chrono>//for complie time purpose
using namespace std;
using namespace std::chrono;

long long factorial_rec(long long n){
    return(n<=1)?1:n*factorial_rec(n-1);
}

long long factorial_itr(long long n){
    long long res=1;
    for(long long i=2;i<=n;i++)
    {
        res*=i;
    }
    return res;
}

void comapare_factorial(){
    long long n;
    cout<<"Enter number:";
    cin>>n;
    auto start=high_resolution_clock::now();
    cout<<"Recursive:"<<factorial_rec(n)<<endl;
    auto mid=high_resolution_clock::now();
    cout<<"Iterative:"<<factorial_itr(n)<<endl;
    auto end=high_resolution_clock::now();

 cout<<"\nRecursive time:"<<duration<double,milli>(mid-start).count()<<"ms";
 cout<<"\nItterative time:"<<duration<double,milli>(end-mid).count()<<"ms\n";

}
 //for fibonacci recursive
 int fib_rec(int n, int depth=0)
 {
    cout<<string(depth*2,' ');//indentation for visualization <<"->fib("<<n<<")\n";
    if(n<=1)return n;
    return fib_rec(n-1,depth+1)+fib_rec(n-2,depth+1);
 }
 //for ittrrative fobonacci
 int fib_itr(int n){
    if(n<=1)
    return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
return b;
}

void compare_fibonacci()
{
    int n;
    cout<<"\n enter number for fibonacci:...";
    cin>>n;

    auto start=high_resolution_clock::now();
    cout<<"\n recursive result:"<<fib_rec(n)<<endl;
    auto mid=high_resolution_clock::now();
    cout<<"\n itterative result:"<<fib_itr(n)<<endl;
    auto end=high_resolution_clock::now();


    cout<<"\n Recursive time:"
    <<duration<double,milli>(mid-start).count()<<"ms\n";
    cout<<"\n Itterative time:"
    <<duration<double,milli>(end-mid).count()<<"ms\n";
}



//functions for gcd
//recursively
int gcd_rec(int a,int b){
    if(b==0)return a;
    return gcd_rec(b,a%b);
}

//itteratively
int gcd_itr(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void comapare_gcd(){
    int a,b;
    cout<<"\n enter two numbers for gcd";
    cin>>a>>b;

    auto start=high_resolution_clock::now();
    cout<<"\n recursive gcd:"<<gcd_rec(a,b)<<endl;
    auto mid=high_resolution_clock::now();
    cout<<"\n itterative gcd:"<<gcd_itr(a,b)<<endl;
    auto end=high_resolution_clock::now();


    cout<<"\n recursive time:"<<duration<double,milli>(mid-start).count()<<"ms\n";
    cout<<"\n itterative time:"<<duration<double,milli>(end-mid).count()<<"ms\n";

}

//binary seach
//recursively
int binary_rec(int arr[],int left,int right,int target){
    if(left>right)return -1;
    int mid=left+(right-left)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]>target)
    return binary_rec(arr, left,mid-1,target);
    else
    return binary_rec(arr,mid+1,right,target);
}

//itterative
int binary_itr(int arr[],int n, int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]<target)left=mid+1;
        else right=mid-1;
    }
    return -1;
}
void compare_bsearch(){
    int n;
    cout<<"\n enter the size of sorted array:";
    cin>>n;

    int arr[1000];
    cout<<"enter elements(sorted)";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int target;
    cout<<"\n enter a element to search:";
    cin>>target;

 auto start=high_resolution_clock::now();
 int rec_result=binary_rec(arr,0,n-1,target);
 auto mid=high_resolution_clock::now();
 int itr_result=binary_itr(arr,n,target);
 auto end=high_resolution_clock::now();
 
 cout<<"\n recursive result index:"<<rec_result;
 cout<<"\n itterative result index:"<<itr_result;
 cout<<"\n recursive time:"<<duration<double,micro>(mid-start).count()<<"ms\n";
 cout<<"\n itterative time:"<<duration<double,micro>(end-mid).count()<<"ms\n";

}








int main(){
    cout<<"======Algorithm playground====\n";
    cout<<"1.Factorial Comaparison\n 2.factorial \n 3.gcd \n4.binary search \n 5.exit";
    int choice;
    cin>>choice;
    if(choice==1)
    comapare_factorial();
    else if(choice==2)
    compare_fibonacci();
    else if(choice==3)
    comapare_gcd();
    else if(choice==4)
    compare_bsearch();

 main();
    return 0;
}