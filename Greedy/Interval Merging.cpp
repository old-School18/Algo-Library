// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Merge given intervals

// Interval Merging approach
vector<vector<ll>> mergeIntervals(vector<vector<ll>> &intervals)
{
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    ll writer = 0;
    for (ll i = 1; i < intervals.size(); i++)
    {
        if (intervals[writer][1] >= intervals[i][0])
        {
            intervals[writer][1] = max(intervals[writer][1], intervals[i][1]);
        }
        else
        {
            writer++;
            intervals[writer] = intervals[i];
        }
    }

    intervals.resize(writer + 1);
    return intervals;
}

// Interval Merging approach with iterators - Not as performant
vector<vector<ll>> merge(vector<vector<ll>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    auto slowItr = intervals.begin(), fastItr = intervals.begin();
    fastItr++;
    while (fastItr != intervals.end())
    {
        if (slowItr->at(0) <= fastItr->at(1) && slowItr->at(1) >= fastItr->at(0))
        {
            *slowItr = {min(slowItr->at(0), fastItr->at(0)), max(slowItr->at(1), fastItr->at(1))};
            fastItr = intervals.erase(fastItr);
        }
        else
        {
            slowItr++;
            fastItr++;
        }
    }
    return intervals;
}

---------------------------------
Reference:
https://leetcode.com/problems/merge-intervals/
