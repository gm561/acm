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

    //int bfs(int v0, int v1, int mn, int m = 0) {
    int bfs(int v0, int v1, int mn) {
        REP(i, SZ(g)) g[i].d = -1;

        queue<int> q;
        g[v0].d = 0;
        q.push(v0);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            FOREACH(it, g[v]) if(g[it->to].d < 0) {
                g[it->to].d = g[v].d + 1;
                g[it->to].p = v;
                q.push(it->to);
            }
        }

        return min(min(g[v1].d, g[v1 + mn].d), min(g[v1+ 2*mn].d, g[v1 + 3*mn].d));
    }
};

struct VeX { int d,p; };
struct EdX { int rev;};

void algo(int n, int m) {
    Graph<VeX, EdX> g(n * m * 4);
    VVI blocks(n+1, VI(m+1, 0));
    REP(i, n) REP(j, m) {
        int isBlock; cin >> isBlock;
        if(isBlock) {
            blocks[i][j] = 1;
            if(i + 1 <= n) blocks[i+1][j] = 1;
            if(j + 1 <= m) blocks[i][j+1] = 1;
            if(i + 1 <= n && j + 1 <= m) blocks[i+1][j+1] = 1;
        }
    }

    int move[] = {1,2,3};

    //imp go command
    REP(i, n) REP(j, m) {
        if(i == 0 || j == 0) continue;

        //turns
        for(int k = 0; k <= 3; ++k)
            g.EdgeU(i * m + j + k * m * n , i * m + j + ((k+1) % 4) * n * m);

        bool stop0 = false;
        //go east
        for(int x : move) {
            if(j + x >= m || j + x <= 0 || blocks[i][j+x]) stop0 = true;
            if(!stop0) g.EdgeD(i * m + j + m * n, i * m + j + x + m * n);
        }

        stop0 = false;
        //go west
        for(int x : move) {
            if(j - x >= m || j - x <= 0 || blocks[i][j-x]) stop0 = true;
            if(!stop0) g.EdgeD(i * m + j + 3 * m * n, i * m + j - x + 3 * m * n);
        }

        stop0 = false;
        //go north
        for(int x : move) {
            if(i - x >= n || i - x <= 0 || blocks[i-x][j]) stop0 = true;
            if(!stop0) g.EdgeD(i * m + j, (i-x) * m + j);
        }

        stop0 = false;
        //go south
        for(int x : move) {
            if(i + x >= n || i + x <= 0 || blocks[i+x][j]) stop0 = true;
            if(!stop0) g.EdgeD(i * m + j + 2*m*n, (i+x) * m + j + 2*m*n);
        }
    }

    int s0s1,e0,e1; cin >> s0 >> s1 >> e0 >> e1;
    string dir; cin >> dir;
    int x = 0; //north
    x = (dir == "east") ? 1 : x;
    x = (dir == "south") ? 2 : x;
    x = (dir == "west") ? 3 : x;

    cout << g.bfs(s0 * m + s1 + m*n*x, e0 * m + e1, m*n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    while(n != 0 && m != 0) {
        algo(n, m);
        cin >> n >> m;
    }

    return 0;
}
