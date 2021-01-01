#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];

	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<arr[n-1]<<" ";

	    for(int i=0; i<n-1; i++)
	        cout<<arr[i]<<" ";
        cout<<endl;
	}
	return 0;
}
