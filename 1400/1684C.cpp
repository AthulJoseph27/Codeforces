#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

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

void swap_col_and_check(vvi &a, int x, int y){
    int n = a.size();
    for(int i=0;i<n;i++){
        int t = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = t;
    }

    int m = a[0].size();

    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]<a[i][j-1]){
                cout<<"-1\n";
                return;
            }
        }
    }

    cout<<(x+1)<<" "<<(y+1)<<"\n";
}

void solve(int cc)
{
    // if first row is ok, then answer is either 1 1 or -1

    int n, m;
    cin>>n>>m;

    vvi a(n,vi(m));
    vvi b(n, vi(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b[i][j] = a[i][j];
        }
    }

    set<int>first;
    set<int>second;

    for(int i=0;i<n;i++){

        sort(all(b[i]));
        
        vi indices;
        
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                indices.push_back(j);
            }
        }

        int count = indices.size();

        if(count == 1){
            int nxt = indices[0]+1;
            if(nxt == m){
                nxt = indices[0]-1;
            }
            swap_col_and_check(a,indices[0],nxt);
            return;
        }

        if(count == 2){
            swap_col_and_check(a,indices[0],indices[1]);
            return;
        }

        if(count != 0){
            cout<<"-1\n";
            return;
        }
    }

    cout<<"1 1\n";
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

/*
    In a fully connected K-ary Tree
    parent of nth node is
    p = (n+k-2)/k
*/