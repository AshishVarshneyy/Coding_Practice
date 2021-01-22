/*
Question_link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already
sorted so there is no inversion count.

Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array
are same, so there is no inversion count.
*/

//Using merge sort method

#include<bits/stdc++.h>
using namespace std;

int count_inversion(vector<int> nums){
    int count=0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]>nums[j])
                count++;
        }
    }
    return count;
}

int main(){
    vector<int> nums{2, 4, 1, 3, 5};
    cout<<count_inversion(nums);
    return 0;
}
