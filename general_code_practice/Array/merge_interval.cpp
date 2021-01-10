/*
Question_link: https://leetcode.com/problems/merge-intervals/

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/


#include<bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2){
    return v1[0]<v2[0];
}

int main(){
    vector<vector<int>> vect {{1,3},{8,10}, {2,6},{15,18}};
    sort(vect.begin(), vect.end(), sortcol);

    for(int i=vect.begin(); i<vect.end(); i++){
        if(vect[i][1]>vect[0][i+1])
            cout<<vect[i+1][1];

    }

    for(auto x:vect){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}