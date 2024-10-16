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


void solve(int tc)
{
	string s; cin >> s;
	vector<pair<char,int>> tokens = {mp(s[0],1)};
	for(int i = 1; i < s.size(); i++){
		if(isalpha(s[i])){
			tokens.pb(mp(s[i], 1));
		}else{
			string tmp;
			while(i < s.size()){
				if(isalpha(s[i])){
					i--;
					break;
				}
				tmp += s[i];
				i++;
			}
			tokens.back().second = stoi(tmp);
		}
	}

	unordered_map<char, float> molars;
	molars['C'] = 12.01;
	molars['H'] = 1.008;
	molars['O'] = 16.00;
	molars['N'] = 14.01;

	float out = 0;
	for(auto i : tokens){
		out += molars[i.first] * i.second;
	}
	cout << fixed << setprecision(3) << out << endl;
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
