/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
set < ll > st;
ll L, P;

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                st.clear();
                scanf("%lld %lld", &P, &L);
                printf("Case %d:", tc);
                ll n = P - L;
                if( n <= L ) {
                        printf(" impossible\n");
                        continue;
                }
                for(ll i=1; i * i <= n; i++) {
                        if( n % i == 0 ) {
                                st.insert(i);
                                st.insert(n / i);
                        }
                }
                for(set< ll > :: iterator it = st.begin(); it != st.end(); it++ ) {
                        ll a = *it;
                        if( a > L ) {
                                printf(" %lld", a);
                        }
                }

                printf("\n");

        }

        return 0;
}
