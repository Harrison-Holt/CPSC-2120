/*
 * Name: Harrison S. Holt 
 * Date Submitted: 2-20-23
 * Lab Section: 005
 * Assignment Name: Lab 4 
 */
//linear search
#include <vector>

template <typename T>
int binarySearch(std::vector<T> arr, T target) {
    
    int low = 0; 
    int high = arr.size() - 1; 
    
    int mid; 
    
    while (low <= high) {
        
        mid = (low + high) / 2; 
        
        if (target == arr[mid]) {
            
            return mid; 
        } 
        else if (target > arr[mid]) {
            
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    } 
    return -1; 
}
template<typename T>
//function will return 0-based index of 'target'
int linearSearch(std::vector<T> arr, T target) {

	int n = arr.size();

	//index = position of target
	int index= -1;
    
    // loops through the vector
	for(int i=0; i<n; i++)
	{
		if(arr[i] == target)
		{
			index= i;
			break;
		}
	}

	return index;
}
