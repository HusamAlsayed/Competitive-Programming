﻿#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using  namespace std;
#define ll long long
const ll N = 200000 + 10, Max = 2, MOD = 98765431;
const ll OO = 1e18 + 5000;
const ll Sqrt = 710;
const double EPS = 1e-9;
struct Matrix {
	// remmember to make the grid as you wan't  ..
	// remmember to set a MOD like you wan't .. 
	ll X[Max][Max];

	Matrix() {}

	void clear() {
		memset(X, 0, sizeof X);
	}
	void init() {
		clear();
		for (int i = 0; i < Max; ++i) {
			X[i][i] = 1;
		}
	}
	Matrix operator + (const Matrix &rhs) const {
		Matrix ans;
		ans.clear();
		for (int i = 0; i < Max; ++i)
			for (int j = 0; j <  Max; j++) {
				ans.X[i][j] = X[i][j] + rhs.X[i][j];
				ans.X[i][j] %= MOD;
			}
		return ans;
	}
	Matrix operator * (const Matrix &rhs) const {
		Matrix ans;
		ans.clear();
		for (int i = 0; i < Max; ++i)
			for (int j = 0; j <  Max; j++)
				for (int k = 0; k <  Max; k++) {
					ans.X[i][k] = (ll)((ans.X[i][k] + (ll)X[i][j] * rhs.X[j][k]));
					ans.X[i][k] %= MOD;
				}
		return ans;
	}
};
Matrix matPow(Matrix A, ll p) {
	Matrix res;
	if (p == 0) {
		res.init();
		return res;
	}
	if (p == 1) {
		return A;
	}
	res = matPow(A, p / 2);
	if (p & 1) return res * res * A;
	return res * res;
}
ll a[N];
int main() {
	// dp[i] = we need the Sum of The Other .. 

	// So we can Make 2 By 2 the first is the Value Of Me and the second is The value of The Other .. 

	// 1 0 4 .. 
	// so Initialy we Have 1 and 4 .. 

	// the next Time we will have 4 and 6 

	// the next time we will have 6 and 14 
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		Matrix Base;
		Base.clear();
		Base.X[0][0] = a[i];
		Base.X[0][1] = (sum - a[i])%MOD;
		Matrix trans;
		trans.clear();
		trans.X[0][0] = 0;
		trans.X[0][1] = (n - 1);
		trans.X[1][0] = 1;
		trans.X[1][1] = (n - 2);
		Matrix ans = Base*matPow(trans, m - 1);
		cout << ans.X[0][1] << endl;
	}
}