import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class BubbleSort {

    public static void bubbleSort(List<Integer> arr, int n) {
        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int j = i; j < n - i - 1; j++) {
                if (arr.get(j + 1) < arr.get(j)) {
                    flag = false;
                    Collections.swap(arr, j, j + 1);
                }
            }
            if (flag) {
                break;
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
        bubbleSort(arr, n);
        System.out.println("Sorted array: " + arr);
    }
}
