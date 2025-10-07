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

void solve(int h)
{
    vvi a(h, vint(5));
    rep(i, h) rep(j, 5) cin >> a[i][j];

    ll ans = 0;
    while (1)
    {
        bool changed = false;
        rep(i, h)
        {

            int cnt = -1;
            int index = -1;
            bool ok = true;
            for (int j = 5; j >= 3; j--)
            {

                cnt = j;
                for (int start = 0; start <= 5 - j; start++)
                {
                    ok = true;
                    index = start;
                    rep(k, j - 1)
                    {
                        if ((a[i][k + start] != a[i][k + 1 + start]) || a[i][k + start] == 0)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        break;
                }
                if (ok)
                    break;
            }
            // cout << ok << endl;

            if (ok)
            {
                changed = true;
                ans += a[i][index] * cnt;
                for (int k = index; k < index + cnt; k++)
                {
                    a[i][k] = 0;
                }
            }
        }
        vvi na(h, vint(5, 0));

        rep(i, 5)
        {
            int index = h-1;

            for(int j=h-1;j>=0;j--)
            {
                if (a[j][i] != 0)
                {
                    na[index][i] = a[j][i];
                    index--;
                }
            }
        }
        swap(a, na);

        if (!changed)
            break;
    }
    cout << ans << endl;
}

int main()
{
    while (1)
    {

        int n;
        cin >> n;
        if (n == 0)
            return 0;

        solve(n);
    }

    return 0;
}
