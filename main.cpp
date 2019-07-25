/*C++ 11 Concepts are discussed here*/

#include <iostream>
#include<string>

using namespace std;

class Functor{

private:
    string welcomeTxt;
 public:

    Functor(string str):welcomeTxt(str)
    {

    }
    void operator() (string name)
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
    Functor fntor("hi");
    fntor("Ilavarasan");

    Functor fntor1("Hello");
    fntor1(" Ilavarasan");

    construct("ilavarasan", Functor(" Wow"));
    return 0;
}
