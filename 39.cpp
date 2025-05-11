#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vstr = vector<string>;
using vint = vector<int>;
using vvi = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
#define mkpr make_pair
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define printv(x)           \
    ;                       \
    for (auto now : x)      \
        cout << now << " "; \
    cout << endl;
#define yes(q) cout << ((q) ? "Yes" : "No") << endl;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = 1001001001;
const ll INFL = 4e18;

int main()
{
    int N;
    cin >> N;
    vll a(N);
    rep(i, N)
    {
        cin >> a[i];
    }
    vvll dp(N + 1, vll(21));
    dp[0][0] = 1;

    rep(i, N - 1)
    {
        rep(j, 21)
        {
            if (j - a[i] >= 0)
            {

                dp[i + 1][j] += dp[i][j - a[i]];
                // cout << dp[i + 1][j - a[i]] << endl;
            }
            if ((j + a[i] <= 20))
            {
                if((i==0)&&a[i]==0)continue;

                // chmax(dp[i+1][j],dp[i][j+a[i]]+1);
                dp[i + 1][j] += dp[i][j + a[i]];
                // cout << dp[i + 1][j - a[i]] << endl;
            }
           
        }
        // printv(dp[1 + i]);
    }
    int ans = 0;
    cout << dp[N - 1][a.back()] << endl;

    return 0;
}
