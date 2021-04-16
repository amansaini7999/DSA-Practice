#include<bits/stdc++.h>
using namespace std;

int solve(int n){

    int layers = ceil(n/4.0)-1;

    if(n%4==1)
        return layers==0?20:44*layers+32;
    
    else if(n%4==2)
        return layers==0?36:44*layers+44;

    else if(n%4==3)
        return layers==0?51:44*layers+55;
    
    else
        return layers==0?60:44*layers+60;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}