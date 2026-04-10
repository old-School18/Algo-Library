// Custom comparators for ordered collections declaration like set, map, priority_queue. Collections need Functors

// Lambda Functor
void util()
{
    auto comp = [](const ll &x, const ll &y) { return x > y; };
    set<ll, decltype(comp)> s(comp);
}

----------------------------
// Struct Functor - Preferred
template <typename T> struct Comparator
{
    bool operator()(const T &x, const T &y) const
    {
        return x > y;
    }
};

void util()
{
    set<ll, Comparator<ll>> s;
}

----------------------------
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
    set<ll, Comparator<ll>> s;
}
