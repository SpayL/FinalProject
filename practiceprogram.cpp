#include <iostream> 
using namespace std; 
  //Program to search an element in a sorted and pivoted array
int binarySearch(int arr[], int low,int high, int key) 
{ 
  if (high < low) 
    return -1; 
      
  int mid = (low + high)/2; 
  if (key == arr[mid]) 
    return mid; 
      
  if (key > arr[mid]) 
    return binarySearch(arr, (mid + 1), high, key); 
      
 else
    return binarySearch(arr, low, (mid -1), key); 
} 
  
int findPivot(int arr[], int low, int high) 
{ 
   
  if (high < low) return -1; 
  if (high == low) return low; 
  
   int mid = (low + high)/2; /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1]) 
    return mid; 
      
   if (mid > low && arr[mid] < arr[mid - 1]) 
    return (mid-1); 
      
   if (arr[low] >= arr[mid]) 
    return findPivot(arr, low, mid-1); 
   else 
   return findPivot(arr, mid + 1, high); 
} 
  

int pivotedBinarySearch(int arr[], int n, int key) 
{ 
  int pivot = findPivot(arr, 0, n-1); 
  
 
  if (pivot == -1) 
    return binarySearch(arr, 0, n-1, key); 
  
   if (arr[pivot] == key) 
    return pivot; 
      
  if (arr[0] <= key) 
    return binarySearch(arr, 0, pivot-1, key); 
  else
    return binarySearch(arr, pivot+1, n-1, key); 
} 


/*program to delete a linked list*/
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
void deleteList(Node** head_ref)  
{  
     
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
      
*head_ref = NULL;  
}  
 
void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
 
    new_node->data = new_data;  
      
    new_node->next = (*head_ref);  
      
    (*head_ref) = new_node;  
}  



/*implementation of selection sort*/
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
   
    for (i = 0; i < n-1; i++) 
    {  
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
   
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
