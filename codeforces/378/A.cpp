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
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    int a, b;
    while (cin >> a >> b) {
        int win = 0, draw = 0, lose = 0;
        FOR(i,1,6) {
            int da = abs(a - i), db = abs(b - i);
            if (da < db) ++win;
            else if (da == db) ++draw;
            else ++lose;
        }
        cout << win << ' ' << draw << ' ' << lose << endl;
    }
    return 0;
}
