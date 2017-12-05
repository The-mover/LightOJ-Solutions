/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;

const int N = 102;

ll dp[N][N], ara[N], n, w, k;

ll rec(ll i, ll lagbe) {
    if( lagbe == 0 ) {
        return 0LL;
    }
    if( i == n + 1 ) {
        return 0LL;
    }
    if( dp[i][lagbe] != -1 ) {
        return dp[i][lagbe];
    }
    int a = upper_bound(ara, ara+n, ara[i] + w) - ara;
    a = a ? a : a - 1;
    ll x = (a - i) + rec(a, lagbe - 1);
    ll z =  rec(i + 1, lagbe);
    return dp[i][lagbe] = max(x, z);
}

int main()
{
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
        freopen("ou.txt", "w", stdout);
    #endif /// _OFFLINE_

    int t, tc = 0;
    scanf("%d", &t);
    while( t-- ) {
        memset(dp, -1, sizeof dp);
        scanf("%lld %lld %lld", &n, &w, &k);
        for(int i=0; i<n; i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            ara[i] = y;
        }
        sort(ara, ara+n);
        ll ans = rec(0, k);
        printf("Case %d: %lld\n", ++tc, ans);
    }
    return 0;
}
