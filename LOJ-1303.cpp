#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;

list<int> store;
list<int> :: iterator it;

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    cin >> t;
    while( t-- ) {
        store.clear();
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            store.push_back(i);
        }
        int vis[22];
        int status[22][22];
        memset(vis, 0, sizeof vis);
        for(int i=0; i<22; i++) {
            for(int j=0; j<22; j++) {
                status[i][j] = 0;
            }
        }
        int cur = 0;
        int z = 0;
        int ans = 0;
        while( z < n * m ) {
            cur++;
            cur = cur % m ? cur % m : m;
            ans++;

            //cerr << "OK " << z << endl;

            if( !vis[cur] ) {
                for(it = store.begin(); it!=store.end(); it++) {
                    int a = *it;
                    if(!status[a][cur]) {
                        status[a][cur] = 1;
                        vis[cur] = a;
                        store.erase(it);
                        //cerr << a << " utheche "<< cur << " e\n";
                        z++;
                        break;
                    }
                }
            }
            else if( vis[cur] ) {
                int b = vis[cur];
                vis[cur] = 0;
                store.push_back(b);
                //cerr << b << " nemeeche "<< cur << " teke\n";
                for(it = store.begin(); it!=store.end(); it++) {
                    int a = *it;
                    if( !status[a][cur] ) {
                        status[a][cur] = 1;
                        vis[cur] = a;
                        store.erase(it);
                        //cerr << a << " utheche "<< cur << " e\n";
                        z++;
                        break;
                    }
                }
            }
        }

        ans += m;
        ans *= 5;

        cout << "Case " << ++k << ": " << ans << "\n";
    }

    return 0;
}
