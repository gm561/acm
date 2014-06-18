#include <set>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
#include <bitset>
#include <numeric>
#include <sstream>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

#define FOR(i, s, e) for(int i = (s); i <= (e); ++i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define MP(x,y) make_pair(x,y)
#define ALL(x) (x).begin(), (x).end()
#define FT first
#define ST second
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB(x) push_back((x))
#define SZ(x) (int)x.size()
#define LN(x) (int)(x).length()
const int INF = 1000000001;

template<class VeX, class EdX> struct Graph {

    struct Ed : EdX {
        int to;
        Ed(EdX edx, int to_) : EdX(edx), to(to_) {}
    };

    struct Ve : VeX, vector<Ed> {};
    vector<Ve> g;

    Graph(int n = 0) : g(n) {}

    void EdgeD(int from, int to, EdX edx = EdX()) {
        Ed ed(edx, to); g[from].PB(ed);
    }

    void EdgeU(int from, int to, EdX edx = EdX()) {
        Ed ed0(edx, to);
        ed0.rev = SZ(g[to]) + (from == to);
        g[from].PB(ed0);

        Ed ed1(edx, from);
        ed1.rev = SZ(g[from]) - 1;
        g[to].PB(ed1);
    }

    void dfs0(int v) {
        if(g[v].s > 0) return;
        g[v].s = 1;
        FOREACH(it, g[v]) dfs0(it->to);
        g[v].f = dfst++;
        g[v].c = comp;
    }

    int dfst;
    void dfs(int s = -1) {
        if(s < 0) {
            REP(i, SZ(g)) if(g[i].s < 0) dfs0(i);
        }
        else dfs0(s);
    }

    int comp;
    int scc() {
        Graph<VeX, EdX> gT(SZ(g));
        REP(i, SZ(g)) FOREACH(it, g[i]) gT.EdgeD(it->to, i);

        REP(i, SZ(g)) g[i].s = g[i].f = g[i].c = -1;
        dfst = 0;
        dfs();

        VI ves(SZ(g), -1);
        REP(i, SZ(g)) ves[g[i].f] = i;

        gT.comp = 0;
        REP(i, SZ(gT.g)) gT.g[i].s = gT.g[i].f = gT.g[i].c = -1;
        REP(i, SZ(ves)) {
            if(gT.g[ves[SZ(ves) - i - 1]].s < 0) {
                gT.dfs(ves[SZ(ves) - i - 1]);
                ++gT.comp;
            }
        }

        REP(i, SZ(gT.g)) g[i].c = gT.g[i].c;
        return gT.comp;
    }

    int solve() {
        int nc = scc();
        Graph<VeX, EdX> gc(nc);
        REP(i, SZ(g)) FOREACH(it, g[i]) {
            if(g[i].c != g[it->to].c) {
                gc.EdgeD(g[i].c, g[it->to].c);
            }
        }

        VI vts = gc.topoSort();
        int t = 0;
        REP(i, SZ(gc.g)) gc.g[i].s = gc.g[i].f = gc.g[i].c = -1;
        REP(i, SZ(gc.g)) if(gc.g[vts[i]].s < 0) {
            ++t; gc.dfs(vts[i]);
        }

        return t;
    }

    VI topoSort() {
        VI inDeg(SZ(g), 0);
        REP(i, SZ(g)) FOREACH(it, g[i]) {
            ++inDeg[it->to];
        }
        VI q; VI ans;

        REP(i, SZ(inDeg)) if(!inDeg[i]) q.PB(i);
        for(int i = 0; i < SZ(q); ++i) {
            ans.PB(q[i]);
            FOREACH(it, g[q[i]]) {
                --inDeg[it->to];
                if(!inDeg[it->to]) q.PB(it->to);
            }
        }
        return ans;
    }

};

struct VeX { int s, f, c; };

struct EdX {};

void algo() {
    int n,m; cin >> n >> m;
    Graph<VeX,EdX> g(n);
    while(m--) {
        int a,b; cin >> a >> b;
        g.EdgeD(--a, --b);
    }

    cout << g.solve() << "\n";
}

int main() {
    int tc; cin >> tc;
    while(tc--) algo();
    return 0;
}
