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
using namespace std;

typedef long long LL;
typedef vector<LL> VI;
typedef vector<vector<LL> > VVI;
typedef pair<int, int> pii;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define MP(x,y) make_pair(x,y)
#define ALL(x) (x).begin(), (x).end()
#define FT first
#define ST second
#define FOREACH(i, c) for(typeof((c.begin())) i = (c).begin() ; i != (c).end(); ++i)
#define PB(x) push_back((x))
#define SZ(x) (int)x.size()
#define LN(x) (int)(x).length()
#define INF 1000001


bool isPos(int dx, int dy, int x, int y, int size) {
	if(!((dx + 2) % 2 || (dy + 2) % 2)) return false;
	if(x  + dx < 0 || x + dx >= size || y + dy < 0 || y + dy >= size) return false;
	return true;
}

long long howMany(int size, vector<LL> &start, vector<LL> &end, int n) {
	VVI b0(size, VI(size, 0)), b1(size, VI(size, 0));
	VVI bs[] = {b0, b1};
	bs[0][start[0]][start[1]] = 1;

    REP(i, n) {
        int wh = (i+1) % 2;
        bs[wh] = VVI(size, VI(size, 0));
        REP(j, size) REP(k, size) if(bs[wh^1][j][k])
            for(int i0 = -2; i0 <= 2; ++i0)
                for(int i1 = -2; i1 <= 2; ++i1)
                    if(isPos(i0, i1, j, k, size)) bs[wh][i0 + j][i1 + k] += bs[wh^1][j][k];
    }

	return bs[n % 2][end[0]][end[1]];
}


int main(int argc, char *argv[]) {
    VI s,e;
    s.PB(0); s.PB(0);
    e.PB(1); e.PB(0);
    assert(howMany(3, s, e, 1) == 1L);


    VI s0,e0;
    s0.PB(0); s0.PB(0);
    e0.PB(0); e0.PB(0);
    assert(howMany(3, s0, e0, 2) == 5);

    VI s1,e1;
    s1.PB(0); s1.PB(0);
    e1.PB(0); e1.PB(99);
    assert(howMany(100, s1, e1, 50) == 243097320072600);

    return 0;
}
