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
const ll inf=1e18+5;


 //----------------------------CODE----------------------------//
ll n;
bool like[7][7];
Vll set1,set2,set3;
string node[]={"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
map<string,ll>ID;
ll expe[3];

ll maxDif=inf;
ll maxFriends=0;

void Answer(ll cur=0)
{
    if(cur==7)
    {
        if(set1.size()==0 or set2.size()==0 or set3.size()==0) return;
        
        ll d1,d2,d3,d;
        d1=expe[0]/set1.size();
        d2=expe[1]/set2.size();
        d3=expe[2]/set3.size();
        d=max({d1,d2,d3})-min({d1,d2,d3});
        
        ll friends=0;
        
        forAuto(i,set1)
        forAuto(j,set1)
        friends+=like[i][j];
        
        forAuto(i,set2)
        forAuto(j,set2)
        friends+=like[i][j];
        
        forAuto(i,set3)
        forAuto(j,set3)
        friends+=like[i][j];
        
//        printC(set1);
//        printC(set2);
//        printC(set3);
//        print(d,friends);nl;nl;
        
        if(d<maxDif)
            maxDif=d,maxFriends=friends;
        else if(d==maxDif)
            maxFriends=max(maxFriends,friends);
        
        return;
        
    }
    
    set1.append(cur);
    Answer(cur+1);
    set1.pop_back();
    
    set2.append(cur);
    Answer(cur+1);
    set2.pop_back();
    
    set3.append(cur);
    Answer(cur+1);
    set3.pop_back();
    
    
}

void code()
{
    cin>>n;
    memset(like,false,sizeof(like));
    
    forRange(i,0,7)
    ID[node[i]]=i;
    
    forRange(i,0,n)
    {
        string u,_,v;
        cin>>u>>_>>v;
        like[ID[u]][ID[v]]=true;
    }
    
    cin>>expe[0]>>expe[1]>>expe[2];
    
    
    Answer();
    print(maxDif,maxFriends);
    
    
}










 //--------------------------------END-----------------------------//
 int main()
 {
     fast;
     ll t=1;
     
    //  vsInput();
//     cout << fixed << setprecision(6);
//     cin>>t;

     
     forRange(c,1,t+1) {
//         cout<<"Case #"<<c<<':';ns;
         code();
     }

     return 0;
 }
