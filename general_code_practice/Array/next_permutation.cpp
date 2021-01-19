/*
Question_link: https://leetcode.com/problems/next-permutation/

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:

Input: nums = [1]
Output: [1]

*/

#include<bits/stdc++.h>
using namespace std;

void swap(int *element1, int *element2){
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void next_permutation(vector<int>& nums){
    int idx=0, swap_idx=0;
    bool check = true;

    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            check=false;
            idx=i;
            break;
        }
    }

    if(!check){
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[idx]<nums[i]){
                swap_idx=i;
                break;
            }
        }
        swap(&nums[idx],&nums[swap_idx]);
        sort(nums.begin()+idx+1,nums.end());
    }else{
        sort(nums.begin(),nums.end());
    }
}

int main(){
    vector<int> nums{1,3,5,2,4};
    //vector<int> nums{5,4,3,2,1};
    next_permutation(nums);

    for(auto element:nums)
        cout<<element;
    return 0;
}
