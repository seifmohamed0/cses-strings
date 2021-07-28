#include <bits/stdc++.h>
#include <ext/numeric>

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
using namespace std;
#define go ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
typedef vector<vector<int>> vvi;
typedef complex<long double> Point;
const double Pi = acos(-1.0), eps = 1e-8;
#define X real()
#define Y imag()
#define Angle(v) (atan2((v).Y , (v).X))
#define Length(v) ((long double)hypot((v).Y , (v).X))
#define Lengthsqr(v) (dot((v) , (v)))
const int mxn = 1e6 + 5, mod = 1e9 + 7, MOD = 1e9 + 7, mod2 = 998244353;
bool stop[mxn];
int tri[mxn][26], curr;
int dp[5005];
string s;
void insert(string &ss) {
	int node = 0;
	for (int i = 0; i < ss.size(); i++) {
		if (!tri[node][ss[i] - 'a'])
			tri[node][ss[i] - 'a'] = ++curr;
		node = tri[node][ss[i] - 'a'];
	}
	stop[node] = true;
}
int solve(int i) {
	int ret = 0, node = 0;
	for (; i < (int) s.size(); i++) {
		if (!tri[node][s[i] - 'a'])
			return ret;
		node = tri[node][s[i] - 'a'];
		if (stop[node]) {
			ret = ((ll) ret + dp[i + 1]) % mod;
		}
	}
	return ret;
}
void bingo() {
	cin >> s;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string ss;
		cin >> ss;
		insert(ss);
	}
	int n = s.size();
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = solve(i);
	}
	cout << dp[0];
}
int main() {
	go
#ifdef LOCAL
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
	//freopen("card.in", "rt", stdin);
	int t = 1;
	//cin>>t;
	while (t--) {
		bingo();
	}
	return 0;
}

