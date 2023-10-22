class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = k;
        int hi = k;
        
        int min_val = nums[k];
        int ans = nums[k];

        while(lo>0 || hi < n-1){
            if(lo == 0){
                hi++;
            }
            else if(hi == n-1){
                lo--;
            }
            else if(nums[lo-1]<nums[hi+1]){
                hi++;
            }
            else{
                lo--;
            }

            min_val = min(min_val, min(nums[lo],nums[hi]));
            ans = max(ans,min_val * (hi-lo+1));

        }
        return ans;
    }
};
