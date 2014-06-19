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


struct IncrementingSequence {

    string canItBeDone(int k, vector <int> A) {
        int n = SZ(A);
        VI mis(n, 0);

        bool ans = true;
        REP(i, n) {
            int m = i + 1;
            ans = false;
            while(m > 0 && !ans) {
                REP(j, n) if(A[j] == m && mis[j] == 0) {
                    mis[j] = 1;
                    ans = true;
                    break;
                }
                m -= k;
            }
            if(!ans) return "IMPOSSIBLE";
        }

        return "POSSIBLE";
    }
};

int main() {
    int as[] = {5,3,3,2,1};
    VI vs(as, as + sizeof(as) /sizeof(int));
    IncrementingSequence  is;
    cout << is.canItBeDone(2, vs) << endl;
    return 0;
}
