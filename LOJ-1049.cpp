/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

vector < pair < int, int > > adj[102];

int dfs(int s, int par = 1) {
        if( s == 1 ) return 0;
        for(int i=0; i<adj[s].size(); i++) {
                int v = adj[s][i].first;
                if( v != par ) {
                        return adj[s][i].second + dfs(v, s);
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
                for(int i=1; i<=100; i++) {
                        adj[i].clear();
                }
                int n;
                scanf("%d", &n);
                for(int i=1; i<=n; i++) {
                        int u, v, c;
                        scanf("%d %d %d", &u, &v, &c);
                        adj[u].push_back({v, 0});
                        adj[v].push_back({u, c});
                }
                int ans1 = dfs(adj[1][0].first) + adj[1][0].second;
                int ans2 = dfs(adj[1][1].first) + adj[1][1].second;
                printf("Case %d: %d\n", tc, min(ans1, ans2));
        }

        return 0;
}
