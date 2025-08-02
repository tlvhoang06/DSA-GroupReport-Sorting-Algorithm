#include"SORTING.h"

// Functions to solve the command line argument:
bool CheckStringisNumber(string s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

// Functions to solve 5 CMDs:
void CMD1(vector<string> Algorithms, string inputFile, string outputParameter)
{
	cout << "Algorithm: " << Algorithms[0] << endl;
	cout << "Input file: " << inputFile << endl;
	cout << "---------------------------------" << endl;

	ifstream fileIn(inputFile);
	int n;
	fileIn >> n;
	cout << "Input size: " << n << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fileIn >> a[i];
	}
	fileIn.close();

	Result SortResult = ExecuteSortAndGetRecord(a, n, Algorithms[0]);

	if (outputParameter == "-time")
		cout << "Running time: " << SortResult.runTime << "ms" << endl;
	else if (outputParameter == "-comp")
		cout << "Comparisons: " << SortResult.comparison << endl;
	else
	{
		cout << "Running time: " << SortResult.runTime << "ms" << endl;
		cout << "Comparisons: " << SortResult.comparison << endl;
	}

	ofstream fileOut("output.txt");
	fileOut << n << endl;
	for (int i = 0; i < n; i++)
	{
		fileOut << a[i] << " ";
	}
	fileOut.close();

	delete[] a;
}

void CMD2(vector<string> Algorithms, int inputSize, string inputOrder, string outputParameter)
{
	int* a = new int[inputSize];
	int dataType = 0;

	if (inputOrder == "-rand") dataType = 0;
	else if (inputOrder == "-sorted") dataType = 1;
	else if (inputOrder == "-rev") dataType = 2;
	else dataType = 3;

	GenerateData(a, inputSize, dataType);
	
	ofstream fileIn("input.txt");
	fileIn << inputSize << endl;
	for (int i = 0; i < inputSize; i++)
	{
		fileIn << a[i] << " ";
	}
	fileIn.close();

	Result SortResult = ExecuteSortAndGetRecord(a, inputSize, Algorithms[0]);

	cout << "Algorithm: " << Algorithms[0] << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "---------------------------------" << endl;

	if (outputParameter == "-time")
		cout << "Running time: " << SortResult.runTime << "ms" << endl;
	else if (outputParameter == "-comp")
		cout << "Comparisons: " << SortResult.comparison << endl;
	else
	{
		cout << "Running time: " << SortResult.runTime << "ms" << endl;
		cout << "Comparisons: " << SortResult.comparison << endl;
	}

	ofstream fileOut("output.txt");
	fileOut << inputSize << endl;
	for (int i = 0; i < inputSize; i++)
	{
		fileOut << a[i] << " ";
	}
	fileOut.close();

	delete[] a;
}

void CMD3(vector<string> Algorithms, int inputSize, string outputParameter)
{
	cout << "Algorithm: " << Algorithms[0] << endl;
	cout << "Input size: " << inputSize << endl;

	for (int i = 1; i <= 4; i++)
	{
		int* a = new int[inputSize];
		GenerateData(a, inputSize, i - 1);

		string filename = "input_" + to_string(i) + ".txt";
		ofstream fileOut(filename);
		fileOut << inputSize << endl;
		for (int j = 0; j < inputSize; j++)
		{
			fileOut << a[j] << " ";
		}
		fileOut.close();

		switch (i)
		{
			case 1: cout << "Input order: Randomize" << endl; break;
			case 2: cout << "Input order: Nearly Sorted" << endl; break;
			case 3: cout << "Input order: Sorted" << endl; break;
			case 4: cout << "Input order: Reversed" << endl; break;
		}

		Result SortResult= ExecuteSortAndGetRecord(a, inputSize, Algorithms[0]);
		cout << "---------------------------------" << endl;

		if (outputParameter == "-time")
		{
			cout << "Running time: " << SortResult.runTime << "ms" << endl;
		}
		else if (outputParameter == "-comp")
		{
			cout << "Comparisons: " << SortResult.comparison << endl;
		}
		else
		{
			cout << "Running time: " << SortResult.runTime << "ms" << endl;
			cout << "Comparisons: " << SortResult.comparison << endl;
		}

		delete[] a;
	}
}

