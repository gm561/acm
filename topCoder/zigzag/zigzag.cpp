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

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
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

int zigZag(VI &vs) {
    int n = SZ(vs);
    VVI vvs0(n, VI(n,0)), vvs1(n, VI(n,0));
    REP(i,n) vvs0[i][i] = vvs1[i][i] = 1;
    int gmax = 1;
    REP(i, n) REP(j, n) {
        int cmax0 = 0, cmax1 = 0;
        for(int k = i; k < j; ++k) {
            if(((vvs0[i][k] & 1) && vs[k] < vs[j]) || (!(vvs0[i][k] & 0x1) && vs[k] > vs[j]))
                cmax0 = max(vvs0[i][k] + 1, cmax0);

            if(((vvs1[i][k] & 0x1) && vs[k] > vs[j]) || (!(vvs1[i][k] & 0x1) && vs[k] < vs[j]))
                cmax1 = max(vvs1[i][k] + 1, cmax1);
        }
        vvs0[i][j] = max(cmax0, vvs0[i][j]);
        vvs1[i][j] = max(cmax1, vvs1[i][j]);
        gmax = max(max(cmax0, cmax1), gmax);
    }
    return gmax;
}

int main() {
    int as[] = { 1, 7, 4, 9, 2, 5 };
    VI vs(as, as + sizeof(as) / sizeof(int));
    assert(zigZag(vs) == 6);

    int as0[] = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    VI vs0(as0, as0 + sizeof(as0) / sizeof(int));
    assert(zigZag(vs0) == 7);

    int as1[] = {44};
    VI vs1(as1, as1 + sizeof(as1) / sizeof(int));
    assert(zigZag(vs1) == 1);

    int as2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    VI vs2(as2, as2 + sizeof(as2) / sizeof(int));
    assert(zigZag(vs2) == 2);

    int as3[] = {374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
249, 22, 176, 279, 23, 22, 617, 462, 459, 244};

    VI vs3(as3, as3 + sizeof(as3) / sizeof(int));
    assert(zigZag(vs3) == 36);

    return 0;
}
