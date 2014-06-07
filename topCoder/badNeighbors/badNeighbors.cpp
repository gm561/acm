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

int maxDontation(vector<int> &dons) {
	if(dons.size() == 1) return dons[0];

	int n = dons.size();
	VI res0(n-1,0), res1(n-1,0);
	res0[0] = dons[0];
	res1[0] = dons[1];
	int gmax = max(res0[0], res1[0]);
	for(int i = 1; i < n - 1; ++i) {
		res0[i] = max(res0[i-1], dons[i]);
        res1[i] = max(res1[i-1], dons[i+1]);
        for(int j = 0; j < i-1; ++j) {
            res0[i] = max(res0[j] + dons[i], res0[i]);
            res1[i] = max(res1[j] + dons[i+1], res1[i]);
        }
        gmax = max(max(res0[i], res1[i]), gmax);
    }
    return gmax;
}

int main(int argc, char *argv[]) {
    int as[] = {10, 3, 2, 5, 7, 8};
    VI vs(as, as + sizeof(as)/sizeof(int));
    assert(maxDontation(vs) == 19);

    int as0[] = { 7, 7, 7, 7, 7, 7, 7};
    VI vs0(as0, as0 + sizeof(as0)/sizeof(int));
    assert(maxDontation(vs0) == 21);

    int as1[] = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
    VI vs1(as1, as1 + sizeof(as1)/sizeof(int));
    assert(maxDontation(vs1) == 2926);

    return 0;
}
