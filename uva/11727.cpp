#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    int tc; cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        int as[3]; cin >> as[0] >> as[1] >> as[2];
        vector<int> vs(as, as + 3);
        sort(vs.begin(), vs.end());
        cout << "Case " << i << ": " << vs[1] << "\n";
    }
    return 0;
}
