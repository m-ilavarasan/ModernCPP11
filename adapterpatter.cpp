#include<iostream>

using namespace std;


class AbstractPlug{
    int voltage;
    int roundPin;
public:
    virtual void Round(){}
    virtual void Voltage(){}
};

class Plug: public AbstractPlug{

public:
    void Round(){
        cout <<" this is round pin\n";
    }
    void Voltage()
    {
        cout<<" the voltage of round pin:" <<endl;
    }
};

class AdapterSwitchBoard
{
    public:
    virtual void FlatPin(){}

};

class SwitchBoard:public AdapterSwitchBoard
{
public:
    void FlatPin()
    {
        cout <<" This is flat pin\n";
    }

};

class Adapter: public AbstractPlug
{
public:
    AdapterSwitchBoard* ASB;
    Adapter(AdapterSwitchBoard *asb){
        ASB=asb;
    }
    void RoundPin()
    {
        ASB->FlatPin();
    }
};

int mainAdapter()
{
    SwitchBoard ASB;
    Adapter *adpt = new Adapter(&ASB);
    adpt->RoundPin();
    delete adpt;
    adpt = NULL;
    return 0;
}
