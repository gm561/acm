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
        if(g[v].v > -1) return;
        g[v].v = 1;
        FOREACH(it, g[v]) dfs0(it->to);
    }

    bool isEuler() {
        REP(i, SZ(g)) g[i].v = -1;
        REP(i, SZ(g)) if(SZ(g[i])) { dfs0(i); break;}
        REP(i, SZ(g)) if(g[i].v < 0 && SZ(g[i]) > 0 ) return false;
        REP(i, SZ(g)) if(SZ(g[i]) & 1) return false;
        return true;
    }

    void dfs(int v, VI& res, VI& eds) {
        while(g[v].k < SZ(g[v])) {
            int i = g[v].k;
            int to = g[v][i].to;
            if(!eds[g[v][i].i]) {
                eds[g[v][i].i] = 1;
                dfs(to, res, eds);
                res.PB(v);
            }
            ++g[v].k;
        }
    }

    VI eulerCycle(int m) {
        VI ans, eds(m, 0);
        int v = -1;
        REP(i, SZ(g)) if(g[i].v == 1) {
            v = i;
            break;
       }

        dfs(v, ans, eds);
        return ans;
    }
};

struct VeX { int s, k, v; };

struct EdX {
    int rev;
};

void algo(int n, int m) {
    Graph<VeX,EdX> g(n);
    bool t = false;
    while(m--) {
        t = true;
        int a,b; cin >> a >> b;
        g.EdgeU(a,b);
    }

    cout << ((g.isEuler() && t) ? "Possible\n" : "Not Possible\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m) {
        algo(n,m);
    }
    return 0;
}
