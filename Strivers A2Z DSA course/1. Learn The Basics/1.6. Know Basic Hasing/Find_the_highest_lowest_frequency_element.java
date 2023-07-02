import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;


public class Find_the_highest_lowest_frequency_element {
    public int[] topK(int[] nums, int k) {

        Map<Integer, Integer>mp = new HashMap<>();
        for(int x: nums){
            mp.merge(x, 1, Integer::sum);
        }
        List<List<Integer>> arr = new ArrayList<>();
        mp.forEach((key, value) -> {
            arr.add(Arrays.asList(key, value));
        });
        Collections.sort(arr, (a1, a2) -> {
            if(a1.get(1).equals(a2.get(1))){
                return a2.get(0).compareTo(a1.get(0));
            }
            return a2.get(1).compareTo(a1.get(1));
        });
        // for(List<Integer>l : arr){
        //     System.out.println(l.get(0) + " ---> " + l.get(1));
        // }
        int res [] = new int[k];
        for(int i=0; i<k; i++){
            res[i] = arr.get(i).get(0);
        }
        return res;
    }
}
