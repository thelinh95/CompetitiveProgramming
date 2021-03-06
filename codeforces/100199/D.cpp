
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

const int MN = 10111;

int deg[MN], n;

int main() {
    ios :: sync_with_stdio(false);
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    int m;
    while (cin >> n >> m) {
        memset(deg, 0, sizeof deg);
        while (m--) {
            int u, v; cin >> u >> v;
            ++deg[u];
            ++deg[v];
        }
        ll res = 0;
        FOR(i,1,n) res += deg[i] * (ll) deg[i];
        cout << res << endl;
    }
}
