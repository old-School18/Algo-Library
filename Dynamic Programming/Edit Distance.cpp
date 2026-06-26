// Time Complexity: O(3^(n+m)) Recursive | O(n*m) for remaining
// Memory Complexity: O(n+m) Recursive | O(n*m) Memoization & Tabulation | O(m) Space optimized Tabulation
// Minimum number of insertions, replacements or deletions required to convert string s into string t.

// Recursive
ll editDistanceRecurse(string &s, string &t, ll n, ll m, ll idx, ll idy)
{
    if (idx == n || idy == m)
    {
        return (n - idx) + (m - idy);
    }

    if (s[idx] == t[idy])
    {
        return editDistanceRecurse(s, t, n, m, idx + 1, idy + 1);
    }
    return 1 + min({
                   editDistanceRecurse(s, t, n, m, idx, idy + 1),     // Insert
                   editDistanceRecurse(s, t, n, m, idx + 1, idy + 1), // Replace
                   editDistanceRecurse(s, t, n, m, idx + 1, idy)      // Delete
               });
}

ll editDistance(string &s, string &t)
{
    return editDistanceRecurse(s, t, s.size(), t.size(), 0, 0);
}

// Memoization (Top-down)
ll editDistanceMemo(string &s, string &t, vector<vector<ll>> &dp, ll n, ll m, ll idx, ll idy)
{
    if (idx == n || idy == m)
    {
        return (n - idx) + (m - idy);
    }
    if (dp[idx][idy] != -1)
    {
        return dp[idx][idy];
    }

    if (s[idx] == t[idy])
    {
        return dp[idx][idy] = editDistanceMemo(s, t, dp, n, m, idx + 1, idy + 1);
    }
    return dp[idx][idy] = 1 + min({
                                  editDistanceMemo(s, t, dp, n, m, idx, idy + 1),     // Insert
                                  editDistanceMemo(s, t, dp, n, m, idx + 1, idy + 1), // Replace
                                  editDistanceMemo(s, t, dp, n, m, idx + 1, idy)      // Delete
                              });
}

ll editDistance(string &s, string &t)
{
    ll n = s.size();
    ll m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return editDistanceMemo(s, t, dp, n, m, 0, 0);
}

// Tabulation (Bottom-up)
ll editDistance(string &s, string &t)
{
    ll n = s.size();
    ll m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = i + j;
                continue;
            }
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i][j - 1],     // Insert
                                   dp[i - 1][j - 1], // Replace
                                   dp[i - 1][j]      // Delete
                               });
            }
        }
    }
    return dp[n][m];
}

// Space optimized Tabulation (Rolling-array optimization)
ll editDistance(string &s, string &t)
{
    ll n = s.size();
    ll m = t.size();
    vector<vector<ll>> dp(2, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i % 2][j] = i + j;
                continue;
            }
            if (s[i - 1] == t[j - 1])
            {
                dp[i % 2][j] = dp[1 - i % 2][j - 1];
            }
            else
            {
                dp[i % 2][j] = 1 + min({
                                       dp[i % 2][j - 1],     // Insert
                                       dp[1 - i % 2][j - 1], // Replace
                                       dp[1 - i % 2][j]      // Delete
                                   });
            }
        }
    }
    return dp[n % 2][m];
}
