#include<bits/stdc++.h>
using namespace std;

deque <int > store;

int main() {
    #ifdef _OFFLINE_
        freopen("LOJ.txt", "r", stdin);
    #endif // _OFFLINE_

    int t, k = 0;
    cin >> t;
    while( t-- ) {
        int n, m;
        store.clear();
        cin >> n >> m;
        cout << "Case " << ++k << ":\n";
        for(int i=1; i<=m; i++) {
            string s;
            cin >> s;
            if( s == "pushLeft") {
                int x;
                cin >> x;
                if( store.size() < n ) {
                    store.push_front(x);
                    cout << "Pushed in left: " << x << "\n";
                }
                else {
                    cout << "The queue is full\n";
                }
            }
            else if( s == "pushRight") {
                int x;
                cin >> x;
                if( store.size() < n ) {
                    store.push_back(x);
                    cout << "Pushed in right: " << x << "\n";
                }
                else {
                    cout << "The queue is full\n";
                }
            }
            else if( s == "popLeft") {
                if( store.size() == 0 ) {
                    cout << "The queue is empty\n";
                }
                else {
                    int x = store.front();
                    store.pop_front();
                    cout << "Popped from left: " << x << "\n";

                }
            }
            else if( s == "popRight") {
                if( store.size() == 0 ) {
                    cout << "The queue is empty\n";
                }
                else {
                    int x = store.back();
                    store.pop_back();
                    cout << "Popped from right: " << x << "\n";
                }
            }
        }
    }

    return 0;
}
