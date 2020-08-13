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
 
 Vll Vinput(ll n){Vll a;forRange(i,0,n){ll x;cin>>x;a.append(x);}return a;}
 
 bool cmp(const ll &a, const ll &b)
 { return a<b; }
 
 
 #define CPN 200005
 ll M=1000000007;
 const int inf=1e18+5;
 
 
 //----------------------------CODE----------------------------//
int r,c,Sx,Sy,Dx,Dy;
Vs adj;
int dist[30][30];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
#define TP pair<int,Pii>
 
 
int DJ()
{
    priority_queue<TP,vector<TP>,greater<TP>> qu;
    
    forRange(i,0,r)
    forRange(j,0,c)
    dist[i][j]=inf;
    
    dist[Sx][Sy]=0;
    
    qu.push({0,{Sx,Sy}});
    
    while(not qu.empty())
    {
        int x=qu.top().second.first,y=qu.top().second.second;
        qu.pop();
        
//        print(x,y,dist[x][y]);nl;
        
        if(x==Dx and y==Dy)
            return dist[x][y];
        
        forRange(i,0,4)
        {
            int x1=x+dx[i], y1=y+dy[i];
            
            if(x1>=0 and y1>=0 and x1<r and y1<c and adj[x1][y1]!='X' and dist[x1][y1]>dist[x][y]+(adj[x1][y1]-48))
            {
                dist[x1][y1]=dist[x][y]+(adj[x1][y1]-48);
                qu.push({dist[x1][y1],{x1,y1}});
            }
        }
        
    }
    return 0;
}
 
void code()
{
    while(true)
    {
        cin>>c>>r;
        if(r==0 or c==0)
            return;
        
        forRange(i,0,r)
        {
            string s;cin>>s;
            adj.append(s);
            
            forRange(j,0,c)
            {
                if(s[j]=='S')
                {
                    Sx=i;
                    Sy=j;
                }
                if(s[j]=='D')
                {
                    adj[i][j]='0';
                    Dx=i;
                    Dy=j;
                }
            }
            
        }
        
        cout<<DJ()<<endl;
        adj.clear();
    }
    
    
    
    
    
 
}
 
 
 
 
 
 
 
 
 
 //--------------------------------END-----------------------------//
 int main()
 {
     fast;
     ll t=1;
     
     //vsInput();
     //cout << fixed << setprecision(6);
     //cin>>t;
     
     forRange(c,1,t+1) {
//         cout<<"Case #"<<c<<':';ns;
         code();
     }
 
     return 0;
 }
 
