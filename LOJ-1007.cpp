/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e6 + 10;
const int M = 5e6 + 2;

int mark[N];
ull phi[N];

void sievephi() {
        for(int i=2; i<=5000002; i++) {
                phi[i] = i;
        }
        for(int i=2; i<=5000002; i++) {
                if(!mark[i]) {
                        for(int j=i; j<=5000002; j+=i) {
                                mark[j] = 1;
                                phi[j] = phi[j]/i * (i-1);
                        }
                }
        }
        for(ll i=3; i<5000002; i++) {
                phi[i] *= phi[i];
                phi[i] += phi[i-1];
        }
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        sievephi();
        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                ll a, b;
                scanf("%llu %llu", &a, &b);
                ll ans = phi[b] - phi[a-1];
                printf("Case %d: %llu\n", tc, ans);
        }

        return 0;
}
