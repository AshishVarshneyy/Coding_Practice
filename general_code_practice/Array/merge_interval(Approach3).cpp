/*
Question_link: https://leetcode.com/problems/merge-intervals/

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/


#include<bits/stdc++.h>
using namespace std;

int mergeInterval(vector<vector<int>>& vect){
    if(vect.size()==0)
        return{};

    int idx=0;

    for(int i=0; i<vect.size(); i++){
        if(vect[idx][1]>=vect[i][0]){
            vect[idx][1]=vect[i][1];
        }
        else{
            idx++;
            vect[idx]=vect[i];
        }
    }
    return idx;
}

int main(){
    vector<vector<int>> vect {{1,2},{2,4}, {5,8},{1,10}, {11,12}};

    int limit;
    limit=mergeInterval(vect);
    for(int i=0; i<=limit; i++){
        for(auto element:vect[i]){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    //printStack(res);

    return 0;
}
