#include<bits/stdc++.h>
using namespace std;
//この問題で扱う整数は最大4×10^12であり、int型の上限を超えるため、long longを用いる。
//実装の簡略化のためlong longをllとして使えるようにする。（以下、llという型はlong long型と同じ）
using ll = long long;
//コピペする場合はここから～
//Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector < bool > isprime;
//返り値は素数のリスト。
vector < ll > Era(int n) {
	isprime.resize(n, true);
	vector < ll > res;
	isprime[0] = false;
	isprime[1] = false;
	for(ll i = 2; i < n; ++i) isprime[i] = true;
	for(ll i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(ll j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}

//以下は素因数分解
template<typename T>
vector<pair<T, T>> FACTORIZATION(T x) {
    vector<pair<T, int>> ans;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            T count = 0;
            while (x % i == 0) {
                count++;
                x /= i;
            }
            ans.push_back(make_pair(i, count));
        }
    }
    if (x != 1) ans.push_back(make_pair(x, 1));
    return ans;
}
