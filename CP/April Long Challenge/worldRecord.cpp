#include<bits/stdc++.h>
using namespace std;

float round2Place(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

int main()
{
    int t;
    cin>>t;

    float recordTime = 9.58;

    while(t--){
        float k1, k2, k3, v;
        cin>>k1>>k2>>k3>>v;

        float chefSpeed = k1*k2*k3*v;
        float time = 100/chefSpeed;

        time = round2Place(time);

        if(time<recordTime)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}