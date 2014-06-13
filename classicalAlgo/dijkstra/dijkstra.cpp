#include <stack>
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
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

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
        int v;
        Ed(EdX p, int w) : EdX(p), v(w) {}
    };

    struct Ve : VeX, vector<Ed> {};
    vector<Ve> g;
    Graph(int n = 0) : g(n) {}
    void EdgeD(int from, int to, EdX d = EdX()) {
        Ed eg(d,to); g[from].PB(eg);
    }

    struct djcmp {
        bool operator()(const Ve* e0, const Ve* e1) const {
            return (e0->cost == e1->cost) ? e0 < e1 : e0->cost < e1->cost;
        }
    };

    void Dijkstra(int s) {
        set<Ve*, djcmp> k;
        FOREACH(it, g) { it->cost = INF; it->parent = -1; }
        g[s].cost = 0; g[s].parent = -1; k.insert(&g[s]);
        while(!k.empty()) {
            Ve *cur  = *(k.begin());
            k.erase(k.begin());
            FOREACH(it, *cur) if(g[it->v].cost > cur->cost + it->weight) {
                k.erase(&g[it->v]);
                g[it->v].cost = cur->cost + it->weight;
                g[it->v].parent = it->v;
                k.insert(&g[it->v]);
            }
        }
    }
};

struct VeX {
    int cost; int parent;
};

struct EdX {
    int weight;
    EdX(int w) : weight(w) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n;
    Graph<VeX, EdX> g(2 * n);
    REP(i, n) {
        int cost; cin >> cost;
        g.EdgeD(i, i + n, EdX(0.5 * cost));
    }
    cin >> m;
    REP(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from, --to;
        g.EdgeD(from, to, EdX(cost));
        g.EdgeD(from + n, to + n, EdX(cost));
    }

    g.Dijkstra(0);
    cout << g.g[n].cost << "\n";

    return 0;
}

