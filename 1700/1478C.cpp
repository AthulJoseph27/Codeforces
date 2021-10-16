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

    int N = 2 * n;

    vector<long long> d(N);

    for (long long &i : d)
        cin >> i;

    /*
       d[i] = sigma abs(a[i] - a[j]) for j from 1 to 2n
       d[i] = a[i] - a[0] + ... + a[i] - a[i] + .... + a[i] - a[n]
       there will be -a[i] in this array, distinct elements!!

        -a -b -c -d d c b a

       abs(-a+a)+ abs(-a+b) + abs(-a+c) + abs(-a+d) + abs(-a-d) + ... + abs(a+a)
       0 + a + a + a + a + a + a + a+a
       8a => 2a + (n-1)*2*a => n*2a

       4*a = 12 => a = 3

       a + b + b + b + b + 2b + a

       2b + (4b) + 2a => 

       2b + 4b + 2a

       a + b + 0 + c + c + 2c + b + a

       4c + 2b + 2a = d[i]
       d[i] - 2b - 2a / 4

    */

    sort(all(d));

    map<long long, int> mp;

    for (long long i : d)
        mp[i]++;

    vector<long long> a;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((it->first % 2 != 0) || (it->second != 2))
        {
            cout << "NO\n";
            return;
        }
        a.push_back(it->first);
    }

    d = a;

    a.clear();

    reverse(all(d));

    long long sub = 0;

    int size = d.size();

    // debug(d);

    for (int i = 0; i < d.size(); i++)
    {
        if ((d[i] - sub) % (2 * size) != 0)
        {
            cout << "NO\n";
            return;
        }
        a.push_back((d[i] - sub) / (2 * size));
        sub += (a.back() * 2LL);
        size--;
    }

    set<long long> st;

    for (long long i : a)
    {
        if (i <= 0)
        {
            cout << "NO\n";
            return;
        }
        st.insert(i);
    }

    if (st.size() != a.size())
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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