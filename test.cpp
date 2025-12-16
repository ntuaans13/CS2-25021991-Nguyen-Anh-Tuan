#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b)  for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for(int i = (b), _a = (a); i >= _a; --i)
#define REP(i, a, b)  for(int i = (a), _b = (b); i < _b;  ++i)
#define REPD(i, b, a) for(int i = (b), _a = (a); i > _a;  --i)
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(v) (int)v.size()
#define fi first
#define se second

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {return l + rng() % (r - l + 1);}

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const int mod = 1e9 + 7;
const int inf = 1e9;
const int N = 2e3 + 5;

int n, dp[N][N];
string s;

void process() {
    cin >> s;
    n = s.size(); s = ' ' + s;
    memset(dp, -0x3f, sizeof(dp));
    FOR(i, 1, n) {
        dp[i][i] = 1;
        if(i < n && s[i] == s[i + 1]) 
            dp[i][i + 1] = 2;
    }
    FORD(i, n, 1) {
        FOR(j, i + 2, n) {
            if(s[i] == s[j]) maximize(dp[i][j], dp[i + 1][j - 1] + 2);
            maximize(dp[i][j], dp[i + 1][j]);
            maximize(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[1][n] << '\n';
}

signed main() {
    if(fopen("test.inp","r")) {
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ntests = 1;
    // cin >> ntests;
    while(ntests--) process();

    // cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s!\n";
    return 0;
}