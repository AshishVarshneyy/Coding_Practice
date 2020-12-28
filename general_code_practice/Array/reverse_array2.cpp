/*
Question_link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

Input : arr[] = {1, 2, 3}
Output: arr[] = {3, 2, 1}
*/


#include<bits/stdc++.h>
using namespace std;

void r_arr(vector<int>&vect){
    for(int itr=0,lst=vect.size()-1;itr<lst;itr++,lst--){
        int tmp=vect[itr];
        vect[itr]=vect[lst];
        vect[lst]=tmp;
    }
}
void print(vector<int>vect){
    for(auto x:vect)
        cout<<x;
}

int main(){
    int n;
    cin>>n;
    vector<int> vect;
    while(n--){
        int ele;
        cin>>ele;
        vect.push_back(ele);
    }
    r_arr(vect);
    print(vect);
    return 0;
}
