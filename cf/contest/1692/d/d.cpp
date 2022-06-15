// divyanshmittal-exe  
// 14 06 2022
#pragma GCC optimize("Ofast,unroll-loops") 
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
 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 


void solve()
{

    char time[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> time[i];
    }
    int h = (time[0]-'0')*10 + (time[1]-'0');
    int m = (time[3]-'0')*10 + (time[4]-'0');
    int x;
    cin >> x;
    int count = 1440/(gcd(1440,x));


    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        if((h%10)*10 + (h/10)  == m){
            ++sum;
            // cout << h << " " << m << endl;
        }

        m += (x%60);
        h += ((x/60) + (m/60));
        h = h%24;
        m = m%60;

    }
    
    cout << sum << endl;

 
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