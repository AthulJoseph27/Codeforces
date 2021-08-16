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

vector<pair<int, int>> prime_factorize(long long n)
{
    // O(sqrt(n))

    map<int, int> mp;

    while (!(n % 2))
    {
        n >>= 1;
        mp[2]++;
    }

    int ub = sqrt(n) + 1;

    for (long long i = 3; i <= ub; i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }

    if (n > 2)
        mp[n]++;

    vector<pair<int, int>> factors;

    for (auto it = mp.begin(); it != mp.end(); it++)
        factors.emplace_back(it->first, it->second);

    return factors;
}

void solve(int cc)
{
    long long p, q;
    cin >> p >> q;

    if (p % q != 0)
    {
        cout << p << '\n';
        return;
    }

    /*
        p -> 2^a * 3^b * 5^c
        q -> 2^x * 3^y * 5^z 

        p%q == 0

        so,
        a>=x , b>=y c>=z
    */

    vector<pair<int, int>> qf = prime_factorize(q);

    long long ans = 1;

    for (auto &i : qf)
    {
        long long temp = p;
        int count = 0;
        while (temp % i.first == 0)
        {
            temp /= i.first;
            count++;
        }
        long long res = p;
        for (int j = 0; j < count - i.second + 1; j++)
        {
            res /= i.first;
        }

        ans = max(ans, res);
    }

    cout << ans << '\n';
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