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
typedef pair<double, double> pdd;
typedef pair<double, pii> pdpi;

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

    typedef typename vector<Ed>::iterator dit;
    typedef  pair<int, dit> piit;
    int mstPrima(int s) {
        int cost = 0;
        priority_queue<piit> q;
        vector<Ed> dummy; dummy.PB(Ed(EdX(0), s));
        dummy.begin()->sp = 1;
        q.push(MP(0, dummy.begin()));
        while(!q.empty()) {
            piit p = q.top(); q.pop();
            if(!g[p.second->to].vis) {
                cost -= p.first;
                g[p.second->to].vis = 1;
                p.second->sp = 1;
                FOREACH(it, g[p.second->to]) if(!g[it->to].vis)
                    q.push(MP(-it->w, it));
            }
        }

        return cost;
    }
};

struct VeX {int vis; int sts;};

struct EdX {
    int rev, w, sp;
    EdX(int w_) : w(w_) {}
};

void algo(int n, int m) {
    Graph<VeX, EdX> g(n);

    REP(i, m) {
        int x,y,w; cin >> x >> y >> w;
        g.EdgeU(x,y,EdX(w));
    }

    REP(i, n) g.g[i].vis = 0;
    REP(i, n) FOREACH(it, g.g[i]) {
        it->sp = 0;
    }

    REP(i, n) if(!g.g[i].vis) {
        g.mstPrima(i);
    }

    VI edges;
    REP(i, n) FOREACH(it, g.g[i]) {
        if(!it->sp && !g.g[it->to][it->rev].sp && i < it->to) {
            edges.PB(it->w);
        }
    }
    sort(ALL(edges));
    if(edges.size() > 0)
        REP(i, SZ(edges)) {
            cout << edges[i] << ((i < SZ(edges) - 1) ? " " : "\n");
        }
    else cout << "forest\n";
}

int main() {
    int n,m;
    cin >> n >> m;
    while(n != 0 || m != 0) {
        algo(n,m);
        cin >> n >> m;
    }
    return 0;
}
