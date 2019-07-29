/*C++ 11 Concepts are discussed here*/

#include <iostream>
#include<string>
#include<typeinfo>
#include<algorithm>
#include<initializer_list>
#include<map>
#include<list>
#include<vector>
#include<memory>
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

// Stongly typed enums

//enum Color{
//    BLACK=0,
//    RED,
//    BLUE,
//    GREEN
//};

//enum  YMCK{
//    YELLOW = 0,
//    MEGANTA,
//    CYAN,
//    BLACK // Gives compilation error
//};

enum class Color{   //Storngly typed enums
    BLACK=0,
    RED,
    BLUE,
    GREEN
};

enum  class YMCK{    //Storngly typed enums
    YELLOW = 0,
    MEGANTA,
    CYAN,
    BLACK // Works because of stongly typed
};

void construct(string msg, Functor fntr)

{

    fntr(msg);

}
//==============================================//
//          final                              //
//==============================================//

//class declared with Final
class A final
{
public:
    A(){
        cout<<" This is base class A with final keyword"<<endl;
    }

};
//class B:public A // Wont work. Since base class declared as final
//{

//};


//functions declared with Final

class test{
public:

   virtual void TestFn() final; //only virtual can be marked as final
    virtual void display();
    virtual ~test();
};

class testDerived :public test{
public:
   // void TestFn(); // Wont compile since it is declared wth final in parent
    void display();
    ~testDerived();
};

//==============================================//
//          Override                           //
//==============================================//

class override{
public:

    virtual void display();
    void print();
};
class overridederived:public override{

public:
    //void display(int a) override; // wont work since function signature is different
    void display();
   // void print() override; //wont work since it is not virtual function

};

//==============================================//
//          constexpr                           //
//==============================================//

constexpr int add(int a, int b)
{
    //int c = a+b;
   // return c;  //will not work

    //if(a == 5) return a;  // wont work. multiple return is not supported
    return (a+b);
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
    //         decltype                              //
    //==============================================//

    decltype (5)x; //typeid(x).name will give as interger
    decltype(x)y;
    cout <<x << y <<endl;

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

    //Stongly typed enums
    cout <<static_cast<int>(Color::BLACK)<<endl; // output:0
    cout << static_cast<int>(YMCK::BLACK)<<endl; //output:3

    //nullPtr

    //int a = nullptr;  // Gives compile error since its type of nullptr_t and cant convert to integer type
    int b = NULL; // Works

    int *a = nullptr; //works

    //=============================constexpr usage=============

    const int sum = add(5,10);
    cout << " Constexpr sum:" << sum <<endl;

    int addi = add(10,20);
    cout << "constexpr with out const :" << addi <<endl;
<<<<<<< HEAD

    //==============================================//
    //          rValue reference                    //
    //==============================================//

    int&& rval = 5;
    cout<< "Rval:" <<rval <<endl;

    int&& temp = 10;
    int &t = temp;
    //int&& S = temp;
    cout <<" lvalue ref:"<< t <<"rval:"<< temp <<endl;

    //==============================================//
    //          unique_ptr                          //
    //==============================================//

    unique_ptr<int> uniPtr(new int(10));
    unique_ptr<int> up1 = unique_ptr<int>(new int());

    up1 = move(uniPtr);
    cout <<" The up1 contains: " << *up1 <<endl;

    cout <<" The unique ptr get Val :" << *(up1.get()) <<endl;
    up1.reset();
    if(up1 != nullptr)
    cout <<" up1 after reset :" << *up1 <<endl;
    else
    cout <<" Up1 gets released so it might be null\n";

    //using raw pointer

    int* raw = new int(5);

    unique_ptr<int>up2(raw);
    cout <<" the value of up2 now after creating using raw pointer  :" << *up2 << endl;

    up2.reset();
    cout <<" the value of raw pointer now is:" << *raw <<endl; // it should be junk value

    //create raw pointer using the unique pointer

    unique_ptr<int> up3 (new int(15));
    int* rawPtr = up3.get();
    cout <<" raw poniter from unique is :" << *rawPtr <<endl;
=======
    
   
>>>>>>> 264f68060097960ba4ee0f8832aa8df1e81bf05c
    return 0;
}
