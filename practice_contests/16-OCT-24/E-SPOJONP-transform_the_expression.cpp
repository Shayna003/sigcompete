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


// this problem was a direct implementation of the SHUNTING YARD ALGORITHM
// The shunting yard algorithm is a famous stack algorithm used for turning
// infix notation ( 1+2*3^(4+1) ), into more computer operable postfix 
// notation (or RPN) ( 12341+^*+ )
// this brilliant article explains it pretty well
// https://brilliant.org/wiki/shunting-yard-algorithm/

template<class T>
void printq(queue<T> x){
	while(!x.empty()){
		cout<<x.front()<<" ";
		x.pop();
	}
}

void printstack(stack<char> x){
	string out;
	while(!x.empty()){
		out = string(1,x.top()) + string(1,' ') + out;
		x.pop();
	}
	cout << out;

}

void solve()
{
	queue<char> stream;
	string output;
	char inpc;
	while(cin >> inpc) {
		stream.push(inpc);
	}


	unordered_map<char, int> precedence;
	precedence['('] = -1;
	precedence[')'] = -1;
	precedence['+'] = 0;
	precedence['-'] = 0;
	precedence['*'] = 1;
	precedence['/'] = 1;
	precedence['^'] = 2;
	stack<char> s;
	while(!stream.empty()) {
		/*
		cout << "stack: ";
		printstack(s);
		cout << endl;
		cout << "queue: ";
		printq(stream);
		cout << endl;
		cout << "out: ";
		cout << output;
		cout << endl << endl;
		*/
		char front = stream.front(); stream.pop();
		if(isdigit(front) or isalpha(front)){
			output += front;
			continue;
		}

		if(front == ')'){
			while(s.top() != '('){
				char top = s.top(); s.pop();
				output += top;
			}
			if(s.empty()){
				cout << "Invalid Expression
			}
			s.pop();
		}
		else if(front=='('){
			s.push(front);
		}
		else {
			while(!s.empty() and precedence[s.top()] >= precedence[front]){
				output += s.top(); s.pop();
			}
			s.push(front);
		}
	}

	while(!s.empty()){
		output += s.top();
		s.pop();
	}


	cout << output << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
    return 0;
}
