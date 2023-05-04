#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
  
// Function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify 
   int l = (2 * root) + 1; // index of left-child
   int r = (2 * root) + 2; // index of right-child

   int largest = root; 

   // check whether left-child is larger than root
   if(l <= n && arr[l] > arr[largest]){
      largest = l;
   }

   // check whether right child is larger
   if(r <= n && arr[r] > arr[largest]){
      largest = r;
   }

   // if largest isn't root, then swap and recursively call heapify
   if (largest != root){
      swap(arr[largest], arr[root]);
      heapify(arr, n, largest);
   }   
}
  

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap

   // index of last element belonging to heap
   int heapsize = n - 1;

   // Builds max-heap from given array elements
   for (int i = ((heapsize - 1) / 2); i >= 0; i--){
      heapify(arr, n, i);      
   }

   // extracting elements from heap one by one
   while (heapsize > 0){
      swap(arr[heapsize], arr[0]);
      --heapsize;
      heapify(arr, heapsize, 0);
   }
   
}


// main program
int main()
{
   string line = "";
   int entry = 0;
   vector<int> entered_nums;

   cout << "Enter integers: ";

   // The following allows us to take an arbitrary number of space-separated integers
   // from the user over the terminal. The `getline()` function takes input until
   // user hits 'enter' (i.e. a newline character is found)

   // Read input until newline is found
   getline(cin, line);

   // Create istringstream object
   istringstream iss(line);

   // Iterate while itnegers can be extracted from iss
   while(iss >> entry){
      entered_nums.push_back(entry);
   }

   // Since provided functions use array instead of vector<int>, convert
   // vector into array of same size.
   int n = entered_nums.size(); // required size of the array
   int heap_arr[n];
   copy(entered_nums.begin(), entered_nums.end(), heap_arr); // copy elements into array

   cout << "Input array" << endl;
   displayArray(heap_arr, n);
  
   // Heapsort the array
   heapSort(heap_arr, n);
  
   cout << "Sorted array" << endl;
   displayArray(heap_arr, n);

   return 0;
}