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

struct GameOfSegments {

    int winner(int N) {
        vector<int> pol(1000, 0);
        pol[0] = 0;
        pol[1] = 0;
        pol[2] = 1;
        pol[3] = 1;
        for(int i = 4; i <= N; ++i) {
            int win = 0;
            for(int j = 0; j < i - 1; ++j) {
                int left = pol[j];
                int right = pol[i - j - 2];
                win = max((int)(!left && !right), win);
            }
            pol[i] = win;
        }
        return (pol[N]) ? 1 : 2;
    }
};

int main(int argc, char *argv[]) {
    GameOfSegments gs;
    cout << gs.winner(3) << endl;
    cout << gs.winner(4) << endl;
    cout << gs.winner(15) << endl;
    cout << gs.winner(191) << endl;
    return 0;
}
