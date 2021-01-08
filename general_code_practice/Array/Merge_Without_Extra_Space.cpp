/*
Question_link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

Input : N = 4, M = 5
        arr1[] = {1, 3, 5, 7}
        arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
*/


#include <iostream>
using namespace std;


int mergeArrarys(int arr1[], int arr2[], int res[], int N, int M, int k){
    int i,j;
    for(i=0, j=0; i<=N-1, j<=M-1;){
        if(arr1[i]<arr2[j]){
            res[k++]=arr1[i++];
        }
        else{
            res[k++]=arr2[j++];
        }
    }
    if(i<N){
        for(; i<N; i++)
            res[k++]=arr1[i];
    }
    if(j<M){
        for(; i<M; i++)
            res[k++]=arr2[j];
    }
    return k;
}

void print(int res[], int k){
    for(int i=0; i<k; i++){
        cout<<res[i]<<" ";
    }
}

int main() {
    int N = 4, M = 5, arr1[] = {1, 3, 5, 7}, arr2[] = {0, 2, 6, 8, 9}, k=0;
    int resLength = N+M;
    int res[resLength];

    k= mergeArrarys(arr1, arr2, res, N, M, k);
    print(res, k);
    return 0;
}
