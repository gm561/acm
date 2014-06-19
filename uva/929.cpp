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


    void dijkstra(int s, int n, int m, int w) {
        REP(i, SZ(g)) { g[i].d = INF; g[i].v = 0;}
        g[s].d = w;
        priority_queue<pii> q;
        q.push(MP(0,s));
        while(!q.empty()) {
            int v = q.top().second; q.pop();
            if(v == (n - 1 + n * (m-1))) return;
            if(g[v].v) continue;
            g[v].v = 1;
            FOREACH(it, g[v]) {
                if(!g[it->to].v) {
                    if(g[it->to].d > g[v].d + it->w) {
                        g[it->to].d = g[v].d + it->w;
                        q.push(MP(-g[it->to].d, it->to));
                    }
                }
            }
        }
    }
};

struct VeX { int d; int v;};

struct EdX {
    int w, rev;
    EdX(int w_) : w(w_) {}
};

bool isPos(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void algo() {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    int n, m, iw = 0; cin >> m >> n;
    Graph<VeX, EdX> g(n*m);
    REP(j, m) {
        REP(i, n) {
            int w; cin >> w;
            if(i == 0 && j == 0) iw = w;
            REP(k, 4) if(isPos(i + dx[k], j + dy[k], n, m)) {
                g.EdgeD(i + dx[k] + (j + dy[k]) * n, i + j * n, EdX(w));
            }
        }
    }

    g.dijkstra(0, n, m, iw);
    cout << g.g[n - 1 + n * (m-1)].d << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) algo();

    return 0;
}

