#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}

vector<long long> fac, finv, inv;

// テーブルを作る前処理
//fac:階乗, finv:階乗の逆元, inv:逆元
//MOD:法, MAX:テーブルの大きさ
void COMinit(vector<long long> &fac,vector<long long> &finv,vector<long long> &inv,long long MOD,long long MAX) {
    // const int MOD = mint::mod();
    // long long MAX=fac.size();
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
// nCk mod を計算する
// fac:階乗, finv:階乗の逆元, n: n, k: k, MOD:法
long long COM(vector<long long> fac,vector<long long> finv,long long n, long long k,long long MOD){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	// mod. 13 での逆元を求めてみる
	for (int i = 1; i < 13; ++i) {
		cout << i << " 's inv: " << modinv(i, 13) << endl;
	}
}
