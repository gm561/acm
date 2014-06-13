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
        Ed ed(edx, to);

        ed.rev = SZ(g[to]) + (from == to);
        g[from].PB(ed);

        ed.rev = SZ(g[ed.to = from]) - 1;
        g[to].PB(ed);
    }

    vector<int> topoSort() {
        vector<int> bag;
        vector<int> inDegs(SZ(g), 0);
        REP(i, SZ(g)) REP(j, SZ(g[i])) ++inDegs[g[i][j].to];
        REP(i, SZ(inDegs)) if(!inDegs[i]) bag.PB(i);
        vector<int> ans;
        while(!bag.empty()) {
            int v = bag.back(); bag.pop_back();
            ans.PB(v);
            REP(i, SZ(g[v]))
                if(!--inDegs[g[v][i].to]) bag.PB(g[v][i].to);
        }
        return ans;
    }
};

struct VeX { };

struct EdX{ };

int main() {
    Graph<VeX,EdX> g(4);
    g.EdgeD(0,1);
    g.EdgeD(1,2);
    g.EdgeD(0,3);

    VI res0 = g.topoSort();
    REP(i, SZ(res0)) cout << res0[i] << endl;
    return 0;
}
