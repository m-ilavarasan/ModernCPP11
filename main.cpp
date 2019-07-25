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


    return 0;

}
