/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

int n, m, q, cnt;
char grid[502][502];
int vis[502][502], clr[2502];

bool is_ok(int x, int y) {
        if( grid[x][y] == '.' ) return true;
        if( grid[x][y] == 'C' ) return true;
        return false;
}

void bfs(int x, int y, int color) {
        queue < pair < int, int > > Q;
        Q.push(make_pair(x, y));
        vis[x][y] = color;
        if( grid[x][y] == 'C' ) {
                cnt++;
        }
        while( !Q.empty() ) {
                pair < int, int > top = Q.front();
                Q.pop();
                int xx = top.first;
                int yy = top.second;
                for(int i=0; i<4; i++) {
                        int tx = xx + dx[i];
                        int ty = yy + dy[i];
                        if( tx > 0 && ty > 0 && tx <=n && ty <= m && is_ok(tx, ty) == true ) {
                                if( !vis[tx][ty] ) {
                                        vis[tx][ty] = color;
                                        if( grid[tx][ty] == 'C' ) cnt++;
                                        Q.push(make_pair(tx, ty));
                                }
                        }
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
                scanf("%d %d %d", &n, &m, &q);
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                                scanf(" %c", &grid[i][j]);
                        }
                }
                memset(vis, 0, sizeof vis);
                memset(clr, 0, sizeof clr);
                int z = 0;
                vector < int > ve;
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                                if( !vis[i][j] && grid[i][j] == '.' || !vis[i][j] && grid[i][j] == 'C' ) {
                                        cnt = 0;
                                        z++;
                                        bfs(i, j, z);
                                        clr[z] = cnt;
                                }
                        }
                }
                printf("Case %d:\n", tc);
                while( q-- ) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        int vv = vis[x][y];
                        if( vv == 0 ) {
                                printf("%d\n", vv);
                        }
                        else
                                printf("%d\n", clr[vis[x][y]]);
                }
        }

        return 0;
}
