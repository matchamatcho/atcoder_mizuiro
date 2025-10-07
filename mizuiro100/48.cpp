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
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vint w(n);
        rep(i, n) cin >> w[i];
        vvi visited(n + 1, vint(n + 1, -1));
        auto dfs = [&](auto self, int l, int r) -> int
        {
            if (visited[l][r] != -1)
                return visited[l][r];
            if (l == r)
            {
                visited[l][r] = 0;
                return 0;
            }
            if (l + 1 == r)
            {
                visited[l][r] = 0;
                return 0;
            }
            if (l + 1 == r - 1)
            {
                if (abs(w[l] - w[l + 1]) <= 1)
                {
                    visited[l][r] = 2;
                    return visited[l][r];
                }
                else
                {
                    visited[l][r] = 0;
                    return visited[l][r];
                }
            }
            // cout<<self(self,l+1,r-1)<<" "<<l+1<<" "<<r-1<<endl;
            int now=0;
            if (self(self, l + 1, r - 1) == r - l - 2)
            {
                if (abs(w[l] - w[r - 1]) <= 1)
                {
                    chmax(now,r-l);
                    
                }
                else
                {
                    chmax(now,r-l-2);
                    
                }
                
            }
            
            for (int i = l+1; i < r; ++i)
            {
                // cout<<l<<' '<<i<<' '<<r<<endl;
                chmax(now, self(self, l, i) + self(self, i , r));
            }
            visited[l][r] = now;
            return visited[l][r];
        };
        // cout<<visited[0][n]<<endl;
        // break;
        cout << dfs(dfs, 0, n) << '\n';
        // cout << visited[0][3] << endl;

        // break;
    }

    return 0;
}
