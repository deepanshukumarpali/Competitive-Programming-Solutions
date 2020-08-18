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


#define CPN 100005
//ll M=1000000007;
//const ll inf=1e18+5;


//----------------------------CODE----------------------------/

struct circle{ld x,y,r;};
struct point{ld x,y;};
vector<point> alien;
vector<point>r;


ld dist(point p1,point p2)
{
    ld d=sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    return d;
}

bool isInside(circle c,point p)
{
    return (c.x-p.x)*(c.x-p.x) + (c.y-p.y)*(c.y-p.y) <= c.r*c.r;
}

point get_circle_center(ld bx, ld by,ld cx, ld cy)
{
    ld B = bx * bx + by * by;
    ld C = cx * cx + cy * cy;
    ld D = bx * cy - by * cx;
    return { (cy * B - by * C) / (2 * D),(bx * C - cx * B) / (2 * D) };
}


circle circleWith(point p1,point p2,point p3)
{
    point C = get_circle_center(p2.x - p1.x, p2.y - p1.y,p3.x - p1.x, p3.y - p1.y);
    
    C.x+=p1.x;
    C.y+=p2.y;
    return {C.x,C.y,dist(C,p1)};
}

circle circleWith(point p1,point p2)
{
    ld x,y,r;
    x=(p1.x+p2.x)/2.0;
    y=(p1.y+p2.y)/2.0;
    r=dist({x,y},p1);
    
    return {x,y,r};
}




circle MEC(ll cur, ll rs)
{
    
    if(rs==3)
        return circleWith(r[0],r[1],r[2]);
    else if(cur==0 and rs==2)
        return circleWith(r[0],r[1]);
    else if(cur==0)
    {
        if(rs==0) return {0,0,0};
        return {r[0].x,r[0].y,0};
    }
    
    
    
    circle c=MEC(cur-1,rs);
    
    if(isInside(c,alien[cur-1]))
        return c;
    
    r.append(alien[cur-1]);
    return MEC(cur-1,rs+1);
}


void code()
{
    ll n;
    cin>>n;
    
    forRange(i,0,n)
    {
        ld x,y;
        cin>>x>>y;
        alien.append({x,y});
    }
    
    circle ans=MEC(n,0);
    
    print(ans.x,ans.y,ans.r);
    nl;
    
}










//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
    vsInput();
    cin>>t;
//    cin.ignore();
//    cout << fixed << setprecision(12);

 
    forRange(c,1,t+1)
    {
//        cout<<"Case "<<c<<':';ns;
        code();
    }

 return 0;
}
