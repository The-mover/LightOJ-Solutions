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
                ll n;
                scanf("%lld", &n);
                string s = "";
                while( n ) {
                        int rem = n % 2;
                        s += '0' + rem;
                        n /= 2;
                }
                reverse(s.begin(), s.end());
                s = "0" + s;
                next_permutation(s.begin(), s.end());
                ll num = 0;
                for(int i=0; i<s.size(); i++) {
                        num = (num * 2) + (s[i] - '0');
                }
                printf("Case %d: %lld\n", tc, num);
        }

        return 0;
}
