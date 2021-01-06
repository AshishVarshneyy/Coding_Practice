/*
Question_link: https://leetcode.com/problems/find-the-duplicate-number/

Input: nums = [1,3,4,2,2]
Output: 2
*/


#include<bits/stdc++.h>
using namespace std;


int find_duplictae_element(vector<int> nums){
    map<int,int> freq;
    for(auto x:nums)
        freq[x]++;

    map<int,int>::iterator it;
    for(it=freq.begin(); it!=freq.end(); it++){
        if((it->second)>1)
            return(it->first);
    }
}


int main(){
    vector<int> nums{1,3,4,2,2};
    cout<<find_duplictae_element(nums);
    return 0;
}

