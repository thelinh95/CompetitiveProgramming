#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <complex>
#include <iostream>
#include <algorithm>

#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

const int MN = 100111;
int n, a[MN];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    cout << (fixed) << setprecision(6);
    while (cin >> n) {
        FOR(i,1,n) cin >> a[i];

        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        sort(a+1, a+n+1);

        int nn = a[1] - a[2], ln = a[1] - a[2];
        FOR(i,1,n-1) {
            int cur = a[i] - a[i+1];
            nn = min(nn, cur);
            ln = max(ln, cur);
        }
        if (ln + ln == nn) swap(nn, ln);

        vector<int> res;
        if (nn == ln) {
            res.push_back(a[1] + nn);
            res.push_back(a[n] - nn);

            if (n == 2) {
                if ((a[1] + a[2]) % 2 == 0)
                    res.push_back((a[1] + a[2]) / 2);
            }
        }
        else if (nn + nn == ln) {
            int cnt = 0;
            FOR(i,1,n-1)
                if (a[i] - a[i+1] != nn) ++cnt;

            if (cnt == 1) {
                FOR(i,1,n-1) if (a[i] - a[i+1] == ln) {
                    res.push_back(a[i] - nn);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        cout << res.size() << endl;
        REP(i,res.size()) cout << res[i] << ' '; cout << endl;
    }
    return 0;
}
