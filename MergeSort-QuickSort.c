#include <stdio.h>

int main()
{
    //initializing the array
    int a[]={4,65,2,-31,0,99,2,83,782,1};
    //assiging the size of the array to n
    int n=sizeof(a)/sizeof(a[0]);
    //print the string
    printf("Initial Array: ");  
    //printing the array before sorting
    printArray(a,n);

    //calling qsort2 method to sort the array
    qsort2(a,n);
    
    //printing the string
    printf("Sorted array by Quick sort: ");
	//printing the sorted array
    printArray(a,n);
    
    //initializing the array
    int b[]={4,65,2,-31,0,99,2,83,782,1};
	//print the string
    printf("Initial Array: ");  
    //printing the array before sorting
    printArray(b,n);
    
    //calling msort method to sort the array
    msort(b,n);
    
    //printing the string
    printf("Sorted array by Merge sort: ");
    //printing the sorted array
    printArray(b,n);
	
    return 0;
}

//quicksort method that takes in the array and size of the array as parameters
void qsort2(int *a, int n){
    //checks if the size of the array is not less than 1
    if(n>1){
        //the index returned from partition method is assigned to partitionIndex 
        int partitionIndex=partition(a,n);
        //sort the left subarray 
        qsort2(a,partitionIndex);
        //sort the right subarray
        qsort2(a + partitionIndex + 1, n - partitionIndex - 1);
    }
}

//partition method that takes the array and size of the array as parameters
int partition(int *a, int n){
    //initializing i and j as 1
    int i=1;
    int j=1;
    int temp;
    //initializing pivot as the first element of the array
    int pivot=a[0];
    //loop that iterates over the array
    while(j<n){
        //checks if the element at jth index is less than the pivot
        if(a[j]<pivot){
            //swaps the element at ith index and the element at jth index
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            //increments i by 1
            i++;
        }
        //increments j by 1
        j++;
    }
    //swapping the first element with the element at (i-1)th position
    temp=a[0];
    a[0]=a[i-1];
    a[i-1]=temp;
    //returning i-1 as partitionIndex
    return i-1;
}

//Merge sort method that takes the array and the size of the array as input
void msort(int *a, int n){
    //check if the size of the array is greater than 1
    if(n>1){
        //calculating the size of left sub-array
        int sizeOfLeft = n/2;
        //calculating the size of right sub-array
        int sizeOfRight = n - sizeOfLeft;
        //allocating memory for the left sub-array
        int *left=(int*)malloc(sizeof(int)*sizeOfLeft);
        //allocating memory for the right sub-array
        int *right=(int*)malloc(sizeof(int)*sizeOfRight);
        //assigns the elements to the left sub-array
        //loops incrementing the value of i until i< size of left sub-array
        for(int i=0;i<sizeOfLeft;i++){
            //assigns the element at ith index in the main array to the ith index of the left sub-array
            left[i]=a[i];
        }
        //assigns the elements to the right sub-array
        //loops incrementing the value of i until i< size of right sub-array
        for(int i=0;i<sizeOfRight;i++){
            //assigns the element at i+sizeOfLeft th index in the main array to the ith index of the right sub-array
            right[i]=a[sizeOfLeft+i];
        }
        //calls msort function recursively on the left sub-array
        msort(left,sizeOfLeft);
        //calls msort function recursively on the right sub-array
        msort(right,sizeOfRight);
        //calls the merge function to merge the left and right sub-arrays
        merge(a,left,sizeOfLeft,right,sizeOfRight);
    }
}



//merge method that takes in the array, left sub-array, and right sub-array along with its sizes as paramters.
void merge(int *a, int *left,int sizeOfLeft, int *right, int sizeOfRight) {
    //initializing variables to keep track of index positions.
    int i=0,j=0,k=0;
    //loop that iterates only when there are elements in both sub-arrays to compare from
    while(i<sizeOfLeft && j<sizeOfRight){
        //checks if the element at ith index in the left sub-array is less than the element at jth index of right sub-array.
        if(left[i]<=right[j]){
            //assigns the element from the left sub-array to the main array incrementing i and k
            a[k++]=left[i++];
        }
        else{
            //assigns the element from the right sub-array to the main array incrementing j and k
            a[k++]=right[j++];
        }
    }
    //loops until it goes through entire left sub-array
    while(i<sizeOfLeft){
        //assigns the element from the left sub-array to the main array incrementing i and k
        a[k++]=left[i++];
    }
    //loops until it goes through entire right sub-array
    while(j<sizeOfRight){
        //assigns the element from the right sub-array to the main array incrementing j and k
        a[k++]=right[j++];
    }
}



//method to iterate through the list of array and print them
void printArray(int *a,int size){
    //for loop that iterates through the array
    for(int i=0; i<size;i++){
        //prints the elements of the array
        printf("%d  ",a[i]);
    }
    //prints new line
    printf("\n");
}


