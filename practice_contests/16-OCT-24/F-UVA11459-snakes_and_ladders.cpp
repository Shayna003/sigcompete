#include "bits/stdc++.h"

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
typedef unsigned int uint;
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

// this problem was mainly implementation heavy. You don't actually need to make
// a grid (2d list or matrix) to solve this problem. This solution is probably
// not the neatest way of going about it...
void solve(int tc)
{
	int players, snadders, rolls;
	cin >> players >> snadders >> rolls;

	vector<int> playerpos(players,0);
	vector<int> routes(100, -1);
	vector<int> movelist(rolls,0);

	for(int i = 0; i < snadders; i++)
	{
		int a,b; cin >> a >> b;
		routes[a-1] = b-1;
	}

	for(int i =0 ; i < rolls; i++)
	{
		cin >> movelist[i];
	}

	int curplayer = 0;
	for(int i = 0; i < rolls; i++)
	{
		playerpos[curplayer] += movelist[i];
		if(routes[playerpos[curplayer]] >= 0) {
			playerpos[curplayer] = routes[playerpos[curplayer]];
		}
		if(playerpos[curplayer] == 99){
			break;
		}
		curplayer = (curplayer + 1) % players;
	}

	for(int i = 0; i < players; i++)
	{
		cout << "Position of player " << i+1 << " is " << playerpos[i]+1 << "." << endl;
	}

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc; cin >> tc;
    int ogtc = tc;
    while(tc--)
    {
        solve(ogtc-tc);
    }
    return 0;
}
