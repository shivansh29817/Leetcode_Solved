class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int total_row_index= matrix.size()-1;
            int total_col = matrix[0].size()-1;
//   cout<<total_column_index;
      int low=0;
      int high = total_row_index;
      int mid=0;
      while(low<high)
      {
            mid=(low+high)/2;
            if(matrix[mid][total_col] < target)
            {
                low=mid+1;

            }
            else
            {
                high = mid;

            }
            


      }
      low=0;
      mid=0;
      int sr = high;
      high=total_col;
      while(low<high)
      {
            mid = (low+high)/2;
            if(matrix[sr][mid] < target)
            {
                low=mid+1;
            }
            else
            {
                high = mid;

            }

      }
        if(matrix[sr][low] == target)
        {
            return true;
        }

        return false;

    }
};