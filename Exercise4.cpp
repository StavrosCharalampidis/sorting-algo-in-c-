//Christos Charalampidis icsd21071 
//Stavros Charalampidis icsd22239

#include <iostream>
#include <vector>
#include <time.h>

// Function signatures
void swap(int &A, int &B);
void SwapPivot(int *A, int *B);
void InsertionSort(std::vector<int> &Array, int *Counter);
void SelectionSort(std::vector<int> &Array, int *Counter);
void QuickSort(std::vector<int> &Array, int Left, int Right, int *Counter);
void MergeSort(std::vector<int> &Array, int Left, int Right, int *Counter);
void HeapSort(std::vector<int> &heap, int N, int *Counter);
void merge(std::vector<int> &arr, int Left, int Mid, int Right, int *Counter);
int Partition(std::vector<int> &array, int Left, int Right, int *Counter);
void FixHeap(std::vector<int> &heap, int i, int hs);
void createHeap(std::vector<int> &heap, int N);
void printArr(std::vector<int> &Array);

int main() {
    srand(time(0));
    clock_t start, end;
    double elapsed;
    double Time1 = 0, Time2 = 0, Time3 = 0, Time4 = 0, Time5 = 0;
    int Comparisons1 = 0, Comparisons2 = 0, Comparisons3 = 0, Comparisons4 = 0, Comparisons5 = 0, Times = 0;
    int N;

    std::cout << "Give the size of the array: " << std::endl;
    std::cin >> N;
    std::vector<int> ArrayList(N);

    int choice;
    // Menudaki
    std::cout << "Press 1 For Insertion Sort: ";
    std::cout << "Press 2 For Selection Sort: ";
    std::cout << "Press 3 For Merge Sort: ";
    std::cout << "Press 4 For Quick Sort: ";
    std::cout << "Press 5 For Heap Sort: ";
    std::cin >> choice;

    

    for (int i = 0; i < 30; ++i) {
        // Initialization of the array with random integers
        for (int i = 0; i < ArrayList.size(); i++) {
            ArrayList[i] = rand() % 10001;   
        }

        // switch case for choice sorting
        switch (choice) {
            case 1:
                start = clock();

                // Call the InsertionSort Function
                InsertionSort(ArrayList, &Times);

                Comparisons1 += Times;
                end = clock();
                elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                Time1 += elapsed;
            
                break;

            case 2:
                start = clock();

                // Call the SelectionSort Function
                SelectionSort(ArrayList, &Times);

                Comparisons2 += Times;
                end = clock();
                elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                Time2 += elapsed;
                break;

            case 3:
                start = clock();

                // Call the MergeSort Function
                MergeSort(ArrayList, 0, N - 1, &Times);

                Comparisons3 += Times;
                end = clock();
                elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                Time3 += elapsed;
                break;

            case 4:
                start = clock();

                // Call the QuickSort Function
                QuickSort(ArrayList, 0, N - 1, &Times);

                Comparisons4 += Times;
                end = clock();
                elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                Time4 += elapsed;
                break;

            case 5:
                start = clock();

                // Call the HeapSort Function
                HeapSort(ArrayList, N, &Times);

                Comparisons5 += Times;
                end = clock();
                elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                Time5 += elapsed;
                break;

            default:
                std::cout << "Invalid choice for Sorting." << std::endl;
            
        }


    }

    // switch case, Comparisons and time for sorting
    switch (choice) {
        case 1:
            // print size of array, the Avg Comparisons and time for Insertion Sort
            printf("Insertion Sort (Avg Comparisons %.6f)\n",(float)Comparisons1 / 30);
            printf("Insertion Sort (Size %d): %lf seconds\n", N, Time1 / 30);
            break;
        
        case 2:
            // print size of array, the Avg Comparisons and time for Selection Sort
            printf("Selection Sort (Avg Comparisons %.6f)\n",(float)Comparisons2 / 30);
            printf("Selection Sort (Size %d): %lf seconds\n", N, Time2 / 30);
            break;

        case 3:
            // print size of array, the Avg Comparisons and time for Merge Sort
            printf("Merge Sort (Avg Comparisons %.6f)\n",(float)Comparisons3 / 30);
            printf("Merge Sort (Size %d): %lf seconds\n", N, Time3 / 30);
            break;

        case 4:
            // print size of array, the Avg Comparisons and time for Quick Sort
            printf("Quick Sort (Avg Comparisons %.6f)\n",(float)Comparisons4 / 30);
            printf("Quick Sort (Size %d): %lf seconds\n", N, Time4 / 30);
            break;

        case 5:
            // print size of array, the Avg Comparisons and time for Heap Sort
            printf("Heap Sort (Avg Comparisons %.6f)\n",(float)Comparisons5 / 30);
            printf("Heap Sort (Size %d): %lf seconds\n", N, Time5 / 30);
            break;
    }

    std::cout << "" << std::endl;
    return 0;
}

