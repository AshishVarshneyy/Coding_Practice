/*
Question_link: https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#

Input : A = 978, B = 518, C = 300
Output: 518
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;

    int x,y,z;

    x=A-B;
    y=B-C;
    z=C-A;

    if(x*y>0)
        cout<<B;
    if(y*z>0)
        cout<<C;
    cout<<A;

    return 0;
}