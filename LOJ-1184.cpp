/**
        In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;

struct data {
        int age, height, status;
        data() {
                age = height = status = 0;
        }
};

data ara[N], bra[N];

int Left[N], Right[N], vis[N], n, m;
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
                scanf("%d %d", &n, &m);
                for(int i=0; i<n; i++) {
                        int x, y, z;
                        scanf("%d %d %d", &x, &y, &z);
                        ara[i].height = x;
                        ara[i].age = y;
                        ara[i].status = z;
                        adj[i].clear();
                        //cerr << ara[i].age << " " << ara[i].height << " " << ara[i].status << "\n";
                }
                for(int i=0; i<m; i++) {
                        int x, y, z;
                        scanf("%d %d %d", &x, &y, &z);
                        bra[i].height = x;
                        bra[i].age = y;
                        bra[i].status = z;
                        //cerr << bra[i].age << " " << bra[i].height << " " << bra[i].status << "\n";

                }
                for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                                int agap = abs(ara[i].age - bra[j].age);
                                int hgap = abs(ara[i].height - bra[j].height);
                                int sgap = ara[i].status ^ bra[j].status;
                                //cerr << agap << " " << hgap << " " << sgap << "\n";

                                if( agap <= 5 && hgap <= 12 && sgap == 0 ) {
                                        adj[i].push_back(j);
                                }
                        }
                }
                int ans = max_BPM();
                printf("Case %d: %d\n", tc, ans);

                cerr << "----------------\n";
        }

        return 0;
}
