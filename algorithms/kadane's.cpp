/*
wiki: https://en.wikipedia.org/wiki/Maximum_subarray_problem

Input:  N = 5
        arr[] = {1,2,3,-2,5}
Output: 9

Input:  N = 4
        arr[] = {-1,-2,-3,-4}
Output: -1

Input:  N = 8
        arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}
Output: -1

Explanation:
Initialization of max_end_here: 0 max_so_far: -2147483648
Iteration 0 max_end_here: -2 max_so_far: -2
Iteration 1 max_end_here: -3 max_so_far: -2
Iteration 2 max_end_here:  4 max_so_far:  4
Iteration 3 max_end_here:  3 max_so_far:  4
Iteration 4 max_end_here:  1 max_so_far:  4
Iteration 5 max_end_here:  2 max_so_far:  4
Iteration 6 max_end_here:  7 max_so_far:  7
Iteration 7 max_end_here:  4 max_so_far:  7

max_sum= 7
*/


#include<bits/stdc++.h>
using namespace std;

int largest_sum_contiguous_subarray(int arr[],int n){
    int max_so_far=INT_MIN, max_end_here=0;
    for(int i=0; i<n; i++){
        max_end_here = max_end_here + arr[i];
        if(max_end_here<arr[i])
            max_end_here = arr[i];
        if(max_so_far<max_end_here)
            max_so_far=max_end_here;
    }
    return max_so_far;
}

int main(){
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3}, n=8;
    cout<<largest_sum_contiguous_subarray(arr,n);
    return 0;
}
