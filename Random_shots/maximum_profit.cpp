/*
Example 1:
    Input: 7,5,6,2,3,200,4,5
    Output: 205

Example 2:
    Input: 7,204,3,1,5,7,9
    Output: 22

Example 3:
    Input: 4,5,2,3,7
    Output: 12

Constraint:
    1<Input<1000
*/


#include<bits/stdc++.h>
using namespace std;

int max_profit(vector<int>nums){
    int msf=INT_MIN, meh=0;
    meh=meh+nums[0];
    for(int i=1; i<nums.size(); i++){
        meh=meh + nums[i];
        if(nums[i-1]>nums[i])
            meh=nums[i];
        if(meh<nums[i])
            meh=nums[i];
        if(msf<meh)
            msf=meh;
    }
    return msf;
}

int main(){
    vector<int> nums{-1,-2,-3};
    cout<<max_profit(nums);
    return 0;
}
