/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll n, w, half, ara[32];
vector < ll > a, b;

void rec(ll i, ll sum) {
        if( sum > w ) return;
        if( i > half ) {
                if(sum <= w) {
                        a.push_back( sum );
                        return;
                }
                return;
        }
        rec(i+1, sum);
        rec(i+1, sum+ara[i]);
}

void rec1(ll i, ll sum) {
        if( sum > w ) return;
        if( i == n ) {
                if(sum <= w) {
                        b.push_back( sum );
                        return;
                }
                return;
        }
        rec1(i+1, sum);
        rec1(i+1, sum+ara[i]);
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                scanf("%lld %lld", &n, &w);
                for(int i=0; i<n; i++) {
                        scanf("%lld", &ara[i]);
                }
                half = (n - 1) / 2;
                a.clear(), b.clear();
                rec(0, 0);
                rec1(half + 1, 0);
                ll ans = 0LL;
                sort(b.begin(), b.end());
                for(int i=0; i<a.size(); i++) {
                        ll x = w - a[i];
                        ll idx = upper_bound(b.begin(), b.end(), x) - b.begin();
                        ans += idx;
                }
                printf("Case %d: %lld\n", tc, ans);
        }

        return 0;
}
