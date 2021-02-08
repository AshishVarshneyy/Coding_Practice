/*
Example 1:
    Input: 10
    Output: 4

Constraint:
    1<Input<1000
*/


#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int coprime(int num){
    int count=0;
    for(int i=1; i<num; i++){
        if(gcd(i,num)==1){
            count++;
        }

    }
    return count;
}
int main(){
    int num = 10;
    cout<<coprime(num);
    return 0;
}
