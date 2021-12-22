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

// void check_ans(string a, string b, string c)
// {
//     if (a.size() < b.size())
//     {
//         swap(a, b);
//     }

//     while (a.size() > b.size())
//     {
//         b = '0' + b;
//     }

//     int index = c.size() - 1;
//     for (int i = a.size() - 1; i >= 0; i--)
//     {
//         int res = (a[i] - '0') + (b[i] - '0');
//         if (res > 9)
//         {
//             assert(index >= 1);
//             int num = (c[index] - '0') + (c[index - 1] - '0') * 10;
//             if (num != res)
//             {
//                 cout << a << " " << b << " " << c << endl;
//             }
//             assert(num == res);
//             index -= 2;
//             continue;
//         }
//         assert((c[index] - '0') == res);
//         index--;
//     }
// }

void solve(int cc)
{
    string a, s;

    cin >> a >> s;

    if (s.size() < a.size())
    {
        cout << -1 << '\n';
        return;
    }

    string b = "";

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            cout << -1 << '\n';
            return;
        }
        int last = s.back() - '0';
        s.pop_back();
        int cur = a[i] - '0';
        if (last < cur)
        {
            if (s.size() == 0)
            {
                cout << -1 << '\n';
                return;
            }
            last += (10 * (s.back() - '0'));
            s.pop_back();
        }
        if ((last - cur) < 0)
        {
            cout << -1 << '\n';
            return;
        }
        if ((last - cur) > 9)
        {
            cout << -1 << '\n';
            return;
        }
        b = to_string(last - cur) + b;
    }

    if (s.size() > 0)
    {
        b = s + b;
    }

    string res = "";

    int index = -1;

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != '0')
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << 0 << '\n';
        return;
    }

    res = b.substr(index, b.size() - index);

    // check_ans(a, res, b);

    cout << res << '\n';
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