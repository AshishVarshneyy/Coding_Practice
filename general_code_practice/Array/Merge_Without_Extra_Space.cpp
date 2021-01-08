/*
Question_link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

Input : N = 4, M = 5
        arr1[] = {1, 3, 5, 7}
        arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
*/


#include <bits/stdc++.h>
using namespace std;


int mergeArrarys(int arr1[], int arr2[], int n, int m){
    int i=n-1,j=0, swap=0;
    while(i>=0 && j<m){
        if(arr1[i]>=arr2[j])
        {
            int temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
            swap++;
        }
        i--;j++;
    }
    //cout<<swap<<"\n";
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}

void print(int res[], int k){
    for(int i=0; i<k; i++)
        cout<<res[i]<<" ";
}

int main() {
    int N = 4, M = 5, arr1[] = {1, 3, 5, 7}, arr2[] = {0, 2, 6, 8, 9};

    mergeArrarys(arr1, arr2, N, M);

    print(arr1, N);
    print(arr2, M);

    return 0;
}

