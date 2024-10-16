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


// this is a chess FEN notation converter problem. It is quite nitpicky
// and has several edge cases. My current solution is brute-forcey but can be done in 
// around an hour. For some prepatory problems, or other chess related CS problems
// check out:
// UVA 278
// UVA 696

bool ok(pair<int,int> pos){
	if(pos.first < 8 and pos.second < 8 and pos.first >= 0 and pos.second >= 0)
		return true;
	return false;
}

void solve(string fen)
{
	vector<vector<char>> board(8, vector<char>(8, 0));
	vector<string> rows;
	int tmpptr = 0;
	while(tmpptr < fen.size()){
		int nxt = fen.find('/',tmpptr);
		rows.pb(fen.substr(tmpptr, nxt-tmpptr));
		if(nxt == string::npos) {
			tmpptr = fen.size();
		}
		else tmpptr = nxt+1;
	}


	for(int i =0 ; i < 8; i++)
	{
		int ptr = 0;
		for(int j = 0; j < rows[i].size(); j++)
		{
			if(isdigit(rows[i][j])){
				ptr += rows[i][j]-'0';
			}
			else{
				board[i][ptr] = rows[i][j];
				ptr++;
			}
		}
	}

	/*
	for(int i =0 ; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
	*/

	map<char, vector<pair<int,int>>> deltas;
	deltas['n'] = {
		mp(2,1),
		mp(2,-1),
		mp(-2,1),
		mp(-2,-1),
		mp(1,2),
		mp(1,-2),
		mp(-1,2),
		mp(-1,-2)
	};
	deltas['r'] = {
		mp(0,1),
		mp(0,2),
		mp(0,3),
		mp(0,4),
		mp(0,5),
		mp(0,6),
		mp(0,7),
		mp(0,8),
		mp(0,-1),
		mp(0,-2),
		mp(0,-3),
		mp(0,-4),
		mp(0,-5),
		mp(0,-6),
		mp(0,-7),
		mp(0,-8),
		mp(1 ,0),
		mp(2 ,0),
		mp(3 ,0),
		mp(4 ,0),
		mp(5 ,0),
		mp(6 ,0),
		mp(7 ,0),
		mp(8 ,0),
		mp(-1,0),
		mp(-2,0),
		mp(-3,0),
		mp(-4,0),
		mp(-5,0),
		mp(-6,0),
		mp(-7,0),
		mp(-8,0)
	};
	deltas['b'] = {
		mp(1,1),
		mp(2,2),
		mp(3,3),
		mp(4,4),
		mp(5,5),
		mp(6,6),
		mp(7,7),
		mp(8,8),
		mp(1,-1),
		mp(2,-2),
		mp(3,-3),
		mp(4,-4),
		mp(5,-5),
		mp(6,-6),
		mp(7,-7),
		mp(8,-8),
		mp(-1,1),
		mp(-2,2),
		mp(-3,3),
		mp(-4,4),
		mp(-5,5),
		mp(-6,6),
		mp(-7,7),
		mp(-8,8),
		mp(-1,-1),
		mp(-2,-2),
		mp(-3,-3),
		mp(-4,-4),
		mp(-5,-5),
		mp(-6,-6),
		mp(-7,-7),
		mp(-8,-8)
	};
	deltas['q'] = {
		mp(1,1),
		mp(2,2),
		mp(3,3),
		mp(4,4),
		mp(5,5),
		mp(6,6),
		mp(7,7),
		mp(8,8),
		mp(1,-1),
		mp(2,-2),
		mp(3,-3),
		mp(4,-4),
		mp(5,-5),
		mp(6,-6),
		mp(7,-7),
		mp(8,-8),
		mp(-1,1),
		mp(-2,2),
		mp(-3,3),
		mp(-4,4),
		mp(-5,5),
		mp(-6,6),
		mp(-7,7),
		mp(-8,8),
		mp(-1,-1),
		mp(-2,-2),
		mp(-3,-3),
		mp(-4,-4),
		mp(-5,-5),
		mp(-6,-6),
		mp(-7,-7),
		mp(-8,-8),
		mp(0,1),
		mp(0,2),
		mp(0,3),
		mp(0,4),
		mp(0,5),
		mp(0,6),
		mp(0,7),
		mp(0,8),
		mp(0,-1),
		mp(0,-2),
		mp(0,-3),
		mp(0,-4),
		mp(0,-5),
		mp(0,-6),
		mp(0,-7),
		mp(0,-8),
		mp(1 ,0),
		mp(2 ,0),
		mp(3 ,0),
		mp(4 ,0),
		mp(5 ,0),
		mp(6 ,0),
		mp(7 ,0),
		mp(8 ,0),
		mp(-1,0),
		mp(-2,0),
		mp(-3,0),
		mp(-4,0),
		mp(-5,0),
		mp(-6,0),
		mp(-7,0),
		mp(-8,0)
	};
	deltas['k'] = {
		mp(1,0),
		mp(0,1),
		mp(-1,0),
		mp(0,-1),
		mp(1,1),
		mp(-1,1),
		mp(1,-1),
		mp(-1,-1)
	};
	deltas['p'] = {
		mp(1,1),
		mp(1,-1)
	};


	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board[i][j] < 2) continue;
			if(tolower(board[i][j]) == 'p'){
				if(islower(board[i][j])){
					for(auto k : deltas['p']){
						if(!ok(k+mp(i,j))) continue;
						pair<int,int> pos = k+mp(i,j);
						if(board[pos.first][pos.second] == 0) 
							board[pos.first][pos.second] = 1;
					}
				} else {
					for(auto k : deltas['p']){
						if(!ok(mp(-k.first,-k.second)+mp(i,j))) continue;
						pair<int,int> pos = mp(-k.first,-k.second)+mp(i,j);
						if(board[pos.first][pos.second] == 0) 
							board[pos.first][pos.second] = 1;
					}
				}
			}
			else {
				for(int k = 0; k < deltas[tolower(board[i][j])].size(); k++){
					if(!ok(deltas[tolower(board[i][j])][k]+mp(i,j))) continue;
					pair<int,int> pos = deltas[tolower(board[i][j])][k]+mp(i,j);
					if(board[pos.first][pos.second] < 2) 
						board[pos.first][pos.second] = 1;
					else {
						switch(tolower(board[i][j])){
							case 'r':
								k = ((k/8)*8)+7;
								break;
							case 'q':
								k = ((k/8)*8)+7;
								break;
							case 'b':
								k = ((k/8)*8)+7;
								break;
						}
					}
				}

				/*
				for(auto k : deltas[tolower(board[i][j])]){
					if(!ok(k+mp(i,j))) continue;
					pair<int,int> pos = k+mp(i,j);
					if(board[pos.first][pos.second] == 0) 
						board[pos.first][pos.second] = 1;
				}
				*/
			}
		}
	}


	/*
	for(int i =0 ; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board[i][j] == 0)
				cout << "X\t";
			else if(board[i][j] == 1)
				cout << "Y\t";
			 else {
				cout << board[i][j] << "\t";
			}
		}
		cout << endl;
	}
	*/

	int out = 0;
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board[i][j] == 0)
			{
				out++;
			}
		}
	}
	cout << out << endl;
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
