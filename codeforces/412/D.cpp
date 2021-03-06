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
#define SZ(S) ((int) ((S).size()))

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int n, m;
set<int> ke[30111];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    cout << (fixed) << setprecision(6);
    while (cin >> n >> m) {
        FOR(i,1,n) ke[i].clear();
        FOR(i,1,m) {
            int u, v; cin >> u >> v;
            ke[u].insert(v);
        }

        vector<int> res; res.push_back(1);
        FOR(i,2,n) {
            res.push_back(i);
            int u = res.size() - 1;
            while (u > 0 && ke[res[u-1]].find(res[u]) != ke[res[u-1]].end()) {
                swap(res[u], res[u-1]);
                --u;
            }
        }
        REP(i,res.size()) cout << res[i] << ' '; cout << endl;
    }
    return 0;
}
