/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005;
int status[N], n, m, vis[N], dis[N];
vector < int > factor[N];
vector < int > prime;

void siv() {
        int sq = sqrt(N);
        status[1] = 1;
        for(int i=4; i<=N; i+=2) {
                status[i] = 1;
        }
        for(int i=3; i<=sq; i+=2) {
                if( !status[i] ) {
                        for(int j=i*i; j<=N; j+=i) {
                                status[j] = 1;
                        }
                }
        }
}

int bfs(int s) {
        queue < int > Q;
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        Q.push( s );
        vis[s] = 1;
        dis[s] = 0;
        if( s == m ) {
                return dis[s];
        }
        while( !Q.empty() ) {
                int top = Q.front();
                Q.pop();
                for(int i=0; i<factor[top].size(); i++) {
                        int v = top + factor[top][i];
                        if( factor[top][i] == top ) {
                                continue;
                        }
                        if( !vis[v] ) {
                                vis[v] = 1;
                                dis[v] = dis[top] + 1;
                                if( v == m ) {
                                        return dis[v];
                                }
                                if( v < m ) {
                                        Q.push( v );
                                }
                        }
                }
        }
        return -1;
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        siv();
        for(int i=2; i<=1000; i++) {
                if( !status[i] ) {
                        prime.push_back( i );
                }
        }
        int sz = prime.size();
        //cerr << sz << "\n";

        for(int a=1; a<=1000; a++) {
                int x = a;
                for(int i=0; i<sz; i++) {
                        if( x % prime[i] == 0 ) {
                                factor[a].push_back( prime[i] );
                                while( x % prime[i] == 0 ) {
                                        x /= prime[i];
                                }
                        }
                }
                if( x > 1 ) {
                        factor[a].push_back( x );
                }
        }

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                scanf("%d %d", &n, &m);
                int ans = bfs(n);
                printf("Case %d: %d\n", tc, ans);
        }

        return 0;
}
