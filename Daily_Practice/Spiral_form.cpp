/*Given a 2D array of size m*n, write a program to print it in spiral form.
Example:
Input:1 2 3
	  4 5 6
	  7 8 9
output:123698745
*/

/*Implementation: think of a box and start covering outline of the box of each box till all element didn't cover.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int sp[m][n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>sp[i][j];
        }
    }
    cout<<m*n<<endl;
    int startrow = 0, startcol = 0, endrow = m - 1, endcol = n - 1, count = 0;

    while(count < (m*n))
    {
		//print first row.
        for(int i = startcol; i <= endcol; i++){
            cout<<sp[startrow][i];
            count++;
        }startrow++;
		//print last col
        for(int i = startrow; i <=endrow; i++){
            cout<<sp[i][endcol];
            count++;
        }endcol--;
		//print last row
        if(endrow > startrow){
            for(int i = endcol; i >= startcol; i--){
                cout<<sp[endrow][i];
                count++;
            }endrow--;
        }
		//print first col
        if(endcol > startcol){
            for(int i = endrow; i >= startrow; i--){
                cout<<sp[i][startcol];
                count++;
            }startcol++;
        }
    }
    return 0;
}