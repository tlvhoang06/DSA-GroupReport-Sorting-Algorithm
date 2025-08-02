#include"SORTING.h"

// Function to get Record from each sort algorithm:
Result ExecuteSortAndGetRecord(int a[], int n, string algorithm)
{
    Result newResult = {0, 0.0};
    int* copya = new int[n];
    for (int i = 0; i < n; i++)
        copya[i] = a[i];

    clock_t start, end;

    if (algorithm == "selection-sort")
    {
        SelectionSort_cmp(a, n, newResult.comparison);
        start = clock();
        SelectionSort(copya, n);
        end = clock();
    }
    else if (algorithm == "insertion-sort")
    {
        InsertionSort_cmp(a, n, newResult.comparison);
        start = clock();
        InsertionSort(copya, n);
        end = clock();
    }
    else if (algorithm == "shell-sort")
    {
        ShellSort_cmp(a, n, newResult.comparison);
        start = clock();
        ShellSort(copya, n);
        end = clock();
    }
    else if (algorithm == "bubble-sort")
    {
        BubbleSort_cmp(a, n, newResult.comparison);
        start = clock();
        BubbleSort(copya, n);
        end = clock();
    }
    else if (algorithm == "heap-sort")
    {
        HeapSort_cmp(a, n, newResult.comparison);
        start = clock();
        HeapSort(copya, n);
        end = clock();
    }
    else if (algorithm == "merge-sort")
    {
        MergeSort_cmp(a, n, newResult.comparison);
        start = clock();
        MergeSort(copya, n);
        end = clock();
    }
    else if (algorithm == "quick-sort")
    {
        QuickSort_cmp(a, n, newResult.comparison);
        start = clock();
        QuickSort(copya, n);
        end = clock();
    }
    else if (algorithm == "radix-sort")
    {
        RadixSort_cmp(a, n, newResult.comparison);
        start = clock();
        RadixSort(copya, n);
        end = clock();
    }
    else if (algorithm == "counting-sort")
    {
        CountingSort_cmp(a, n, newResult.comparison);
        start = clock();
        CountingSort(copya, n);
        end = clock();
    }
    else if (algorithm == "binaryinsertion-sort")
    {
        BinaryInsertionSort_cmp(a, n, newResult.comparison);
        start = clock();
        BinaryInsertionSort(a, n);
        end = clock();
    }
    else if (algorithm == "shaker-sort")
    {
        ShakerSort_cmp(a, n, newResult.comparison);
        start = clock();
        ShakerSort(copya, n);
        end = clock();
    }
    else if (algorithm == "flash-sort")
    {
        FlashSort_cmp(a, n, newResult.comparison);
        start = clock();
        FlashSort(copya, n);
        end = clock();
    }
    

    newResult.runTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    delete[] copya;
    return newResult;
}
    
// Selection Sort algorithm:
void SelectionSort_cmp(int a[], int n, ll &countCmp)
{
    for (int i = 0; ++countCmp && i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; ++countCmp && j < n; j++)
        {
            if (++countCmp && a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if (++countCmp && i != minIndex)
        {
            swap(a[i], a[minIndex]);
        }
    }
}
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            swap(a[i], a[minIndex]);
        }       
    }
}

