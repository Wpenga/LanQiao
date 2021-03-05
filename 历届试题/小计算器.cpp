#include<iostream>
using namespace std;
typedef long long ll;




string to_any(ll ten,int type)
{
    if(!ten) return "0";
    string any;
    while(ten)
    {
        
        //any+='o';
        int m=ten%type;
        if(m<=9) any=char('0'+m)+any;
        else any=char('A'+m-10)+any;
        ten/=type;
    }
    return any;
}

ll to_ten(string any,int type)
{
    ll ten=0;
    for(string::iterator it=any.begin();it!=any.end();it++)
    {
        if(*it>='0'&&*it<='9') ten=(ten*type)+(*it-'0');
        else ten=(ten*type)+(*it-'A'+10);
    }
    return ten;
}

ll to_op(ll x,string op,ll y)
{
    if(op=="ADD") return x+y;
    else if(op=="SUB") return x-y;
    else if(op=="MUL") return x*y;
    else if(op=="DIV") return x/y;
    else if(op=="MOD") return x%y;
    
}


int main ()
{   
    int times,type=10;
    string cmd,op,a;
    ll b;

    cin>>times;
    while(times--)
    {
        cin>>cmd;
        if(cmd=="CLEAR") op.clear(),a.clear();
        else if(cmd=="CHANGE") cin>>type;
        else if(cmd=="EQUAL") 
        {
            cout<<to_any(b,type)<<endl;
        }
        else if(cmd=="NUM"&& op.empty()) 
        {
            cin>>a;
            b=to_ten(a,type);
        }
        else if(cmd=="NUM"&& !op.empty()) {
            cin>>a;
            //cout<<"a="<<to_ten(a,type)<<"   "<<"b="<<b<<endl;
            b=to_op(b,op,to_ten(a,type));
        }
        else op=cmd;

    }

    return 0;
}



