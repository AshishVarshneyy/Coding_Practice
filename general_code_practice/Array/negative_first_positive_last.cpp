/*
Question_link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
*/


#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange(int arr[], int n){
    int negIndx=0;

    for(int i=0; i<n; i++){
        if(arr[i]>0){
            negIndx=i;
            break;
        }
    }

    for(int i=negIndx+1; i<n; i++){
        if(arr[i]<0){
            swap(&arr[i],&arr[negIndx]);
            negIndx++;
        }
    }

}


void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main(){
    int arr[]={ -1, 2, -3, 4, 5, 6, -7, 8, 9 }, n=9;
    rearrange(arr,n);
    print(arr,n);
    return 0;
}
