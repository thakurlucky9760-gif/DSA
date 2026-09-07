 class Solution {
public:
    int maxNumberOfBalloons(string text) {
       unordered_map<char,int> have;
       int n=text.size();
       int res=INT_MAX;
       unordered_map<char,int>need;

       for(int i=0;i<n;i++){
        have[text[i]]++;
       } 
       need['b']=1;
       need['a']=1;
       need['l']=2;
       need['o']=2;
       need['n']=1;

       for(auto i:need){
        char c=i.first;
        int fneed=i.second;
        int fhave=have[c];
        int times=fhave/fneed;

        res=min(res,times);
       }
       return res;
    }
};