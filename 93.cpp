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
    int h, w, k;
    cin >> h >> w >> k;
    vstr s(h);
    rep(i, h) cin >> s[i];
    // 削除
    auto deleteline = [&](vstr &s, int i, int left, int right)
    {
        for (int j = left; j < right; ++j)
        {
            s[i][j] = '0';
        }
    };

    auto candeleteline = [&](vstr &s, int i, int &left, int &right) -> bool
    {
        // 1行を走査して、最初の「長さ>=k の同値連続区間」を返す
        for (int j = 0; j < w; ) {
            if (s[i][j] == '0') { ++j; continue; }
            int t = j + 1;
            while (t < w && s[i][t] == s[i][j]) ++t;
            if (t - j >= k) {
                left = j;
                right = t; // [left, right)
                return true;
            }
            j = t;
        }
        return false;
    };

    auto gravity = [&](vstr &s)
    {
        vstr tmp(h, string(w, '0'));
        rep(j, w)
        {
            int index = h - 1;
            for (int i = h - 1; i >= 0; --i)
            {
                if (s[i][j] != '0')
                {
                    tmp[index][j] = s[i][j];
                    index--;
                }
            }
        }
        s = tmp;
    };

    
    auto solve = [&](vstr ss) -> int
    {
        int result = 0;
        int tei = 1;
        gravity(ss);
        while (1)
        {
            bool changed = false;
            rep(i, h)
            {
                int left, right;
                while(candeleteline(ss, i, left, right)){
                    changed = true;
                    result += tei * (ss[i][left] - '0') * (right - left);
                
                    deleteline(ss, i, left, right);

                }
    
            }
            if (!changed)
                break;

            tei*=2;
            gravity(ss);
        }
        return result;
    };

    int ans = 0;

    rep(i,h)rep(j,w){
        vstr ss=s;
        ss[i][j]='0';
        chmax(ans,solve(ss));
    }

    cout<<ans<<endl;
    return 0;
}
