
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

int GI(int& x) {
    return scanf("%lld", &x);
}

const int MN = 300111;
int f[MN];

map<int,int> cached;
int get(int n) {
    if (n < MN) return f[n];
    if (cached.count(n)) return cached[n];

    int res = n / 2 + 1;
    for(int i = 2; i*i <= n; i++) if (n % i == 0) {
        int group = i, each = n/i;
        res = min(res, (group / 2 + 1) * get(each));

        group = n/i, each = i;
        res = min(res, (group / 2 + 1) * get(each));
    }
    return cached[n] = res;
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);

    FOR(i,1,MN-1) {
        f[i] = i / 2 + 1;
        for(int j = 1; j*j <= i; ++j) if (i % j == 0) {
            int group = j, each = i/j;
            f[i] = min(f[i], (group / 2 + 1) * f[each]);

            group = i/j, each = j;
            f[i] = min(f[i], (group / 2 + 1) * f[each]);
        }
    }

    int n;
    while (cin >> n) {
        cout << get(n) << endl;
    }
}
