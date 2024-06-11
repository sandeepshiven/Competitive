import java.io.*;
import java.util.*;
import java.lang.*;

public class Test {

    public static void main(String args[] ) throws Exception {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        
        int [] weights = new int[n];

        for(int i=0; i<n; i++){
            weights[i] = sc.nextInt();
        }
        
        int matrix[][] = new int[n][n];
        
        Map<Integer, Integer> mp = new HashMap<>();
        int largest = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = weights[i]+weights[j];
                mp.computeIfPresent(sum, (k, v) -> v+1);
                mp.putIfAbsent(sum, 1);

                largest = Math.max(largest, mp.get(sum));
                
            }
        }
        System.out.println(largest);
    }
    
}
