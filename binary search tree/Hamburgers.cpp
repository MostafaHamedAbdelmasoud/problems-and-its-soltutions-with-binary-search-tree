
Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.

Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.

Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

Input
The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).

The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen. The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

Examples
Input
BBBSSC
6 4 1
1 2 3
4
Output
2


Input
BBC
1 10 1
1 10 1
21
Output
7

Input
BSC
1 1 1
1 1 3
1000000000000
Output
200000000001




solution:



#include <bits/stdc++.h>
using namespace std;
long long mid,n,k,a[9],b[9],c[9];
string s;
bool ok(long long mid)
{
	long long K=k;
  for(int i=0; i < 3 ;++i)
  {
  	if( a[i]  -  (c[i]*mid)  < 0 ) 
  		K += b[i] * ( a[i]  -  (c[i]*mid) ) ;
  	if(K <0)
  		return 0;
  }
  return 1;
}
long long Bs()
{
	long long low=0 , high =1e12+100;
	while (low < high)
       {
        mid=low+(high-low+1)/2;
        if (!ok(mid))
         high = mid-1;
        else
         low = mid;
       }
    return high;
}
void input()
{
	cin>>s;
	for(int i=0 ; i < s.size() ;i++)
	{
		if(s[i]=='B')c[0]++;
		if(s[i]=='S')c[1]++;
		if(s[i]=='C')c[2]++;
	}
	for(int i=0 ; i<3 ;i++)cin>>a[i];
	for(int i=0 ; i<3 ;i++)cin>>b[i];
	cin>>k;
}
int main()
{
	input();
	cout<<Bs()<<endl;
	return 0;
}
