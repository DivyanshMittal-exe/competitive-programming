// divyanshmittal-exe  
// 10 06 2022

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

#ifndef ONLINE_JUDGE
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(ii, c) for (__typeof((c).begin()) ii = (c).begin(); ii != (c).end(); ii++)
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define max3(A, B, C) max(max((A), (B)), (C))
#define max4(A, B, C, D) max(max((A), (B)), max((C), (D)))
#define min3(A, B, C) min(min((A), (B)), (C))
#define min4(A, B, C, D) min(min((A), (B)), min((C), (D)))
#define endl(x) " \n"[x]
#define count_1(n) __builtin_popcountll(n)
#define fsb(index) (index & -index)

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define MP make_pair
#define FI first
#define SE second
#define MT make_tuple
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

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

// -------------------------<RNG>-------------------------
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

// ----------------------<MATH>---------------------------

template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }

template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = 0, yy = 1;
    y = 0;
    x = 1;
    while (b)
    {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD)
{
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
}

/****************** Prime Generator **********************/
/****************** Prime Generator End **********************/
int countsize(vi& size , vvi& tree, int node, vi& visitedcount){

    visitedcount[node] = 1;
    // cout << node << endl;
    int sum = 0;
    for (int i = 0; i < tree[node].size(); i++)
    {
        if(visitedcount[tree[node][i]] ==0){
            sum += countsize(size,tree,tree[node][i],visitedcount);
        }else{
            tree[node].erase(tree[node].begin() + i);
            --i;
        }

    }
    
    size[node] = 1 + sum;
    return 1 + sum;
}


int savetree(vi& size , vvi& tree, int node){

    if(tree[node].size() == 0){
        return 0;
    }else if (tree[node].size() == 1){
        return size[node] - 2;
    }else{
        if(size[tree[node][0]] > size[tree[node][1]] ){
            return size[tree[node][0]] + savetree(size,tree,tree[node][1])-1;
        }else{
            return size[tree[node][1]] + savetree(size,tree,tree[node][0])-1;
        }
    }

}


void solve()
{
    int count; 
    cin >> count;
    vvi tree(count+1);
    vi sizes(count+1);
    vi visitedcount(count+1);

    for (int i = 0; i < count+1; i++)
    {
        visitedcount[i] = 0;
    }
    
    for (int i = 0; i < count-1; i++)
    {
        int l,p;
        cin >> l >> p;

        tree[p].push_back(l);
        tree[l].push_back(p);
    }

    countsize(sizes,tree,1,visitedcount);
    // int saved = 0;

    cout << savetree(sizes,tree,1) << endl;

}

int main()
{
#ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // ll t = 1;
    cin >> t;
    // Comment out above if only 1 test case
    // t = 1;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " ms" << endl;
#endif
    return 0;
}