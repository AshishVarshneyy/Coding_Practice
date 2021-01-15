/*
Question_link: https://leetcode.com/problems/merge-intervals/

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
}

int main(){
    vector<vector<int>> vect {{1,3},{8,10}, {2,6},{15,18}};
    vector<vector<int>>res;

    res=merge(vect);

    for(auto rows:res){
        for(auto element:rows){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}
