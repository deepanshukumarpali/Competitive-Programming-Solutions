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
#define forRange(i,l,h) for(ll i=l;i<h;i++)
#define all(x) x.begin(),x.end()
#define append push_back


template<class T>
T GCD(T a,T b)
{
 if (b == 0)
     return a;
 return GCD(b, a % b);
   
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

void Value() {}
template <class T1, class... T2>
void Value(T1& var1, T2&... var2) { cin>>var1; Value(var2...); }

void print() {}
template <class T1, class... T2>
constexpr void print(const T1& var1, const T2& ... var2) { cout<<var1;ns; print(var2...); }


template<class T1,class T2>
void printM(map<T1,T2> a){forAuto(i,a){cout<<i.first<<" -> ";cout<<i.second; nl;}}

template<class T>
vector<T> Vinput(T n){ vector<T> a;forRange(i,0,n){T x;cin>>x;a.append(x);}return a;}

bool cmp(const ll &a, const ll &b)
{ return a<b; }


#define CPN 200005
//ll M=1000000007;
//const ll inf=1e18+5;


//----------------------------CODE----------------------------//
ll R,G,B;
Vll Rp,Gp,Bp;
ll dp[205][205][205];

ll Answer(ll r,ll g,ll b)
{
    
    if(dp[r][g][b]!=-1) return dp[r][g][b];
    
    ll ans=0;
    
    if(r<R and g<G)
        ans=max(ans, Rp[r]*Gp[g] + Answer(r+1,g+1,b));
    
    if(r<R and b<B)
        ans=max(ans, Rp[r]*Bp[b] + Answer(r+1,g,b+1));
    
    if(b<B and g<G)
        ans=max(ans, Gp[g]*Bp[b] + Answer(r,g+1,b+1));
    
    return dp[r][g][b]=ans;
    
}


void code()
{
    memset(dp,-1,sizeof(dp));
    cin>>R>>G>>B;
    Rp=Vinput(R);
    Gp=Vinput(G);
    Bp=Vinput(B);
    
    sort(all(Rp),greater<ll>());
    sort(all(Gp),greater<ll>());
    sort(all(Bp),greater<ll>());
           
    print(Answer(0,0,0));
    
    
}








//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
    vsInput();
//    cin>>t;
//    cin.ignore();
//    cout << fixed << setprecision(6);

 
    forRange(c,1,t+1)
    {
//        cout<<"Case #"<<c<<':';nl;
        code();
    }

 return 0;
}
