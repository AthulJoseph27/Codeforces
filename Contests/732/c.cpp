#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pbds                                              \
    tree<pair<int, int>, null_type, less<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>

#define pbds2                                                \
    tree<pair<int, int>, null_type, greater<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;

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

long long countSmallerRight(vector<int> &arr, int n)
{
    pbds s;

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(s.order_of_key({arr[i], i}));
        }
        s.insert({arr[i], i});
    }

    long long count = 0;

    for (int i : ans)
        count += (long long)i;

    // debug(ans);
    return count;
}

// long long countLargerLeft(vector<int> arr, int n)
// {
//     pbds2 s;

//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             ans.push_back(0);
//         }
//         else
//         {
//             ans.push_back(s.order_of_key({arr[i], i}));
//         }
//         s.insert({arr[i], i});
//     }

//     long long count = 0;
//     for (int i : ans)
//         count += (long long)i;

//     // debug(ans);
//     return count;
// }

void solve(int cc)
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    // debug(countSmallerRight(a, n));
    // debug(countLargerLeft(a, n));
    long long count = countSmallerRight(a, n); // + countLargerLeft(a, n);
    // count /= 2L;
    if (count % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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