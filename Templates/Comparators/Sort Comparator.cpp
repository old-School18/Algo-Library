// To define custom logic to sort elements in a container. sort() function needs Callable

// Comparator function - Preferred
template <typename T> bool comp(const T &x, const T &y)
{
    return x > y;
}

void util()
{
    vector<ll> v;
    sort(v.begin(), v.end(), comp);
}

--------------------------------
// Lambda Functor inline - Preferred
void util()
{
    vector<ll> v;
    sort(v.begin(), v.end(), [](const ll &x, const ll &y) { return x > y; });
}

--------------------------------
// Lambda Functor
void util()
{
    vector<ll> v;
    auto comp = [](const ll &x, const ll &y) { return x > y; };
    sort(v.begin(), v.end(), comp);
}

--------------------------------
// Struct Functor
template <typename T> struct Comparator
{
    bool operator()(const T &x, const T &y) const
    {
        return x > y;
    }
};

void util()
{
    vector<ll> v;
    sort(v.begin(), v.end(), Comparator<ll>());
}

--------------------------------
// Class Functor
template <typename T> class Comparator
{
  public:
    bool operator()(const T &x, const T &y) const
    {
        return x > y;
    }
};

void util()
{
    vector<ll> v;
    sort(v.begin(), v.end(), Comparator<ll>());
}
