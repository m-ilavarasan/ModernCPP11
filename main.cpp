/*C++ 11 Concepts are discussed here*/



#include <iostream>
#include<string>

using namespace std;

class Functor{

private:

    string  welcomeTxt;

 public:
    Functor()  = default; // default constructor
    
    Functor(const Functor& fun)// Copy constructor
    {
        this->welcomeTxt = fun.welcomeTxt;
    }
    
    Functor( Functor&& func) = default;
    
    Functor operator=(const Functor &fun) = delete; //assignment constructor

    Functor(string str):welcomeTxt(str){}

    void operator() (string name) // Function call overload
    {
        cout<< welcomeTxt+name<<endl;
    }
};



void construct(string msg, Functor fntr)

{

    fntr(msg);

}

int main()

{

    cout << "Hello World!" << endl;

    /* Functor Examples*/
    /*                  */
    /*******************/
    Functor fntor("hi");

    fntor("Ilavarasan");

    Functor fntor1("Hello");

    fntor1(" Ilavarasan");
    
    construct("ilavarasan", Functor(" Wow"));
    /* *****************/
    
    Functor fntor2;
   // fntor2 = fntor1; //will give compile error since assignment constructor declared as delete
    Functor funtor3(fntor2);

    //=============================================//
    //          Auto                               //
    //=============================================//

    auto i = 1; //integer
    auto d = 8.0; // double
    auto str = "Ilavarasan"; // string
    
    cout << i <<"\t"<<d <<"\t"<<str<<endl;
    
    auto list = {1,2,3,4,5};
    //list.pop();
    cout << typeid(list).name() <<endl;
    for(auto num:list)
        cout << num <<"\t";
    cout <<endl;
    return 0;

}
