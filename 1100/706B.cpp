#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
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

int binarySearch(vi &a, int t)
{
    int mid, s = 0, e = a.size();
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] == t)
            return mid;

        if (a[mid] > t)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return (s + e) / 2;
}
void solve(int cc)
{
    int n;
    cin >> n;
    vi costs(n);
    for (int i = 0; i < n; i++)
        cin >> costs[i];

    sort(all(costs));
    int q;
    cin >> q;
    int a;
    for (int i = 0; i < q; i++)
    {
        cin >> a;
        int index = binarySearch(costs, a);
        if (costs[index] > a)
        {
            cout << 0 << '\n';
        }
        else if (costs[index] > a)
        {
            while (index >= 0 && costs[index] > a)
            {
                index--;
            }
            if (index == -1)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << index + 1 << '\n';
            }
        }
        else
        {
            while (index < costs.size() && costs[index] <= a)
            {
                index++;
            }
            cout << index << '\n';
        }
        // debug(index);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}