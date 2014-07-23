#include <iostream>
#include <bitset>

using namespace std;

void algo(uint n_) {
    bitset<32> bs(n_);
    bitset<32> ans[2];

    bool last = true;
    for(int i = 0; i < 32; ++i) {
        if(bs.test(i)) {
            ans[last][i] = bs[i];
            last = !last;
        }
    }

    uint a = ans[1].to_ulong();
    uint b = ans[0].to_ulong();

    cout << a << " " << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    uint n;
    while(cin >> n, n) algo(n);

    return 0;
}
