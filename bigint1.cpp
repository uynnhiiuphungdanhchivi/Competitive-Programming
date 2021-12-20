/* 
	link problem: 
	Author : vidut_206_CNH
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;



typedef vector<int> vi;
const int BASE = 10000;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            a[i + 1]--;
        }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

vi operator*(const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / BASE;
            c[i + j] %= BASE;
        }
    return fix(c), c;
}

vi to_vi(int x) {  // x < Base
    assert(x < BASE);
    return vi(1, x);
}

vi operator+(vi a, const vi &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i)
        a[i] += b[i];
    return fix(a), a;
}
vi operator-(vi a, const vi &b) {
    for (int i = 0; i < b.size(); ++i)
        a[i] -= b[i];
    return fix(a), a;
}
vi operator*(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= x;
    return fix(a), a;
}

bool operator<(const vi &a, const vi &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

vi operator/(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = (int)a.size() - 1, r = 0; i >= 0; --i, r %= x) {
        r = r * BASE + a[i];
        a[i] = r / x;
    }
    return fix(a), a;
}
int operator%(const vi &a, int x) {  //x < BASE
    int r = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i)
        r = (r * BASE + a[i]) % x;
    return r;
}

istream &operator>>(istream &cin, vi &a) {
    string s;
    cin >> s;
    a.clear();
    a.resize(s.size() / 4 + 1);
    for (int i = 0; i < s.size(); ++i) {
        int x = (s.size() - 1 - i) / 4;  // <- log10(BASE)=4
        a[x] = a[x] * 10 + (s[i] - '0');
    }
    return fix(a), cin;
}

ostream &operator<<(ostream &cout, const vi &a) {
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%04d", a[i]);
    return cout;
}

void solve() {
	string a,b;
	cin >> a >> b;
	bignum bigA = toBignum(a);
	bignum bigB = toBignum(b);
	printBignum(add(bigA,bigB));
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}