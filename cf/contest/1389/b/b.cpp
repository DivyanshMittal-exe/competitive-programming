// divyanshmittal-exe  
// 20 06 2022
#pragma GCC optimize("Ofast,unroll-loops") 
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(ii, c) for (__typeof((c).begin()) ii = (c).begin(); ii != (c).end(); ii++)
#define rtr(ii, c) for (__typeof((c).rbegin()) ii = (c).rbegin(); ii != (c).rend(); ii++)

#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define max3(A, B, C) max(max((A), (B)), (C))
#define max4(A, B, C, D) max(max((A), (B)), max((C), (D)))
#define min3(A, B, C) min(min((A), (B)), (C))
#define min4(A, B, C, D) min(min((A), (B)), min((C), (D)))

#define count_1(n) __builtin_popcountll(n)
#define fsb(index) (index & -index)

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;


#define maximum(a) max_element(a.begin(),a.end()) 
#define minimum(a) min_element(a.begin(),a.end()) 
#define all(a) (a).begin(), (a).end()

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
// const ll MAXN = 1e6;
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
 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 


void solve()
{

    int n,z,k;

    cin >> n >> k >> z;

    vl values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    
    ll ans = 0,sum=0,maxN =0;
    for (int i = 0; i <= z; i++)
    {
        ll pos = k-2*i;
        if(pos <0){
            continue;
        }

        maxN = 0;
        sum = 0;

        for (int j = 0; j <= pos; j++)
        {
            if (j < n - 1){
				maxN = maX(maxN, values[j] + values[j + 1]);
            }
			sum += values[j];
        }
        ans = maX(ans, sum + maxN * i);
        
    }
    
    cout << ans << endl;
 
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

// class SegTree
// {
// public:
//   SegTree *lchild,*rchild;
//   ll leftmost,rightmost;
//   ll gcd = 0;
 
//   SegTree(ll L,ll R,vector<ll> &v)
//   {
//     this->leftmost = L;
//     this->rightmost = R;
//     if(L == R)
//     {
//       gcd = v[L];
//       return;
//     }
//     ll mid = (L+R)/2;
//     lchild = new SegTree(L,mid,v);
//     rchild = new SegTree(mid+1,R,v);
//     calc();
//   }
 
//   void calc()
//   {
//     if(leftmost == rightmost)
//     {
//       return;
//     }
//     gcd = __gcd(lchild->gcd,rchild->gcd);
//   }
 
//   ll rangeGCD(ll L, ll R)
//   {
//     if(R < leftmost || L > rightmost)
//       return 0;
//     if(R >= rightmost && L <= leftmost)
//       return this->gcd;
    
//     return __gcd(lchild->rangeGCD(L,R),rchild->rangeGCD(L,R));
//   }
 
// };