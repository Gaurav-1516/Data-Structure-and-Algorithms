/*Find duplicate number in the array*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
    

/*  Sort colors*/
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int k = n-1;
        while(i <= k){
            if(arr[i] == 0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else if(arr[i] == 1){
                i++;
            }
            else{
                swap(arr[i],arr[k]);
                k--;
            }
        }
    }
};


/*  Remove duplicates from array*/
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i = 0 ;
        int j = 0;
        while(j != n){
            if(arr[i] == arr[j]) j++;
            else {
                i++;
                swap(arr[i],arr[j]);
                j++;
            }
        }
        // i+1 because we need to return 
        return i+1;
    }
};


/**Set Matrix Zero*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool zero_row[rows] ;
        for(int i = 0; i < rows ; i++){
            zero_row[i] = false;
        }
        bool zero_col[cols] ;
        for(int i = 0; i < cols ; i++){
            zero_col[i] = false;
        }

        
        for(int i = 0; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(matrix[i][j] == 0){
                    zero_row[i] = true;
                    zero_col[j] = true;
                }
            }
        }
        for(int i = 0 ; i < rows ; i++){
            if(zero_row[i]){
                for(int j = 0 ; j < cols ; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0 ; i < cols ; i++){
            if(zero_col[i]){
                for(int j = 0 ; j < rows ; j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};


/* Move Zeroes */
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        for(int j = 0 ; j < n ; j++){
            if(arr[j] != 0){
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
};

/* Best Time to buy and sell stock */
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // Here also we can use the same approach as we used in 2 sum problem;
        int n = arr.size();
        int maxPrice = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, arr[i]);
            maxPrice = max(maxPrice, arr[i] - minPrice);
        }
  return maxPrice;
    }
};
