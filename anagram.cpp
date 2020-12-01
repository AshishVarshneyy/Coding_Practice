/*Given an array of words, print the count of all anagram together in increasing order.
Example:
Input: {"cat", "dog" ,"act" ,"god", "tac"}
output: 2,3
*/


//Method 1:
#include <bits/stdc++.h>
using namespace std;

int main(){
    string anagram[] = {"cat", "dog" ,"act" ,"god", "tac"};
    int sum = 0, res[1000] = {0}; 
    int length = sizeof(anagram)/sizeof(anagram[0]);
    for(int i = 0; i < length; i++){
        sum = 1;
        int sub_length = anagram[i].length();
        for(int j = 0; j < sub_length; j++){
            sum = sum + anagram[i][j] - 'a';
        }
        sum = sum + anagram[i].length();
        res[sum]++;
    }
	sort(res, res+1000);
    for(int i = 0; i < 1000; i++){
        if(res[i]!=0)
            cout<<res[i]<<" ";
    }
    return 0;
}

//Method 2:
if __name__ == '__main__':
    
    list = input().split()
    i = 0
    count = {}
    for word in list:
        list[i] = ''.join(sorted(word))
        i = i + 1
    for word in list:
        count[word] = count.get(word,0) + 1
    for i in sorted(count.values()):
        print(str(i) + " ",end = '')
		
//Method 3:
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s[n];
    //insert word and sort it in ascending order
    for(int i = 0; i < n; i++){
        cin>>s[i];
        sort(s[i].begin(), s[i].end());
    }

    //create a map with word as key and count the frequency
    map<string,int>m;
    for(int i=0; i<n; i++){
        m[s[i]]++;
    }

    //make pair of map keys and values to perform sorting
    pair<int,string>p[m.size()];
    int i = 0;
    for(auto it = m.begin(); it!=m.end(); it++){
        p[i++]=make_pair(it->second,it->first);
    }
    sort(p,p+m.size());

    //print result.
    for(int i=0;i<m.size();i++){
        cout<<p[i].first<<" ";
    }
    return 0;
}



