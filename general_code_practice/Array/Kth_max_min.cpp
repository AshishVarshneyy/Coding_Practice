/*
Question_link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Input : 5
        7 10 4 20 15
        4
Output: 15
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);

    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int kthsamllerelement(int arr[], int l, int r, int k) {
    quickSort(arr, l, r);
    return(arr[k-1]);
}

int main(){
    int arr[] = {7,10,4,3,20,15}, k=3, n=6;
    cout<<kthsamllerelement(arr, 0, n-1, k);
    return 0;
}
