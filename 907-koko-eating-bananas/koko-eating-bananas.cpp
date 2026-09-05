class Solution {
public:
    long long helper(vector<int>&piles,int n,int k){
       long long  h=0;
        for(int i=0;i<n;i++){
            h=h+piles[i]/k;
            if(piles[i]%k!=0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        int res=-1;

        while(low<=high){
            int guess=(low+high)/2;

            long long hour=helper(piles,n,guess);

            if(hour>h){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
        
    }
};