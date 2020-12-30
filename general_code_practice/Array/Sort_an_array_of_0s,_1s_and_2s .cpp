/*
Question_link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

Input : N = 5
        arr[]= {0 2 1 2 0}
Output: 0 0 1 2 2

*/

#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n){
    int count0,count1,count2;
    count0=count1=count2=0;

    for(int i=0; i<n; i++){
        if(a[i]==0)
            count0++;
        if(a[i]==1)
            count1++;
        if(a[i]==2)
            count2++;
    }

    for(int i=0; i<n; i++){
        if(count0){
            a[i]=0;
            count0--;
        }
        else if(count1){
            a[i]=1;
            count1--;
        }
        else if(count2){
            a[i]=2;
            count2--;
        }
    }
}

int main(){
    int arr[]= {0,2,1,2,0}, n=5;
    sort012(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