// Insertion Sort algorithm:
void InsertionSort_cmp(int a[], int n, ll &countCmp)
{
    for (int i = 1; ++countCmp && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while ((++countCmp && j >= 0) && (++countCmp && a[j] > key))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Shell Sort algorithm:
void ShellSort_cmp(int a[], int n, ll &countCmp)
{
    for(int gap = n / 2; ++countCmp && gap > 0; gap /= 2)
    {
        for(int i = gap; ++countCmp && i < n; i++)
        {
            int temp = a[i];
            int j;
            for(j = i; ++countCmp && j >= gap && ++countCmp && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
void ShellSort(int a[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

// Bubble Sort algorithm:
void BubbleSort_cmp(int a[], int n, ll &countCmp)
{
    for(int i = 0; ++countCmp && i < n; i++)
    {
        for(int j = 0; ++countCmp && j < n - i - 1; j++)
        {
            if(++countCmp && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Heap Sort algorithm:
void heapRebuild_cmp(int a[], int i, int n, ll &countCmp)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++countCmp && left < n && ++countCmp && a[left] > a[largest])
    {
        largest = left;
    }
    if (++countCmp && right < n && ++countCmp && a[right] > a[largest])
    {
        largest = right;
    }

    if (++countCmp && largest != i)
    {
        swap(a[i], a[largest]);
        heapRebuild_cmp(a, largest, n, countCmp);
    }
}
void heapConstruct_cmp(int a[], int n, ll &countCmp)
{
    for (int i = n / 2 - 1; ++countCmp && i >= 0; i--)
    {
        heapRebuild_cmp(a, i, n, countCmp);
    }
}
void HeapSort_cmp(int a[], int n, ll &countCmp)
{
    heapConstruct_cmp(a, n, countCmp);

    for (int i = n - 1; ++countCmp && i > 0; i--)
    {
        swap(a[i], a[0]);
        heapRebuild_cmp(a, 0, i, countCmp);
    }
}

void heapRebuild(int a[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapRebuild(a, largest, n);
    }
}
void heapConstruct(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapRebuild(a, i, n);
    }
}
void HeapSort(int a[], int n)
{
    heapConstruct(a, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapRebuild(a, 0, i);
    }
}

// Merge Sort algorithm:
void Merge_cmp(int a[], int left, int mid, int right, ll &countCmp)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; ++countCmp && i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; ++countCmp && j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (++countCmp && i < n1 && ++countCmp && j < n2)
    {
        if (++countCmp && L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (++countCmp && i < n1)
        a[k++] = L[i++];
    while (++countCmp && j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergesort_cmp(int a[], int left, int right, ll &countCmp)
{
    if (++countCmp && left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort_cmp(a, left, mid, countCmp);
        mergesort_cmp(a, mid + 1, right, countCmp);
        Merge_cmp(a, left, mid, right, countCmp);
    }
}
void MergeSort_cmp(int a[], int n, ll &countCmp)
{
    return mergesort_cmp(a, 0, n - 1, countCmp);
}

void Merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}
void MergeSort(int a[], int n)
{
    return mergesort(a, 0, n - 1);
}

// Quick Sort algorithm:
int Partition_cmp(int a[], int first, int last, int pivot, ll &countCmp)
{
    int lastS1 = first;
    int firstUnknown = first + 1;
    while(++countCmp && firstUnknown <= last)
    {
        if(++countCmp && a[firstUnknown] < a[pivot])
        {
            swap(a[firstUnknown], a[lastS1 + 1]);
            lastS1++;
        }
        firstUnknown++;
    }
    swap(a[lastS1], a[pivot]);
    return lastS1;
}
void quicksort_cmp(int a[], int first, int last, ll &countCmp)
{
    if(++countCmp && first < last)
    {
        int pivotIndex = Partition_cmp(a, first, last, first, countCmp);
        quicksort_cmp(a, first, pivotIndex - 1, countCmp);
        quicksort_cmp(a, pivotIndex + 1, last, countCmp);
    }
}
void QuickSort_cmp(int a[], int n, ll &countCmp)
{
    quicksort_cmp(a, 0, n - 1, countCmp);
}

int Partition(int a[], int first, int last, int pivot)
{
    int lastS1 = first;
    int firstUnknown = first + 1;
    while(firstUnknown <= last)
    {
        if(a[firstUnknown] < a[pivot])
        {
            swap(a[firstUnknown], a[lastS1 + 1]);
            lastS1++;
        }
        firstUnknown++;
    }
    swap(a[lastS1], a[pivot]);
    return lastS1;
}
void quicksort(int a[], int first, int last)
{
    if(first < last)
    {
        int pivotIndex = Partition(a, first, last, first);
        quicksort(a, first, pivotIndex - 1);
        quicksort(a, pivotIndex + 1, last);
    }
}
void QuickSort(int a[], int n)
{
    quicksort(a, 0, n - 1);
}

// Radix Sort algorithm:
void CountSort_cmp(int a[], int n, int exp, ll &countCmp)
{
    int* output = new int[n];
    int i;
    int count[10] = { 0 };

    for (i = 0; ++countCmp && i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; ++countCmp && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++countCmp && i >= 0; i--) 
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; ++countCmp && i < n; i++)
        a[i] = output[i];
    
    delete[] output;
}
void RadixSort_cmp(int a[], int n, ll &countCmp)
{
    int max = a[0];
    for(int i = 1; ++countCmp && i < n; i++)
    {
        if(++countCmp && max < a[i]) max = a[i];
    }

    for (int exp = 1; ++countCmp && max / exp > 0; exp *= 10)
        CountSort_cmp(a, n, exp, countCmp);
}

void CountSort(int a[], int n, int exp)
{
    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) 
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
    
    delete[] output;
}
void RadixSort(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(max < a[i]) max = a[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        CountSort(a, n, exp);
}

// Couting Sort algorithm:
void CountingSort_cmp(int a[], int n, ll &countCmp)
{
    int max = a[0];

    for(int i = 1; ++countCmp && i < n; i++)
    {
        if(++countCmp && a[i] > max)
        {
            max = a[i];
        }
    }

    int* count = new int[max + 1]();
    int* ans = new int[n];

    for(int i = 0; ++countCmp && i < n; i++)
    {
        count[a[i]]++;
    }
    for(int i = 1; ++countCmp && i <= max; i++)
    {
        count[i] += count[i -1];
    }
    for(int i = n - 1; ++countCmp && i >= 0; i--)
    {
        ans[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for(int i = 0; ++countCmp && i < n; i++)
    {
        a[i] = ans[i];
    }

    delete[] ans;
    delete[] count;
}
void CountingSort(int a[], int n)
{
    int max = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    int* count = new int[max + 1]();
    int* ans = new int[n];

    for(int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for(int i = 1; i <= max; i++)
    {
        count[i] += count[i -1];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        ans[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = ans[i];
    }

    delete[] ans;
    delete[] count;
}

// Binary Insertion Sort algorithm:
int BinarySearch_cmp(const int a[], int item, int low, int high, ll &countCmp)
{
    while (++countCmp && low <= high)
    {
        int mid = low + (high - low) / 2;
        if (++countCmp && item == a[mid])
            return mid + 1;
        else if (++countCmp && item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void BinaryInsertionSort_cmp(int a[], int n, ll &countCmp)
{
    for (int i = 1; ++countCmp && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        int position = BinarySearch_cmp(a, key, 0, j, countCmp);

        while (++countCmp && j >= position)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int BinarySearch(const int a[], int item, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void BinaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        int position = BinarySearch(a, key, 0, j);

        while (j >= position)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Shaker Sort algorithm: 
void ShakerSort_cmp(int a[], int n, ll &countCmp)
{
    int left, right, k, i;
    left = 0;
    right = n - 1;
    k = n - 1;
    while(++countCmp && left < right) 
    {
        for(i = right; ++countCmp && i > left; i--)
        {
            if(++countCmp && a[i] < a[i - 1]) 
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }          
        left = k;

        for(i = left; ++countCmp && i < right; i++)
        {
            if(++countCmp && a[i] > a[i + 1]) 
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}
void ShakerSort(int a[], int n)
{
    int left, right, k, i;
    left = 0;
    right = n - 1;
    k = n - 1;
    while(left < right) 
    {
        for(i = right; i > left; i--)
            if(a[i] < a[i - 1]) 
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k;

        for(i = left; i < right; i++)
            if(a[i] > a[i + 1]) 
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        right = k;
    }
}

// Flash Sort algorithm:
int getBucketID(int value, int min_val, int max_val, int m)
{  
    return (m * (value - min_val)) / (max_val - min_val + 1);
}
void FlashSort_cmp(int a[], int n, ll &countCmp) 
{
    if (++countCmp && n <= 1) return;

    int min_val = a[0];
    int max_val = a[0];
    for (int i = 1; ++countCmp && i < n; ++i) 
    {
        if (++countCmp && a[i] < min_val) min_val = a[i];
        if (++countCmp && a[i] > max_val) max_val = a[i];
    }
    if (++countCmp && min_val == max_val) return;

    int m = max(static_cast<int>(floor(0.45 * n)), 1);
    ++countCmp;
    m = max(m, 1);
    ++countCmp;
    int* Lb = new int[m]();

    for (int i = 0; ++countCmp && i < n; i++) 
    {
        int b_id = getBucketID(a[i], min_val, max_val, m);
        Lb[b_id]++;
    }

    for (int i = 1; ++countCmp && i < m; ++i) {
        Lb[i] += Lb[i - 1];
    }

    for (int b = 0; ++countCmp && b < m - 1; ++b) {
        int start = (++countCmp && b == 0) ? 0 : Lb[b - 1];
        int end = Lb[b];
        for (int i = start; ++countCmp && i < end; i++) {
            int current_b = getBucketID(a[i], min_val, max_val, m);
            while (++countCmp && current_b != b) {
                int swap_start = (++countCmp && current_b == 0) ? 0 : Lb[current_b - 1];
                int swap_end = Lb[current_b];
                int swap_idx = -1;
                for (int j = swap_start; ++countCmp && j < swap_end; j++) {
                    if (++countCmp && getBucketID(a[j], min_val, max_val, m) != current_b) {
                        swap_idx = j;
                        break;
                    }
                }

                if (++countCmp && swap_idx == -1) {
                    swap_idx = swap_end - 1;
                }
                
		swap(a[swap_idx], a[i]);
                current_b = getBucketID(a[i], min_val, max_val, m);
            }
        }
    }

    for (int i = 0; ++countCmp && i < m; ++i) {
        int start = (++countCmp && i == 0) ? 0 : Lb[i - 1];
        int end = Lb[i];
        for (int j = start + 1; ++countCmp && j < end; ++j) {
            int temp = a[j];
            int k = j - 1;
            while (++countCmp && k >= start && ++countCmp && temp < a[k]) {
                a[k + 1] = a[k];
                k--;
            }
            a[k + 1] = temp;
        }
    }

    delete[] Lb;
}
void FlashSort(int a[], int n) 
{
    if (n <= 1) return;

    int min_val = a[0];
    int max_val = a[0];
    for (int i = 1; i < n; ++i) 
    {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    if (min_val == max_val) return;

    int m = max(static_cast<int>(floor(0.45 * n)), 1);
    m = max(m, 1);
    int* Lb = new int[m]();

    for (int i = 0; i < n; i++) 
    {
        int b_id = getBucketID(a[i], min_val, max_val, m);
        Lb[b_id]++;
    }

    for (int i = 1; i < m; ++i) {
        Lb[i] += Lb[i - 1];
    }

    for (int b = 0; b < m - 1; ++b) {
        int start = (b == 0) ? 0 : Lb[b - 1];
        int end = Lb[b];
        for (int i = start; i < end; i++) {
            int current_b = getBucketID(a[i], min_val, max_val, m);
            while (current_b != b) {
                int swap_start = (current_b == 0) ? 0 : Lb[current_b - 1];
                int swap_end = Lb[current_b];
                int swap_idx = -1;
                for (int j = swap_start; j < swap_end; j++) {
                    if (getBucketID(a[j], min_val, max_val, m) != current_b) {
                        swap_idx = j;
                        break;
                    }
                }

                if (swap_idx == -1) {
                    swap_idx = swap_end - 1;
                }
                
		swap(a[swap_idx], a[i]);
                current_b = getBucketID(a[i], min_val, max_val, m);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int start = (i == 0) ? 0 : Lb[i - 1];
        int end = Lb[i];
        for (int j = start + 1; j < end; ++j) {
            int temp = a[j];
            int k = j - 1;
            while (k >= start && temp < a[k]) {
                a[k + 1] = a[k];
                k--;
            }
            a[k + 1] = temp;
        }
    }

    delete[] Lb;
}
