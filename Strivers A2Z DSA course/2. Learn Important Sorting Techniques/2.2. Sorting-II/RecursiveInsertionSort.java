public class RecursiveInsertionSort {

    public void insertionSort(int arr[], int n) {
        if (n <= 1) {
            return;
        }
        insertionSort(arr, n - 1);
        int j = n - 1;
        while (j > 0 && (arr[j - 1] > arr[j])) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

}
