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

int query_count = 0;

int query(int a, int b, int c)
{
    query_count++;
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int res;
    cin >> res;

    return res;
}

void solve(int cc)
{
    query_count = 0;
    int n;
    cin >> n;

    int pr = query(0, 1, 2);

    int imposter = -1, crew = -1;

    for (int i = 1; i < n; i++)
    {
        int res = query(i, (i + 1) % n, (i + 2) % n);

        if (res != pr)
        {
            if (res == 0)
            {
                imposter = (i + 2) % n;
                crew = i - 1;
            }
            else
            {
                imposter = i - 1;
                crew = (i + 2) % n;
            }
            break;
        }
    }

    assert(imposter != -1);

    vector<int> imposters = {imposter};

    for (int i = 0; i < n; i++)
    {
        if ((i == crew) || (i == imposter))
            continue;
        int res = query(imposter, crew, i);
        if (res == 0)
        {
            imposters.push_back(i);
        }
    }

    sort(all(imposters));

    cout << "! " << imposters.size() << " ";

    for (int i : imposters)
        cout << i + 1 << " ";

    cout << endl;
}

// 1 2 3 4 5 6 7 8 9
// imposters -> 2 3 6 8

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