//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10081 - Tight Words
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 111

int n, k;
double f[maxN][11];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    while (scanf("%d %d", &k, &n) != EOF) {
        double ff = 1.0;
        rep(i, n) ff /= (double)(k + 1);
        fr(j, 0, k) f[0][j] = ff;
        fr(i, 1, n - 1) fr(j, 0, k) {
            f[i][j] = f[i - 1][j];
            if (j + 1 <= k) f[i][j] += f[i - 1][j + 1];
            if (j - 1 >= 0) f[i][j] += f[i - 1][j - 1];
        }
        double res = 0;
        fr(j, 0, k) res += f[n - 1][j];
        //rep(i, n) res /= (k + 1);
        printf("%.5lf\n", res * 100.0);
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
