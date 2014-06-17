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

    int idfs;
    void dfs(int v = 0) {
        idfs = 0;
        REP(i, SZ(g)) g[i].low = g[i].s = g[i].p = -1;
        dfs0(0);
    }

    int dfs0(int v) {
        int low;
        g[v].s = low = idfs++;
        FOREACH(it, g[v]) {
            if(g[it->to].s < 0) {
                g[it->to].p = v;
                low = min(dfs0(it->to), low);
            }
            else if(it->to != g[v].p)
                low = min(g[it->to].s, low);
        }
        g[v].f = idfs++;
        g[v].low = low;
        return low;
    }
};

struct VeX {int low, s, p, f;};

struct EdX {
    int rev;
};

void algo(int n) {
    Graph<VeX, EdX> g(n);

    set<pii> eds;
    for(string line; getline(cin, line);) {
        stringstream ss(line);
        int v, k; ss >> v;
        if(!v) break;
        while(ss >> k) {
            if(eds.find(MP(min(v,k), max(v,k))) == eds.end()) {
                g.EdgeU(v-1, k-1);
                eds.insert(MP(min(v,k), max(v,k)));
            }
        }
    }

    g.dfs();

    REP(i, n) { if(g.g[i].s < 0) { cout << n << "\n"; return;}}
    VI art(n, 0);
    REP(i, n) {
        if(g.g[i].p == -1) {
            int chs = 0;
            FOREACH(it, g.g[i]) if(g.g[it->to].p == i) ++chs;
            if(chs >= 2) art[i] = 1;
        }
        else if(g.g[g.g[i].p].p != -1 && g.g[i].low > g.g[g.g[g.g[i].p].p].s) {
            art[g.g[i].p] = 1;
        }
    }

    int ans = accumulate(ALL(art), 0);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string line;
    while(getline(cin, line)) {
        stringstream ss(line); ss >> n;
        if(!n) break;
        algo(n);
    }

    return 0;
}
