/*
Question_link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

Input : 5
        1 2 3 4 5
Output: 5 1 2 3 4
*/


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
