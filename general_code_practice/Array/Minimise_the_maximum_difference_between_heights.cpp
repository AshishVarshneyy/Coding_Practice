/*
Question_link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

Input : 10
        5
        2 6 3 4 7 2 10 3 2 1
Output: 7

algo:
    1. sort an array
    2. take diff of last and first element and store it in variable called res
    3. traverse from indx 1 to n.
    3.1. check if current indx element is greater than or equal to k, then
    3.1.1. find max of previous element+k and last element-k and store it in variable called max_ele.
    3.1.2. find min of first element+k and current element -k and store it in variable called min_ele.
    3.1.3. find min of res and max_ele and min_ele and store in res.
    4. return res
*/

#include<bits/stdc++.h>
using namespace std;

int max_diff(int arr[], int n, int k){
    sort(arr,arr+n);
    int max_ele,min_ele;
    int res = arr[n-1] - arr[0];



    for(int i=1;i<n;i++){
        if(arr[i]>=k){
            max_ele = max(arr[i-1]+k, arr[n-1]-k);
            min_ele = min(arr[0]+k, arr[i]-k);
            res = min(res,max_ele-min_ele);
        }
        else continue;
    }
    return res;
}

int main(){
    int arr[]={2,6,3,4,7,2,10,3,2,1}, n=10, k=5;
    cout<<max_diff(arr,n,k);
    return 0;
}
