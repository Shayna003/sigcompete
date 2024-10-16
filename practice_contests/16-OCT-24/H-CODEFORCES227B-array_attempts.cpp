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
