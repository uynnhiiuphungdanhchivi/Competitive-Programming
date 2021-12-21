/*
	link problem: https://oj.vnoi.info/problem/nkabd
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
	int l, r, cnt = 0;
	cin >> l >> r;
	vector<int> a(r + 1, 1);
	for (int i = 2; i <= r; ++i) {
		int tmp = max((l - 1 + i) / i, 2);
		tmp *= i;
		while (tmp <= r) {
			a[tmp] += i;
			tmp += i;
		}
	}
	for (int i = l; i <= r; ++i) {
		if (a[i] > i) {
			cnt++;
		}
	}
	cout << cnt;
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