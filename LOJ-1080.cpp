/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct data {
        int sum;
        int prop;
        data() {
                sum = 0;
                prop = 0;
        }
};

char s[N];
int ara[N];
data tree[N * 3];

void init(int node, int b, int e) {
        if( b == e ) {
                tree[node].sum = ara[b];
                return;
        }
        int left = node * 2;
        int right = (node * 2) + 1;
        int mid = ( b + e ) / 2;
        init(left, b, mid);
        init(right, mid+1, e);
        tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, int x) {
        if( i > e || j < b ) {
                return;
        }
        if( b >= i && e <= j ) {
                tree[node].sum += ((e - b + 1) * x);
                tree[node].prop += x;
                return;
        }
        int left = node * 2;
        int right = (node * 2) + 1;
        int mid = ( b + e ) / 2;
        update(left, b, mid, i, j, x);
        update(right, mid+1, e, i, j, x);
        tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry) {
        if( i > e || j < b ) {
                return 0;
        }
        if( b >= i && e <= j ) {
                return tree[node].sum + carry * (e - b + 1);
        }
        int left = node * 2;
        int right = (node * 2) + 1;
        int mid = (b + e) / 2;
        int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
        int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);
        return p1 + p2;
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        scanf("%d", &t);
        for(int tc=1; tc<=t; tc++) {
                memset(tree, 0, sizeof tree);
                memset(ara, 0, sizeof ara);

                scanf("%s", s);
                int n = strlen( s );
                for(int i=0; i<n; i++) {
                        if( s[i] == '1' ) {
                                ara[i+1] = 1;
                        }
                        else {
                                ara[i+1] = 0;
                        }
                }
                init(1, 1, n);
                int q;
                scanf("%d", &q);
                printf("Case %d:\n", tc);
                for(int i=1; i<=q; i++) {
                        char ch;
                        scanf(" %c", &ch);
                        if( ch == 'I' ) {
                                int l, r;
                                scanf("%d %d", &l, &r);
                                update(1, 1, n, l, r, 1);
                        }
                        else {
                                int id;
                                scanf("%d", &id);
                                int ans = query(1, 1, n, id, id, 0);
                                printf("%d\n", ans % 2);
                        }
                }
        }

        return 0;
}
