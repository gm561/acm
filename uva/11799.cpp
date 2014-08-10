#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int tc; cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        int n; cin >> n;
        vector<int> vs(n, 0);
        for(int j = 0; j < n; ++j) cin >> vs[j];
        cout << "Case " << i << ": " << *max_element(vs.begin(), vs.end()) << "\n";
    }
    return 0;
}
