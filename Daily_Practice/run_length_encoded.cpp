/*Given an input, write an program that returns the Run Length Encoded string for the input string.
Example:
Input:wwwwwaaadexxxxxxx
output:w5a3d1e1x7
*/

//Method 1:

#include <bits/stdc++.h>
using namespace std;

void Run_Length_encode(string str)
{
    int temp[26] = {0}, i =0;
    while(str[i]!='\0'){
        temp[str[i] - 'a']++;
        i++;
    }
    i = 0;
    while(str[i]!='\0'){
        cout<<str[i]<<temp[str[i] - 'a'];
        i =  i + (temp[str[i] - 'a']);
    }
}

int main(){
    string str;
    cin>>str;
    Run_Length_encode(str);
}

//Method 2:

#include <bits/stdc++.h>
using namespace std;

void Run_Length_encode(string str)
{
    int i =0, count = 1;
    string res = "";
    while(str[i]!='\0'){
        if (str[i] == str[i+1])
            count ++;
        else{
            res = res + str[i] + to_string(count);
            count = 1;
        }
        i++;
    }
    cout<<res;
}

int main(){
    string str;
    cin>>str;
    Run_Length_encode(str);
}