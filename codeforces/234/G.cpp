
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios :: sync_with_stdio(false);
    int n;
    while (cin >> n) {
        int res = 0;
        while ((1<<res) < n) ++res;

        cout << res << endl;
        for(int bit = 0; bit < res; ++bit) {
            int cnt = 0;
            FOR(i,1,n) if ((i >> bit) & 1) ++cnt;
            cout << cnt;
            FOR(i,1,n) if ((i >> bit) & 1) cout << ' ' << i;
            cout << endl;
        }
    }
    return 0;
}
