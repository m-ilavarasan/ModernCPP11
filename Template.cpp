// C++ Templates functionalities discussed here

#include <iostream>
#include<string.h>
using namespace std;

template<typename T>
T Max(T a, T b)
{
    return a>b?a:b;
}

//explicit specialization
template<> const char* Max<const char*>(const char* str, const char* str1)
{
    return strcmp(str, str1)>0?str:str1;
}

//Non-type argument template

template<int size> // Should be constant 
void Print()
{
    cout << " The value of size is :" << size <<endl;
}
int main()
{
    printf("Hello World\n");
    
    cout << "addding int :" << Max(5,6) <<endl;
    cout <<" Adding float :" <<Max(5.0, 10.0) <<endl;
    
    auto z = Max(6,6); //Successfull
    
    //auto v = Add(5.6, 7); // Gives compilation erro
    auto v = Max(static_cast<int>(5.6), 7); // Either do type casting or_eq
    cout <<" V Value Now: " << v <<endl;
    auto x = Max<double>(5.6,7.8);
      cout <<" X Value Now: " << x <<endl;
    const char* s = {"B"};
    const char* s1 = {"A"};
      cout <<" String compare Now: " << Max(s,s1) <<endl;
  
    Print<3>(); // it should be constant
    return 0;
}
