#include<bits/stdc++.h>
//typedef long long int ll;
using namespace std;
using ll = long long;
using ld = long double;
using Vc = vector <char>;
using Vs = vector <string>;
using Vll = vector <ll>;
using Vi = vector <int>;
using Sll = set <ll>;
using Ss = set <string>;
using Sc = set <char>;
using Si = set <int>;
using MiVi = map<int,Vi>;
using MllVll = map<ll,Vll>;
using Mllll = map<ll,ll>;
using Mii = map<int,int>;
using MllSll = map<ll,Sll>;
using Mlls = map<ll,string>;
using Pllll = pair<ll,ll>;
using Pii = pair<int,int>;
 
 
#define nl cout<<endl
#define ns cout<<" "
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
#define forAuto(i,x) for(auto i: x)
#define forRange(i,l,h) for(int i=l;i<h;i++)
#define all(x) x.begin(),x.end()
#define append push_back
 
 
template<class T>
T gcd(T a,T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}
ll bigmod(ll a, ll b, ll c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        ll x=bigmod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * bigmod(a,b-1,c))%c;
}
 
void vsInput()
{
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
}
template<class T1,class T2>
T2 sum(T1 a,T2 ans){ans=0;forAuto(i,a)ans+=i;return ans;}
template<class T>
void printC(T a){forAuto(i,a)cout<<i<<" ";cout<<endl;}
template<class T1,class T2>
void printP(pair<T1,T2> i){cout<<"{"<<i.first<<",";cout<<i.second<<"} ";}
template<class T1,class T2>
void printG(map<T1,T2> a){forAuto(i,a){cout<<i.first<<" -> ";printC(i.second);}}
template<class T1,class T2>
void printWG(map<T1,T2> a){forAuto(i,a){cout<<i.first<<" -> ";forAuto(j,i.second)printP(j);nl;}}
 
 
template<class T1,class T2>
void printM(map<T1,T2> a){forAuto(i,a){cout<<i.first<<" -> ";cout<<i.second; nl;}}
 
Vll Vinput(ll n){Vll a;forRange(i,0,n){ll x;cin>>x;a.append(x);}return a;}
 
bool cmp(const ll &a, const ll &b)
{ return a<b; }
 
 
#define CPN 700007
#define M 1000000007
const int inf=1e18+5;
 
 
//----------------------------CODE----------------------------//
int r,c;
char adj[200][200];
int ans[200][200];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
 
priority_queue< pair<int,Pii>, vector<pair<int,Pii> > , greater<pair<int, Pii>> > qu;
 
 
 
 
void DJ()
{
   while(not qu.empty())
   {
       int x=qu.top().second.first,y=qu.top().second.second;
       qu.pop();
       
       //printP(qu.top().second);nl;
       
       forRange(i,0,4)
       {
           int new_x=x+dx[i],new_y=y+dy[i];
           
           if(new_x>=0 and new_y>=0 and new_x<r and new_y<c)
           {
               if(ans[new_x][new_y]> ans[x][y]+1)
               {
                   ans[new_x][new_y]=ans[x][y]+1;
                   qu.push({ans[new_x][new_y],{new_x,new_y}});
               }
           }
       }
   }
    
}
 
 
 
 
 
 
void code()
{
    cin>>r>>c;
    
    forRange(i,0,r)
    forRange(j,0,c)
    {
        cin>>adj[i][j];
        ans[i][j]=inf;
    }
    forRange(i,0,r)
    forRange(j,0,c)
    if(adj[i][j]=='1')
    {
        qu.push({0,{i,j}});
        ans[i][j]=0;
    }
    
    DJ();
    
    forRange(i,0,r)
    {
        forRange(j,0,c)
        cout<<ans[i][j]<<" ";
        nl;
    }
    
}
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
    //vsInput();
    
    
    //cout << fixed << setprecision(10);
    cin>>t;
    
    
    while(t) {
        t--;
        code();
    }
 
    return 0;
}
 
