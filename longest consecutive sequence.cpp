class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty()) return 0;
        if(num.size()==1) return 1;
        sort(num.begin(),num.end());
        int consecutiveLength = 1;
        int maxLength = 1;
        for(int i=0;i<num.size()-1;i++)
        {
            if(num[i+1]==num[i])
                continue;
            int difference = num[i+1] - num[i];
            if(difference==1 || difference==-1)
            {
                consecutiveLength++;
                if(consecutiveLength>maxLength)
                    maxLength = consecutiveLength;
            }
            else
                consecutiveLength = 1;
        }
        return maxLength;
    }
};