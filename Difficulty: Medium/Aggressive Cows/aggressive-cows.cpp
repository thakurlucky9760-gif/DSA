class Solution {
  public:
    bool help(vector<int>&arr,int n,int guess,int k){
        int cow=1;
        int i;
        int pos=arr[0];

        for(i=1;i<n;i++){
            int dist=arr[i]-pos;

            if(dist<guess){
                continue;
            }

            cow++;
            pos=arr[i];

            if(cow>=k){
                return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());

        int low=1;
        int n=arr.size();
        int high=arr[n-1]-arr[0];
        int res=-1;

        while(low<=high){
            int guess=(low+high)/2;

            if(help(arr,n,guess,k)){
                res=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }

        return res;
    }
};