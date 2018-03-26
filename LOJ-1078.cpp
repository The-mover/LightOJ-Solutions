/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                int n, m;
                scanf("%d %d", &n, &m);
                int ans = 1;
                int temp = m % n;
                while( temp ) {
                        temp = (temp * 10) + m;
                        if( temp >= n ) {
                                temp %= n;
                        }
                        ans++;
                }
                printf("Case %d: %d\n", tc, ans);
        }

        return 0;
}
