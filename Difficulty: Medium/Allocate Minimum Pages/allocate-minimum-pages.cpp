class Solution { 
  public: 
    bool fun(vector<int>&arr,int n,int stu,long long guess){ 
        int k=1; 
        long long page=0; 

        for(int i=0;i<n;i++){ 
            if(page+arr[i]<=guess){ 
                page=page+arr[i]; 
            } 
            else{ 
                k++; 
                page=arr[i]; 

                if(k>stu){ 
                    return false; 
                } 
            } 
        } 

        return true; 
    } 

    int findPages(vector<int> &arr, int stu) { 
        int n=arr.size(); 
        long long res=-1; 
        long long low=0; 
        long long high=0; 

        if(stu > n){ 
            return -1; 
        } 

        for(int i=0;i<n;i++){ 
            low=max(low,(long long)arr[i]); 
            high=high+arr[i]; 
        } 

        while(low<=high){ 
            long long guess=(high+low)/2; 

            if(fun(arr,n,stu,guess)){ 
                res=guess; 
                high=guess-1; 
            } 
            else{ 
                low=guess+1;
            } 
        } 

        return res; 
    } 
};