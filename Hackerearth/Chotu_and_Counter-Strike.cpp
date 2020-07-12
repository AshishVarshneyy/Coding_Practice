//Question link: https://www.hackerearth.com/problem/algorithm/shikhar-stl/description/

#include <bits/stdc++.h>
using namespace std;

 
int main(){
    int t;
    cin>>t;
    while(t--){
        int nline;
        cin>>nline;

        map<string,int> win;
        map<string,int> lose;
        map<string,int>::iterator it;
        int wmax = 0, wlose = 0;
        string p1,common,p2,mostwin,mostlose;

        while(nline--){
            cin>>p1>>common>>p2;
            win[p1]++;
            lose[p2]++;
        }

        for(auto&it:win){
            if(wmax<it.second){
                wmax = it.second;
                mostwin = it.first;
            }
        }

        for(auto&it:lose){
            if(wlose<it.second){
                wlose = it.second;
                mostlose = it.first;
            }
        }
        cout<<mostwin<<" "<<mostlose<<"\n";
    } 
    return 0;
}