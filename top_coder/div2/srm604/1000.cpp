
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef vector<VI> VVI;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()

#define PB push_back
struct FoxConnection2 {

    int k;
    VI dfs(VVI& tree, VI& vis, int v, LL& result) {
	LL mod = 1000000007;
	VI t(SIZE(tree)+1);
	t[0] = 1;
	REP(i, SIZE(tree[v])) {
	    if(!vis[tree[v][i]]) {
		vis[tree[v][i]] = 1;
		VI t0 = dfs(tree, vis, tree[v][i], result);
		REP(j, SIZE(t0)-1) t[j+1] = (t0[j] + t[j+1]) % mod;
	    }
	}

	REP(i, SIZE(t)) if(k-i >=0) result += t[i]*t[k-i] % mod;

	return t;
    }

    int ways(vector <int> A, vector <int> B, int k_) {
	k = k_;
	VVI tree(SIZE(A)+1);

	REP(i, SIZE(A)) REP(j, SIZE(B))
	    tree[A[i]-1].PB(B[j]-1);

	VI visited(SIZE(tree));

	LL result = 0;
	dfs(tree, visited, 0, result);

	return result;
    }
};

int main() {
    int t0[] = {1,2,3};
    int t1[] = {2,3,4};

    VI v0(t0, t0 + 3);
    VI v1(t1, t1 + 3);
    FoxConnection2 fc;

    cout << fc.ways(v0,v1,2) << endl;
    return 0;
}
