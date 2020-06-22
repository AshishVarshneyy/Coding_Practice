/* This code ilustrate the map STL
 * and its working(insertion, traversing, searching, find, erase, clear)
 * and also reverse_traversing
 */

#include<iostream>
#include<map>

using namespace std;

int main(){

	int n;  //Enter count to digit
	scanf("%d",&n);
	int arr[n];
	map<int,int> m;

	//Insertion
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		m[arr[i]]++;
	}

	//traversion
	map<int,int>::iterator it;
	for(it=m.begin(); it!=m.end();it++){
		printf("%d %d\n",it->first,it->second);
	}

	return 0;
}

