// Time Complexity: O(nlog n)
// Memory Complexity: O(n)
// Stable: Yes
// Mechanism to sort sequences by dividing into smaller sequences and recursively MERGING them

void merge(ll a[], ll l, ll r)
{
    ll mid = l + (r - l) / 2;
    ll n1 = mid - l + 1, n2 = r - mid;
    ll left[n1], right[n2];

    for (ll i = l; i <= mid; i++)
    {
        left[i - l] = a[i];
    }
    for (ll i = mid + 1; i <= r; i++)
    {
        right[i - mid - 1] = a[i];
    }

    ll currIdx = l;
    ll x = 0, y = 0;

    while (x < n1 && y < n2)
    {
        a[currIdx++] = (left[x] <= right[y]) ? left[x++] : right[y++];
    }
    while (x < n1)
    {
        a[currIdx++] = left[x++];
    }
    while (y < n2)
    {
        a[currIdx++] = right[y++];
    }

    return;
}

void mergeSortRecurse(ll a[], ll l, ll r)
{
    ll mid = l + (r - l) / 2;
    if (l < r)
    {
        mergeSortRecurse(a, l, mid);
        mergeSortRecurse(a, mid + 1, r);
        merge(a, l, r);
    }
}

void mergeSort(ll a[], ll n)
{
    mergeSortRecurse(a, 0, n - 1);
}
