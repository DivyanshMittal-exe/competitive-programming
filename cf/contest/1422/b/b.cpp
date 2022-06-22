#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll mincost(ll a, ll b, ll c){


    ll result=a;
    ll cost=abs(a-b)+abs(a-c);

    if(abs(a-b)+abs(b-c) < cost){
        cost = abs(a-b)+abs(b-c);
        result=b;
    }

    if(abs(c-b)+abs(a-c) < cost){
        cost = abs(c-b)+abs(a-c);
        result=c;
    }

    return result;
}


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll A[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> A[i][j];
            }
        }

        ll res=0;


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pair<ll,ll> p1={i,(m-1)-j}, p2={(n-1)-i,j};
                ll tempvalue=A[i][j], tempcost=0;



                if(i==p1.first && j==p1.second && i==p2.first && j==p2.second){

                }
                else if(i==p1.first && j==p1.second){
                    res+=abs(A[i][j] - A[p2.first][p2.second]);
                    A[i][j]=A[p2.first][p2.second];
                }
                else if(i==p2.first && j==p2.second){
                    res+=abs(A[i][j] - A[p1.first][p1.second]);
                    A[i][j]=A[p1.first][p1.second];
                }
                else{
                    ll temp=mincost(A[i][j], A[p1.first][p1.second], A[p2.first][p2.second]);
                    res += abs(A[i][j]-temp) + abs(A[p1.first][p1.second]-temp) + abs(A[p2.first][p2.second]-temp);
                    A[i][j]=temp;
                    A[p1.first][p1.second]=temp;
                    A[p2.first][p2.second]=temp;
                }
            }
        }


        cout << res << endl;


    }


  

    return 0;
}
