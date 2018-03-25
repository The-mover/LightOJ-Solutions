/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
        return (a * b) / __gcd(a, b);
}

ll getans(ll g, ll n) {
        vector < ll > ve;
        for(ll i=1; i * i <= n; i++) {
                if( n % i == 0 ) {
                        ve.push_back(n / i);
                        if( lcm(g, i) == n ) return i;
                }
        }
        for(int i=ve.size()-1; i>=0; i--) {
                if( lcm(g, ve[i]) == n ) return ve[i];
        }
        return -1;
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                ll a, b, l;
                scanf("%lld %lld %lld", &a, &b, &l);
                ll g = lcm(a, b);
                printf("Case %d: ", tc);
                if( g > l ) {
                        puts("impossible");
                }
                else {
                        ll ans = getans(g, l);
                        if( ans == -1 ) {
                                printf("impossible\n");
                        } else
                                printf("%lld\n", ans);
                }
        }

        return 0;
}
