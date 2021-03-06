
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%I64d", &x);
}

const int MN = 100111;
int n, h[MN], a[MN];
int good;
vector< pair<int,int> > ke[MN];

void dfs(int u, int bound) {
    if (h[u] - a[u] > bound) return ;
    ++good;

    for(auto e : ke[u]) {
        int v = e.first;
        h[v] = h[u] + e.second;

        dfs(v, min(bound, h[u]));
    }
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (GI(n) == 1) {
        FOR(i,1,n) GI(a[i]);
        FOR(i,1,n) ke[i].clear();
        FOR(i,2,n) {
            int fi; GI(fi);
            int c; GI(c);

            ke[fi].push_back(make_pair(i, c));
        }
        good = 0;
        dfs(1, 1000111000111000LL);
        cout << n - good << endl;
    }
}
