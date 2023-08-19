/*1. Write a C program to the following sorting 
operations on the give sequence in ascending 
order: 10, 75, 115, 51, 33, 12, 2, 12
A) Bubble Sort
B) Selection Sort
C) Insertion Sort
D) Heap Sort
E) Radix Sort
F) Merge Sort
G) Quick Sort*/

#include <stdio.h>
#include <stdlib.h>

void swap(int &n,int &m){
    int temp=n;
    n=m;
    m=temp;
}

void bubbleSort(int arr[], int size) {
	int i, j, temp;
    printf("\nIntermediate Steps\n");
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j+1]);
			}
		}
        printf("for i=%d",i);
        printf("\nThe array is : ");
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");    
	}
}

void selection_sort(int arr[], int size) {
    printf("\nIntermediate Steps\n");
    int min_idx;
    for (int i = 0; i < size - 1; i++) {
        printf("\nThe array is : ");
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");  
        min_idx = i;
        for (int j = i + 1; j < size; j++) {

        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
            if (arr[j] < arr[min_idx])
            min_idx = j;
        }
        printf("for i=%d min_index=%d swap(%d,%d)",i,min_idx,arr[i],arr[min_idx]);
        // put min at the correct position
        swap(arr[min_idx], arr[i]);
        
        printf("\n");           
    }
}

void insertion_sort(int arr[],int n){
    int i,key,j;
    printf("\nIntermediate Steps\n");
    for(i=1;i<n;i++)
    {
        printf("\nThe array is : ");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
            printf("\n\n");
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
        }
        arr[j+1]=key;
        printf("\nfor i=%d Key=%d\n",i,key);
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n\n");
    }
}

//for heap sort
void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

        printf("\nThe array is : ");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }    
}

void heap_sort(int arr[],int n){
        for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

        for (int i = n - 1; i >= 0; i--){
            printf("\nswap(%d,%d)",arr[0],arr[i]);
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
        
}

//for radix sort
// Function to get the largest element from an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++){
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int exp) {
    int output[size];
    int count[10]={0};
    printf("\nIntermediate Steps\n");
    printf("\nfor exp=%d",exp);
  // Calculate count of elements F1:
    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;
    printf("\nfor F1 ");
    for(int i=0;i<10;i++){
        printf("%d ",count[i]);
    }
    
    
  // Calculate cumulative count F2:
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    printf("\nfor F2 ");
    for(int i=0;i<10;i++){
        printf("%d ",count[i]);
    }

  // exp the elements in sorted order F3:Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    //F4: Copy the output array to arr[], so that 
    //arr[] contains sorted numbers according to current digit
    //exp
    
    printf("\nThe array is : ");
    for (int i = 0; i < size; i++){
        array[i] = output[i];
        printf("%d ",array[i]);
    }
    printf("\n");
}

// Main function to implement radix sort
void radix_sort(int array[], int size) {
  // Get maximum element
    int max = getMax(array, size);

  // Apply counting sort to sort elements based on exponential(exp) value.
  for (int exp = 1; max / exp > 0; exp *= 10)
    countingSort(array, size, exp);
}

//for merge sort
void merge(int arr[],int l,int mid,int r){
    int i,j,k;
    printf("\n\nFrom %d to %d\n",arr[l],arr[r]);
    printf("\nMid Value = %d",arr[mid]);
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    printf("\nLeft array : ");
        for(int i=0;i<n1;i++)
        {
            printf("%d ",L[i]);
        }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    printf("\nRight array : ");
        for(int i=0;i<n2;i++)
        {
            printf("%d ",R[i]);
        }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
    printf("\nSorted Merged array : ");
        for(int i=0;i<r+1;i++)
        {
            printf("%d ",arr[i]);
        }      
}

void merge_sort(int arr[],int l,int r){
    int mid;
    if(l<r)
    {
        int mid=(l+r)/2;
        
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    else
    {
        return;
    }
}

//for quick sort
int partition(int arr[],int l, int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
void quick_sort(int arr[], int l,int h){
    if(l<h)
    {
        int pi=partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}

void display(int arr[],int size){
    printf("\nThe array is : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    /*int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }*/
    
    int arr[]={10, 75, 115, 51, 33, 12, 2, 12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ch;
    //int again;
    do
    {

        printf("\n\t\tSorting\t\t\n");
        printf("\n1. Bubble Sort\n");
        printf("\n2. Selection Sort\n");
        printf("\n3. Insertion Sort\n");
        printf("\n4. Heap Sort\n");
        printf("\n5. Radix Sort\n");
        printf("\n6. Merge Sort\n");
        printf("\n7. Quick Sort\n");
        printf("\n0. Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            display(arr,n);
            bubbleSort(arr,n);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 2:
            display(arr,n);
            selection_sort(arr,n);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 3:
            display(arr,n);
            insertion_sort(arr,n);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 4:
            display(arr,n);
            heap_sort(arr,n);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 5:
            display(arr,n);
            radix_sort(arr,n);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 6:
            display(arr,n);
            merge_sort(arr,0,n-1);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 7:
            display(arr,n);
            quick_sort(arr,0,n-1);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nIncorrect Entry! Try Again.\n");
            break;
        }
        exit(1);
		//printf("\nTry Another Method? (Press 1 for Yes / Press 0 for No :)\t");
		//scanf("%d", &again);
    } while (1);

}