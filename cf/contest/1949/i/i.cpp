// divyanshmittal-exe
// 03 06 2024
#pragma GCC optimize("Ofast,unroll-loops")

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);

// ----------------------<DEBUG>---------------------------
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)                                                            \
  cerr << "[" << #x << "] = [";                                                \
  _print(x)
#else
#define debug(x...)
#endif

// ----------------------<MACROS>---------------------------
using ll = long long;
using ld = long double;
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(ii, c)                                                              \
  for (__typeof((c).begin()) ii = (c).begin(); ii != (c).end(); ii++)
#define rtr(ii, c)                                                             \
  for (__typeof((c).rbegin()) ii = (c).rbegin(); ii != (c).rend(); ii++)
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define max3(A, B, C) max(max((A), (B)), (C))
#define max4(A, B, C, D) max(max((A), (B)), max((C), (D)))
#define min3(A, B, C) min(min((A), (B)), (C))
#define min4(A, B, C, D) min(min((A), (B)), min((C), (D)))
#define count_1(n) __builtin_popcountll(n)
#define fsb(index) (index & -index)
#define maximum(a) max_element(a.begin(), a.end())
#define minimum(a) min_element(a.begin(), a.end())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) static_cast<int>((x).size())
#define MP make_pair
#define FI first
#define SE second
#define MT make_tuple
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
typedef tuple<int, int, int> iii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;
const ll INF = 1e15 - 1;
const ld EPS = 1e-8;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};

// ----------------------<MATH>---------------------------
template <typename T> T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
ll cdiv(ll a, ll b) {
  return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll fdiv(ll a, ll b) {
  return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down

bool dfs(vector<vector<int>> &g, vi &col, int node, pair<int, int> &p,
         int color) {
  col[node] = color;
  if (color == 0)
    p.first++;
  else
    p.second++;

  bool flag = true;

  for (auto &child : g[node]) {

    if (col[child] == -1) {
      bool key = dfs(g, col, child, p, color ^ 1);

      if (!key)
        flag = false;
    }

    else if (col[child] == color)
      flag = false;
  }
  return flag;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(3)), g(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i][0];
    cin >> v[i][1];
    cin >> v[i][2];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {

      if ((v[i][2] + v[j][2]) * (v[i][2] + v[j][2]) ==
          (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) +
              (v[i][1] - v[j][1]) * (v[i][1] - v[j][1])) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  // debug(g);
  vi col(n, -1);
  for (int i = 0; i < n; i++) {
    if (col[i] == -1) {
      pair<int, int> p = {0, 0};

      if (dfs(g, col, i, p, 0)) {
        if (p.first != p.second) {
          cout << "YES";
          return;
        }
      }
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1;
  // cin >> t;
  // Comment out above if only 1 test case
  while (t--) {
    solve();
    cout << "\n";

    // cout << (solve() ? "Yes" : "No") << '\n';
    // cout << (solve() ? "YES" : "NO") << '\n';
    // cout << (solve() ? "Alice" : "Bob") << '\n';
  }
  return 0;
}
