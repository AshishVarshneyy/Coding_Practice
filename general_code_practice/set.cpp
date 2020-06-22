/* This code illustrate the set STL
 * and its working(insertion, traversing, searching, find)
 * Function : Time complexity
 * insertion: nlog(n)
 * traverse : nlog(n)
 * search   : log(n)
 * erase    : log(n)
 * for further details refer https://www.geeksforgeeks.org/set-in-cpp-stl/
 */

#include<iostream>
#include<set>

using namespace std;

int main(){
    int n;
    cin>>n;
    char ch[n];
    set<char> ch_set;

    for(int i=0;i<n;i++){
        cin>>ch[i];
        ch_set.insert(ch[i]);
    }

    set<char>::iterator it;

    for(it=ch_set.begin();it!=ch_set.end();it++){
        cout<<*it<<"\n";
    }

    //find()
    char x;
    cin>>x;
    it = ch_set.find(x);
    if(it!=ch_set.end()){
        cout<<*it
    }
    return 0;
}
