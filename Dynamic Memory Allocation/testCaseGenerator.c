#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(){
 FILE *fp;
 fp = fopen("testcase.txt", "w");
 srand(time(NULL));
 int numIngredients = 1+rand()%10000; // n <= 10^5;
 fprintf(fp,"%d\n", numIngredients);
 for(int i = 0; i < numIngredients; i++){
 fprintf(fp, "Ingredient%d\n", i);
 }
 int numRecipes = 1+rand()%10000; // s <= 10^5
 fprintf(fp, "%d\n", numRecipes);
 for(int i = 0; i < numRecipes; i++){
 int numItems = 1+rand()%100; //i <= 100
 fprintf(fp, "%d ", numItems);
 for(int j = 0; j < numItems; j++){
 fprintf(fp, "%d %d ", rand()%numIngredients, 1+rand()%1000); // Idx of Ingredient,
parts up to 1000.
 }
 fprintf(fp, "\n");
 }
 int numStores = 1+rand()%100; // k <= 100 stores
 fprintf(fp, "%d\n", numStores);
 for(int i = 0; i < numStores; i++){
 int numRecs = 1+rand()%100; //s <= 10^5
 fprintf(fp, "%d ", numRecs);
 for(int j = 0; j < numRecs; j++){
 fprintf(fp, "%d %d ", rand()%numRecipes, 1+rand()%1000); // Idx of Smoothie, weigh
t up to 1000.
 }
 fprintf(fp,"\n");
 }
 fclose(fp);
 return 0;
}