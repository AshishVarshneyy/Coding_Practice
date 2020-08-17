//Question link: https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        long int size = height.size();
        if(size == 0)
            return 0;
        else{
            long int left_max[size], right_max[size];
            long int trapped_water = 0;
            
            left_max[0]=height[0];
            right_max[size-1]=height[size-1];
            
            for(long int i=1; i<size; i++){
                if(height[i]>left_max[i-1])
                    left_max[i]=height[i];
                else
                    left_max[i]=left_max[i-1];
            }
            
            for(long int i=size-2; i>=0; i--){
                if(height[i]>right_max[i+1])
                    right_max[i]=height[i];
                else
                    right_max[i]=right_max[i+1];
            }
            
            for(long int i=0; i<size; i++){
                if(left_max[i]<right_max[i])
                    trapped_water=trapped_water + left_max[i]-height[i];
                else
                    trapped_water=trapped_water + right_max[i]-height[i];
            }
            return trapped_water;
        }
    }
};