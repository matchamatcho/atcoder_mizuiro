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

vint di={-1,1,0,0};
vint dj={0,0,-1,1};

int main()
{
    int H,W,N;
    cin >> H >> W >> N;
    vstr s(H);
    rep(i,H) cin >> s[i];
    int si,sj;
    rep(i,H) {
        rep(j,W) {
            if(s[i][j]=='S'){
                si = i;
                sj = j;
                s[i][j]='.';
            }
        }
    }
    // cout<<si<<" "<<sj<<endl;
    // cout<<s[si][sj]<<endl;
    int hp=1;
    int ans=0;
    rep(ni,N){
        vvi visited(H, vint(W, 0));
        queue<pii>q;
        q.push({si,sj});
        visited[si][sj] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            // cout<<"visited:"<<visited[i][j]<<endl;
            if(0<=s[i][j]-'0'&&s[i][j]-'0'<=N){
                int kata=s[i][j]-'0';
                // cout<<kata<<endl;
                if(hp>=kata){
                    hp++;
                    s[i][j]='.';
                    ans+=visited[i][j]-visited[si][sj];
                    // cout<<visited[i][j]<<" "<<visited[si][sj]<<endl;
                    si = i;
                    sj = j;
                    // cout<<"HP:"<<hp<<endl;
                    break;
                }
            }
            q.pop();
            rep(d,4){
                int ni = i + di[d];
                int nj = j + dj[d];
                if(ni<0 || ni>=H || nj<0 || nj>=W) continue;
                if(visited[ni][nj]||s[ni][nj]=='X') continue;
                visited[ni][nj] = visited[i][j] + 1;
                q.push({ni,nj});
            }
        }
        

    }
    cout << ans << endl;
    

    return 0;
}
