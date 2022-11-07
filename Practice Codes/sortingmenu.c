#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *n,int *m){
    int temp=*n;
    *n=*m;
    *m=temp;
}

void bubbleSort(int arr[], int size) {
	int i, j, temp;
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void selection_sort(int arr[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
            if (arr[i] < arr[min_idx])
            min_idx = i;
        }

        // put min at the correct position
        swap(&arr[min_idx], &arr[step]);
    }
}

void insertion_sort(int arr[],int n){
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    } 
}

void heap_sort(int arr[],int n){
        for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

        for (int i = n - 1; i >= 0; i--){
            swap(&arr[0],&arr[i]);
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

  // Calculate count of elements F1:
    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;
    
  // Calculate cumulative count F2:
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

  // exp the elements in sorted order F3:Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    //F4: Copy the output array to arr[], so that 
    //arr[] contains sorted numbers according to current digit
    //exp
    for (int i = 0; i < size; i++)
        array[i] = output[i];
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
void merge(int *arr,int l,int mid,int r){
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    int temparray[100];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            temparray[k]=L[i];
            i++;
        }
        else
        {
            temparray[k]=R[j];
            j++;
        }
    }
    while(i<n1)
    {
        temparray[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        temparray[k]=R[j];
        j++;
        k++;
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
int partition(int *arr,int l, int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
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
    printf("\nThe Sorted array is : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ch,again;
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
            bubbleSort(arr,n);
            display(arr,n);
            break;
        case 2:
            selection_sort(arr,n);
            display(arr,n);
            break;
        case 3:
            insertion_sort(arr,n);
            display(arr,n);
            break;
        case 4:
            heap_sort(arr,n);
            display(arr,n);
            break;
        case 5:
            radix_sort(arr,n);
            display(arr,n);
            break;
        case 6:
            merge_sort(arr,0,n);
            display(arr,n);
            break;
        case 7:
            quick_sort(arr,0,n);
            display(arr,n);
            break;
        case 0:
            exit(1);
            break;
        }
		printf("\nTry Another Method? (Press 1 for Yes / Press 0 for No :)\t");
		scanf("%d", &again);
    } while (again==1);

}


