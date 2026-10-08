class Solution {
public:
    bool isSorted(vector<int>& arr, int i = 0) {

        if (i == arr.size() - 1) {
            return true;
        }

        if (arr[i] > arr[i + 1]) {
            return false;
        }

        return isSorted(arr, i + 1);
    }
};