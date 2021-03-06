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

//Buffer reading
int INP,AM,REACHEOF;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        if (REACHEOF) return 0;\
        memset(BUF,0,sizeof BUF);\
        int inpzzz = fread(BUF,1,BUFSIZE,stdin);\
        if (inpzzz != BUFSIZE) REACHEOF = true;\
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading

const long double PI = acos((long double) -1.0);

int n, q;
char a[111];
char b[111];
int cnt[11];

int main() {
    while (scanf("%d%d\n", &n, &q) == 2) {
        gets(a);
        while (q--) {
            int l, r; scanf("%d%d", &l, &r);
            FOR(i,l,r) b[i] = a[i-1];

            int CP = l, DP = 1;
            memset(cnt, 0, sizeof cnt);
            while (CP >= l && CP <= r) {
                if (b[CP] >= '0' && b[CP] <= '9') {
                    ++cnt[b[CP]-'0'];
                    --b[CP];
                    CP += DP;
                    while (b[CP] == '0' - 1) CP += DP;
                }
                else if (b[CP] == '<' || b[CP] == '>') {
                    if (b[CP] == '<') DP = -1; else DP = 1;
                    int old = CP;
                    
                    CP += DP;
                    while (b[CP] == '0' - 1) CP += DP;
                    if (b[CP] == '<' || b[CP] == '>')
                        b[old] = '0' - 1;
                }
            }
            REP(i,10) printf("%d ", cnt[i]); puts("");
        }
    }
    return 0;
}
