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

int flip(const uint i, const uint x) {
    return x ^ (1 << i);
}

void algo(const int n) {
    VI cs(pow(2,n), -1);
    VI sums(pow(2,n), 0);

    REP(i,SZ(cs)) cin >> cs[i];

    REP(i, SZ(cs)) {
        int sum = 0;
        REP(j, n) {
            int nx = flip(j, i);
            sum += cs[nx];
        }
        sums[i] = sum;
    }

    int max_sum = 0;
    REP(i, SZ(cs)) {
        REP(j, n) {
            int nx = flip(j, i);
            int sum = sums[nx] + sums[i];
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n) algo(n);

    return 0;
}
