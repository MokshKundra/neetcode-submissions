class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int rob1 = 0, rob2 = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        int rob3 = 0, rob4 = 0;

        for (int i = 1; i < nums.size(); i++){
            int temp = max(nums[i] + rob3, rob4);
            rob3 = rob4;
            rob4 = temp;
        }

        return max(rob4, rob2);
    }
};