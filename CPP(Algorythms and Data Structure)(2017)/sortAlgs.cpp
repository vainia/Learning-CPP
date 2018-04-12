#include <iostream>
#include <ctime>
using namespace std;
 
void bubbleSort(int *, int); 
void polishNationalFlagSort(int *, int);
void countingSort(int *, int);

int main(int argc, char* argv[])
{
	srand(time(NULL));
	cout << "Enter size of digits array: ";
	int size_array; 
	cin >> size_array;
	int *sorted_array = new int [size_array]; 
	for (int counter = 0; counter < size_array; counter++)
	{
		sorted_array[counter] = rand() % 10;
		cout << sorted_array[counter] << "  ";
	}
	cout << "\nSorted table: \n";
	countingSort(sorted_array, size_array);
	//polishNationalFlagSort(sorted_array, size_array);
	//bubbleSort(sorted_array, size_array); 
	for (int counter = 0; counter < size_array; counter++)
		cout << sorted_array[counter] << "  "; 
	cout << "\n";
	return 0;
}

void countingSort(int* arrayPtr, int length_array) 
{
	int CountArr[length_array/2] = { 0 };
    for (int i=0;i<length_array;i++)
		CountArr[arrayPtr[i]]++;
    int outputindex=0;
    for (int j=0;j<length_array/2;j++)
        while (CountArr[j]--)
            arrayPtr[outputindex++] = j;
}
 
void polishNationalFlagSort(int* arrayPtr, int length_array) 
{
	int i = 0;
	int j = length_array - 1;
	int zmiana;
	while (i < j)
	{
		while (i < length_array && arrayPtr[i] == 0)
			i++;
		while (j >= 0 && arrayPtr[j] == 1)
			j--;
		if (i < j)
		{
			zmiana = arrayPtr[i];
			arrayPtr[i] = arrayPtr[j];
			arrayPtr[j] = zmiana;
		}        
	}
}
 
void bubbleSort(int* arrayPtr, int length_array) 
{
	int temp = 0;
	bool exit = false; 
	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false; 
			}
	}
}