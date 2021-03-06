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
ll M=1000000007;
//const ll inf=1e18+5;


//----------------------------CODE----------------------------//
int A,B,C;
set<Pii>vis,nodes;

int Answer()
{
    int a,b,new_a,new_b;
    int steps=0;
    
    queue<Pii>qu;
    qu.push({0,0});
    vis.insert({0,0});
    
    while(not qu.empty())
    {
        int len=qu.size();
        forRange(i,0,len)
        {
            nodes.clear();
            a=qu.front().first;
            b=qu.front().second;
            qu.pop();
            
            if(a==C or b==C) return steps;
            
            // Fill A
            new_a=A;
            new_b=b;
            nodes.insert({new_a,new_b});
            
            // Fill B
            new_a=a;
            new_b=B;
            nodes.insert({new_a,new_b});
            
            // Empty A
            new_a=0;
            new_b=b;
            nodes.insert({new_a,new_b});
            
            // Empty B
            new_a=a;
            new_b=0;
            nodes.insert({new_a,new_b});
            
            // A to B
            new_b=min(B,b+a);
            new_a=a-(new_b-b);
            nodes.insert({new_a,new_b});
            
            // B to A
            new_a=min(A,b+a);
            new_b=b-(new_a-a);
            nodes.insert({new_a,new_b});
            
            forAuto(i,nodes)
            {
//                printP(i);
                if(vis.find(i)==vis.end())
                {
                    qu.push(i);
                    vis.insert(i);
                }
            }
            
            
        }
        steps+=1;
    }
    return -1;
}



void code()
{
    vis.clear();
    cin>>A>>B>>C;
    
    if(C>A && C>B)
        cout<<-1<<endl;
    else
        cout<<Answer()<<endl;
}










//--------------------------------END-----------------------------//
int main()
{
    fast;
    ll t=1;
 
//    vsInput();
    cin>>t;
//    cin.ignore();
//    cout << fixed << setprecision(6);

 
    forRange(c,1,t+1)
    {
//        cout<<"Case #"<<c<<':';nl;
        code();
    }

 return 0;
}
