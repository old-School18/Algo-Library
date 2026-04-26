// Time Complexity: O(n2) Worst | O(n2) Average | O(n) Best
// Memory Complexity: O(1)
// Stable: Yes
// Mechanism to sort sequences by INSERTING the current iterating index into its appropriate position in the gradually expanding window

void insertionSort(ll a[],ll n) {
    for (ll i = 1; i < n; i++)
    {
        ll curr = a[i];
        ll j = i - 1;
        while (j >= 0 && a[j] > curr)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
    return;
}
