// Devang Sharma, GDG SINGAPORE

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define int long long
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm;

struct node {
  int id;
  vector<int> son;
  int father;
  int depth;
  int ason = 1, bson = 1, lcmson = 1;
  int sonnum = 1;
};

void filldepth(vector<node> &tree, int node) {
  if (node == 0)
    tree[node].depth = 0;
  else
    tree[node].depth = tree[tree[node].father].depth + 1;
  for (auto &i : tree[node].son) {
    filldepth(tree, i);
    tree[node].sonnum += tree[i].sonnum;
  }
}

void fillson(vector<node> &tree, int node, int a, int b, vector<int> &fnode) {
  auto &now = tree[node];
  fnode.push_back(node);
  for (auto &i : now.son) {
    fillson(tree, i, a, b, fnode);
  }
  if (fnode.size() > a) {
    tree[fnode[fnode.size() - 1 - a]].ason += now.ason;
  }
  if (fnode.size() > b) {
    tree[fnode[fnode.size() - 1 - b]].bson += now.bson;
  }
  if (fnode.size() > lcm) {
    tree[fnode[fnode.size() - 1 - lcm]].lcmson += now.lcmson;
  }
  fnode.pop_back();
}
void slove() {
  int n, a, b;
  cin >> n >> a >> b;
  lcm = a * b / gcd(a, b);
  vector<int> input(n);
  for (int i = 1; i < n; i++) {
    cin >> input[i];
    input[i] = input[i] - 1;
  }
  vector<node> tree(n);
  for (int i = 1; i < n; i++) {
    tree[i].father = input[i];
    tree[input[i]].son.push_back(i);
  }
  filldepth(tree, 0);
  vector<int> fnode;
  fillson(tree, 0, a, b, fnode);
  int ans = 0;
  for (auto &i : tree) {
    ans += i.ason * n + i.bson * n - i.ason * i.bson;
  }
  cout << fixed << setprecision(10) << (double)ans / n / n << endl;
}
signed main() {
  fast;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
} 
