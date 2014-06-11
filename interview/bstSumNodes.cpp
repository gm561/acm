#include <stack>
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
const int INF = 1000000001;

struct Node {
    int value;
    Node *left, *right;
    Node(int v_) : value(v_) {left = right = NULL;}
};

Node *n0, *n1;
bool findValue(int value, Node *node) {
	bool result = false;
	if(node == NULL) return result;
    if(value < node->value)
        result = findValue(value, node->left);
    else if(value > node->value)
        result = findValue(value, node->right);
    else if(n0 != node) {
        n1 = node;
        result = true;
    }
    return result;
}

void findSum0(int sum, Node* root, Node *first = NULL) {
	if(first == NULL) first = root;

    n0 = first;
    bool res = findValue(sum - first->value, root);
    if(!res) {
        findSum0(sum, root, first->left);
        findSum0(sum, root, first->right);
    }

}


void inOrderNoRec0(Node *root) {
    stack<Node*> st;
    st.push(root);
    while(st.size() > 0) {
        Node *n = st.top(); st.pop();
        if(n->left != NULL) {
            st.push(n);
            st.push(n->left);
            n = n->left;
        }
        else {
            cout << n->value << endl;
            if(st.size() == 0) return;
            n = st.top(); st.pop();
            cout << n->value << endl;
            if(n->right != NULL) {
                st.push(n->right);
            }
        }
    }
}

void inOrderNoRec(Node *root) {
    stack<Node*> nodes;
    nodes.push(root);
    Node *cur, *prev = root;
    while(nodes.size() > 0) {
        cur = nodes.top();
        if(cur->left != NULL && prev->value >= cur->value) {
            nodes.push(cur->left);
            prev = cur;
        }
        else {
            cout << cur->value << endl;
            nodes.pop();
            prev = cur;
            if(cur->right != NULL) {
                nodes.push(cur->right);
                prev = cur->right;
            }
        }

    }
}

void revInOrder(Node *root) {
    stack<Node*> st;
    st.push(root);
    Node *cur, *prev = root;
    while(st.size() > 0) {
        cur = st.top();
        if(cur->right != NULL && prev->value <= cur->value) {
            st.push(cur->right);
        }
        else {
            cout << cur->value << endl;
            st.pop();
            if(cur->left != NULL) st.push(cur->left);
        }
        prev = cur;
    }

}

void stop() {int a; cin >> a;}

pair<Node*, Node*> findSum(Node *root, int sum) {
    stack<Node*> minSt, maxSt;
 	Node *cur0 = root, *cur1 = root, *prev0, *prev1;

    minSt.push(root); maxSt.push(root);
 	while(cur0->left != NULL) {
        minSt.push(cur0->left);
        cur0 = cur0->left;
        prev0 = cur0;
    }
 	while(cur1->right != NULL) {
        maxSt.push(cur1->right);
        cur1= cur1->right;
        prev1 = cur1;
    }

    minSt.pop();
    maxSt.pop();

    while(cur0->value < cur1->value) {
        if(cur0->value + cur1->value > sum) {
            while(true){
                cout << cur0->value << " " << cur1->value << endl;
                cur1 = maxSt.top();
                if(cur1->right != NULL && cur1->value >= prev1->value) {
                    maxSt.push(cur1->right);
                    prev1 = cur1;
                }
                else {
                    maxSt.pop();
                    prev1 = cur1;
                    if(cur0->value + cur1->value <= sum) break;
                    if(cur1->left != NULL) {
                        prev1 = cur1->left;
                        maxSt.push(cur1->left);
                    }
                }
            }
        }
        if(cur0->value + cur1->value < sum) {
            while(true) {
                cout << cur0->value << " " << cur1->value << endl;
                cur0 = minSt.top();
                if(cur0->left != NULL && cur0->value <= prev0->value) {
                    minSt.push(cur0->left);
                    prev0 = cur0;
                }
                else {
                    minSt.pop();
                    prev0 = cur0;
                    if(cur0->value + cur1->value >= sum) break;
                    if(cur0->right != NULL) {
                        prev0 = cur0->right;
                        minSt.push(cur0->right);
                    }
                }
            }
        }

        if(cur0->value + cur1->value == sum) return make_pair(cur0, cur1);
    }
    assert(false);
}

int main() {
    Node n0(0);
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);

    Node& root = n4;
    n4.left = &n2;
    n4.right = &n6;
    n2.left = &n1;
    n2.right = &n3;
    n6.left = &n5;
    n6.right = &n7;

    //findSum(5, &root);
    // cout << ::n0->value << endl;
    // cout << ::n1->value << endl;
//    inOrderNoRec(&root);
//    cout << endl;
//    revInOrder(&root);
    inOrderNoRec0(&root);
    // for(int i = 3; i <= 13; ++i) {
    //     cout << "Find value " << i << endl;
    //     pair<Node*, Node*> ns = findSum(&root, i);
    //     assert(ns.first->value + ns.second->value == i);
    // }
    return 0;
}
