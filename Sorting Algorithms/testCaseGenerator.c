#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
srand(time(0));
FILE *fp;

fp = fopen("test_in1.txt","w");
int numCases = 1+(int)rand()%10;
printf("%d\n", numCases);
fprintf(fp, "%d\n", numCases);
for(int i = 0; i < numCases; i++){
int numBooks = 1+(int)rand()%10;
printf("%d ", numBooks);
fprintf(fp, "%d", numBooks);

long long int numPages = 1+rand()%100;
printf("%lld\n", numPages);
fprintf(fp, "%lld\n", numPages);

for(int i = 0; i < numBooks; i++){
  int pageNum = 1+rand()%100;
  printf("%d ", pageNum);
  fprintf(fp, "%d ", pageNum);
}
printf("\n");
}

}
