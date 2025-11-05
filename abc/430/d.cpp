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
    int n;
    cin>>n;
    vll x(n);
    rep(i,n)cin>>x[i];

    set<ll> pq;
    vll pp;
    pp.push_back(0);
    pq.insert(0);
    ll ans=0;
    rep(i,n){
        if(i==0){
            pq.insert(x[i]);
            pp.push_back(x[i]);
            ans+=2*x[i];
            continue;
        }
        ll right=pq.size();
        ll left=0;
        while(right-left>1){
            ll mid=(right+left)/2;
            auto it=pq.begin();
            advance(it,mid);
            if(*it<x[i]){
                left=mid;
            }else{
                right=mid;
            }
        }
        // cout<<right<<" "<<x[i]<<endl;
        // printv(pq);
        if(right==pq.size()){
            auto aa=pq.rbegin();
            auto aaa=pq.rbegin();
            aaa--;
            // cout<<"aa:"<<*aa<<endl;
            // cout<<"aaa:"<<*aaa<<endl;
            ll del=*aa-*aaa;
            if(del>x[i]-*aa){
                ans+=2*(x[i]-*aa)-(*aa-*aaa);
            }
            else{
                ans+=x[i]-*aa;
            }

        }
        else if(right==1){
            auto aa=pq.begin();
            auto aaa=pq.begin();
            aaa++;
            // cout<<"aa:"<<*aa<<endl;
            // cout<<"aaa:"<<*aaa<<endl;
            ll del=*aaa-*aa;
            ans-=*aaa-*aa;
            ans+=x[i]-*aa+min(*aaa-x[i], x[i]-*aa);
        }
        else if(right==pq.size()-1){
            auto aa=pq.rbegin();
            auto aaa=pq.rbegin();
            aaa--;
            // cout<<"aa:"<<*aa<<endl;
            // cout<<"aaa:"<<*aaa<<endl;
            ans-=*aaa-*aa;
            ans+=*aa-x[i]+min(*aa-x[i], x[i]-*aaa);


        }
        else{
            int index=lower_bound(ALL(pp),x[i])-pp.begin();
            ans-=pp[index]-pp[index-1];
            ans+=min(x[i]-pp[index-1],pp[index-1]-pp[index-2])-(pp[index-1]-pp[index-2]);
            ans+=min(pp[index+1]-pp[index],pp[index]-x[i])-(pp[index+1]-pp[index]);
        }

        // cout<<*pq.rbegin()<<endl;
        
        pq.insert(x[i]);
        pp.push_back(x[i]);
        sort_heap(ALL(pp));
        cout<<ans<<endl;

    }
    

    return 0;
}
