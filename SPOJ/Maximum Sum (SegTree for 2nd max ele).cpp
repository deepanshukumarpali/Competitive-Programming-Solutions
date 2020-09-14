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


#define CPN 1000005
//ll M=1000000007;
const ll inf=1e18;


//----------------------------CODE----------------------------/
ll n,k;
Pllll st[CPN];
ll a[CPN];


void Construct(ll l,ll r,ll cur=0)
{
    if(l==r)
    {
        st[cur]={a[l],-1};
        return;
    }
    
    ll m=l+(r-l)/2;
    Construct(l,m,2*cur+1);
    Construct(m+1,r,2*cur+2);
    
    Vll temp={st[2*cur+1].first,st[2*cur+1].second,st[2*cur+2].first,st[2*cur+2].second};
    sort(all(temp));
    st[cur].first=temp[3];
    st[cur].second=temp[2];
}

Pllll Get(ll left,ll right,ll l,ll r,ll cur=0)
{

    if(left>r or right<l) return {-1,-1};
    if(left<=l and right>=r) return st[cur];
    
    ll m=l+(r-l)/2;
    Pllll a=Get(left,right,l,m,2*cur+1),b=Get(left,right,m+1,r,2*cur+2);
    
    Vll temp={a.first,a.second,b.first,b.second};
    sort(all(temp));
    
    return {temp[3],temp[2]};
    
}

void update(ll ind ,ll l,ll r,ll cur=0)
{
    if(ind<l or ind>r) return;
    if(l==r)
    {
        st[cur]={a[l],-1};
        return;
    }
    
    ll m=l+(r-l)/2;
    update(ind,l,m,2*cur+1);
    update(ind,m+1,r,2*cur+2);
    
    Vll temp={st[2*cur+1].first,st[2*cur+1].second,st[2*cur+2].first,st[2*cur+2].second};
    sort(all(temp));
    st[cur].first=temp[3];
    st[cur].second=temp[2];
    
}


void code()
{
    cin>>n;
    forRange(i,0,n) cin>>a[i];
    cin>>k;
    
    char t;
    ll l,r;
    
    Construct(0,n-1,0);
    
    forRange(_,0,k)
    {
        cin>>t>>l>>r;
        l--;
        r--;
        
        if(t=='Q')
        {
            Pllll ans=Get(l,r,0,n-1,0);
            
//            printP(ans);nl;
            print(ans.first+ans.second);nl;
        }
        else
        {
            a[l]=r+1;
            update(l,0,n-1,0);
        }
    }
    
    
    

}
    











//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
      //vsInput();
//    cin>>t;
//    clock_t tot = clock();
//    cin.ignore();
//    cout << fixed << setprecision(12);

 
    forRange(c,1,t+1)
    {
//        cout<<"Case "<<c<<':';nl;
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
