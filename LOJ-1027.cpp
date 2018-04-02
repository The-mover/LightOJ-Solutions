/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int ara[N];

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                int n;
                scanf("%d", &n);
                int sum = 0, p = 0;
                for(int i=1; i<=n; i++) {
                        scanf("%d", &ara[i]);
                        sum += abs(ara[i]);
                        p += ara[i] > 0;
                }
                if( !p ) {
                        printf("Case %d: inf\n", tc);
                }
                else {
                        int g = __gcd(sum, p);
                        int a = sum / g;
                        int b = p / g;
                        printf("Case %d: %d/%d\n", tc, a, b);
                }
        }

        return 0;
}
