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


void solve(int b, int v)
{
	vector<pair<string,int>> vars;
	int ramsize = 0;
	for(int i = 0; i < v; i++){
		string s; int l;
		cin >> s >> l;
		vars.pb(mp(s,l));
		ramsize += l;
	}

	unordered_map<string, unsigned long long> vals;
	for(int i =0 ; i < v; i++){
		string tmp = "";
		for(int j = 0; j < vars[i].second; j++){
			string s;
			cin >> s;
			tmp += s;
		}

		// c++ has a special way you can convert from binary strings to 
		// ints (or in this case long longs) 
		vals[vars[i].first] = stoull(tmp,nullptr,2);
	}

	int checks; cin >> checks;

	for(int i = 0; i < checks; i++){
		string var; cin >> var; 
		if(vals.count(var)) {
			cout << var << "=" << vals[var] << endl;
		} else { 
			cout << var << "=" << endl;
		}
	}

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a,b;
    while(cin >> a >> b)
    {
        solve(a,b);
    }
    return 0;
}
