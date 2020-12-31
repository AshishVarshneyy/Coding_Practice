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
	        hash[brr[i]]++;
	    }
	    
	    int count=0;
	    for(int i=0; i<100001; i++)
	        if(hash[i]==2)
	            count++;
    
        cout<<count<<endl;
    }
	
	return 0;
}