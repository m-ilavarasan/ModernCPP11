/*C++ 11 Concepts are discussed here*/

#include <iostream>
#include<string>
#include<typeinfo>
#include<algorithm>
#include<initializer_list>
#include<map>
#include<list>
#include<vector>

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
    
    cout<<endl;
    
    //==============================================//
    //          Lambda                              //
    //==============================================//
    
    auto lmbd = [](){
        cout <<" This is empty capture clause & no param lambda function"<<endl;
    };
    
    lmbd();
    
    auto ParamLamb = [](int a)
    {
       return a*a;
    };
    cout << " Input param to Lamda:"<<ParamLamb(5) <<endl;
    
    auto mulParam = [](int a, int b){
        return a+b;
    };
    
    cout <<" Multi param Lamda:" << mulParam(10,5) <<endl;
    
    auto s = "ilavarasan";
    
    auto capValLamb = [s](string str) // passing value as read only
    {
        cout<<" Lambda Capture as Value:";
        cout << str+ " " + s <<endl;
    };
    capValLamb("Hi") ;
    
    auto capRefLamb = [&s](string str){ // passing value as reference. Values can be editable
        s = " Ilavarasan Manickam";
        cout<<" Lambda Capture as Value:";
        cout << str+ " " + s <<endl;
    };
    capRefLamb("Hello")  ;
    
    auto capAllValReadable = [=]()
    {
      cout<<" Lambda function which will read all the variable declared outside: "  <<s<<endl;
    };
    capAllValReadable();
    
    auto capAllValEditable = [&](){
        s = "Ilavarasan M";
        cout <<" Lambda function which can edit all the variable declared outside: "  <<s<<endl;
    };
    capAllValEditable();
    
    
    auto arr ={1,2,3,4,5};

    int total = 0;
    for_each(arr.begin(), arr.end(), [&total](int x)
    {
        total +=x;
    });
    cout<<" LAmbda in STL===>";
    cout <<" total:" << total <<endl;

    //==============================================//
    //          Initializer_list                    //
    //==============================================//


    int arrIni[] = {1, 2,3,4,5}; //Array initialization
    cout <<" Array Values after initializer list=>";
    for(auto arrItr:arrIni) cout<<arrItr;
    cout <<endl;

    vector<int> vec = {1,3,4,5,7,8}; //Vector Initialization
    cout <<" Vector valurs after initializer list=>";
    for(auto vecItr:arrIni) cout<<vecItr;
    cout<<endl;

    map<string, int> inimap = {
        {"Ila", 0},
        {"Ilavaa", 2}
    };
    
    cout <<" Map values after initializer list=>";
    for(auto mapItr:inimap)
    {
        cout <<mapItr.first <<":" << mapItr.second <<endl;
    }
    return 0;
}
