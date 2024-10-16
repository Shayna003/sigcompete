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

//To solve this problem you need to essentially find the maximum distance between any two `X` values,
//inclusive of the beginning and end of the array. Once we find this maximum distance, the maximum a
//person can be distanced between the two `X` values will be found by using the formula: 
//	floor((x-1)/2)
//However, if our maximum distance is between an `X` and boundary, 
//i.e. the beginning or end of the array. Then we can maximise our distance by simply sleeping at the 
//end of the array, or beginning of it, since there is no second `X` value to compare with. The formula 
//for this is simply just x-1
void solve(string s)
{
	vector<int> beds;
	stringstream ss(s);
	char c;
	vector<int> dists;
	int lastbed = -1;
	while(ss >> c){
		if(c == 'X'){
			beds.pb(1);
			dists.pb(beds.size()-2-lastbed);
			lastbed = beds.size()-1;
			if(dists.size() == 1){
				dists.back()--;
			}
			else{
				dists.back() = (dists.back()-1)/2;
			}
		}
		else{
			beds.pb(0);
		}
	}
	dists.pb(beds.size()-1-lastbed);
	dists.back()--;
	lastbed = beds.size()-1;
	auto mx = max_element(dists.begin(), dists.end());

	cout << *mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
    while(cin >> s)
    {
        solve(s);
    }
    return 0;
}
