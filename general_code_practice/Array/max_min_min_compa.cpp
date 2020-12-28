/*
Question_link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

Input : arr[] = { 1000, 11, 445, 1, 330, 3000 };
Output: Minimum element is 1
        Maximum element is 3000
*/

#include<bits/stdc++.h>
using namespace std;

void find_max_min(vector<int> res){
    int min_ele=999999, max_ele=0;
    for(auto x:res){
        if(min_ele>x)
            min_ele=x;
        if(max_ele<x)
            max_ele=x;
    }
    cout<<"Minimum element is "<<min_ele<<"\n"<<"Maximum element is "<<max_ele;
}

int main(){
    vector<int> res={ 1000, 11, 445, 1, 330, 3000 };
    find_max_min(res);
    return 0;
}
