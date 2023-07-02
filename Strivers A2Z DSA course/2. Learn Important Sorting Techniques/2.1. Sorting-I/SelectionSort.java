import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class SelectionSort {

    public static void selectionSort(List<Integer> arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            int mini = i;
            for (int j = i; j < n; j++) {
                if (arr.get(j) < arr.get(mini)) {
                    mini = j;
                }
            }
            Collections.swap(arr, i, mini);
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
        selectionSort(arr, n);
        System.out.println("Sorted array: " + arr);
    }

}
