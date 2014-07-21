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

    int bfs(int v0, int v1) {
        REP(i, SZ(g)) g[i].d = -1;

        queue<int> q;
        g[v0].d = 0;
        q.push(v0);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            FOREACH(it, g[v]) if(g[it->to].d < 0) {
                g[it->to].d = g[v].d + 1;
                q.push(it->to);
            }
        }

        return g[v1].d;
    }
};

struct VeX { int d; };

struct EdX { int rev;};

bool isClose(string& s0, string& s1) {
    if(s0.length() != s1.length()) return false;

    uint conf = 0u;
    REP(i, LN(s0)) if(s0[i] != s1[i]) ++conf;

    return conf == 1;
}

void algo() {
    string line, word;
    getline(cin, line);
    vector<string> words;
    while(line != "*") {
        stringstream ss(line);
        ss >> word;
        words.PB(word);
        getline(cin, line);
    }

    Graph<VeX, EdX> g(SZ(words));
    REP(i, SZ(words))
        FOR(j, i + 1, SZ(words) - 1) if(isClose(words[i], words[j])) {
            g.EdgeU(i,j);
        }

    getline(cin, line);
    while(line != "") {
        stringstream ss(line);
        string s0, s1;
        ss >> s0 >> s1;
        int k = -1, j = -1;
        REP(i, SZ(words)) if(words[i] == s0) { k = i; break; }
        REP(i, SZ(words)) if(words[i] == s1) { j = i; break; }
        int dist = g.bfs(k, j);
        cout << s0 << " " << s1 << " " << dist << "\n";
        getline(cin, line);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        algo();
        if(n > 0) std::cout << "\n";
    }

    return 0;
}

