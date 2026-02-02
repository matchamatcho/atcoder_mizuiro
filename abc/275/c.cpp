#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll,ll>;
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
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(),(x).end()
#define printv(x); for(auto now : x) cout << now << " "; cout << endl;
#define Yes(q) cout << ((q) ? "Yes" : "No") << endl;
#define priv(value) print_variable(#value, value)
// 汎用的な表示関数テンプレート
// どんな型 T の変数でも受け取れるようにする
template <typename T>
void print_variable(const std::string& name, const T& value) {
    std::cout << "変数名: " << name << ", 値: " << value << std::endl;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;

int main()
{
int n=9;
    vstr s(9);
    rep(i,9)cin>>s[i];

    auto f=[&](int x)->char{
        vint ans;
        ans.push_back(x/n);
        ans.push_back(x%n);

        return s[ans[0]][ans[1]];

    };

    // 点 (p, q) が N 点に含まれるかどうか
    auto check = [&](int p, int q) -> bool {
        if (p < 0 || p >= n || q < 0 || q >= n) return false;
        return true;
    };

    int ans=0;
    set<set<int>> st;
    rep(i,n*n)rep(j,i){

        int x1 = i/n, y1 = i%n, x2 = j/n, y2 = j%n;
        int dx = x2 - x1, dy = y2 - y1;
        int square = dx * dx + dy * dy;


        // i を中心として i->j を 90 度回転した点を考える
        {
            int x3 = x1 - dy, y3 = y1 + dx;
            int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
            if (check(x3, y3) && check(x4, y4)) {
                if(s[x1][y1]=='#'&&s[x2][y2]=='#'&&s[x3][y3]=='#'&&s[x4][y4]=='#'){
                ans+=(s[x1][y1]=='#'&&s[x2][y2]=='#'&&s[x3][y3]=='#'&&s[x4][y4]=='#')?1:0;
                set<int>now;
                now.insert(x1*n+y1);
                now.insert(x2*n+y2);
                now.insert(x3*n+y3);
                now.insert(x4*n+y4);

                st.insert(now);}
            }
        }

        // i を中心として i->j を -90 度回転した点を考える
        {
            int x3 = x1 + dy, y3 = y1 - dx;
            int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
            if (check(x3, y3) && check(x4, y4)) {
            if(s[x1][y1]=='#'&&s[x2][y2]=='#'&&s[x3][y3]=='#'&&s[x4][y4]=='#'){
                ans+=(s[x1][y1]=='#'&&s[x2][y2]=='#'&&s[x3][y3]=='#'&&s[x4][y4]=='#')?1:0;
                set<int>now;
                now.insert(x1*n+y1);
                now.insert(x2*n+y2);
                now.insert(x3*n+y3);
                now.insert(x4*n+y4);

                st.insert(now);}
            }
        }

        



    }
    
        cout<<st.size()<<endl;

    

    return 0;
}
