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
#define printv(x); for(auto now : x) cout << now << " "; cout << endl;

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
    int m, n;
    cin >> m >> n;
    int k;

    cin >> k;

    vstr s(m);
    rep(i, m) cin >> s[i];

    vll a(k), b(k), c(k), d(k);
    rep(i, k) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<vvll> ss(3, vvll(m + 1, vll(n + 1, 0)));
    rep(i, m) rep(j, n)
    {
        if (s[i][j] == 'J')
            ss[0][i + 1][j + 1] = 1;
        if (s[i][j] == 'O')
            ss[1][i + 1][j + 1] = 1;
        if (s[i][j] == 'I')
            ss[2][i + 1][j + 1] = 1;
    }

    // rep(k, 3) {
    //     cout << "k=" << k << endl;
    //     rep(i, m+1) {
    //         printv(ss[k][i]);
    //     }
    // }
    // cout << endl;

    rep(k, 3)
    {

        rep(i, m)
        {
            rep(j, n+1)
            {
                ss[k][i + 1][j] += ss[k][i][j];
            }
        }
        rep(i, m+1)
        {
            rep(j, n )
            {
                ss[k][i][j + 1] += ss[k][i][j];
            }
        }
    }
    rep(i, k)
    {
        rep(j, 3)
        {
            cout << ss[j][c[i]][d[i]] - ss[j][a[i] - 1][d[i]] - ss[j][c[i]][b[i] - 1] + ss[j][a[i] - 1][b[i] - 1];
            if (j != 2)
                cout << " ";
            else
                cout << endl;
        }
    }

    return 0;
}
