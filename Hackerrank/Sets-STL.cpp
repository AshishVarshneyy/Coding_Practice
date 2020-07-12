//Question link: https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin>>q;

    set<int> s;
    set<int>:: iterator it;
    int qur, num;

    while(q--){
        cin>>qur>>num;
        if (qur == 1)
            s.insert(num);
        if(qur == 2)
            s.erase(num);
        if(qur == 3){
            it = s.find(num);
            if(it != s.end())
                cout<<"Yes"<<"\n";
            else
                cout<<"No"<<"\n";
        }
    }   
    return 0;
}



