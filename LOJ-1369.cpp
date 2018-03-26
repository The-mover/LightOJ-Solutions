/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

ll ara[N];
ll s[N];

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                ll n, q;
                scanf("%lld %lld", &n, &q);
                for(int i=1; i<=n; i++) {
                        scanf("%lld", &ara[i]);
                        s[i] = 0;
                }
                for(int i=1; i<=n; i++) {
                        s[i] = s[i-1] + ara[i];
                }
                printf("Case %d:\n", tc);
                ll sum = 0;
                for(int i=1; i<n; i++) {
                        ll val = n - i;
                        val = val * ara[i];
                        sum += val - (s[n] - s[i]);
                }
                //cerr << sum << "\n";
                while( q-- ) {
                        int type;
                        scanf("%d", &type);
                        if( type == 1 ) {
                                printf("%lld\n", sum);
                        }
                        else {
                                ll id, val;
                                scanf("%lld %lld", &id, &val);
                                id++;
                                ll change = ara[id] - val;
                                change = change * (id-1);
                                sum += change;
                                sum -= (n - id) * ara[id];
                                ara[id] = val;
                                //update(1, 1, n, id, val);
                                sum += (n - id) * ara[id];
                        }
                }
        }

        return 0;
}
