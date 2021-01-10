#include<bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2){
    return v1[0]<v2[0];
}

int main(){
    vector<vector<int>> vect {{1,3},{8,10}, {2,6},{15,18}};
    sort(vect.begin(), vect.end(), sortcol);

    for(auto x:vect){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}