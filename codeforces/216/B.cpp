#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;
using namespace std;

const double PI = acos(-1.0);

vector<int> ke[111];
bool mark[111];
int qu[111], first, last, n, m;

int bfs(int u) {
    first = last = 1;
    qu[1] = u;
    mark[u] = true;
    while (first <= last) {
        int u = qu[first++];
        REP(i,ke[u].size()) {
            int v = ke[u][i];
            if (mark[v]) continue;

            mark[v] = true;
            qu[++last] = v;
        }
    }

    FOR(i,1,last) if (ke[qu[i]].size() != 2) return 0;
    return last % 2;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        FOR(i,1,n) ke[i].clear();
        memset(mark, false, sizeof mark);

        FOR(i,1,m) {
            int u, v; scanf("%d%d", &u, &v);
            ke[u].PB(v); ke[v].PB(u);
        }

        int res = 0;
        FOR(i,1,n) if (!mark[i]) {
            if (ke[i].size() == 0) {
                mark[i] = true;
                continue;
            }
            res += bfs(i);
        }
        n -= res;
        if (n % 2 == 1) ++res;
        printf("%d\n", res);
    }
    return 0;
}