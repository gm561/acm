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

bool isValid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

int bfs(int v0, int v1, VVI &g) {
    int c = SZ(g[0]);
    int r = SZ(g);
    VI q;
    g[v0 / c][v0 % c] = 0;
    q.PB(v0);

    int up[4] = {-1, 0, 0, 1};
    int left[4] = {0, 1, -1, 0};

    for(int i = 0; i < SZ(q); ++i) {
        int v = q[i];
        for(int k = 0; k < 4; ++k)
            if(isValid(v / c + up[k], v % c + left[k], r, c) &&
               g[v/c + up[k]][v % c + left[k]] < 0) {
            g[v/c + up[k]][v % c + left[k]] = g[v/c][v % c] + 1;
            if(v + up[k] * c + left[k] == v1)
                return g[v/c + up[k]][v % c + left[k]];

            q.PB(v + up[k] * c + left[k]);
        }
    }

    return -1;
}

struct VeX { int d; };

struct EdX { int rev; };

void algo(int r, int c) {
    VVI g(r, VI(c, -1));
    int rb; cin >> rb;
    while(rb-- > 0) {
        int rn, nb, cn;
        cin >> rn >> nb;
        while(nb-- > 0) {
            cin >> cn;
            g[rn][cn] = INF;
        }
    }
    int s0,s1,e0,e1; cin >> s0 >> s1 >> e0 >> e1;

    int ans = bfs(s0 * c + s1, e0 * c + e1, g);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int r,c;
    cin >> r >> c;
    while(r != 0 && c != 0) {
        algo(r,c);
        cin >> r >> c;
    }

    return 0;
}
