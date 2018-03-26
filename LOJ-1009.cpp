
/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20001;

int vis[N], clr[N], a, b;
vector < int > adj[N];

void dfs(int s, int color) {
        vis[s] = 2;
        clr[s] = color;
        color == 0 ? a++ : b++;
        for(int i=0; i<adj[s].size(); i++) {
                int v = adj[s][i];
                if( vis[v] == 1 ) {
                        dfs(v, (color ^ 1));
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
                int n;
                scanf("%d", &n);
                for(int i=1; i<=N; i++) {
                        adj[i].clear();
                        vis[i] = 0;
                        clr[i] = 3;
                }
                for(int i=1; i<=n; i++) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                        vis[u] = 1;
                        vis[v] = 1;
                }
                int ans = 0;
                for(int i=1; i<=N; i++) {
                        if( vis[i] == 1 ) {
                                a = 0, b = 0;
                                dfs(i, 0);
                                ans += max(a, b);
                        }
                }
                printf("Case %d: %d\n", tc, ans);
        }

        return 0;
}
