/*
Question_link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

Input : 5 3
		1 2 3 4 5
		1 2 3
Output: 5
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int hash[100001]={0};
	    int n,m;
	    cin>>n>>m;
	    int arr[n], brr[m];
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        hash[arr[i]]=1;
	    }
	    
	    for(int i=0; i<m; i++){
	        cin>>brr[i];
	        hash[brr[i]]=1;
	    }
	    
	    int count=0;
	    for(int i=0; i<100001; i++)
	        if(hash[i])
	            count++;
    
        cout<<count<<endl;
    }
	
	return 0;
}