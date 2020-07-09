/* This code illustrate the vector STL
 * and its working(insertion, traversing, searching, find)
 * Function : Time complexity
 * insertion: nlog(n)
 * traverse : nlog(n)
 * search   : log(n)
 * erase    : log(n)
 * for further details refer https://www.geeksforgeeks.org/vector-in-cpp-stl/
 */

#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<char> vect;
    char ch;

    cout<<"Insertion::"<<"\n";
    while(1){
        cin>>ch;
        vect.push_back(ch);
        if (cin.get() == '\n')
            break;
    }
    cout<<"traverse::"<<"\n";
    for(auto x:vect){
        cout<<x<<" ";
    }
    cout<<"\n";
    cout<<"Sort in increase order::"<<"\n";
    sort(vect.begin(), vect.end());
    for(auto x:vect)
        cout<<x<<" ";
    cout<<"\n";
    cout<<"Sort in decrease order::"<<"\n";
    sort(vect.begin(), vect.end(), greater<int>());
    for(auto x:vect)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}
