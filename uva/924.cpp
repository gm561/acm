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

    void bfs(int s) {
        VI q; q.PB(s); g[s].d = 0;

        for(size_t i = 0; i < q.size(); ++i) {
            FOREACH(it, g[q[i]]) if(g[it->to].d == INF) {
                g[it->to].d = g[q[i]].d + 1;
                q.PB(it->to);
            }
        }
    }
};

struct VeX { int d; };

struct EdX {
    int i, rev;
};

void algo() {
    int n; cin >> n;
    Graph<VeX,EdX> g(n);
    REP(i, n) {
        int m; cin >> m;
        while(m--) {
            int x; cin >> x;
            g.EdgeD(i, x);
        }
    }

    int tc; cin >> tc;
    while(tc--) {
        int v; cin >> v;
        REP(i, SZ(g.g)) g.g[i].d = INF;
        g.bfs(v);
        VI ds(n, 0);
        REP(i, n) if(g.g[i].d < INF) {
            ++ds[g.g[i].d];
        }

        int im = 0;
        ds[0] = 0;
        REP(i, SZ(ds)) if(ds[im] < ds[i]) im = i;

        if(!im) cout << im << "\n";
        else cout << ds[im] << " " << im << "\n";
    }

}

int main() {
    algo();
    return 0;
}
