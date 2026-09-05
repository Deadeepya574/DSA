class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    int first = -1;
    int last = -1;
    int n = nums.size();

    // First occurrence
    int low = 0, high = n - 1;

    vector<int> res;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            if (nums[mid] == target)
                first = mid;

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Last occurrence
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
        {
            if (nums[mid] == target)
                last = mid;

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    res.push_back(first);
    res.push_back(last);
    return res;    

    }
};