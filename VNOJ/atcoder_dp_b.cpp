/*
	link problem: https://oj.vnoi.info/problem/atcoder_dp_b
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b

const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), dp(n, 0);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		dp[i] = 1e9;
		for (int j = 1; i - j >= max(0, i - k); ++j) {
			dp[i] = min(dp[i - j] + abs(a[i] - a[i - j]), dp[i]);
		}
	}
	cout << dp.back();
}

int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}