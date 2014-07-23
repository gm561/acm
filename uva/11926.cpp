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
#include <bitset>

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

int main() {
    const int len = 1000001;
    bitset<len> bs;

    int n,m;
    while(scanf("%d %d", &n, &m), n || m) {
        bool ans = true;
        REP(_, n) {
            int s,e; scanf("%d %d", &s, &e);
            FOR(i, s, e-1) {
                if(!ans) break;
                if(bs.test(i)) {
                    ans = false;
                    break;
                }
                bs.set(i);
            }
        }

        REP(_, m) {
            int s, e, r;
            scanf("%d %d %d", &s, &e, &r);
            while(e < len) {
                if(!ans) break;
                FOR(i, s, e-1) {
                    if(bs.test(i)) {
                        ans = false;
                        break;
                    }
                    bs.set(i);
                }
                s += r;
                e = min(e + r, len);
            }
        }

        bs.reset();
        printf(((ans) ? "NO CONFLICT\n" : "CONFLICT\n"));
    }

    return 0;
}
