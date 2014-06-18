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

struct VeX { };

struct EdX { };

void algo(int n, int m) {
    Graph<VeX,EdX> g(n);
    while(m--) {
        int a,b; cin >> a >> b;
        g.EdgeD(a-1,b-1);
    }

    const VI ts = g.topoSort();
    FOREACH(it, ts) cout << *it + 1<< " ";
    cout << "\n";
}

int main() {
    while(true) {
        int n,m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        algo(n,m);
    }

    return 0;
}
