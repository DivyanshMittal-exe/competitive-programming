#include<bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> mutli_ordered_set;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define GO ll t; cin>>t; for(int i = 1 ; i <= t ;i++)
#define mod  1000000007
#define fore(p) for(auto& x:p)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(), x.rend()
#define F first
#define S second
class SegTree
{
public:
  SegTree *lchild,*rchild;
  ll leftmost,rightmost;
  ll gcd = 0;

  SegTree(ll L,ll R,vector<ll> &v)
  {
    this->leftmost = L;
    this->rightmost = R;
    if(L == R)
    {
      gcd = v[L];
      return;
    }
    ll mid = (L+R)/2;
    lchild = new SegTree(L,mid,v);
    rchild = new SegTree(mid+1,R,v);
    calc();
  }

  void calc()
  {
    if(leftmost == rightmost)
    {
      return;
    }
    gcd = __gcd(lchild->gcd,rchild->gcd);
  }

  ll rangeGCD(ll L, ll R)
  {
    if(R < leftmost || L > rightmost)
      return 0;
    if(R >= rightmost && L <= leftmost)
      return this->gcd;
    
    return __gcd(lchild->rangeGCD(L,R),rchild->rangeGCD(L,R));
  }

};

void Solve()
{
  ll i,j,l,n,m,k;
  cin >> n;
  vector<ll> v(n);
  fore(v)
    cin >> x;

  vector<ll> temp;
  for(i = 0 ; i < n-1 ;i++)
  {
    temp.push_back(abs(v[i+1]-v[i]));
  }
  // fore(temp)
  //   cerr << x << " ";
  // cerr << "\n";
  temp.push_back(0);
  SegTree st(0LL,n-1,temp);
  ll ans = 1;


  for(i = 0 ; i< n ; i++)
  {
    ll L = i;
    ll R = n-1;
    while(L < R)
    {
      ll mid = (L+R)/2;
      if(st.rangeGCD(i,mid) > 1)
      {
        L = mid+1;
      }
      else
        R = mid;
    }
    ans = max(ans,L-i+1);
  }

  cout << ans << "\n";
}
int main() 
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cout.precision(10);

   GO
   {     
    Solve();
   }

 return 0;
}