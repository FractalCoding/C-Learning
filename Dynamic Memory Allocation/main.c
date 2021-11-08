#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "leak_detector_c.h"

 
static FILE *fp;
static FILE *out;
 
typedef struct item {
    int itemID;
    int numParts;
} item;
 
typedef struct recipe {
    int numItems;
    item* itemList;
    int totalParts;
} recipe;
   
char** readIngredients(int *numIngredient){
    
    size_t charsize = *numIngredient*sizeof(char*);
    char** ingredientList = (char**)malloc(charsize); // 1 alloc
    assert(ingredientList != NULL);

    for(int i = 0; i < *numIngredient; i++){
        char temp[20];
        fscanf(fp,"%s", temp);
        
        
        charsize = (strlen(temp)+1)*sizeof(char);
        char* currIngredient = (char*)malloc(charsize); // 2 alloc
        assert(currIngredient != NULL);
        
        strcpy(currIngredient,temp);
        ingredientList[i] = currIngredient;
    }   
    return ingredientList;
}
 
recipe* readRecipe(){
    size_t recsize = sizeof(recipe);
    recipe* currentRecipe = (recipe*)malloc(recsize); // 3 alloc
    assert(currentRecipe != NULL);
    
    fscanf(fp, "%d", &currentRecipe->numItems);
    
    recsize = currentRecipe->numItems*sizeof(item);
    currentRecipe->itemList = (item*)malloc(recsize); // 4 alloc
    assert(currentRecipe->itemList != NULL);
    
    currentRecipe->totalParts = 0;
    for(int i = 0; i < currentRecipe->numItems; i++){
        fscanf(fp, "%d %d", &currentRecipe->itemList[i].itemID, &currentRecipe->itemList[i].numParts);
        currentRecipe->totalParts += currentRecipe->itemList[i].numParts;
    }
    return currentRecipe;
}
 
recipe** readAllRecipes(int *numRecipes){
    
    size_t recsize = *numRecipes*sizeof(recipe*);
    recipe** recipeList = (recipe**)malloc(recsize); // 5 alloc
    assert(recipeList != NULL);
    
    for(int i = 0; i < *numRecipes; i++){
        recipeList[i] = readRecipe();
    }
    
    return recipeList;
}
 
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList){
    size_t dSize = ingredientCount*sizeof(double);
    double* orderList = (double*)calloc(ingredientCount, sizeof(double)); // 6 alloc
    assert(orderList != NULL);


    for(int i = 0; i < numSmoothies; i++){
        int smoothieIdx;
        int smoothieWeight;
        fscanf(fp, "%d %d", &smoothieIdx, &smoothieWeight);
        
        for(int j = 0; j < recipeList[smoothieIdx]->numItems; j++){
            item currItem = recipeList[smoothieIdx]->itemList[j];
            orderList[currItem.itemID] += ((double)currItem.numParts * (double)smoothieWeight)/(double)recipeList[smoothieIdx]->totalParts;             
        }
    }
    return orderList;
}
 
int main(){
	atexit(report_mem_leak);

    fp = fopen("in1.txt","r");
    out = fopen("out1.txt", "w");
    
    if(fp == NULL) {
            fprintf(stderr, "Could not open in file. Exiting now.");
    }

/* ============================================================================= */
/*               Part 1: Reading The Possible Ingredients List                   */
/* ============================================================================= */
    
    int numIngredients; // This value ranges from 1 to 10^5. 
            
    fscanf(fp, "%d", &numIngredients);
    
    if((numIngredients > 10000) || (numIngredients < 0)){
            fprintf(stderr,"Ingredients list out of bounds. Aborting.");
            abort();
    }
    
    char** ingredientList = readIngredients(&numIngredients);

/* ============================================================================= */
/*               Part 2: Reading The Possible Ingredients List                   */
/* ============================================================================= */
 
    int numRecipes; // This value ranges from 1 to 10^5.
        
    fscanf(fp,"%d", &numRecipes);
 
    if((numRecipes > 10000) || (numRecipes < 0)){
            fprintf(stderr,"Recipes list out of bounds. Aborting.");
            abort();
    }
    
    recipe** recipeList = readAllRecipes(&numRecipes);
/* ============================================================================= */
/*               Part 3: Reading The Store List                                  */
/* ============================================================================= */
 
    int numStores; // This value ranges from 1 to 100.
    double* amtOfEachItem;
    fscanf(fp,"%d", &numStores);

    if((numStores > 100)||(numStores < 0)){
            fprintf(stderr,"Stores list out of bounds. Aborting.");
            abort();
    }

    for (int i = 0; i < numStores; i++){
        int numOrders;
        fscanf(fp, "%d", &numOrders);
         amtOfEachItem = calculateOrder(numIngredients, numOrders, recipeList);
        
        printf("Store #%d:\n", i+1);
        fprintf(out, "Store #%d:\n", i+1);
        for(int j = 0; j < numIngredients; j++){
            if(amtOfEachItem[j] > 0){
            	printf("%s %0.6lf\n", ingredientList[j], amtOfEachItem[j]);
            	fprintf(out, "%s %0.6lf\n", ingredientList[j], amtOfEachItem[j]);
            }
        }
        printf("\n");
        fprintf(out, "\n");
		free(amtOfEachItem);
    }
	fclose(fp);
	fclose(out);

/* ============================================================================= */
/*               Part 4: Freeing the Malloced Memory		                     */
/* ============================================================================= */


    for(int i = 0; i < numIngredients; i++){
      free(ingredientList[i]);
    }
    free(ingredientList);

    
    for(int i = 0; i < numRecipes; i++){
      free(recipeList[i]->itemList);
      free(recipeList[i]);
    }
    free(recipeList);
	


   return 0;
}