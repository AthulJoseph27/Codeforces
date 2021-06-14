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

struct Node
{
    Node *left, *right;
    int value;
};

struct Tree
{
    Node *root;
};

Node *BuildTree(vector<int> &a, int st, int en)
{
    if (st > en)
        return NULL;

    if (st == en)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->value = a[st];
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    int index = (max_element(a.begin() + st, a.begin() + en + 1) - a.begin());

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;

    newNode->value = a[index];

    newNode->left = BuildTree(a, st, index - 1);
    newNode->right = BuildTree(a, index + 1, en);

    return newNode;
}

unordered_map<int, int> mp;

void preOrder(Node *node, int level)
{
    if (node == NULL)
        return;

    mp[node->value] = level;
    preOrder(node->left, level + 1);
    preOrder(node->right, level + 1);
}

void deleteTree(Node *node)
{
    if (node == NULL)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    free(node);
}

void solve(int cc)
{
    int n;
    cin >> n;

    vector<int> a(n);
    mp.clear();

    Tree *T = (Tree *)malloc(sizeof(Tree));
    T->root = NULL;

    for (int &i : a)
        cin >> i;

    T->root = BuildTree(a, 0, n - 1);

    preOrder(T->root, 0);

    deleteTree(T->root);
    free(T);

    for (int i = 0; i < n; i++)
        cout << mp[a[i]] << ' ';

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