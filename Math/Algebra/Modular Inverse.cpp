// Time Complexity => O(log(min(a,M))
// Memory Complexity => Recursive: O(log min(a,M)) | Iterative: O(1)  [Extended Euclid]
// Determines 'inv' where (a * inv) % M = 1

ll extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll g = extendedEuclid(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return g;
}

ll modInverse(ll a, ll M)
{
    ll x, y;
    ll g = extendedEuclid(a, M, x, y);
    if (g != 1)
    {
        return -1; // No inverse
    }
    return (x % M + M) % M;
}
