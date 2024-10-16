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

// Uses a queue data structure to implement the solution to the problem. 
// Also have a hash map to store the index-value pairs of the elements
void solve(int tc)
{
	int n, m; cin >> n >> m;

	unordered_map<int,int> h;
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		q.push(i);
		h[i] = x;
	}

	while(q.size() > 1)
	{
		auto x = q.front(); q.pop();
		if(h[x]-m > 0)
		{
			h[x] -= m;
			q.push(x);
		}
	}
	cout << q.front() + 1;

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; //; cin >> tc;
    int ogtc = tc;
    while(tc--)
    {
        solve(ogtc-tc);
    }
    return 0;
}
