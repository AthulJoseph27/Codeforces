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
    vector<int> b(n, -1);

    for (int i = 0; i < n; i++)
    {
        int ddt;
        cin >> ddt;
        a[i] = ddt - 1;
    }

    vector<set<int>> g(n);

    for (int i = 0; i < n; i++)
    {
        g[a[i]].insert(i);
    }

    set<int> taken;

    int sad = 0, k = 0;

    set<int> rem;

    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 0)
        {
            if (taken.find(a[i]) != taken.end())
            {
                rem.insert(i);
                continue;
            }
            b[i] = a[i];
            taken.insert(a[i]);
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
            continue;
        if (taken.find(a[i]) != taken.end())
        {
            rem.insert(i);
        }
        else
        {
            taken.insert(a[i]);
            b[i] = a[i];
            k++;
        }
    }

    set<int> avail;

    for (int i = 0; i < n; i++)
        avail.insert(i);

    for (int i = 0; i < n; i++)
        if (b[i] != -1)
            avail.erase(b[i]);

    vector<int> ravail;

    for (int i : avail)
        ravail.push_back(i);

    reverse(all(ravail));

    if (ravail.size() == 1)
    {
        if ((*rem.begin()) == ravail[0])
        {
            b[ravail[0]] = *rem.begin();
            if (ravail[0] != 0)
            {
                swap(b[ravail[0]], b[ravail[0] - 1]);
            }
            else
            {
                swap(b[ravail[0]], b[ravail[0] + 1]);
            }
            k--;
        }
        else
        {
            // debug(ravail);
            // debug(b);
            b[*rem.begin()] = ravail[0];
        }
    }
    else
    {
        // debug(ravail);
        // debug(b);
        int index = 0;
        for (auto it = rem.begin(); it != rem.end(); it++)
        {
            if (*(it) == ravail[index])
            {
                swap(ravail[index + 1], ravail[index]);
            }
            b[*(it)] = ravail[index];
            index++;
        }
    }

    // for (auto it = rem.begin(); it != rem.end(); it++)
    // {
    //     if (*(it) == *(avail.begin()))
    //     {
    //         int num = *(avail.begin());
    //         b[*(it)] = num;
    //         avail.erase(num);
    //         alone_index.insert(*(it));
    //     }
    //     else
    //     {
    //         auto tempit = avail.begin();
    //         int num = *(tempit);
    //         if (num == (*it))
    //         {
    //             tempit++;
    //             if (tempit == avail.end())
    //             {
    //                 if (alone_index.size() == 0)
    //                 {
    //                     b[num] = num;
    //                     if (num != 0)
    //                     {
    //                         swap(b[num], b[num - 1]);
    //                     }
    //                     else
    //                     {
    //                         swap(b[num + 1], b[num]);
    //                     }
    //                     k--;
    //                 }
    //                 else
    //                 {
    //                     bool fixed = false;
    //                     for (auto itt = alone_index.begin(); it != alone_index.end(); it++)
    //                     {
    //                         if (*(itt) != num)
    //                         {
    //                             itt
    //                         }
    //                     }
    //                 }
    //             }
    //             else
    //             {
    //                 num = *(tempit);
    //                 avail.erase(num);
    //                 b[*(it)] = num;
    //             }
    //         }
    //         else
    //         {
    //             avail.erase(num);
    //             b[*(it)] = num;
    //         }
    //     }
    // }

    cout << k << "\n";
    for (int i = 0; i < b.size(); i++)
        cout << (b[i] + 1) << " ";

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