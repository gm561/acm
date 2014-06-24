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

    pdd mstPrima() {
        const int n = SZ(g);
        double cost0  = 0, cost1 = 0;
        VI vis(n, 0);

        priority_queue<pdpi> q;
        q.push(MP(.0,MP(0,0)));
        while(!q.empty()) {
            pdpi p = q.top(); q.pop();
            if(!vis[p.second.second]) {
                (p.second.first) ? cost0 += sqrt(abs(p.first)) : cost1 += sqrt(abs(p.first));
                vis[p.second.second] = 1;
                FOREACH(it, g[p.second.second]) if(!vis[it->to])
                    q.push(MP(-it->w, MP(it->type, it->to)));
            }
        }

        return MP(cost0, cost1);
    }

    void dfs0(int s, int sts) {
        g[s].vis = 1;
        g[s].sts = sts;
        FOREACH(it, g[s]) if(!g[it->to].vis) {
            dfs0(it->to, sts);
        }
    }
};

struct VeX {int vis; int sts;};

struct EdX {
    double w;
    int rev, type;
    EdX(double w_, int type_) : w(w_), type(type_) {}
};

double dist2(const pdd& x0, const pdd& x1) {
    return pow(x0.first - x1.first, 2) + pow(x0.second - x1.second, 2);
}

void algo(int tc) {
    int n, th, sts = 0; cin >> n >> th;
    Graph<VeX, EdX> g(n);
    vector<pdd> vs; vs.reserve(n);
    REP(i, n) {
        double x, y; cin >> x >> y;
        vs.PB(MP(x,y));
    }

    const double th2 = th * th;
    REP(i, n) {
        for(int j = 0; j < i; ++j) {
            double dist = dist2(vs[j], vs[i]);
            if(dist < th2) g.EdgeU(i, j, EdX(dist, 1));
        }
    }

    REP(i, n) g.g[i].vis = 0, g.g[i].sts = 0;
    REP(i, n) if(!g.g[i].vis) {
        ++sts;
        g.dfs0(i, sts);
    }

    REP(i, n) for(int j = 0; j < i; ++j) if(g.g[i].sts != g.g[j].sts) {
            double dist = dist2(vs[j], vs[i]);
            g.EdgeU(i, j, EdX(dist, 0));
    }

    pdd costs = g.mstPrima();
    cout << "Case #" << tc << ": " << sts << " " << int(costs.first + 0.5)
         << " " << int(costs.second + 0.5) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    REP(i, tc) algo(i + 1);
    return 0;
}
