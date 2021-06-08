#include<bits/stdc++.h>
using namespace std;

int findFirstOccurence(vector<int> arr, int key){
    int beg=0;
    int end=arr.size()-1;
    int index=-1;

    while(beg<=end){
        int mid = (beg+end)/2;

        if(arr[mid]==key){
            index=mid;
            end=mid-1;
        }

        else if(arr[mid]>key)
            end=mid-1;
        
        else
            beg=mid+1;
    }
    return index;
}

int findLastOccurence(vector<int> arr, int key){
    int beg=0;
    int end=arr.size()-1;
    int index=-1;

    while(beg<=end){
        int mid = (beg+end)/2;

        if(arr[mid]==key){
            index=mid;
            beg=mid+1;
        }

        else if(arr[mid]>key)
            end=mid-1;
        
        else
            beg=mid+1;
    }
    return index;
}

int countOccurence(vector<int> arr, int key){

    int a = findFirstOccurence(arr, key);
    int b = findLastOccurence(arr, key);

    cout<<a<<" "<<b<<"\n";

    return b-a+1;
}

int main(){
    vector<int> arr {1, 1, 2, 2, 2, 3, 4, 5, 6};
    cout<<countOccurence(arr, 2)<<"\n";
    return 0;
}