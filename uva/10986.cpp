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

    void dijkstra(int s) {
        REP(i, SZ(g)) { g[i].v = -1; g[i].d = INF; }
        priority_queue<pii> q; q.push(MP(0,s)); g[s].d = 0;

        while(!q.empty()) {
            int v = q.top().second; q.pop();
            if(g[v].v < 0) {
                g[v].v = 1;
                FOREACH(it, g[v]) {
                    if(g[it->to].v < 0) {
                        g[it->to].d = min(g[it->to].d, g[v].d + it->w);
                        q.push(MP(-g[it->to].d, it->to));
                    }
                }
            }
        }
    }
};

struct VeX { int d; int v;};

struct EdX {
    int w, rev;
    EdX(int w_) : w(w_) {}
};

void algo(int tc) {
    int n,m,s,t; cin >> n >> m >> s >> t;
    Graph<VeX,EdX> g(n);
    while(m--) {
        int a,b,w; cin >> a >> b >> w;
        g.EdgeU(a,b,EdX(w));
    }
    REP(i, SZ(g.g)) g.g[i].d = INF;
    g.dijkstra(s);
    cout << "Case #" << tc << ": " <<
        ((g.g[t].d == INF) ? "unreachable" : to_string(g.g[t].d)) << "\n";
}

int main() {

    int tc; cin >> tc;

    REP(i, tc) algo(i+1);
    return 0;
}
