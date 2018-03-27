/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int ara[55];

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                int n;
                scanf("%d", &n);
                vector < int > cnt (N, 0);
                for(int i=0; i<n; i++) {
                        scanf("%d", &ara[i]);
                }
                int ans = 0;
                for(int i=0; i<n; i++) {
                        cnt[ara[i]]++;
                        if( ara[i] + 1 == cnt[ara[i]] ) {
                                ans += ara[i] + 1;
                                cnt[ara[i]] = 0;
                        }
                }
                for(int i=0; i<N; i++) {
                        if( cnt[i] ) {
                                ans += i + 1;
                        }
                }
                printf("Case %d: %d\n", tc, ans);
        }

        return 0;
}
