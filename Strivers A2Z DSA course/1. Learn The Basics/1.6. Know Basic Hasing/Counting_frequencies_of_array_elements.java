import java.util.HashMap;
import java.util.Map;

public class  Counting_frequencies_of_array_elements{
    

    public static void frequencyCount(int arr[], int n, int p)
    {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int x: arr){
            mp.merge(x, 1, Integer::sum);
        }
        for(int i=1; i<=n; i++){
            Integer x = mp.get(i);
            if(x == null){
                arr[i-1] = 0;
            }
            else{
                arr[i-1] = x;
            }
        }
    }

}
