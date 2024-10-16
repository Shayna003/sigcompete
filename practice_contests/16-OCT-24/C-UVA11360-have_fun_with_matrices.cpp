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
	int n; cin >> n; 
	vector<vector<int>> mat(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c; cin >> c;
			mat[i][j] = c-'0';
		}
	}

	int q; cin >> q;
	while(q--){
		string ins; cin >> ins;
		if(ins == "inc"){
			for(int i =0 ; i < n; i++){
				for(int j = 0; j < n; j++){
					mat[i][j]++;
					mat[i][j] %= 10;
				}
			}
		}
		else
		if(ins == "dec"){
			for(int i =0 ; i < n; i++){
				for(int j = 0; j < n; j++){
					mat[i][j]--;
					if(mat[i][j] < 0) mat[i][j] += 10;
				}
			}
		}
		else
		if(ins == "transpose") {
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					swap(mat[i][j], mat[j][i]);
				}
			}
		}
		else
		if(ins == "row"){
			int a,b; cin >> a >> b;
			a--; b--;
			swap(mat[a], mat[b]);
		}
		else { // col
			int a,b; cin >> a >> b;
			a--; b--;
			for(int i = 0; i < n; i++){
				swap(mat[i][a], mat[i][b]);
			}
		}
	}

	cout << "Case #" << tc << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
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
