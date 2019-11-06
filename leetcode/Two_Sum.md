# Two Sum

## method 1 - brute force
time complexity is   <img src="https://latex.codecogs.com/gif.latex?O(n^2)" />
``` c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int > ans;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
```

## method 2 - use map
map can find if the `num` is in it with almost constant time (?
construct map first
take very number and need `target-number` to complete the problem , so find it in map !(constant time !)
So time complexity is <img src="https://latex.codecogs.com/gif.latex?O(n)" />
``` c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use map for find value
        vector<int > ans;
        
        map<int, int> hash;
        // hash[value] = index
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if ( hash.find(target-nums[i]) != hash.end() && hash.find(target-nums[i])->second != i) {
                ans.push_back(i);
                ans.push_back(hash[target-nums[i]]);
                return ans;
            }
        }
        
        return ans;
    }
};
```