# Programming Assignment 1
## Dynamic Memory Allocation
## Project designed by Tanvir Ahmed / Arup Guha at University of Central Florida

**Due to copyright reasons, I cannot attach the original assignment instructions.**
**Project summary listed below for problem statement purposes**
**I do not own the rights to this assignment.**
**This project is provided on GitHub as a demonstration of my understanding of the topics provided to future employers and is not intended to be used as reference for UCF students on their assignments.**
**Using any part of this assignment in any way in your own assignment at UCF is a violation of the UCF Honor Code**

**Note: Files leak_detector_c.c, leak_detector_c.h, and all related files are the property of Tanvir Ahmed, and you may NOT use these files as part of your code. They are added simply to demonstrate the lack of a memory leak in my code.**

## **How To Compile This Code**

Make sure gcc is installed on your computer. Then run the following command while in this folder:
```
gcc main.c -lm leak_detector_c.c
```
If you would like to compile this code without the use of the memory leak detector, please remove it from the header inclusions and remove the first line of code in main.

## **Project Description**

Given a list of possible smoothie ingredients, a list of smoothie recipes, and lists of sales from several stores, determine how much of each ingredient each store must order.

**Note: This is the verbatim problem statement provided in the assignment.**

## **Input File Specifications**

Line 1 will contain a single integer n for number of smoothie Ingredients.

Next n lines will contain a single smoothie ingredient.

Next line will contain a single integer s for number of smoothie recipes.

Next s lines will contain a single integer m (number of ingredients in the smoothie, followed by m pairs of ingredient indices and their quantity.

Next line will contain a single integer k for number of stores
Last k lines will contain a single integer r representing number of offered smoothies, followed by r pairs of recipe indices and their weight.

### **Sample Input File**

```
9
Ingredient0
Ingredient1
Ingredient2
Ingredient3
Ingredient4
Ingredient5
Ingredient6
Ingredient7
Ingredient8
7
4 7 10 1 7 4 9 2 1 
1 5 4 
7 2 1 0 1 6 8 8 7 6 8 2 6 0 6 
7 0 7 1 6 3 7 4 1 8 3 4 3 2 7 
2 1 8 5 2 
4 7 6 6 7 4 8 3 8 
6 2 2 7 7 3 10 5 2 2 1 1 8 
5
3 2 1 1 7 2 10 
2 6 3 6 5 
3 1 10 4 4 2 1 
6 4 4 0 6 2 8 1 4 5 4 1 6 
6 0 1 1 10 0 7 3 9 0 2 6 4 
```

## Output File Specifications

For each store, print each used ingredient and the total weight of the ingredient used.

### Sample Output File

```
Store #1:
Ingredient0 2.081081
Ingredient2 2.081081
Ingredient5 7.000000
Ingredient6 4.756757
Ingredient8 2.081081

Store #2:
Ingredient1 2.133333
Ingredient2 0.800000
Ingredient3 2.666667
Ingredient5 0.533333
Ingredient7 1.866667

Store #3:
Ingredient0 0.189189
Ingredient1 3.200000
Ingredient2 0.189189
Ingredient5 10.800000
Ingredient6 0.432432
Ingredient8 0.189189

Store #4:
Ingredient0 1.513514
Ingredient1 4.755556
Ingredient2 1.735736
Ingredient3 1.103448
Ingredient4 3.103448
Ingredient5 10.800000
Ingredient6 4.424977
Ingredient7 3.049808
Ingredient8 1.513514

Store #5:
Ingredient0 1.852941
Ingredient1 5.247495
Ingredient2 2.623312
Ingredient3 3.186275
Ingredient4 4.392157
Ingredient5 10.266667
Ingredient7 4.637037
Ingredient8 0.794118
```

## **Test Case Generator**

This file can be compiled normally. File generates randomly sized test cases, but if you would like to fix the number of test cases, the variables are labeled clearly enough for you to know which one to change to a fixed value, rather than a randomly generated one. 