void CMD4(vector<string> Algorithms, string inputFile)
{
    ifstream fileIn(inputFile);
    int n;
    fileIn >> n;
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
        b[i] = a[i]; 
    }
    fileIn.close();

    Result SortResult1 = ExecuteSortAndGetRecord(a, n, Algorithms[0]);
    Result SortResult2 = ExecuteSortAndGetRecord(b, n, Algorithms[1]);

    cout << "Algorithms: " << Algorithms[0] << " | " << Algorithms[1] << endl;
    cout << "Input File: " << inputFile << endl;
    cout << "Input Size: " << n << endl;
	cout << "---------------------------------" << endl;
    cout << "Running Times: " << SortResult1.runTime << "ms" << " | " << SortResult2.runTime << "ms" << endl;
    cout << "Comparisons: " << SortResult1.comparison << " | " << SortResult2.comparison << endl;

    delete[] a;
    delete[] b;
}

void CMD5(vector<string> Algorithms, int inputSize, string inputOrder)
{
	int* a = new int[inputSize];
    int* b = new int[inputSize];

    int dataType = 0;
	if (inputOrder == "-rand") dataType = 0;
	else if (inputOrder == "-sorted") dataType = 1;
	else if (inputOrder == "-rev") dataType = 2;
	else dataType = 3;

	GenerateData(a, inputSize, dataType);
    for (int i = 0; i < inputSize; i++)
    {
        b[i] = a[i]; 
    }

    ofstream fileOut("input.txt");
    fileOut << inputSize << endl;
    for (int i = 0; i < inputSize; i++)
    {
        fileOut << a[i] << " ";
    }
    fileOut.close();

    Result SortResult1 = ExecuteSortAndGetRecord(a, inputSize, Algorithms[0]);
    Result SortResult2 = ExecuteSortAndGetRecord(b, inputSize, Algorithms[1]);

    cout << "Algorithms: " << Algorithms[0] << " | " << Algorithms[1] << endl;
    cout << "Input Size: " << inputSize << endl;
    cout << "Input Order: " << inputOrder << endl;
	cout << "---------------------------------" << endl;
    cout << "Running Times: " << SortResult1.runTime << "ms" << " | " << SortResult2.runTime << "ms" << endl;
    cout << "Comparisons: " << SortResult1.comparison << " | " << SortResult2.comparison << endl;

    delete[] a;
    delete[] b;
}

void ReadCmdArg(int argc, char* argv[])
{
	set<string> AlgorithmName = {"selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "binaryinsertion-sort", "shaker-sort", "counting-sort", "radix-sort", "flash-sort"};
	string MODE = "";
	vector<string> SortAlgorithm;
	int inputSize = 0;
	string inputOrder = "";
	string outputParameters = "";
	string inputFile = "";

	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "-a" || string(argv[i]) == "-c")
		{
			MODE = argv[i];
		}
		else if (AlgorithmName.find(argv[i]) != AlgorithmName.end())
		{
			SortAlgorithm.push_back(argv[i]);
		}
		else if (CheckStringisNumber(argv[i]))
		{
			inputSize = stoi(argv[i]);
		}
		else if (string(argv[i]) == "-rand" || string(argv[i]) == "-nsorted" || string(argv[i]) == "-sorted" || string(argv[i]) == "-rev")
		{
			inputOrder = argv[i];
		}
		else if (string(argv[i]) == "-time" || string(argv[i]) == "-comp" || string(argv[i]) == "-both")
		{
			outputParameters = argv[i];
		}
		else 
		{
			inputFile = argv[i];
		}
	}

	if (SortAlgorithm.empty() || MODE == "")
	{
		cout << "ERROR!" << endl;
		return;
	}

	if (MODE == "-a")
	{
		cout << "ALGORITHM MODE" << endl;

		if (inputFile != "" && SortAlgorithm.size() == 1)
		{
			CMD1(SortAlgorithm, inputFile, outputParameters);
		}
		else if (inputSize > 0 && inputOrder != "" && SortAlgorithm.size() == 1)
		{
			CMD2(SortAlgorithm, inputSize, inputOrder, outputParameters);
		}
		else if (inputSize > 0 && outputParameters != "")
		{
			CMD3(SortAlgorithm, inputSize, outputParameters);
		}
		else
		{
			cout << "Invalid command line arguments for -a mode." << endl;
		}
	}
	else if (MODE == "-c")
	{
		cout << "COMPARE MODE" << endl;

		if (SortAlgorithm.size() > 1 && inputFile != "")
		{
			CMD4(SortAlgorithm, inputFile);
		}
		else if (SortAlgorithm.size() > 1 && inputSize > 0 && inputOrder != "")
		{
			CMD5(SortAlgorithm, inputSize, inputOrder);
		}
		else
		{
			cout << "Invalid command line arguments for -c mode." << endl;
		}
	}
}

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}
//-------------------------------------------------
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}
void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}