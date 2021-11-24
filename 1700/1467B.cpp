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

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    int cnt = 0;

    vector<bool> hill(n, false), valley(n, false);

    for (int i = 1; i < (n - 1); i++)
    {
        if (a[i] > max(a[i - 1], a[i + 1]))
        {
            cnt++;
            hill[i] = true;
        }
        else if (a[i] < min(a[i - 1], a[i + 1]))
        {
            cnt++;
            valley[i] = true;
        }
    }

    bool changed = false;

    // debug(cnt);

    for (int i = 1; i < (n - 1); i++)
    {
        if (((hill[i - 1] && valley[i] && hill[i + 1]) || (valley[i - 1] && hill[i] && valley[i + 1])))
        {
            changed = true;
            cnt -= 3;
            break;
        }
    }

    for (int i = 1; !changed && i < n; i++)
    {
        if (hill[i] && valley[i - 1])
        {
            // debug(a[i - 2], a[i - 3], a[i]);
            // change a[i-1] to a[i] and check if a[i-2] is a valley and a[i+1] not a hill
            if (((i > 2) && (a[i - 2] < min(a[i - 3], a[i]))) && (i < (n - 2) && (a[i + 1] > max(a[i - 1], a[i + 2]))))
            {
                continue;
            }
            changed = true;
            cnt -= 2;
            break;
        }
        if (hill[i - 1] && valley[i])
        {
            if (((i < (n - 2)) && (a[i + 1] < min(a[i + 2], a[i - 1]))) && ((i > 2) && (a[i - 2] > max(a[i - 3], a[i]))))
            {
                continue;
            }
            changed = true;
            cnt -= 2;
            break;
        }
    }

    for (int i = 0; !changed && i < n; i++)
    {
        if (hill[i] || valley[i])
        {
            cnt--;
            break;
        }
    }

    assert(cnt >= 0);

    cout << cnt << '\n';
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