// Function for swap two
void swap(int &A, int &B) {
    // declar temp equals A
    int temp = A;
    // A equals B
    A = B;
    // B equals temp
    B = temp;
}

// Function for swap two
void SwapPivot(int *A, int *B) {
    // declar temp equals A
    int temp = *A;
    // A equals B
    *A = *B;
    // B equals temp
    *B = temp;
}

// Function for Insertion Sort 
void InsertionSort(std::vector<int> &Array, int *Counter) {
    int N = Array.size();
    *Counter = 0;
    for (int i = 0; i < N; i++) {
        int pos = i;
        while (pos > 0 && Array[pos] < Array[pos - 1]) {
            
            // call the swap Function
            swap(Array[pos], Array[pos - 1]);
            pos--;
            // Increase counter for the final comparison
            (*Counter)++;
        }
    }
}

// Function for Selection Sort 
void SelectionSort(std::vector<int> &Array, int *Counter) {
    int N = Array.size();
    *Counter = 0;
    // Cross the entire array
    for (int i = 0; i < N - 1; i++)
    {
        // find the minimum element in the unsorted array
        int min = i;

        for (int j = i + 1; j < N; j++)
        {
            // Array[j] < Array[min] for ascending order
            if (Array[j] < Array[min])
            {
                min = j;
            }
            (*Counter)++;
        }

        if (min != i)
        {
            
            
            swap(Array[i], Array[min]);
        }
    }
}

// Function for Merge two subarrays
void merge(std::vector<int> &arr, int Left, int Mid, int Right, int *Counter) {
    int n1 = Mid - Left + 1;
    int n2 = Right - Mid;

    // create temp arrays to store Left and Right subarrays
    int L[n1], R[n2];

    // Copying data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[Left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[Mid + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = Left;

    while (i < n1 && j < n2) {
        // place the smaller item at arr[k] pos
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
        // Increase counter for the final comparison
        (*Counter)++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function for Merge Sort 
void MergeSort(std::vector<int> &Array, int Left, int Right, int *Counter) {
    int Mid;
    *Counter = 0;
    if (Left < Right)
    {
        // Mid is divided into two subarrays
        int Mid = Left + (Right - Left) / 2;
        

        // recursive calls to sort first half and second half subarrays
        MergeSort(Array, Left, Mid, Counter);
        MergeSort(Array, Mid + 1, Right, Counter);

        // Merge the sorted subarrays
        merge(Array, Left, Mid, Right, Counter);
    }

}

// Function to rearrange array (find the partition point)
int Partition(std::vector<int> &array, int Left, int Right, int *Counter) {
    // select the rightmost element as pivot
    int pivot = array[Right];

    // pointer for greater element
    int i = (Left - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = Left; j < Right; j++) {
        if (array[j] <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            SwapPivot(&array[i], &array[j]);
            
        }
    }

    // swap pivot with the greater element at i
    SwapPivot(&array[i + 1], &array[Right]);
    // Increase counter for the final comparison
    (*Counter)++;

    // return the partition point
    return (i + 1);
}

// Function for Quick Sort 
void QuickSort(std::vector<int> &Array, int Left, int Right, int *Counter) {
    if (Left < Right) {
        // indexP is partitioning index
        int indexP = Partition(Array, Left, Right, Counter);

        // recursive call on the left partition
        QuickSort(Array, Left, indexP - 1, Counter);

        // recursive call on the right partition
        QuickSort(Array, indexP + 1, Right, Counter);
    }
}

void FixHeap(std::vector<int> &heap, int i, int hs) {
    // Find smallest root, left child, and right child
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < hs && heap[left] > heap[smallest])
    {
        smallest = left;
    }

    if (right < hs && heap[right] > heap[smallest])
    {
        smallest = right;
    }

    // Swap and continue heapifying if root is not the smallest
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        // Corrected the recursive call
        FixHeap(heap, smallest, hs);
    }
}

// Iterate from the last parent to the root
void createHeap(std::vector<int> &heap, int N) {
    int hs = N;
    for (int i = N / 2; i >= 0; i--)
    {
        // Restoration heap down
        FixHeap(heap, i, hs);
    }
}

// Heap sort
void HeapSort(std::vector<int> &heap, int N, int *Counter) {
    // Create min Heap
    createHeap(heap, N);
    int hs = N;
    *Counter = 0;

    // Heap sort
    for (int i = N - 1; i > 0; i--)
    {
        (*Counter)++;
        swap(heap[0], heap[i]);
        hs--;

        // Corrected the index for FixHeap
        FixHeap(heap, 0, hs);
        // Increase counter for the final comparison
        (*Counter)++; 
    }
}

// Function for print the array
void printArr(std::vector<int> &Array) {
    std::cout << "Sorted array: ";
    for (int num : Array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}