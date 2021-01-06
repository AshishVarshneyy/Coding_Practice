/*
Question_link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

Input : N=11
        arr=1 3 5 8 9 2 6 7 6 8 9
Output: 3
*/



#include <iostream>
using namespace std;

int min_jump(int arr[], int n){

    //check if initial value is 0 then we can't jump, return 0 or -1
    if(arr[0]==0)
        return -1;

    //check if size of array is less or equal to 1, return -1 or 0
    if(n<=1)
        return -1;

    // initialize three variable jump as 1 (initial jump from indx 0), step (how many step are left in present leader) as arr[0]
    // and leader( the value of arr[i]) as arr[0]
    int jump=1, steps=arr[0], leader=arr[0];

    //start traverse from 1 to n
    for(int i=1; i<n; i++){
        //check if current index is equal to size of array, then return jump;
        if(i==n-1)
            return jump;

        //check if current index and current index value is greater than present leader then assign that value to leader.
        if(i+arr[i]>leader)
            leader=i+arr[i];

        //take a step(decrease by 1)
        steps--;

        //check if step equal to 0, then increase jump by 1 and assign leader minus current index to steps.
        if(!steps){
            jump++;
            steps=leader-i;
        }
    }
    return jump;
}

int main() {
    int arr[]={1,4,3,7,1,2,6,7,6,10}, n=10;
    cout<<min_jump(arr,n);
    return 0;
}
