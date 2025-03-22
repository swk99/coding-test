class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> map;

        for(int i=0;i<nums.size();i++){
            //현재 숫자가 맵에 있고 거리가 k 이하인지 확인!
            if(map.find(nums[i])!=map.end()){
                if(i-map[nums[i]]<=k){
                    return true;
                }
            }
            map[nums[i]]=i;
        }
        return false;


    }
};
