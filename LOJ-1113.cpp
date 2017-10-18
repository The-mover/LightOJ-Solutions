#include <bits/stdc++.h>
using namespace std;

stack< string > FORWARD, BACKWARD;

int main() {
    #ifdef _OFFLINE_
        freopen("LOJ.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t, k = 0;
    cin >> t;
    while( t-- ) {
        string s;
        string cur = "http://www.lightoj.com/";

        cout << "Case " << ++k << ":\n";

        while( cin >> s ) {
            if( s == "QUIT") {
                break;
            }
            else if( s == "VISIT") {
                string url;
                cin >> url;
                BACKWARD.push(cur);
                cur = url;
                cout << cur << "\n";
                while (!FORWARD.empty())
                {
                    FORWARD.pop();
                }
            }
            else if( s == "BACK") {
                if( BACKWARD.empty() ) {
                    cout << "Ignored\n";
                }
                else {
                    FORWARD.push(cur);
                    cur = BACKWARD.top();
                    BACKWARD.pop();
                    cout << cur << "\n";
                }
            }
            if( s == "FORWARD") {
                if( FORWARD.empty() ) {
                    cout << "Ignored\n";
                }
                else {
                    BACKWARD.push(cur);
                    cur = FORWARD.top();
                    FORWARD.pop();
                    cout << cur << "\n";
                }
            }
        }

        while (!FORWARD.empty()) {
            FORWARD.pop();
        }
        while (!BACKWARD.empty()) {
            BACKWARD.pop();
        }


    }
    return 0;

}

