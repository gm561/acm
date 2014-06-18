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

    bool dfsColor(int v, bool color) {
        bool result = true;
        g[v].c = color;
        FOREACH(it, g[v]) {
            if(g[it->to].c < 0)
                result = result && dfsColor(it->to, !color);
            else result = result && (g[it->to].c != color);

        }
        return result;
    }

    bool isBip() {
        REP(i, SZ(g)) g[i].c = -1;
        return dfsColor(0, 0);
    }
};

struct VeX { int c; };

struct EdX { int rev;};

void algo(int n) {
    int m; cin >> m;
    Graph<VeX,EdX> g(n);
    while(m--) {
        int a,b; cin >> a >> b;
        g.EdgeU(a,b);
    }
    cout << ((g.isBip()) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n > 0) {
        algo(n);
        cin >> n;
    }

    return 0;
}
