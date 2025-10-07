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
int MOD = 10000;

int main()
{
    int N, K;
    cin >> N >> K;
    vll a(N), b(K);
    rep(i, K)
    {
        int aa, bb;
        cin >> aa >> bb;
        a[aa - 1] = bb;
    }
    vector<vvi> dp(N + 1, vvi(3, vint(3, 0)));
    rep(i, N)
    {
        if (a[i] == 0)
        {
            // cout << i << " " << "a[i] == 0" << endl;
            if (i == 0)
            {
                rep(j, 3) dp[i + 1][j][1] = 1;
                continue;
            }
            rep(j, 3) rep(k, 3)
            {
                if (j == k)
                {
                    dp[i + 1][j][2] += dp[i][k][1];
                }
                else
                {
                    dp[i + 1][j][1] += dp[i][k][1] + dp[i][k][2];
                }
                dp[i + 1][j][1] %= MOD;
                dp[i + 1][j][2] %= MOD;
            }
        }
        else
        {
            // cout << i << " " << "a[i] != 0" << endl;
            if (i == 0)
            {
                rep(j, 3)
                {
                    if (j == (a[i] - 1))
                        dp[i + 1][j][1] = 1;
                }
                continue;
            }
            rep(j, 3) rep(k, 3)
            {
                if (j != (a[i] - 1))
                    continue;
                if (j == k)
                {
                    dp[i + 1][j][2] += dp[i][k][1];
                }
                else
                {
                    dp[i + 1][j][1] += dp[i][k][1] + dp[i][k][2];
                }
                dp[i + 1][j][1] %= MOD;
                dp[i + 1][j][2] %= MOD;
            }
        }
      
    }

    ll ans = 0;
    rep(i, 3) rep(j, 3)
    {
        ans = (ans+dp[N][i][j])%10000;
    }
    cout << ans << endl;

    // rep(i, N + 1)
    // {
    //     rep(j, 3)
    //     {
    //         cout << dp[i][j][1] << "+" << dp[i][j][2] << ", ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
