public class ReverseWordsInAString {
    
}
class Solution {
    public String reverseWords(String s) {
        

        int n = s.length();
        char [] arr = s.toCharArray();
        int left = 0, right=0;
        reverse(arr, 0, n-1);

        for(int i=0; i<n; ){
            while(i<n && arr[i]==' ') i++;

            if(i == n) break;

            while(i<n && arr[i] != ' '){
                arr[right] = arr[i];
                right++;
                i++;
            }
            reverse(arr, left, right-1);
            if(right == n){
                right++;
                break;
            } 
            arr[right] = ' ';
            right++;
            left = right;
            i++;

        }

        StringBuilder res = new StringBuilder("");
        for(int i=0; i<right-1; i++){
            res.append(arr[i]);
        }

        return res.toString();
    }

    public void reverse(char a[], int start, int end){
        while(start < end){
            char temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }
}