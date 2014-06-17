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
        Ed ed(edx, to);

        ed.rev = SZ(g[to]) + (from == to);
        g[from].PB(ed);

        ed.rev = SZ(g[ed.to = from]) - 1;
        g[to].PB(ed);
    }

    void Scc() {

    }

    vector<int> topoSort() {

    }
};

struct VeX {
};

struct VdX {

};

bool forced(const int st, const Graph<VeX, VdX> &gF, VI& ans) {
    VI visited(SZ(gF.g), 0);

    int qu[SZ(gF.g)];
    int b = 0, e = 0;

    qu[e] = st;
    visited[st] = 1;

    while(b <= e) {
        int n = qu[b++];
        FOREACH(it, gF.g[n]) {
            int to = it->to;
            //bad cycle
            if(visited[to ^ 1]) return false;
            if(!visited[it->to]) {
                visited[it->to] = 1;
                qu[++e] = it->to;
            }
        }
    }
    REP(i, SZ(visited)) if(visited[i]) ans[i/2] = i;

    return true;
}

bool algo0(const Graph<VeX, VdX>& gF) {
    VI ans(SZ(gF.g)/2, -1);

    REP(i, SZ(gF.g)) {
        int par = i / 2;
        if(ans[par] < 0)
            if(!forced(2*par, gF, ans) && !forced(2*par + 1, gF, ans)) return false;
    }
    REP(i, SZ(ans)) cout << ans[i] + 1 << "\n";
    return true;
}

void algo() {
    int n,m; cin >> n >> m;
    Graph<VeX, VdX> gF(2*n);
    REP(_, m) {
        int a,b,f,s; cin >> a >> b;
        f = min(--a,--b); s = max(a,b);
        gF.EdgeD(f, s ^ 1);
        gF.EdgeD(f ^ 1, s);
    }

    if(!algo0(gF)) cout << "NIE\n";
}

int main() {
    algo();
    return 0;
}
