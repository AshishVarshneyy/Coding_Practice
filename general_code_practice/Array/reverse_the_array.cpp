/*
Question_link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

Input : arr[] = {1, 2, 3}
Output: arr[] = {3, 2, 1}
*/

#include<bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string arr;
    int indx=0,temp;
    vector<int> res_arr;

    cin>>arr;

    while(arr[indx]!='\0'){
            if(arr[indx]!=','){
                res_arr.push_back(arr[indx]-'0');
        }
        indx++;
    }

    for(auto i=res_arr.rbegin(); i!=res_arr.rend();i++)
        cout<<*i<<" ";
    return 0;
}
