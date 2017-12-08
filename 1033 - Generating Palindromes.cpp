#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;
const int M = 1e9 + 7;

string s, t;
int n;
int dp[N][N];

int rec(int i, int j) {
    if( i == n || j == n ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    int ret = 0;
    if( s[i] == t[j] ) ret = 1 + rec(i+1, j+1);
    else {
        int a = rec(i+1, j);
        int b = rec(i, j+1);
        ret = max(a, b);
    }
    return dp[i][j] = ret;
}


int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int tc, k = 0;
    scanf("%d", &tc);
    while( tc-- ) {
        memset(dp, -1, sizeof dp);
        cin >> s;
        t = s;
        reverse(t.begin(), t.end());
        n = s.size();
        int ans = rec(0, 0);
        printf("Case %d: %d\n", ++k, n - ans);
    }

    return 0;
}
