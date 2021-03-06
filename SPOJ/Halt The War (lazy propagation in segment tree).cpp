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


#define CPN 500005
//ll M=1000000007;
//const ll inf=1e18;


//----------------------------CODE----------------------------/
ll n,k;
Vll a;
ll st[CPN],lazy[CPN];


ll Get(ll start,ll end,ll l=0,ll r=n-1,ll cur=0)
{
    if(lazy[cur]!=0)
    {
        st[cur]+=(r-l+1)*lazy[cur];
        if(l!=r)
        {
            lazy[2*cur+1]+=lazy[cur];
            lazy[2*cur+2]+=lazy[cur];
        }
        lazy[cur]=0;
    }
    
    
    
    if(end<l or start>r) return 0;
    if(l>=start and r<=end) return st[cur];
    
    ll m=l+(r-l)/2;
    return Get(start,end,l,m,2*cur+1) + Get(start,end,m+1,r,2*cur+2);
    
}


void Update(ll ind_l,ll ind_r,ll l=0,ll r=n-1,ll cur=0)
{
    
    // PERFORM PENDING UPDATES ----------------------------------/
    
    if(lazy[cur]!=0)
    {
        st[cur]+=(r-l+1)*lazy[cur];
        if(l!=r)
        {
            lazy[2*cur+1]+=lazy[cur];
            lazy[2*cur+2]+=lazy[cur];
        }
        lazy[cur]=0;
    }
    
    if(ind_r<l or ind_l>r) return;
    
    // IF CURRENT TREE RANGE IS WITHIN GIVEN RANGE -------------/
    
    if(l>=ind_l and r<=ind_r)
    {
        st[cur]+=(r-l+1);
        if(l!=r)
        {
            lazy[2*cur+1]++;
            lazy[2*cur+2]++;
        }
        return;
    }
    
    // IF OVERLAPING ------------------------------------------/
    
    ll m=l+(r-l)/2;
    Update(ind_l,ind_r,l,m,2*cur+1);
    Update(ind_l,ind_r,m+1,r,2*cur+2);
    
    st[cur]=st[2*cur+1]+st[2*cur+2];
}



void code()
{
    ll t;scanf("%lld" , &t);
    forRange(Case,1,t+1)
    {
        printf("Scenario #%lld:\n",Case);
        memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
        a.clear();
        
        scanf("%lld %lld",&n,&k);
        char op[15];ll l,r;
        
        forRange(_,0,k)
        {
            scanf("%s",op);
            scanf("%lld %lld",&l,&r);
            l--;
            r--;
            
            
            if(op[0]=='m')
            {
                Update(l,r);
                printf("OK\n");
            }
            else
            {
                ll ans=Get(l,r);
                printf("%lld\n",ans);
            }
        }

    }
}
    











//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
    vsInput();
//    cin>>t;
//    clock_t tot = clock();
//    cin.ignore();
//    cout << fixed << setprecision(12);

 
    forRange(c,1,t+1)
    {
//        cout<<"Case #"<<c<<':';ns;
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
