// C++ program to find number of bins required using
// First Fit algorithm.
#include <iostream>
using namespace std;

// Returns number of bins required using first fit
// online algorithm
int firstFit(double weight[], int n, int c)
{
	// Initialize result (Count of bins)
	int res = 0;

	// Create an array to store remaining space in bins
	// there can be at most n bins
	double bin_rem[n];

	// Place items one by one
	for (int i=0; i<n; i++)
	{
		// Find the first bin that can accommodate
		// weight[i]
		int j;
		for (j=0; j<res; j++)
		{
			if (bin_rem[j] >= weight[i])
			{
				bin_rem[j] = bin_rem[j] - weight[i];
				break;
			}
		}

		// If no bin could accommodate weight[i]
		if (j==res)
		{
			bin_rem[res] = c - weight[i];
			res++;
		}
	}
	return res;
}

// Driver program
int main()
{
	double weight[] = {82.49,7.46,85.38,54.71,22.77,80.95,73.01,77.83,72.4,83.84,49.76,93.61,65.58,65.6,64.85,99.26,70.99,38.68,71.86,6.9,2.67,97.88,67.44,96.34,77.51,46.89,73.1,18.62,8.98,99.35,54.78,21.18,54.78,48.57,50.44,26.04,32.93,80.05,33.82,48.4,42.14,56.38,90.16,56.09,40.07,61.26,47.26,8.46,90.38,45.46,64.63,51.77,30.82,9.3,29.16,22.37,79.79,89.84,85.28,4.97,2.72,45.74,99.36,50.74,76.01,17.99,76.94,53.62,43.4,68.12,56.92,84.11,8.04,68.33,18.6,53.36,37.14,79.14,96.68,40.21,35.84,22.6,38.61,97.29,74.91,85.47,72.49,66.83,83.85,75.29,14.78,74.94,21.45,42.84,17.45,27.29,19.86,94.39,17.58,44.21};
	int c = 500;
	int n = sizeof(weight) / sizeof(weight[0]);

	//sort(weight, weight+n); // sort array for better solutions

	for(int i=0; i<100; i++)
	{
	    cout<<weight[i]<<endl;
	}
	cout<<endl;

	cout << "Number of bins required in First Fit : "
		<< firstFit(weight, n, c)<< endl;
	return 0;
}
