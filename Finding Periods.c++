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
const int B1 = 256;
const int B2 = 128;
const int MOD1 = 2000000011;
const int MOD2 = 1000000007;
const int N = 1e6 + 5;
char s[N];
int mul(int a, int b, int m) {
	return a * 1ll * b % m;
}
int add(long long a, int b, int m) {
	a += b;
	while (a >= m)
		a -= m;
	while (a < 0)
		a += m;
	return a;
}
pair<int, int> prefix[N];
void hash_prefix() {
	int h1, h2;
	h1 = h2 = 0;
	for (int i = 0; s[i]; i++) {
		h1 = ((1LL * h1 * B1) % MOD1 + s[i]) % MOD1;
		h2 = ((1LL * h2 * B2) % MOD2 + s[i]) % MOD2;
		prefix[i] = make_pair(h1, h2);
	}
}
pair<int, int> suffix[N];
void hash_suffix() {
	int h1, h2, pw1, pw2;
	h1 = h2 = 0;
	pw1 = pw2 = 1;
	int sz = strlen(s);
	for (int i = sz - 1; i >= 0; i--) {
		h1 = (h1 + (1LL * pw1 * s[i]) % MOD1) % MOD1;
		h2 = (h2 + (1LL * pw2 * s[i]) % MOD2) % MOD2;
		pw1 = (1LL * pw1 * B1) % MOD1;
		pw2 = (1LL * pw2 * B2) % MOD2;
		suffix[i] = { h1, h2 };
	}
}
int p[N], pp[N];
void pre() { // one time for all test cases
	p[0] = pp[0] = 1;
	for (int i = 1; i < N; i++) {
		p[i] = mul(p[i - 1], B1, MOD1);
		pp[i] = mul(pp[i - 1], B2, MOD2);
	}
}
pair<int, int> get(int l, int r) {
	if (!l)
		return prefix[r];
	int len = r - l + 1;
	return {add(prefix[r].first , -mul(p[len] , prefix[l - 1].first ,
						MOD1) , MOD1)
		, add(prefix[r].second, -mul(pp[len] , prefix[l -
						1].second , MOD2) , MOD2)};
}
int cnt[26], siz;
bool valid(int len) {
	pair<int, int> cu = get(0, len - 1);
	int st = len;
	int en = st * 2 - 1;
	while (en < siz) {
		if (get(st, en) == cu) {
			st = en + 1;
			en = st + len - 1;
		} else {
			return false;
		}
	}
	if (st != siz) {
		int diff = (siz - 1 - st);
		if (get(0, diff) != get(st, siz - 1))
			return false;
	}
	return true;

}
void bingo() {
	scanf("%s", s);
	pre();
	hash_prefix();
	hash_suffix();
	siz = strlen(s);
	for (int i = 0; i < siz; i++) {
		cnt[s[i] - 'a']++;
		if (i == siz - 1 && cnt[s[i] - 'a'] == siz) {
			for (int j = 1; j <= siz; j++) {
				cout << j << " ";
			}
			return;
		}
	}
	for (int i = 2; i < siz; i++) {
		if (valid(i)) {
			cout << i << " ";
		}
	}
	cout << siz;
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
