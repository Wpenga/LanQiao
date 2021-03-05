#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int a,b,n;
    cin>>a>>b>>n;

    //整数位
    a%=b;
    
    int cnt=0,num=0;
    string s;
    //小数位
    while(cnt!=n+2)
    {
        //cout<<"a="<<a<<' '<<"b="<<b<<endl;
        while(a<b&& a!=0)
        {
            a*=10,num*=10,cnt++;
            //cout<<"a="<<a<<' '<<"b="<<b<<endl;
        }
        if(a==0) num*=10;
        num+=a/b;
        num%=1000;
        a%=b;
        //cout<<"a="<<a;
        
    }

    //cout<<num<<endl;
    while(num<100)
    num*=10;

    cout<<num%1000;

    return 0;
}

// 852 / 33= 25.8181818 1818182‬;