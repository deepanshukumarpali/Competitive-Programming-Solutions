#include<bits/stdc++.h>
//typedef long long int ll;
using namespace std;
using ll = long long int;
using ld = long double;
using Vc = vector <char>;
using Vs = vector <string>;
using Vll = vector <ll>;
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


#define CPN 5000005
//ll M=1000000007;
//const ll inf=1e9+7;


//----------------------------CODE----------------------------/
ll n,m,q;
ll st[CPN],a[CPN],lazy[CPN];


void LAZY(ll l,ll r,ll cur)
{
    if(lazy[cur]==2)
    {
        st[cur]=(r-l+1)-st[cur];
        if(l!=r)
        {
            if(lazy[2*cur+1]==2) lazy[2*cur+1]=0;
            else if(lazy[2*cur+1]==0) lazy[2*cur+1]=2;
            else lazy[2*cur+1]*=-1;
            
            if(lazy[2*cur+2]==2) lazy[2*cur+2]=0;
            else if(lazy[2*cur+2]==0) lazy[2*cur+2]=2;
            else lazy[2*cur+2]*=-1;
         }
    }
    else if(lazy[cur]==1)
    {
        st[cur]=r-l+1;
        if(l!=r)
        {
            lazy[2*cur+1]=1;
            lazy[2*cur+2]=1;
        }
    }
    else if(lazy[cur]==-1)
    {
        st[cur]=0;
        if(l!=r)
        {
            lazy[2*cur+1]=-1;
            lazy[2*cur+2]=-1;
        }
    }
    
    lazy[cur]=0;
    
}

ll Construct(ll l,ll r,ll cur=0)
{
    if(l==r)
        return st[cur]=a[l];
    
    ll m=l+(r-l)/2;
    return st[cur]=Construct(l,m,2*cur+1)+Construct(m+1,r,2*cur+2);
}

ll Get(ll left,ll right,ll l,ll r,ll cur=0)
{

    LAZY(l,r,cur);
    
    if(left>r or right<l) return 0;
    if(left<=l and right>=r) return st[cur];
    
    ll m=l+(r-l)/2;
    return Get(left,right,l,m,2*cur+1)+Get(left,right,m+1,r,2*cur+2);
}

void Update(ll left,ll right,ll type,ll l,ll r,ll cur)
{
    LAZY(l,r,cur);
    if(left>r or right<l) return;
    
    if(l>=left and r<=right)
    {
        lazy[cur]=type;
        LAZY(l,r,cur);
        return;
    }
    
    ll m=l+(r-l)/2;
    Update(left,right,type,l,m,2*cur+1);
    Update(left,right,type,m+1,r,2*cur+2);
    st[cur]=st[2*cur+1]+st[2*cur+2];
    
}



void code()
{
    
    memset(st,0,sizeof(st));
    memset(lazy,0,sizeof(lazy));
    memset(a,0,sizeof(a));
    
    cin>>n;
    ll ind=0,l,r,type;
    char t;
    
    forRange(i,0,n)
    {
        string s;
        cin>>m>>s;
        forRange(_,0,m)
        forRange(j,0,s.size())
        a[ind++]=s[j]-48;
    }
    n=ind;
    Construct(0,n-1,0);
    
//    forRange(i,0,ind)
//    print(a[i]);nl;
//    forRange(i,0,50)
//    print(st[i]);nl;
    
    
    cin>>q;
    ll Q=1;
    forRange(_,0,q)
    {
        cin>>t>>l>>r;
        
        if(t=='S')
        {
            cout<<"Q"<<Q++<<":";ns;
            cout<<Get(l,r,0,n-1,0);
            nl;
        }
        else
        {
            if(t=='F') type=1;
            else if(t=='E') type=-1;
            else type=2;

            Update(l,r,type,0,n-1,0);
        }
    }
}
    











//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
      //vsInput();
    cin>>t;
//    clock_t tot = clock();
//    cin.ignore();
//    cout << fixed << setprecision(12);

 
    forRange(c,1,t+1)
    {
        cout<<"Case "<<c<<':';nl;
        code();
    }
    
    
//    nl;nl;print("Total Time:", (double)(clock()-tot)/CLOCKS_PER_SEC);nl;
    return 0;
}

//  CHECK BEFORE YOU SUBMIT !!!!

//  1) Integer overflow? Any maths computaion? MinMax ?
//  2) RTE? Pointer? Erase? Find?
//  3) Precision?
//  4) Use inf(1e18) not LONG_MAX
//  5) Dont't use both scanf and cin
