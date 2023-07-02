public class RecursiveBubbleSort {

    public static void bubbleSort(int arr[], int n) {
        if (n <= 0) {
            return;
        }

        boolean flag = true;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = false;
            }
        }

        if (flag) {
            return;
        }

        bubbleSort(arr, n - 1);
    }

}
