#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;


#define all(v) v.begin(), v.end()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve(int cc)
{
    ll n,k;
    cin>>n>>k;

    vl a(n);

    ll sm = 0;

    for(ll &i:a){
        cin>>i;
        sm+=i;
    }
    
    if(k==1){
        cout<<sm<<'\n';
        return;
    }

    multiset<ll>st;
    multiset<ll>waste;

    for(ll i:a){
        st.insert(i);
    }

    ll cost = 0;

    while(st.size()>1){
        ll back = *st.rbegin();
        ll s_front = (*(st.begin()++));
        ll front = *st.begin();
        // factors of k between back+front and back+s_back
        ll mn = (front+s_front+k-1)/k;
        ll mx = (front+back)/k;

        mn*=k;
        mx*=k;
        bool found = false;
        st.erase(st.begin());

        for(ll i=mn;i<=mx;i+=k){
            if(st.find(i-front)!=st.end()){
                found = true;
                cost+=(i/k);
                st.erase(st.find(i-front));
                break;
            }
        }
        if(!found){
            waste.insert(front);
        }
    }


    while(st.size()>0){
        waste.insert(*st.begin());
        st.erase(st.begin());
    }
        
    assert(waste.size()%2==0);

    // debug(cost);
    // debug(waste);

    while(waste.size()>0){
       ll back = *waste.rbegin();
       waste.erase(--waste.end());
       ll nxt = (back+k-1)/k;
       nxt *= k;
       auto _nxt = waste.lower_bound(nxt-k);

       if(_nxt!=waste.begin()){
           _nxt--;
       }

       if(_nxt == waste.end()){
           _nxt--;
       }

       back+=*(_nxt);
       waste.erase(_nxt);
    //    debug(back);
       cost+=(back/k);
    }

    cout<<cost<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}