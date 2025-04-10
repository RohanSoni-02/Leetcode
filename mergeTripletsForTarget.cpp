class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one = false;
        bool two = false;
        bool three = false;

        for(auto& triplet: triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }

            if(triplet[0] == target[0]){
                one = true;
            }
            if(triplet[1] == target[1]){
                two = true;
            }
            if(triplet[2] == target[2]){
                three = true;
            }
        }

        return one && two && three;
    }
};