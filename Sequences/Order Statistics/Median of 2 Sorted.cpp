// Time Complexity: O(log min(n,m))
// Memory Complexity: Recursive: O(log min(n,m)) | Iterative: O(1)
// Median of two sorted arrays


// Recursive
ld medianOfTwoRecurse(ll a[], ll b[], ll n, ll m, ll k, ll left, ll right)
{
    if (left > right)
    {
        return -1.0;
    }

    ll partitionA = left + (right - left) / 2;
    ll partitionB = k - partitionA;

    ll maxLeftA = (!partitionA) ? LLONG_MIN : a[partitionA - 1];
    ll minRightA = (partitionA == n) ? LLONG_MAX : a[partitionA];
    ll maxLeftB = (!partitionB) ? LLONG_MIN : b[partitionB - 1];
    ll minRightB = (partitionB == m) ? LLONG_MAX : b[partitionB];

    if (maxLeftA <= minRightB && maxLeftB <= minRightA)
    {
        if ((n + m) % 2)
        {
            return max(maxLeftA, maxLeftB);
        }
        else
        {
            return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
        }
    }
    else if (maxLeftA > minRightB)
    {
        return medianOfTwoRecurse(a, b, n, m, k, left, partitionA - 1);
    }
    else
    {
        return medianOfTwoRecurse(a, b, n, m, k, partitionA + 1, right);
    }
}

ld medianOfTwo(ll a[], ll b[], ll n, ll m)
{
    if (n > m)
    {
        return medianOfTwo(b, a, m, n);
    }
    ll k = (n + m + 1) / 2;

    return medianOfTwoRecurse(a, b, n, m, k, max(0ll, k - m), min(k, n));
}

-------------------------------

// Iterative
ld medianOfTwo(ll a[], ll b[], ll n, ll m)
{
    if (n > m)
    {
        return medianOfTwo(b, a, m, n);
    }
    ll k = (n + m + 1) / 2;

    ll left = max(0ll, k - m), right = min(k, n);
    while (left <= right)
    {
        ll partitionA = left + (right - left) / 2;
        ll partitionB = k - partitionA;

        ll maxLeftA = (!partitionA) ? LLONG_MIN : a[partitionA - 1];
        ll minRightA = (partitionA == n) ? LLONG_MAX : a[partitionA];
        ll maxLeftB = (!partitionB) ? LLONG_MIN : b[partitionB - 1];
        ll minRightB = (partitionB == m) ? LLONG_MAX : b[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA)
        {
            if ((n + m) % 2)
            {
                return max(maxLeftA, maxLeftB);
            }
            else
            {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            }
        }
        else if (maxLeftA > minRightB)
        {
            right = partitionA - 1;
        }
        else
        {
            left = partitionA + 1;
        }
    }

    return -1.0;
}
