#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
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
#define yes(q) cout << ((q) ? "Yes" : "No") << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF =1001001001;
const ll INFL = 4e18;

vint di={1,1,1,-1,-1,-1,0,0},dj={-1,0,1,-1,0,1,-1,1};
int main()
{
    while(1){
        int h,w;
        cin >> w >> h;
        if(h == 0 && w == 0) break;
        vvi c(h, vint(w));
        int ans=0;
        vvi visited(h,vint(w));
        rep(i,h) rep(j,w) cin >> c[i][j];
        auto dfs=[&](auto self,int i,int j)->void{
            // if(i < 0 || i >= h || j < 0 || j >= w) return ;
            // if(visited[i][j]>0||c[i][j]==0) return;
            visited[i][j]=1;
            // cout<<i<<" "<<j<<endl;
            rep(k,8){
                int ni=i+di[k],nj=j+dj[k];
                // cout<<ni<<" "<<nj<<"ninj"<<endl;
                if(ni<0||ni>=h||nj<0||nj>=w) continue;
                if(c[ni][nj]==0||visited[ni][nj]>0) continue;
                self(self,ni,nj);
            }
            return;

        };
        rep(i,h){
            rep(j,w){
                if(visited[i][j]==0 && c[i][j]>0){
                    ans++;
                    // cout<<i<<" "<<j<<endl;
                    dfs(dfs,i,j);
                    // cout<<h<<" "<<w<<endl;
                    // rep(ii,h){
                    //     rep(jj,w){
                    //         cout<<visited[ii][jj]<<" ";
                    //     }
                    //     cout<<endl;
                        
                    // }
                    // cout<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    

    return 0;
}
