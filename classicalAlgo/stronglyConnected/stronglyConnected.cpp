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
        REP(i,SZ(g)) g[i].d = g[i].s = g[i].f = -1;
        stack<int> st;
        int t = 0, s = 0, fs = 0;
        (e == -1) ? e = SZ(g)-1 : s = e;
        FOR(i, s, e) if(g[i].s < 0) {
            st.push(i); g[i].s = t++;
            while(!st.empty()) {
                int v = st.top();
                if(g[v].d >= 0) {
                    g[v].f = t++;
                    g[v].d = fs++;
                    st.pop();
                } else {
                    g[v].d = 1;
                    g[v].s = t++;
                    REP(j, SZ(g[v])) if(g[g[v][j].to].s < 0) {
                        st.push(g[v][j].to);
                    }
                }
            }
        }
    }

    void dfsScc(int e, int nr) {
        stack<int> st;
        int t = 0, s = 0, fs = 0;
        (e == -1) ? e = SZ(g)-1 : s = e;
        FOR(i, s, e) if(g[i].s < 0) {
            st.push(i); g[i].s = t++;
            while(!st.empty()) {
                int v = st.top();
                if(g[v].d >= 0) {
                    g[v].f = t++;
                    g[v].d = fs++;
                    g[v].c = nr;
                    st.pop();
                } else {
                    g[v].s = t++;
                    g[v].d = 1;
                    REP(j, SZ(g[v])) if(g[g[v][j].to].s < 0) {
                        st.push(g[v][j].to);
                    }
                }
            }
        }
    }

    void scc() {
        Graph gT(SZ(g));
        REP(i, SZ(g)) REP(j, SZ(g[i])) gT.EdgeD(g[i][j].to, i);
        dfs();
        vector<int> vfs(SZ(g));
        REP(i, SZ(g)) vfs[g[i].d] = i;
        int n = SZ(gT.g), nr = 0;

        REP(i, SZ(gT.g)) gT.g[i].d = gT.g[i].s = gT.g[i].f = -1;
        REP(i, SZ(gT.g)) if(gT.g[i].d < 0) gT.dfsScc(vfs[n - 1 - i], nr++);
        REP(i, SZ(g)) g[i].c = gT.g[i].c;
    }
};

struct VeX {
    int c, d, s, f;
};

struct EdX{ };

int main() {
    Graph<VeX,EdX> g(6);
    g.EdgeD(0,1);
    g.EdgeD(1,2);
    g.EdgeD(2,0);
    g.EdgeD(0,3);
    g.EdgeD(3,4);
    g.EdgeD(4,5);
    g.EdgeD(5,4);

    g.scc();
    REP(i, SZ(g.g)) cout << "Vertex " << i << " st. comp. " << g.g[i].c << endl;
    return 0;
}
