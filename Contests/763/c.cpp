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
    int n;
    cin >> n;

    vl a(n);

    for (ll &i : a)
        cin >> i;

    ll l = *min_element(all(a)), r = *max_element(all(a));

    ll ans = l;

    vl tmp = a;

    // debug(a);

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        for (int i = n - 1; i >= 2; i--)
        {
            ll d3;
            ll extra = a[i] - tmp[i];
            if (extra >= mid)
                d3 = tmp[i];
            else
                d3 = tmp[i] - (mid - extra);

            if (d3 < 0)
            {
                a[i] = -1;
                break;
            }
            a[i] -= d3;
            a[i - 1] += d3 / 3;
            a[i - 2] += (2 * (d3 / 3));
        }

        ll cur_min = *min_element(all(a));

        ans = max(ans, cur_min);

        if (cur_min >= mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }

        a = tmp;
    }

    cout << ans << '\n';

    /*
        1 2 10 100
        
        1 58 38 16

        1+2*7 58 + 7 17 16

        15 58 
                
    */
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