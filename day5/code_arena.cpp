/*
ok about day5 here we learn about the cp and algorithms then about logic builders

wts cpp :its a competitive programming and its all about how u solve a problem using logic and math under the time and space as minimum as possible
the goal is to make program more effecient

cp main there  pillars are 
1 :time complexity---how fast is it runs?
here the algorithm time taken to execute or to solve based on the input size matters 
O(1)>O(log n)>O(n)>O(n^2)>O(n^3)...
 
2: space complexity---how mcuh memory does it useS?
here check of how much space is taken to slove the problem  and every variable and ds consume memory 
and it also check using O notaion O notation is the worst case...
calacutating the worst case is the best thing in the programing..if its runs faster its ok but u should know the worst case always 

3:Opmization---can we do better?
every time when we code a solution ask like can i do this in fewer steps or with less space? always if yes then thats the optimal soultaion use the time sand space  complextity to check them

here the project u will learn all this here 

project name: Code_arena
objective and goal: A CLI or command line based project where we presents logical challenges
(like arrays search and sorting battels and string puzzles) 
then the user selects a challenge runs the algorithm and compares preformances stats btwn you 
and an optmized reference one

overall concepts  :
Time and Space Complexity (Big O Notation)

Understanding why O(n log n) beats O(n²)

Measuring efficiency in recursive & iterative approaches

Trade-offs between memory and speed

Arrays & Strings (Deep Dive)

Sliding Window Technique

Prefix Sums & Subarray Optimization

String manipulation, palindrome checking, frequency counting

Searching & Sorting Algorithms

Binary Search, Merge Sort, Quick Sort — code and compare time

Sort custom objects using comparators and lambdas

Mathematical & Logical Problem Solving

Prime numbers, divisors, GCD/LCM, modular arithmetic

Problem reduction (breaking big tasks into smaller ones)


for commiple use this first then the program name.cpp
cl /EHsc /std:c++17
*/

#include<iostream>//for i/o operations
#include<vector>//to use dynamic arrays(vectors)
#include<chrono>//for measuring execution time
#include<algorithm>//for STL functions like sort,mac_elemet
#include<unordered_map>// for frequency counting
#include<random>//for generating large arrays
using namespace std;
using namespace std::chrono;

//==============================================//
/*  thory before the code
--we'll build a mini battle arena where we test two versions of the same logic
1. a basic implementation(our hand written loops)
2. an optimized implementation(using stl or better logic)

the goal:measure and compare time performance in milliseconds
*/

//======utility function to measure time taken by a function
//we use a C++ feature called "template" which allows us to pass any function type

//print a simple banner
void print_banner(){
    cout<<"\n================================\n";
    cout<<"         code arena 2\n";
    cout<<"================================\n";
}

template<typename Func>
void measure_time(Func f,const string& label){
    auto start=high_resolution_clock::now();//record start time
    f();//run the function(lambda)
    auto end=high_resolution_clock::now();//record end time
    cout<<label<<"took"<<duration<double,milli>(end-start).count()<<"ms"<<endl;

}

//====challenge 1 ---find maximum---//
//basic method
int findMax_basic(const vector<int>&arr){
    //O(n)-we must check each elemet once so linear 
    int maxVal=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxVal)
        maxVal=arr[i];

    }
    return maxVal;
}

//optimized method use stlc
int findMax_optimal(const vector<int>&arr){
    //stl uses internal cpu level optmizations
    return *max_element(arr.begin(),arr.end());
}


//===challenge 2---->Reverse String-----
// basic method using loops
string reverse_basic(string s){
    //we build a new string from the end of s to start
    string result="";
    for(int i=s.length()-1;i>0;i--){
        result+=s[i];
    }
    return result;
}

//optmized method ---use stl reverse algorithm
string reverse_optimal(string s){
    reverse(s.begin(),s.end());
    return s;
}
    

//=====challenge 3---->Sorting numbers----
//basic --selction sort(O(n^2))----using two pointer
void sort_basic(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i])
            swap(arr[i],arr[j]);
        }
    }
}
 
//optimal solution---stl sort (O(n lon n))
void sort_optimal(vector<int>&arr){
    sort(arr.begin(),arr.end());
}


//=====challenge 4---->Count Primes----
//basic-- check each number for diivisibility
int countPrimes_basic(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        bool isPrime=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime)count++;
    }
    return count;
}

//optimal way ---sieve of eratosthenes algorthim (O(n log log n))
int countPrimes_optimal(int n){
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i)
            isPrime[j]=false;

        }
    }
    return count(isPrime.begin(),isPrime.end(),true);
}

