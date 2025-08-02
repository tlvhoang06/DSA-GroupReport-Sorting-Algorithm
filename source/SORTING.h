#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<time.h>
#include<chrono>
#include<set>


using namespace std;
using namespace chrono;
using ll = long long;


struct Result
{
    ll comparison;
    double runTime;
};

Result ExecuteSortAndGetRecord(int a[], int n, string algorithm);

// Function read command line arguments:
void CMD1(vector<string> Algorithms, string inputFile, string outputParameter);
void CMD2(vector<string> Algorithms, int inputSize, string inputOrder, string outputParameter);
void CMD3(vector<string> Algorithms, int inputSize, string outputParameter);
void CMD4(vector<string> Algorithms, string inputFile);
void CMD5(vector<string> Algorithms, int inputSize, string inputOrder);
void ReadCmdArg(int argc, char* argv[]);

// Original sorting algorithm function:
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void ShellSort(int a[], int n);
void BubbleSort(int a[], int n);
void HeapSort(int a[], int n);
void MergeSort(int a[], int n);
void QuickSort(int a[], int n);
void RadixSort(int a[], int n);
void CountingSort(int a[], int n);
void BinaryInsertionSort(int a[], int n);
void ShakerSort(int a[], int n);
void FlashSort(int a[], int n);


// Sorting function algorithm count comparisons:
void SelectionSort_cmp(int a[], int n, ll &countCmp);
void InsertionSort_cmp(int a[], int n, ll &countCmp);
void ShellSort_cmp(int a[], int n, ll &countCmp);
void BubbleSort_cmp(int a[], int n, ll &countCmp);
void HeapSort_cmp(int a[], int n, ll &countCmp);
void MergeSort_cmp(int a[], int n, ll &countCmp);
void QuickSort_cmp(int a[], int n, ll &countCmp);
void RadixSort_cmp(int a[], int n, ll &countCmp);
void CountingSort_cmp(int a[], int n, ll &countCmp);
void BinaryInsertionSort_cmp(int a[], int n, ll &countCmp);
void ShakerSort_cmp(int a[], int n, ll &countCmp);
void FlashSort_cmp(int a[], int n, ll &countCmp);


// Generate Array:
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);