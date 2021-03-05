#include <iostream>
using namespace std;
int main()
{
    int dividend,divisor;
    cout<<"Please enter the dividend:"<<endl;
    cin>>dividend;
    cout<<"Please enter the divisor:"<<endl;
    cin>>divisor;

    while(divisor==0)
    {
        cout<<"Error: divisor can not be zero! Please enter a new divisor:"<<endl;
        cin>>divisor;
    }
    cout<<dividend/divisor;


    return 0;
}