//new  problem from home work where added here
//binary search comparision
//b search using recursion
int binarySearch_rec(vector<int>&arr,int left,int right,int target){
    if(left>right)return -1;
    int mid=left+(right-left)/2;
    if(arr[mid]==target)return mid;
    if(arr[mid]>target)return binarySearch_rec(arr,left,mid-1,target);
    else return binarySearch_rec(arr,mid+1,right,target);
}

//b search using itterative loop
int b_search_itr(vector<int>&arr,int target){
    int left=0,right=arr.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target)return mid;
        if(arr[mid]<target)left=mid+1;
        else right=mid-1;
    }
    return -1;
}

//comapre function for b search
void compare_bsearch(){
    cout<<"\n Binary search battle\n";
    vector<int>arr(100000);
    for(int i=0;i<arr.size();i++)
    arr[i]=i;//sorted numbers

    int target=98765;
    measure_time([&](){
        cout<<"Recursive Index:"<<binarySearch_rec(arr,0,arr.size()-1,target)<<endl;
},"recursive search\n");

measure_time([&](){
    cout<<"Iterative Index:"<<b_search_itr(arr,target)<<endl;
},"Iterative search\n");

}
///2 problem from home wrok is frequency counter
//basic by loops
void count_fbasic(vector<int>&arr){
    cout<<"\n basic frequency counter (O(n^2))\n";
    for(int i=0;i<arr.size();i++){
        int count=0;
        for(int j=0;j<arr.size();j++)
        if(arr[i]==arr[j])count++;
        cout<<arr[i]<<":"<<count<<"times\n"<<endl;

    
    }
}
//optimized one//
void count_foptimal(vector<int>&arr){
    cout<<"\n optimized frequency counter (O(n))\n";
    unordered_map<int,int>freq;
    for(int num:arr)
    freq[num]++;
    for(auto&p :freq)
    cout<<p.first<<":"<<p.second<<"times\n";
}

void compare_fcounter(){
    vector<int>arr={3,1,2,3,4,1,2,2,3};
    measure_time([&](){count_fbasic(arr);},"Basic Frequency");
    measure_time([&](){count_foptimal(arr);},"Optimal freuency");

}

///3 one sorting 10000 elements
//basic approach
void sort_b(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
    for(int j=i+1;j<arr.size();j++)
    if(arr[j]<arr[i])
    swap(arr[i],arr[j]);
}

//optimal approach
void sort_opt(vector<int>& arr){
    sort(arr.begin(),arr.end());

}

//compare function for large sort
void compare_lsort(){
    cout<<"\n ---sorting 10000 numbers---\n";
    vector<int>arr(10000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dist(1,10000);
    for(int&x:arr) 
    x=dist(gen);

    measure_time([&](){vector<int>temp=arr;sort_b(temp);},"Basic sort (O(n²))");
    measure_time([&](){vector<int>temp=arr;sort_opt(temp);},"Optimal sort (O(n log n))");

}


//menu system//
int main(){
    cout<<"====Code Arena--logic battele simulator===\n";
    cout<<"Choose you challege:\n";
    cout<<"1.find maximum\n 2.Reverse string\n 3.Sorting Battle\n 4.Count Primes\n 5.Binary search battle\n 6.Frequency counter battle\n 7.sorting 10000 numbers\n 8.exit\n";

    int choice;
    int num;
    cin>>choice;
    if(choice==1){
      vector<int> arr = {1, 3, 5, 2, 9, 7};
        measure_time([&](){cout<<"Max:"<<findMax_basic(arr)<<endl;},"Basic FindMax");
   measure_time([&](){cout<<"Max:"<<findMax_optimal(arr)<<endl;},"Opmized FindMax");

    }

    else if(choice==2){
        string s;
        cout<<"enter string:";
        cin>>s;
        measure_time([&](){cout<<"Basic Reverse:"<<reverse_basic(s)<<endl;},"Basic reverse");
        measure_time([&](){cout<<"Optmial Reverse:"<<reverse_optimal(s)<<endl;},"Optmial Reverse");


    }
    else if(choice==3){
      vector<int> arr = {9, 5, 2, 7, 1, 3};
        
        measure_time([&](){vector<int>temp=arr;sort_basic(temp);},"Baisc sort");
        measure_time([&](){vector<int>temp=arr;sort_optimal(temp);},"Opimized sort");
        
    }
    else if(choice==4){
        int n;
        cout<<"Count primes up to:";cin>>n;
        measure_time([&](){cout<<"Primes:"<<countPrimes_basic(n)<<endl;},"Basic Prime Count");
        measure_time([&](){cout<<"Primes:"<<countPrimes_optimal(n)<<endl;},"Optimized prime count");
    }else if(choice==5){
        compare_bsearch();
        
    }else if(choice==6){
        compare_fcounter();
    }else if(choice==7){
        compare_lsort();
    }else {cout<<"\nGoodbye...\n";

    cout<<"\n====end of the battel===";}
    return 0;
}