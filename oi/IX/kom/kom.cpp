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
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

#define FOR(i, from, to) for(int i = (from); i <= (to); ++i)
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

    void dfs(int e = -1) {
        REP(i,SZ(g)) g[i].d = g[i].s = g[i].f = g[i].par = -1;
        stack<int> st;
        int t = 0, s = 0;
        (e == -1) ? e = SZ(g)-1 : s = e;
        FOR(i, s, e) if(g[i].s < 0) {
            st.push(i); g[i].s = t++; g[i].f = 0;
            while(!st.empty()) {
                int v = st.top();
                if(g[v].d >= 0) {
                    g[v].d = g[v].f;
                    g[v].f = t++;
                    st.pop();
                } else {
                    g[v].d = 0;
                    g[v].s = t++;
                    REP(j, SZ(g[v])) if(g[g[v][j].to].s < 0) {
                        g[g[v][j].to].f = g[v].f + 1;
                        g[g[v][j].to].par = v;;
                        st.push(g[v][j].to);
                    }
                }
            }
        }
    }
};

struct VeX {int d,f,s,par;};
struct EdX {int rev;};

int main() {
    int n;
    cin >> n;
    Graph<VeX, EdX> g(n);
    REP(_, n-1) {
        int a,b; cin >> a >> b;
        --a, --b;
        g.EdgeU(a,b);
    }

    int m; cin >> m;
    VI  cits(m);
    REP(i, m) {
        int x; cin >> x;
        cits[i] = --x;
    }

    g.dfs(cits[0]);
    int prev = cits[0];
    int dist = 0;

    FOR(i, 1, SZ(cits)-1) {
        int cur = cits[i];
        //child
        if(g.g[cur].s > g.g[prev].s && g.g[cur].f < g.g[prev].f)
            dist += g.g[cur].d - g.g[prev].d;
        //parent
        else if(g.g[prev].s > g.g[cur].s && g.g[prev].f < g.g[cur].f)
            dist += g.g[prev].d - g.g[cur].d;
        //different subtrees
        else {
            int com = cur;
            while(!(g.g[prev].s > g.g[com].s && g.g[prev].f < g.g[com].f)) com = g.g[com].par;
            dist += g.g[prev].d + g.g[cur].d - 2*g.g[com].d;
        }

        prev = cur;
    }
    cout << dist << "\n";
    return 0;
}
