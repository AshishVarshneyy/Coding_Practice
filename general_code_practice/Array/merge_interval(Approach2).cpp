/*
Question_link: https://leetcode.com/problems/merge-intervals/

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/


#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>> mergeInterval(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    stack<pair<int,int>> res;
    res.push({intervals[0][0], intervals[0][1]});

    for(int i=1; i<intervals.size(); i++){
        int start1 = res.top().first;
        int end1 = res.top().second;
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if(end1<start2)
            res.push({start2, end2});
        else{
            res.pop();
            res.push({start1, end2});
        }
    }
    return res;
}

void printStack(stack<pair<int,int>> res){
    if(res.empty())
        return;

    pair<int,int> element=res.top();
    res.pop();
    printStack(res);

    cout<<element.first<<" "<<element.second<<"\n";

}

int main(){
    vector<vector<int>> vect {{1,2},{2,4}, {5,8},{1,10}, {11,12}};
    stack<pair<int,int>>res;

    res=mergeInterval(vect);
    printStack(res);

    return 0;
}
