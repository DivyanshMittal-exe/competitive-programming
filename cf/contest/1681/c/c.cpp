// divyanshmittal-exe  
// 18 06 2022
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
template <class T> void swaP(T &a, T &b){ T temp = a; a = b; b = temp; }

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 


// debugging
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) {
    return os << "(" << p.first << ": " << p.second << ")";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) {
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++) {
        if(!first) os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) {
    bool first = true;
    os << "{";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
    bool first = true;
    os << "{";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "}";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v) {
    return os << std::set<T>(v.begin(), v.end());
}
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v) {
    return os << std::map<T1, T2>(v.begin(), v.end());
}


void solve()
{
    int count;
    cin >> count;
    vector<pair<ll,ll>> values(count);

    for (int i = 0; i < count; i++)
    {
        cin >> values[i].first;
    }
    
    for (int i = 0; i < count; i++)
    {
        cin >> values[i].second;
    }

    vector<pair<ll,ll>> vold(values) ;
    vector<pair<ll,ll>> values2(values) ;
    
    // cout << values;
    sort(all(values),[](const pll& a,const pll& b)-> bool {
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
        } );
    // sort(all(values2),[](const pll& a,const pll& b)-> bool {return  a.second < b.second;} );
    // cout << values;
    // cout << values2;


    for (int i = 0; i < count-1; i++)
    {
        if(values[i].second > values[i+1].second){
            cout << "-1" << endl;
            return;
        }
    }

    // for (int i = 0; i < count-1; i++)
    // {
    //     if(values2[i].first > values2[i+1].first){
    //         cout << "-1" << endl;
    //         return;
    //     }
    // }

    int swc = 0;
    vector<pair<ll,ll>> swaps;

    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (vold[j].first < vold[i].first){
                swaps.push_back({i,j});
                swaP(vold[j],vold[i]);
            }else

            if(vold[j].first == vold[i].first && vold[j].second < vold[i].second){
                swaps.push_back({i,j});
                swaP(vold[j],vold[i]);
            }
        }
        
    }
    
    cout << swaps.size() << endl;
    tr(ii,swaps){
        cout << ii -> second + 1 << " " << ii-> first + 1 << endl;
    }

    

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