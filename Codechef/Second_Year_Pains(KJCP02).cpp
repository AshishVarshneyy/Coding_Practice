//Question link: https://www.codechef.com/problems/KJCP02

#include <bits/stdc++.h>
#include<set>
#define MOD 1000000007
#define initial ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;


void evaluate(){
    int n, m;
    cin>>n>>m;
    set<ll>s;
    ll x;
    while(n--){
        cin>>x;
        s.insert(x);
    }
    while(m--){
        cin>>x;
        if(s.find(x)!=s.end()){
            cout<<"YES\n";
        }
        else{
            s.insert(x);
            cout<<"NO\n";
        }
    }
}

int main() {
    initial
	int tc;
	cin>>tc;
	while(tc--){
	    evaluate();
	}
	return 0;
}