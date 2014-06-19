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

struct AddMultiply {
    VI makeExpression(int y) {
        for(int i = -1000; i <= 1000; ++i) {
            if(i != 0 && i != 1) {
                for(int j = -1000; j <= 1000; ++j) {
                    if(j != 0 && j != 1) {
                        int z = y - i * j;
                        if(z >= -1000 && z <= 1000 && z != 0 && z != 1) {
                            VI ans;
                            ans.PB(i); ans.PB(j); ans.PB(z);
                            return ans;
                        }
                    }
                }
            }
        }
    }
};

int main() {
    AddMultiply a;
    a.makeExpression(6);
    return 0;
}
