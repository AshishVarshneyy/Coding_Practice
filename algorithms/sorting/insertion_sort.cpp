/*
Wiki: https://en.wikipedia.org/wiki/Insertion_sort
*/

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& vect){

}

void print(vector<int> vect){
    for(auto x:vect)
        cout<<x;
}
int main(){
    vector<int> vect{1,5,3,6,8,9,7};
    insertion_sort(vect);
    print(vect);
    return 0;
}