
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

const int INF = 1000000000;
 
struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), g(n), q(n) {
        e.clear();
        REP(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            REP(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        REP(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            REP(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

const int MN = 111;

int n, m, c[MN][MN], a[MN], b[MN], res[MN][MN];

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> n >> m) {
        int suma = 0, sumb = 0;
        FOR(i,1,n) { cin >> a[i]; suma += a[i]; }
        FOR(i,1,n) { cin >> b[i]; sumb += b[i]; }
        
        memset(c, 0, sizeof c);
        FOR(i,1,n) c[i][i] = 111;
        while (m--) {
            int u, v; cin >> u >> v;
            c[u][v] = c[v][u] = 111;
        }

        if (suma != sumb) {
            cout << "NO" << endl;
            continue;
        }

        MaxFlow flow(n+n+2);
        int start = 0, target = n + n + 1;
        FOR(i,1,n) {
            flow.addEdge(start, i, a[i]);
            flow.addEdge(n+i, target, b[i]);
        }
        FOR(i,1,n) FOR(j,1,n) flow.addEdge(i, n+j, c[i][j]);

        if (flow.getMaxFlow(start, target) == suma) {
            cout << "YES" << endl;
            memset(res, 0, sizeof res);
            FOR(i,1,n) {
                for(int id : flow.g[i]) {
                    auto e = flow.e[id];
                    if (e.a == i && e.b >= n+1 && e.b <= n+n)
                        res[i][e.b - n] = e.flow;
                }
            }
            FOR(i,1,n) FOR(j,1,n) cout << res[i][j] << " \n"[j == n];
        }
        else cout << "NO" << endl;
    }
    return 0;
}
