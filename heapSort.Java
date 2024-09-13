package src;

import src.jsjf.ArrayUnorderedList;
import src.jsjf.ArrayHeap;
import java.util.*;


public class HeapSort<T> {

    //Creates a max heap
    public void sortMax(T data[]) 
    { 
        int length = data.length;

        //Builds heap
        for (int i = length/2 - 1; i >= 0; i--){
            heapifyMax(data, length, i);
        }

        // One by one extracts an element from heap
        for (int i = length - 1; i > 0; i--) {
            // Move current root to end
            T temp = data[0];
            data[0] = data[i];
            data[i] = temp;

            // calls heapifyMax
            heapifyMax(data, i, 0);
        } 
    }

    void heapifyMax(T arr[], int N, int root)
    {
        //largest as root
        int largest = root; 
        //left and right child
        int leftChild = 2 * largest + 1; 
        int rightChild = 2 * largest + 2; 

        // If left child is larger 
        if (leftChild < N && ((Comparable) arr[leftChild]).compareTo(arr[largest]) < 0)
            largest = leftChild;

        // If right child is larger 
        if (rightChild < N && ((Comparable) arr[rightChild]).compareTo(arr[largest]) < 0)
            largest = rightChild;

        // If largest is not root - swap
        if (largest != root) {
            T swap = arr[root];
            arr[root] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify
            heapifyMax(arr, N, largest);
        }
    }

    public void sortMin(T data[]) 
    { 
        int length = data.length;

        // Build heap 
        for (int i = length/2 - 1; i >= 0; i--){
            heapifyMin(data, length , i);
        }

        // One by one extract an element from heap
        for (int i = length  - 1; i > 0; i--) {
            // Move current root to end
            T temp = data[0];
            data[0] = data[i];
            data[i] = temp;

            // call max heapify on the reduced heap
            heapifyMin(data, i, 0);
        } 
    }

    void heapifyMin(T arr[], int indexZero, int root)
    {
        // Initialize smallest as root
        int min = root; 
        //left and right child
        int leftChild = 2 * min + 1;  
        int rightChild = 2 * min + 2; 

        //If left child is smaller than root
        if (leftChild < indexZero && ((Comparable) arr[leftChild]).compareTo(arr[min]) > 0)
            min = leftChild;

        //If right child is smaller
        if (rightChild < indexZero && ((Comparable) arr[rightChild]).compareTo(arr[min]) > 0)
            min = rightChild;

        // If smallest is not root - swap
        if (min != root) {
            T swap = arr[root];
            arr[root] = arr[min];
            arr[min] = swap;

            // Recursively heapify 
            heapifyMin(arr, indexZero, min);
        }
    }

}
