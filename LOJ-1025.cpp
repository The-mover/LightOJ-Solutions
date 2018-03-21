/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;

const int N = 62;

ll dp[N][N];
char s[62];

ll rec(int i, int j) {
        if(i > j) {
                return 0;
        }
        if( i == j ) {
                return 1;
        }
        if( dp[i][j] != -1 ) {
                return dp[i][j];
        }
        dp[i][j] = 0;
        if( s[i] == s[j] ) {
                dp[i][j] = 1 + rec(i+1, j-1);
        }

        dp[i][j] += rec(i+1, j) + rec(i, j-1) - rec(i+1, j-1);

        return dp[i][j];
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t, k = 0;
        scanf("%d", &t);
        while( t-- ) {
                memset(dp, -1, sizeof dp);
                scanf("%s", &s);
                int m = strlen(s);
                ll ans = rec(0, m - 1);
                printf("Case %d: %lld\n", ++k, ans);
        }

        return 0;
}
