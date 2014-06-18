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

    int inTime;
    int dfs0(int v) {
        if(g[v].s >= 0) return g[v].s;
        g[v].s = inTime++;
        int low = g[v].s;
        FOREACH(it, g[v]) {
            if(g[it->to].s < 0) {
                g[it->to].p = v;
                low = min(low, dfs0(it->to));
            }
            else if(g[v].p != it->to) {
                low = min(low, g[it->to].s);
            }
        }
        g[v].low = low;
        return low;
    }

    void dfs() {
        REP(i, SZ(g)) g[i].low = g[i].s = g[i].p = g[i].f = -1;
        inTime = 0;
        REP(i, SZ(g)) if(g[i].s < 0) dfs0(i);
    }
};

struct VeX {int low, s, p, f;};

struct EdX {
    int rev;
};

void algo(int n) {
    Graph<VeX, EdX> g(n);
    string line;
    REP(_, n) {
        getline(cin, line);
        stringstream ss(line);
        int v, k; ss >> v;
        string nothing; ss >> nothing;
        while(ss >> k) {
            g.EdgeU(v, k);
        }
    }
    g.dfs();
    vector<pii> bris;
    REP(i, n) {
        int parent = g.g[i].p;
        if(parent != -1 &&  g.g[parent].s < g.g[i].low)
            bris.PB(MP(min(parent, i), max(parent, i)));
    }
    sort(ALL(bris));
    cout << SZ(bris) << " critical links\n";
    FOREACH(it, bris) cout << it->first << " - " << it->second << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    string line;
    while(getline(cin, line)) {
        if(!line.length()) continue;
        stringstream ss(line);
        int n; ss >> n;
        algo(n);
        cout << "\n";
    }

    return 0;
}
