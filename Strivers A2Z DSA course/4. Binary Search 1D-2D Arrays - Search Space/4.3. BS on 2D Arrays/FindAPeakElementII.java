public class FindAPeakElementII {
    
}
class Solution {
    public int[] findPeakGrid(int[][] mat) {

        int n = mat.length;
        int m = mat[0].length;

        int row = n/2, col = m/2;
        while((row < n && row >= 0) && (col < m && col >= 0)){

            int left, right, top, bottom, greaterRow = row, greaterCol = col, greaterEle;
            left = right = top = bottom = greaterEle = -1;

            if(row > 0){
                top = mat[row-1][col];
                if(top > greaterEle){
                    greaterEle = top;
                    greaterRow = row - 1;
                    greaterCol = col;
                }
            }

            if(row < n-1){
                bottom = mat[row+1][col];
                if(bottom > greaterEle){
                    greaterEle = bottom;
                    greaterRow = row + 1;
                    greaterCol = col;
                }
            }


            if(col > 0){
                left = mat[row][col-1];
                if(left > greaterEle){
                    greaterEle = left;
                    greaterRow = row;
                    greaterCol = col-1;
                }
            }


            if(col < m-1){
                right = mat[row][col+1];
                if(right > greaterEle){
                    greaterEle = right;
                    greaterRow = row;
                    greaterCol = col+1;
                }
            }

            if(mat[row][col] > top && mat[row][col] > bottom && mat[row][col] > left 
            && mat[row][col] > right){
                return new int[]{row, col};
            }
            else{
                row = greaterRow;
                col = greaterCol;
            }       


        }
        
        return new int[]{2, 2};
    }
}


class Solution2{

    public int findMaxEleRow(int[][] mat, int n, int m){

        int idx  = 0;
        for(int i=0; i<n; i++){
            if(mat[i][m] > mat[idx][m]){
                idx = i;
            }
        }
        return idx;

    }
    public int[] findPeakGrid(int[][] mat) {
        

        int n = mat.length;
        int m = mat[0].length;

        // spliting into columns and checking right and left
        int low = 0, high = m-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = findMaxEleRow(mat, n, mid);
            int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1]: -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return new int[]{row, mid};
            }
            else if(mat[row][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        return new int[]{0, 0};
    }
}


































