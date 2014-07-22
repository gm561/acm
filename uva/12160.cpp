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

void algo(int l, int u, int r, int tc) {
    const int sp_size = 10000;
    VI ns(r, 0), nums(sp_size, INF), q;
    REP(i, r) cin >> ns[i];
    nums[l] = 0;
    q.PB(l);
    for(int i = 0; i < SZ(q); ++i) {
        int v = q[i];
        REP(j, SZ(ns)) {
            int val = (v + ns[j]) % sp_size;
            if(nums[val] == INF) {
                nums[val] = nums[v] + 1;
                q.PB(val);
            }
        }
    }

    cout << "Case " << tc << ": ";
    if(nums[u] >= INF) cout << "Permanently Locked\n";
    else cout << nums[u] << "\n";
}

int main() {
    int tc = 1, l, u, r;
    cin >> l >> u >> r;
    while(l != 0 || u != 0 || r != 0) {
        algo(l, u, r, tc++);
        cin >> l >> u >> r;
    }

    return 0;
}
