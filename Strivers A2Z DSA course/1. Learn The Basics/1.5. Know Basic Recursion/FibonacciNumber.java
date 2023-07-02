public class FibonacciNumber {

    public static void helper(long arr[], int i, int n){
        if(i == n){
            return;
        }
        arr[i] = arr[i-1] + arr[i-2];
        helper(arr, ++i, n);
    }

    public static long[] printFibb(int n) {

        long arr[] = new long[n];
        arr[0] = 1;
        if(n == 1){
            return arr;
        }
        arr[1] = 1;
        if(n == 2){
            return arr;
        }

        helper(arr, 2, n);

        return arr;

    }
    
        //Your code here
    
}


// leet code

class Solution {

    public int helper(int a, int b, int i, int n){

        if(i > n){
            return b;
        }
        return helper(b, a+b, ++i, n);
    }

    public int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        return helper(0, 1, 2, n);
    }

    // multiple recursion calls
    public int fib2(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        
        return fib(n-1) + fib(n-2);
    }
}