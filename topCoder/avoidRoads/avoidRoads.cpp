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


struct Block  {
	int x0,x1,y0,y1;
};

struct BlockCmp {
	bool operator()(const Block& b0, const Block &b1) {
		if((b0.x0 < b1.x0) ||
           (b0.x1 < b1.x1) ||
           (b0.y0 < b1.y0) ||
           (b0.y1 < b1.y1))
            return 1;
        return 0;
    }
};

long numWays(int w, int h, vector<string> &bad) {
    ++w,++h;
    set<Block, BlockCmp> blocks;
    REP(i, SZ(bad)) {
        stringstream ss(bad[i]);
        Block b;
        ss >> b.x0 >> b.y0 >> b.x1 >> b.y1;
        if(b.x0 > b.x1) swap(b.x0,b.x1);
        if(b.y0 > b.y1) swap(b.y0,b.y1);
        blocks.insert(b);
    }

    vector<vector<long> > ways(w, vector<long>(h,0));
    ways[0][0] = 1;
    REP(i, w) REP(j,h) {
        Block b0,b1;
        b0.x0 = i - 1; b0.x1 = i; b0.y0 = b0.y1 = j;
        b1.x0 = b1.x1 = i; b1.y0 = j-1; b1.y1 = j;

        long to0 = (blocks.find(b0) == blocks.end() && i-1 >= 0) ? ways[i-1][j] : 0;
        long to1 = (blocks.find(b1) == blocks.end() && j-1 >= 0) ? ways[i][j-1] : 0;
        ways[i][j] = to0 + to1;
        if(i == 0 && j == 0) ways[0][0] = 1;
    }
    return ways[w-1][h-1];
}

int main() {
    string as[] = {"0 0 0 1","5 6 6 6"};
    vector<string> vs(as, as + sizeof(as)/sizeof(string));
    cout << numWays(6,6,vs) << endl;

    vector<string> vs0;
    cout << numWays(35, 31, vs0) << endl;

    string as0[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
    vector<string> vs1(as0, as0 + sizeof(as0)/sizeof(string));
    cout << numWays(2,2,vs1) << endl;
    return 0;
}
