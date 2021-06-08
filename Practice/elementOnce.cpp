#include<bits/stdc++.h>
using namespace std;

int getSingleUsingXOR(vector<int> arr){
    int ans=arr[0];
    for(int i=1; i<arr.size(); i++)
        ans^=arr[i];

    return ans;
}

int getSingle(vector<int> arr){

    int beg=0;
    int end=arr.size()-1;

    while(beg<=end){
        int mid=(beg+end)/2;

        if(arr[mid]!=arr[mid+1])
            return arr[mid];

        // else if()

    }

    return 0;
}

int main(){

    vector<int> arr {1, 1, 2, 3, 3, 4, 4, 5, 5};
    cout<<getSingleUsingXOR(arr)<<" "<<getSingle(arr)<<"\n";

    return 0;
}