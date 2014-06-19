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
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

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
const int INF = 10000001;

struct BuildingHeightsEasy {

    int minimum(int M, vector <int> heights) {
        int m = INF;
        for(int i = 1; i <= 50; ++i) {
            VI vs(heights.begin(), heights.end());
            REP(j, SZ(vs)) {
                vs[j] = (i - vs[j] >= 0) ? i-vs[j] : INF;
            }
            sort(ALL(vs));
            int sum = 0;
            REP(j, M) sum += vs[j];
            m = min(sum,m);
        }
        return m;
    }
};


int main(int argc, char *argv[]) {
    int as[] = {1, 3, 5, 2, 1};
    VI vs(as, as + sizeof(as) /sizeof(int));
    BuildingHeightsEasy b;
    cout << b.minimum(3, vs) << endl;
    return 0;
}

