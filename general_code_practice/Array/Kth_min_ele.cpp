/*
Question_link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Input : 5
        7 10 4 20 15
        4
Output: 15
*/

#include<bits/stdc++.h>
using namespace std;

int kthsamllerelement(int arr[], int sindx, int eindx, int ele){
    int hash[100001] = {0};
    for(int i=0;i<=eindx; i++)
        hash[arr[i]]++;
    int ele_count=0;
    for(int i=0;i<=100001;i++){
        if(hash[i]!=0){
            if(ele_count==ele)
                return i;
            ele_count++;

        }
    }
}

int main(){
    int arr[] = {7,10,4,20,15}, k=4, n=6;
    cout<<kthsamllerelement(arr, 0, n-1, k);
    return 0;
}
