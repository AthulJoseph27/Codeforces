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

vector<pair<ll, ll>> prime_factorize(ll n)
{
    // O(sqrt(n))

    map<ll, ll> mp;

    while (!(n % 2))
    {
        n >>= 1;
        mp[2]++;
    }

    int ub = sqrt(n) + 1;

    for (ll i = 3; i <= ub; i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }

    if (n > 2)
        mp[n]++;

    vector<pair<ll, ll>> factors;

    for (auto it = mp.begin(); it != mp.end(); it++)
        factors.emplace_back(it->second, it->first);

    sort(rall(factors));

    return factors;
}

void solve(int cc)
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> factors = prime_factorize(n);

    if (factors.size() == 1 && factors[0].second == n)
    {
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }

    // debug(factors);

    vl ans;

    ll pd = 1;

    for (int j = 0; j < factors[0].first - 1; j++)
    {
        ans.push_back(factors[0].second);
        pd *= factors[0].second;
    }

    pd = n / pd;

    ans.push_back(pd);

    cout << ans.size() << '\n';
    for (ll i : ans)
        cout << i << ' ';
    cout << '\n';

    /*
        a1*a2*....*ak = n
        a(i+1)%ai=0

        if n is prime, then k is 1

        n -> 2^q.3^p.5^r.....

        min(q,p,r)+1

        D -> max prime
        O -> product of others
        O.O.O
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