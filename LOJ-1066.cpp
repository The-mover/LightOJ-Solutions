
/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct data {
        int x, y;
};

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

data idx[27];
int vis[11][11], dis[11][11], n;
char ara[11][11];


bool is_ok(int x, int y, int x1, int y1) {
        if( ara[x][y] == '.' ) return true;
        if( x == x1 && y == y1 ) return true;
        return false;
}

void bfs(int x, int y, int x1, int y1) {
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        queue < pair < int, int > > Q;
        vis[x][y] = 1;
        dis[x][y] = 0;
        Q.push({x, y});
        while( !Q.empty() ) {
                int xx = Q.front().first;
                int yy = Q.front().second;
                Q.pop();
                for(int i=0; i<4; i++) {
                        int tx = xx + dx[i];
                        int ty = yy + dy[i];
                        if( tx > 0 && ty > 0 && tx <=n && ty <= n && is_ok(tx, ty, x1, y1) == true ) {
                                if( !vis[tx][ty] ) {
                                        dis[tx][ty] = dis[xx][yy] + 1;
                                        vis[tx][ty] = 1;
                                        Q.push({tx, ty});
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
                for(int i=0; i<=26; i++) {
                        idx[i].x = 0;
                        idx[i].y = 0;
                }
                scanf("%d", &n);
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=n; j++) {
                                scanf(" %c", &ara[i][j]);
                                if( ara[i][j] >= 'A' && ara[i][j] <= 'Z' ) {
                                        int v = (ara[i][j] - 'A') + 1;
                                        idx[v].x = i;
                                        idx[v].y = j;
                                }
                        }
                }
                vector < data > ve;
                for(int i=1; i<=26; i++) {
                        if( idx[i].x ) {
                                data get;
                                get.x = idx[i].x;
                                get.y = idx[i].y;
                                ve.push_back( get );
                        }
                }
                int ans = 0, f = 0;
                for(int i=1; i<ve.size(); i++) {
                        int xx = ve[i-1].x;
                        int yy = ve[i-1].y;
                        ara[xx][yy] = '.';
                        int xx1 = ve[i].x;
                        int yy1 = ve[i].y;
                        bfs( xx, yy, xx1, yy1 );
                        int res = dis[xx1][yy1];
                        if( res == 0 ) f = 1;
                        ans += dis[xx1][yy1];
                }
                if( f ) {
                        printf("Case %d: Impossible\n", tc);
                } else
                        printf("Case %d: %d\n", tc, ans);
        }

        return 0;
}
