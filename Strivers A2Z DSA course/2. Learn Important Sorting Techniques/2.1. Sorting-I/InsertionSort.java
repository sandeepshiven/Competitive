import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {

    public static void insertionSort(List<Integer> arr, int n) {
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j > 0 && (arr.get(j - 1) > arr.get(j))) {
                Collections.swap(arr, j - 1, j);
                j--;
            }
        }
    }

    public static void main(String[] args) {

        int n;
        System.out.print("Enter the size of array: ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.print("Enter elements: ");
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        insertionSort(arr, n);
        System.out.println("Sorted array: " + arr);
    }

}
