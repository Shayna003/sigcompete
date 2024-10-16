#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ll long long
#define v(i) vector<i>
#define inveci(n,a) for(int integer=0; integer < n; integer++) {int abc123; cin >> abc123; a.pb(abc123);}

// an old codeforces problem
// you can find the official editorial here:
// https://codeforces.com/blog/entry/5378?locale=en (scroll to B)


// The first, and more obvious, attempt at this problem would be to just simulate the searching 
// of both Vasya and Petya, and output the results. However, this leads to a timeout error, 
// since the size of the arrays can reach 10^5. 
// The correct solution is to input the first array as a hash map, so that the indices of every
// element in the array can be found in O(1) time, meaning that we can just figure out how fast a
// linear scan, say for Vasya, would be by just getting the index of the number 
// (and adding 1, because of 0-based indexing), and for Petya just getting the size of the array
// and substracting the index. 


void solve(int tc)
{
	int n; cin >> n;
	unordered_map<int,int> a;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a[x] = i;
	}
	int m; cin >> m;
	vector<int> b; inveci(m,b)
		
	//vasya
	long long c1 = 0;
	for(auto i : b)
	{
		c1 += a[i]+1;
	}

	//petya
	long long c2 = 0;
	for(auto i : b)
	{
		c2 += n-a[i];
	}
	cout << c1 << " " << c2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;//; cin >> tc;
    int ogtc = tc;
    while(tc--)
    {
        solve(ogtc-tc);
    }
    return 0;
}
