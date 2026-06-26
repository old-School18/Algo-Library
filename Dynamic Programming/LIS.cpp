// Time Complexity: O(2^n) Recursive | O(n^2) Memoization & Tabulation | O(nlogn) Binary search
// Memory Complexity: O(n^2) Memoization | O(n) for remaining
// Find the length of longest increasing subsequence

// Recursive
ll lisRecurse(vector<ll> &nums, ll idx, ll prevIdx)
{
    if (idx > nums.size())
    {
        return 0;
    }
    ll lis = lisRecurse(nums, idx + 1, prevIdx);
    if (!prevIdx || nums[idx - 1] > nums[prevIdx - 1])
    {
        lis = max(lis, 1 + lisRecurse(nums, idx + 1, idx));
    }
    return lis;
}

ll lis(vector<ll> &nums)
{
    return lisRecurse(nums, 1, 0);
}

// Memoization (Top-down)
ll lisMemo(vector<ll> &nums, vector<vector<ll>> &dp, ll idx, ll prevIdx)
{
    if (idx == nums.size())
    {
        return 0;
    }
    if (dp[idx][prevIdx] != -1)
    {
        return dp[idx][prevIdx];
    }
    ll lis = lisMemo(nums, dp, idx + 1, prevIdx);
    if (!prevIdx || nums[idx - 1] > nums[prevIdx - 1])
    {
        lis = max(lis, 1 + lisMemo(nums, dp, idx + 1, idx));
    }
    return dp[idx][prevIdx] = lis;
}

ll lis(vector<ll> &nums)
{
    ll n = nums.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    return lisMemo(nums, dp, 1, 0);
}

// Tabulation (Bottom-up)
ll lis(vector<ll> &nums)
{
    ll n = nums.size();
    vector<ll> dp(n + 1, 1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j < i; j++)
        {
            if (nums[i - 1] > nums[j - 1])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Optimized solution (Binary search) / Also prints LIS
ll lis(vector<ll> &nums)
{
    vector<ll> lisNums{nums[0]};
    for (ll i = 1; i < nums.size(); i++)
    {
        if (nums[i] > lisNums.back())
        {
            lisNums.push_back(nums[i]);
        }
        else
        {
            ll idx = lower_bound(lisNums.begin(), lisNums.end(), nums[i]) - lisNums.begin();
            lisNums[idx] = nums[i];
        }
    }
    return lisNums.size();
}

// Printing LIS
vector<ll> lis(vector<ll> &nums)
{
    ll n = nums.size();
    vector<ll> dp(n + 1, 1), prev(n + 1, 0);
    vector<ll> lisNums;
    ll lastIdx = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j < i; j++)
        {
            if (nums[i - 1] > nums[j - 1])
            {
                if (dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
        }
        if (dp[lastIdx] < dp[i])
        {
            lastIdx = i;
        }
    }
    while (lastIdx)
    {
        lisNums.push_back(nums[lastIdx - 1]);
        lastIdx = prev[lastIdx];
    }
    reverse(lisNums.begin(), lisNums.end());
    return lisNums;
}
