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
const int mxn = 2e6 + 5, mod = 1e9 + 7, MOD = 1e9 + 7, mod2 = 998244353;
int Kmp[mxn];
string s, n, m;

int kmp() {
	Kmp[0] = 0;
	int sz = s.size();
	for (int i = 1; i < sz; i++) {
		int j = Kmp[i - 1];
		while (j != 0 && s[i] != s[j]) {
			j = Kmp[j - 1];
		}
		Kmp[i] = j + (s[i] == s[j]);
	}
	int ret = 0;
	for (int i = (int) m.size() + 1; i < (int) s.size(); i++)
		if (Kmp[i] == (int) m.size())
			ret++;
	return ret;
}
void bingo() {
	cin >> n >> m;
	s = m + '%' + n;
	cout << kmp();
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
