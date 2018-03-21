/**
        In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;

int Left[N], Right[N], vis[N], ara[N], bra[N], n, m;
vector < int > adj[N];

bool BPM(int u) {
        for(int i=0; i<adj[u].size(); i++) {
                int v = adj[u][i];
                if(vis[v]) continue;
                vis[v] = 1;
                if( Right[v] == -1 || BPM(Right[v]) ) {
                        Right[v] = u;
                        Left[u] = v;
                        return true;
                }
        }
        return false;
}

int max_BPM() {
        memset(Left, -1, sizeof Left);
        memset(Right, -1, sizeof Right);
        int cnt = 0;
        for(int i=0; i<n; i++) {
                memset(vis, 0, sizeof vis);
                if( BPM(i) ) {
                        cnt++;
                }
        }
        return cnt;
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                scanf("%d", &n);
                for(int i=0; i<n; i++) {
                        scanf("%d", &ara[i]);
                        adj[i].clear();
                }
                scanf("%d", &m);
                for(int i=0; i<m; i++) {
                        scanf("%d", &bra[i]);
                }

                for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                                if(bra[j] % ara[i] == 0) {
                                        adj[i].push_back(j);
                                }
                        }
                }
                int ans = max_BPM();
                printf("Case %d: %d\n",tc, ans);
        }


        return 0;
}
