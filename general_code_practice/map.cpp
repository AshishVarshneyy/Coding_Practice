/* This code ilustrate the map STL
 * and its working(insertion, traversing, searching, find, erase, clear)
 * and also reverse_traversing
 * Function : Time complexity
 * insertion: nlog(n)
 * traverse : nlog(n)
 * search   : log(n)
 * erase    : log(n)
 * Functions that we can use are clear(), empty(), size(), pair insert(keyvalue, mapvalue),
 * insert(), count(), equal_range(), erase(), rend(), rbegin(), find(), crbegin() and crend(),
 * cbegin() and cend(), emplace(), max_size(), upper_bound(), lower_bound(), emplace_hint(),
 * value_comp(), key_comp().
 * for further details refer https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
 */

#include<iostream>
#include<map>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	int arr[n];
	map<int,int> m;

	//Insertion
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		m[arr[i]]++;
	}

	//traverse
	map<int,int>::iterator it;
	for(it=m.begin(); it!=m.end();it++){
		printf("%d %d\n",it->first,it->second);
	}

	//reverse traverse
	map<int,int>::reverse_iterator itr;
	for(itr=m.rbegin();itr!=m.rend();itr++){
        printf("%d %d\n",itr->first,itr->second);
	}

    //find()
    int x;
    cin>>x;
    it = m.find(x);
    if(it!=m.end()){
        printf("%d %d\n",it->first,it->second);
    }

    //erase()
    m.erase(x);
    for(it=m.begin(); it!=m.end();it++){
		printf("%d %d\n",it->first,it->second);
	}

	// assigning the elements from gquiz1 to gquiz2
    map<int, int> m2(m.begin(), m.end());

    //erase upto certain key
    m2.erase(m2.begin(), m2.find(x));
	return 0;
}

