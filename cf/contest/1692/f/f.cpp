// divyanshmittal-exe  
// 14 06 2022
#pragma GCC optimize("Ofast,unroll-loops") 
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

#ifndef ONLINE_JUDGE
#define DEBUG fprintf(stderr, ">=>=TESTING>=>=\n")
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

    int n;
    cin >> n;

    // vi values(n);

    int values[10] = {0};

    for (int i = 0; i < n; i++)
    {
        // cin >> values[i];  
        int x;
        cin >> x; 
        values[x%10] ++ ;
    }

    if(((values[0] >= 2) &&(values[3] >= 1)) || ((values[0] >= 1) &&(values[1] >= 1) &&(values[2] >= 1)) || ((values[0] >= 1) &&(values[2] >= 1) &&(values[1] >= 1)) || ((values[0] >= 2) &&(values[3] >= 1)) || ((values[0] >= 1) &&(values[4] >= 1) &&(values[9] >= 1)) || ((values[0] >= 1) &&(values[5] >= 1) &&(values[8] >= 1)) || ((values[0] >= 1) &&(values[6] >= 1) &&(values[7] >= 1)) || ((values[0] >= 1) &&(values[7] >= 1) &&(values[6] >= 1)) || ((values[0] >= 1) &&(values[8] >= 1) &&(values[5] >= 1)) || ((values[0] >= 1) &&(values[9] >= 1) &&(values[4] >= 1)) || ((values[1] >= 1) &&(values[0] >= 1) &&(values[2] >= 1)) || ((values[1] >= 3)) || ((values[1] >= 1) &&(values[2] >= 1) &&(values[0] >= 1)) || ((values[1] >= 1) &&(values[3] >= 1) &&(values[9] >= 1)) || ((values[1] >= 1) &&(values[4] >= 1) &&(values[8] >= 1)) || ((values[1] >= 1) &&(values[5] >= 1) &&(values[7] >= 1)) || ((values[6] >= 2) &&(values[1] >= 1)) || ((values[1] >= 1) &&(values[7] >= 1) &&(values[5] >= 1)) || ((values[1] >= 1) &&(values[8] >= 1) &&(values[4] >= 1)) || ((values[1] >= 1) &&(values[9] >= 1) &&(values[3] >= 1)) || ((values[2] >= 1) &&(values[0] >= 1) &&(values[1] >= 1)) || ((values[2] >= 1) &&(values[1] >= 1) &&(values[0] >= 1)) || ((values[2] >= 2) &&(values[9] >= 1)) || ((values[2] >= 1) &&(values[3] >= 1) &&(values[8] >= 1)) || ((values[2] >= 1) &&(values[4] >= 1) &&(values[7] >= 1)) || ((values[2] >= 1) &&(values[5] >= 1) &&(values[6] >= 1)) || ((values[2] >= 1) &&(values[6] >= 1) &&(values[5] >= 1)) || ((values[2] >= 1) &&(values[7] >= 1) &&(values[4] >= 1)) || ((values[2] >= 1) &&(values[8] >= 1) &&(values[3] >= 1)) || ((values[2] >= 2) &&(values[9] >= 1)) || ((values[0] >= 2) &&(values[3] >= 1)) || ((values[3] >= 1) &&(values[1] >= 1) &&(values[9] >= 1)) || ((values[3] >= 1) &&(values[2] >= 1) &&(values[8] >= 1)) || ((values[3] >= 2) &&(values[7] >= 1)) || ((values[3] >= 1) &&(values[4] >= 1) &&(values[6] >= 1)) || ((values[5] >= 2) &&(values[3] >= 1)) || ((values[3] >= 1) &&(values[6] >= 1) &&(values[4] >= 1)) || ((values[3] >= 2) &&(values[7] >= 1)) || ((values[3] >= 1) &&(values[8] >= 1) &&(values[2] >= 1)) || ((values[3] >= 1) &&(values[9] >= 1) &&(values[1] >= 1)) || ((values[4] >= 1) &&(values[0] >= 1) &&(values[9] >= 1)) || ((values[4] >= 1) &&(values[1] >= 1) &&(values[8] >= 1)) || ((values[4] >= 1) &&(values[2] >= 1) &&(values[7] >= 1)) || ((values[4] >= 1) &&(values[3] >= 1) &&(values[6] >= 1)) || ((values[4] >= 2) &&(values[5] >= 1)) || ((values[4] >= 2) &&(values[5] >= 1)) || ((values[4] >= 1) &&(values[6] >= 1) &&(values[3] >= 1)) || ((values[4] >= 1) &&(values[7] >= 1) &&(values[2] >= 1)) || ((values[4] >= 1) &&(values[8] >= 1) &&(values[1] >= 1)) || ((values[4] >= 1) &&(values[9] >= 1) &&(values[0] >= 1)) || ((values[5] >= 1) &&(values[0] >= 1) &&(values[8] >= 1)) || ((values[5] >= 1) &&(values[1] >= 1) &&(values[7] >= 1)) || ((values[5] >= 1) &&(values[2] >= 1) &&(values[6] >= 1)) || ((values[5] >= 2) &&(values[3] >= 1)) || ((values[4] >= 2) &&(values[5] >= 1)) || ((values[5] >= 2) &&(values[3] >= 1)) || ((values[5] >= 1) &&(values[6] >= 1) &&(values[2] >= 1)) || ((values[5] >= 1) &&(values[7] >= 1) &&(values[1] >= 1)) || ((values[5] >= 1) &&(values[8] >= 1) &&(values[0] >= 1)) || ((values[9] >= 2) &&(values[5] >= 1)) || ((values[6] >= 1) &&(values[0] >= 1) &&(values[7] >= 1)) || ((values[6] >= 2) &&(values[1] >= 1)) || ((values[6] >= 1) &&(values[2] >= 1) &&(values[5] >= 1)) || ((values[6] >= 1) &&(values[3] >= 1) &&(values[4] >= 1)) || ((values[6] >= 1) &&(values[4] >= 1) &&(values[3] >= 1)) || ((values[6] >= 1) &&(values[5] >= 1) &&(values[2] >= 1)) || ((values[6] >= 2) &&(values[1] >= 1)) || ((values[6] >= 1) &&(values[7] >= 1) &&(values[0] >= 1)) || ((values[6] >= 1) &&(values[8] >= 1) &&(values[9] >= 1)) || ((values[6] >= 1) &&(values[9] >= 1) &&(values[8] >= 1)) || ((values[7] >= 1) &&(values[0] >= 1) &&(values[6] >= 1)) || ((values[7] >= 1) &&(values[1] >= 1) &&(values[5] >= 1)) || ((values[7] >= 1) &&(values[2] >= 1) &&(values[4] >= 1)) || ((values[3] >= 2) &&(values[7] >= 1)) || ((values[7] >= 1) &&(values[4] >= 1) &&(values[2] >= 1)) || ((values[7] >= 1) &&(values[5] >= 1) &&(values[1] >= 1)) || ((values[7] >= 1) &&(values[6] >= 1) &&(values[0] >= 1)) || ((values[7] >= 2) &&(values[9] >= 1)) || ((values[8] >= 2) &&(values[7] >= 1)) || ((values[7] >= 2) &&(values[9] >= 1)) || ((values[8] >= 1) &&(values[0] >= 1) &&(values[5] >= 1)) || ((values[8] >= 1) &&(values[1] >= 1) &&(values[4] >= 1)) || ((values[8] >= 1) &&(values[2] >= 1) &&(values[3] >= 1)) || ((values[8] >= 1) &&(values[3] >= 1) &&(values[2] >= 1)) || ((values[8] >= 1) &&(values[4] >= 1) &&(values[1] >= 1)) || ((values[8] >= 1) &&(values[5] >= 1) &&(values[0] >= 1)) || ((values[8] >= 1) &&(values[6] >= 1) &&(values[9] >= 1)) || ((values[8] >= 2) &&(values[7] >= 1)) || ((values[8] >= 2) &&(values[7] >= 1)) || ((values[8] >= 1) &&(values[9] >= 1) &&(values[6] >= 1)) || ((values[9] >= 1) &&(values[0] >= 1) &&(values[4] >= 1)) || ((values[9] >= 1) &&(values[1] >= 1) &&(values[3] >= 1)) || ((values[2] >= 2) &&(values[9] >= 1)) || ((values[9] >= 1) &&(values[3] >= 1) &&(values[1] >= 1)) || ((values[9] >= 1) &&(values[4] >= 1) &&(values[0] >= 1)) || ((values[9] >= 2) &&(values[5] >= 1)) || ((values[9] >= 1) &&(values[6] >= 1) &&(values[8] >= 1)) || ((values[7] >= 2) &&(values[9] >= 1)) || ((values[9] >= 1) &&(values[8] >= 1) &&(values[6] >= 1)) || ((values[9] >= 2) &&(values[5] >= 1))){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


    


    

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    // {
    //     for (int k = 0; k < 10; k++)
    // {

    //     if(i+j+k >= 13 || i+j+k >= 23||i+j+k >= 3){
    //         // cout << i << ", " << j << ", "  << k << endl;
    //         if(i >= j && j >= k){
    //             cout << " ((values[" << i << "] >= 3)) ||";
    //         }else if(i >= j){
    //             cout << " ((values[" << i << "] >= 2) &&" << "(values[" << k << "] >= 1)) ||";
    //         }else if(i >= k){
    //             cout << " ((values[" << i << "] >= 2) &&" << "(values[" << j << "] >= 1)) ||";
    //         }else if(k >= j){
    //             cout << " ((values[" << k << "] >= 2) &&" << "(values[" << i << "] >= 1)) ||";
    //         }else{
    //         cout << " ((values[" << i << "] >= 1) &&" << "(values[" << j << "] >= 1) &&" << "(values[" << k << "] >= 1)) ||";
    //              }

            
    //     }
    // }
    // }
    // }
    
 
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