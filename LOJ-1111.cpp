/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 2;

vector < int > adj[N];
int vis[N], cnt[N], ara[102];

void dfs(int s, int color) {
        vis[s] = color;
        cnt[s] += 1;
        for(int i=0; i<adj[s].size(); i++) {
                int v = adj[s][i];
                if( vis[v] != color ) {
                        dfs(v, color);
                }
        }
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                int k, n, m;
                scanf("%d %d %d", &k, &n, &m);
                for(int i=1; i<=k; i++) {
                        scanf("%d", &ara[i]);
                }
                for(int i=1; i<=n; i++) {
                        adj[i].clear();
                        cnt[i] = 0;
                        vis[i] = 0;
                }
                for(int i=1; i<=m; i++) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        adj[u].push_back(v);
                }
                for(int i=1; i<=k; i++) {
                        dfs(ara[i], i);
                }
                int ans = 0;
                for(int i=1; i<=n; i++) {
                        if( cnt[i] == k ) {
                                ans++;
                        }
                }
                printf("Case %d: %d\n", tc, ans);

        }

        return 0;
}
