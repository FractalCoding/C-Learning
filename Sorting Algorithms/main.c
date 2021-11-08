#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, I have had the Geeksforgeeks code for merge sort laser cut for almost a year and I have that very close to me almost at all times when I'm at home, so my code is very similar to it as I had been exposed to merge sort prior to this class.

FILE* fpin;
FILE* fpout;
void printList(int* arr, int numBooks){
  for(int i = 0; i < numBooks; i++){
    printf("%d ", arr[i]);
  }
}
void mergeLists(int* arr, int left, int mid, int right){
  int RIdx = right - mid;   // Initial index of right array
  int LIdx = mid - left + 1; // Initial index of left array

  int rgt[RIdx]; // Define temp array to hold right array
  int lft[LIdx]; // Define temp array to hold left array

  for(int i = 0; i < LIdx; i++){  // Copy contents into left array
    lft[i]= arr[i+left];
  }
  for(int j = 0; j < RIdx; j++){  // Copy contents into right array
    rgt[j] = arr[j + mid + 1];
  }

  int a = 0;
  int b = 0;
  int c = left;

  while (a < LIdx && b < RIdx){ // while less than max array sizes
    if( rgt[b]>=lft[a]){  // If else branch performs side by side comparison.
          arr[c]=lft[a];
          a++;
    }
    else {
      arr[c]=rgt[b];
      b++;
    }
    c++;
  }

  while (b < RIdx){ // Copy remaining data in Right
    arr[c]=rgt[b];
    c++;
    b++;
  }

  while (a < LIdx){
    arr[c]=lft[a];
    c++;
    a++;
  }
}

void mergeSort( int* arr, int left, int right){
  if(left  < right){
    int mid = left + (right - left)/2; // Find midpoint
    mergeSort( arr, mid+1, right); // Run division on right half.
    mergeSort (arr, left, mid); // Run division on left half. 
    mergeLists(arr, left, mid,right); // Run the actual merging algorithm.
  }
}

int findBooks(int* arr, int numBooks,long long int numPages){
  
  mergeSort(arr, 0, numBooks-1);
  //printList(arr, numBooks);
  long long int pageCount = 0;
  long long int i = 0;
  long long int bookCount = 0;
  while(pageCount<= numPages){
    pageCount+=arr[i];
    if(pageCount>numPages){
      break;
    }
    i++;
    bookCount++;
  }
  return bookCount;

}


int main(void) {
fpin = fopen("in.txt", "r");
fpout = fopen("out.txt", "w");

int numBooks;
fscanf(fpin, "%d", &numBooks);

for(int i = 0; i < numBooks; i++){
  int numBooks; 
  long long int numPages;
  fscanf(fpin, "%d %lld", &numBooks, &numPages);
  //printf("\n%d %d\n", numBooks, numPages);
  int* bookArr = (int*)malloc(numBooks*sizeof(int));
  assert(bookArr != NULL);
  for(int i = 0; i < numBooks; i++){
    fscanf(fpin ,"%d",&bookArr[i]);
  }
  int readBooks = findBooks(bookArr, numBooks, numPages);
  fprintf(fpout, "%d\n", readBooks);
  printf("%d\n", readBooks);
  free(bookArr);
  
}
}