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

void solve(int cc)
{
    int a, b;
    cin >> a >> b;

    /*
        max value of k is less than a+b+1
    */

    set<int> ans;

    int total = (a + b);
    int serves = (total + 1) / 2;

    // Alice plays first
    // has (total+1)/2 serves
    // no of min breaks => T - (min(a,serves_A) + min(b,serves_B))
    // if Alice loses a serve....then 1 break with Alice and one with Bob coz, one win
    // was won by Bob breaking a serve...., so breaks increases by 2

    int max_holds = min(a, serves) + min(b, total - serves);
    int min_breaks = max(0, serves - a) + max(0, total - serves - b);
    // need to win most of a matches by breaking Bob's serve
    // min(a,b)
    int max_serves_loss = min(a, b);
    for (int i = 0; i <= max_serves_loss; i++)
    {
        ans.insert(min_breaks + 2 * i);
    }

    max_holds = min(a, total - serves) + min(b, serves);
    min_breaks = max(0, serves - b) + max(0, total - serves - a);

    for (int i = 0; i <= max_serves_loss; i++)
    {
        ans.insert(min_breaks + 2 * i);
    }

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
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