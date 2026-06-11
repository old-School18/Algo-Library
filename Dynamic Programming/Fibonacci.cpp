// Time Complexity: O(2^n) Recursive | O(n) for remaining
// Memory Complexity: O(1) Space optimized tabulation | O(n) for remaining
// Find nth fibonacci number

// Recursive
ll fibonacci(ll n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Memoization (Top-down)
ll fibonacciMemo(ll dp[], ll n)
{
    if (n <= 1)
    {
        return n;
    }
    else if (dp[n])
    {
        return dp[n];
    }
    return dp[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
}

ll fibonacci(ll n)
{
    ll dp[n + 1] = {0};
    return fibonacciMemo(dp, n);
}

// Tabulation (Bottom-up)
ll fibonacci(ll n)
{
    ll dp[n + 1] = {0};
    dp[1] = 1;

    for (ll i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Tabulation memory optimized
ll fibonacci(ll n)
{
    if (n <= 1)
    {
        return n;
    }
    ll prev1 = 0, prev2 = 1, curr;
    for (ll i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}
