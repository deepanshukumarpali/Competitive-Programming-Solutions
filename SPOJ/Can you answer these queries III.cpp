#include<bits/stdc++.h>
//typedef long long int ll;
using namespace std;
using ll = int;
using ld = long double;
using Vc = vector <char>;
using Vs = vector <string>;
using Vll = vector <ll>;
using VVll = vector<vector<ll>>;
using Vld = vector <ld>;
using Vi = vector <int>;
using Sll = set <ll>;
using Sld = set <ld>;
using Ss = set <string>;
using Sc = set <char>;
using Si = set <int>;
using MiVi = map<int,Vi>;
using MllVll = map<ll,Vll>;
using UMllVll = unordered_map<ll,Vll>;
using Mllll = map<ll,ll>;
using UMllll = unordered_map<ll,ll>;
using Mii = map<int,int>;
using MllSll = map<ll,Sll>;
using UMllSll = unordered_map<ll,Sll>;
using Mlls = map<ll,string>;
using Pllll = pair<ll,ll>;
using Pii = pair<int,int>;
using SPllll = set<Pllll>;
 
#define nl cout<<endl
#define ns cout<<" "
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
#define forAuto(i,x) for(auto i: x)
#define forRange(i,l,h) for(ll i=l;i<h;i++)
#define all(x) x.begin(),x.end()
#define append push_back
#define mp make_pair
 
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
 
 
#define CPN 500005
//ll M=100000007;
//const ll inf=1e18;
 
//----------------------------CODE----------------------------/
struct ret
{
    ll st,pref,suf,tot;
};

ll n,q;
ll a[CPN];
ret st[CPN];

ret help(ret op1,ret op2)
{
    ret ans;
    ans.st=max({op1.st,op2.st,op2.pref+op1.suf});
    
    ans.pref=max(op1.pref,op1.tot+op2.pref);
    ans.suf=max(op2.suf,op2.tot+op1.suf);
    ans.tot=op1.tot+op2.tot;
    return ans;
}
 
void Construct(ll l,ll r,ll cur)
{
    if(l==r)
    {
        st[cur].st=a[l];
        st[cur].pref=a[l];
        st[cur].suf=a[l];
        st[cur].tot=a[l];
        return;
    }
    
    ll m=l+(r-l)/2;
    Construct(l,m,2*cur+1);
    Construct(m+1,r,2*cur+2);
    
    st[cur]=help(st[2*cur+1],st[2*cur+2]);
}

void Update(ll ind,ll l,ll r,ll cur)
{
    if(ind<l or ind>r) return;
    if(l==r)
    {
        st[cur].st=a[l];
        st[cur].pref=a[l];
        st[cur].suf=a[l];
        st[cur].tot=a[l];
        return;
    }
    
    ll m=l+(r-l)/2;
    Update(ind,l,m,2*cur+1);
    Update(ind,m+1,r,2*cur+2);
    
    st[cur]=help(st[2*cur+1],st[2*cur+2]);
}

ret Get(ll l1,ll r1,ll l,ll r,ll cur)
{

    if(l1>r or r1<l) return {INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    if(l>=l1 and r<=r1) return st[cur];
    
    ll m=l+(r-l)/2;
    
    if(r1<=m) return Get(l1,r1,l,m,2*cur+1);
    else if(l1>m) return Get(l1,r1,m+1,r,2*cur+2);

    
    return help(Get(l1,r1,l,m,2*cur+1),Get(l1,r1,m+1,r,2*cur+2));
}
 
 
void code()
{
    
//    cin>>n;
    scanf("%d",&n);
    
    forRange(i,0,n) scanf("%d",&a[i]);//cin>>a[i];
    Construct(0,n-1,0);
    
//    cin>>q;
    scanf("%d",&q);
    forRange(_,0,q)
    {
        ll t,x,y;
        
//        cin>>x>>y;
        scanf("%d%d%d",&t,&x,&y);
        if(not t)
        {
            a[x-1]=y;
            Update(x-1,0,n-1,0);
        }
        else printf("%d\n",Get(x-1,y-1,0,n-1,0).st);
//        nl;
    }
    
    
    
    
}
  

 
 
 
 
 
 
 
 
//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
    //vsInput();
//    clock_t tot = clock();
//    cin>>t;
//    cin.ignore();
//    cout << fixed << setprecision(2);
 
 
    forRange(c,1,t+1)
    {
//        cout<<"Case "<<c<<':';ns;
        code();
    }
    
    
//    cerr<<"Total Time: "<<(double)(clock()-tot)/CLOCKS_PER_SEC<<endl;
    return 0;
}
 
//  CHECK BEFORE YOU SUBMIT !!!!
 
//  1) Integer overflow? Any maths computaion? MinMax ?
//  2) RTE? Pointer? Erase? Find?
//  3) Precision?
//  4) Use inf(1e18) not LONG_MAX
//  5) Dont't use both scanf and cin
//  6) Use UMll not Mll
