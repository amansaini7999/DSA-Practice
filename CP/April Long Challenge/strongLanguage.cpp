#include<bits/stdc++.h>
using namespace std;

bool check(string str, int k){
    int count=0;

    for(int i=0; i<str.size(); i++){
        if((char)str[i]=='*'){
            count++;

            if(count==k)
                return 1;
        }  
        else
            count=0;
    }

    return 0;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;

        if(check(str, k))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}