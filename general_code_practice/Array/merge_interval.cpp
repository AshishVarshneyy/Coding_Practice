/*
Question_link: https://leetcode.com/problems/merge-intervals/

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;

        //Sorting intervals on start basis:
        sort(intervals.begin(), intervals.end());

        //Declaring result vector
        //Pushing first interval
        vector<vector<int> >result;
        result.push_back(intervals[i]);
        //cout<<result[0][1];

        //Evaluating result;
        for(i = 1; i < intervals.size(); i++) {
            int n = result.size();

            //if interval[i] lie inside result[n-1]
            if(intervals[i][0] <= result[n-1][1] && intervals[i][1] <= result[n-1][1])
                continue;

            //if starting of interval[i] lies inside result[n-1]
            //just changing the end of result interval
            else if(intervals[i][0] <= result[n-1][1])
                result[n-1][1] = intervals[i][1];

            //pushing back the non overlapping interval
            else
                result.push_back(intervals[i]);
        }

        //Returning result yay!!!
        return result;

    }

int main(){
    vector<vector<int>> vect {{1,3},{8,10}, {2,6},{15,18}};

    vector<vector<int>>res;

    res=merge(vect);

    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
