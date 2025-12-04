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
    int H,W,N,h,w;
    cin>>H>>W>>N>>h>>w;
    vvi a(H,vint(W));
    map<int,int>total_mp;
    map<int,int>sub_mp;
    int ans=0;
    rep(i,H)rep(j,W){cin>>a[i][j];total_mp[a[i][j]]++;}
    sub_mp=total_mp;
    ans=total_mp.size();
    rep(i,H-h+1){
                total_mp=sub_mp;

        ans=0;
        for(auto p:total_mp){
            if(p.second>0)ans++;
        }
        map<int,int>mp;
        rep(ii,h)rep(jj,w){
            mp[a[i+ii][jj]]++;
            total_mp[a[i+ii][jj]]--;
        }
        for(auto p:mp){
            // if(total_mp[p.first]==p.second)ans--;
        }
        for(auto p:total_mp){
            if(p.second==0)ans--;
        }
        cout<<ans<<" ";
        // cout<<"---"<<"\n";
        // for(auto p:total_mp){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        // cout<<"---"<<"\n";
        
        rep(jj,W-w){//jj列目を消す黒塗りから
            rep(ii,h){
                mp[a[i+ii][jj]]--;
                // if(mp[a[i+ii][jj]]==0){ans++;cout<<"hukkatu"<<a[i+ii][jj]<<endl;} 
                total_mp[a[i+ii][jj]]++;
                if(total_mp[a[i+ii][jj]]==1){ans++;
                    // cout<<"hukkatu"<<a[i+ii][jj]<<endl;
                }  
            }
            rep(ii,h){
                mp[a[i+ii][jj+w]]++;
                // if(total_mp[a[i+ii][jj+w]]==mp[a[i+ii][jj+w]]){ans--;cout<<"sakujo"<<a[i+ii][jj+w]<<endl;}
                total_mp[a[i+ii][jj+w]]--;
                if(total_mp[a[i+ii][jj+w]]==0){ans--;
                    // cout<<"sakujo"<<a[i+ii][jj+w]<<endl;
                }
            }
            cout<<ans<<" ";
        //     cout<<"---"<<"\n";
        //     for(auto p:total_mp){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        // cout<<"---"<<"\n";

        }

        cout<<endl;

    }

    


    return 0;
}
