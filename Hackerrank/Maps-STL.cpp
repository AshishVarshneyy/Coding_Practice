//Question link: https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin>>q;

    map<string,int> m;
    int qur, marks;
    string name;

    while(q--){
        cin>>qur>>name;
        if (qur == 1){
            cin>>marks;
            m[name]+=marks;
        }
        if(qur == 2){
            m.erase(name);
        }
        if(qur == 3){
            cout<<m[name]<<"\n";
        }
    } 
    return 0;
}