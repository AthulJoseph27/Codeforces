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

const int POW[] = {1, 10, 100, 1000, 10000, 100000};

// void value(string &s) {
//     long long ans = 0;

//     reverse(all(s));

//     char mx = 'A' - 1;

//     for(char c: s) {
//         long long val = POW[c - 'A'];
//         if(c < mx) {
//             val *= -1;
//         }
//         ans += val;
//         mx = max(mx, c);
//     }

//     cout<<ans<<"\n";
// }

long long _solve(string &s, int i, int k, char mx, vector<vector<vector<int>>>& dp) {
    // k -> 0 no changes done, 1 -> changes done
    if(dp[i][mx-'A'][k] != -1) {
        return dp[i][mx-'A'][k];
    }

    int n = s.size();

    if(i == (n-1)) {
        if(k == 0) {
            return POW['E' - 'A'];
        }

        long long val = POW[s[i] - 'A'];
        if(mx > s[i]) {
            return -val; 
        }

        // cout<<i<<" "<<k<<" "<<mx<<" "<<val<<" base case"<<endl;

        return val;
    }

    // change to this char
    long long val = POW[s[i] - 'A'];
    if(mx > s[i]) {
        val *= -1; 
    }

    long long ans =  val + _solve(s, i+1, k, max(mx, s[i]), dp);

    if(k == 1) {
        // cout<<i<<" "<<k<<" "<<mx<<" "<<ans<<endl;
        dp[i][mx-'A'][k] = ans;
        return ans;
    }

    dp[i][mx-'A'][k] = ans; // k = 0

    for(int j=0;j<5;j++) {
        char nw = 'A' + j;
        
        if(nw == s[i]) {
            continue;
        }
        
        long long val = POW[nw - 'A'];
        if(mx > nw) {
            val *= -1;
        }
        ans = max(ans, val + _solve(s, i+1, 1, max(mx, nw), dp));
    }

    dp[i][mx-'A'][k] = ans;
    // cout<<i<<" "<<k<<" "<<mx<<" "<<ans<<endl;
    return ans;
}

void solve(int cc)
{
    string s;
    cin>>s;

    int n = s.size();
    reverse(all(s));

    vector<vector<vector<int>>>dp(n + 5, vector<vector<int>>(6, vector<int>(2, -1)));

    cout<<_solve(s, 0, 0, 'A', dp)<<'\n';
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
