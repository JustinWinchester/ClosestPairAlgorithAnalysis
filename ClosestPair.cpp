


/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 
Programmer:             Justin Winchester
Professor:              Dr. Moinian
Course:                 Algorithm Analysis CS-3713 Fall 2020
Institution:            Cameron University
Project- 3:             The Closest Pair Problem
Details:                -
Given a set of n ≥ 2 random numbers, we want to find the closest pair including their distance.
For example, in the list [15, 8, 19, 1, 10, 4] the closest pair is (8, 10) with a distance of 2.

 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
//Libraries Needed for I/O, Random numbers, ect
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
//#define  SIZE 10
const int N = 10;   //Made Global for print & initialization functions                                                            
using namespace std;  //Standard name space

//Function Declarations for Program
void closestPair(int array[], int left, int right, int& index1, int& index2, int& distance);  //Recursive Pair Function
void initialize(int array[], int N);//Function to initialize array with random integers
void print(int array[],int N); //Print the array of integers



//Main Program!!
int main(){
srand(time(NULL));   //Seeding Random with time for more variation

int index1= 0;
int index2= 0;      //CleAn memory for index and distance values by setting them to zero!
int distance = 0;
//&index1 ;
//&index2 ;
//&distance ;

int array[N];			// Declare array of ten integers (constant size)
initialize(array, N);
print(array,N);				//Print to see values
int left = 0;				//Leftmost index
int right = N-1;			//Rightmost index
 //Function call from MAIN
closestPair( array,  left,  right, &index1, &index2, &distance);  
cout << "Closest pair = " << index1 << index2 << endl;  //Show two closest numbers in array (pair)
//And their distance 
cout << "Their Distance = " << distance << endl; 


return 0;

}

void closestPair(int array[], int left, int right, int& index1, int& index2, int& distance)  //Parameters
{
	
	int num;  //Temporary spot to store first number in array and "set it aside" from the rest!
	
	left = array[0];    //leftmost index
	right = array[N-1]; //rightmost index
	distance = 0;

	
	

	if (right - left == 1)   //array only has two elements! BASE CASE
	{	index1 = left;     //set indexes to return in Main if only two can solve direct by print the numbers at these indices and their distance calculation
		index2 = right;
		 //Have to use absolute value function in case array is not sorted and left index is smaller than right and produce negative number(we need take away value of larger #-smaller# |x-y|)

		distance  = abs(left - right);
	}
		 	    //There are more than two number in array list	}
	else{
	num = array[left]  ;  //set aside one number in first(leftmost) index
	closestPair(array,  left+1,  right, &index1, &index2, &distance); //Recursively solve rest of array(Next left index will be set aside & so forth until we reach two numbers and then each num set aside will return from 
											//Bottom of funciton call stack in memory and their  distances will calculated to find the smallest
	}
	for(int i = 0; i < N;i++)   //After list has two number to compare with num with num value will compare it differnce with that of the other numbers and their minimum to find which is the closest pair and store it in distance
	{
	if(abs(num - array[i+1])<distance){   //Comparison for set aside element and current distance 
	
	 distance = abs(left - right);
	}
}
}
void initialize(int array[],int N)
{
        for (int i = 0;i<N; i++)  //Loop that iterates times the elements in array list
        {
                array[i] = rand()%100+1;  //Generation of random numbers in range of 1 - 100 for each array element 
        }
}
void print(int array[], int N)
{
for (int i = 0;i<N; i++) //Loop N time (number of elements)
        {
                cout << array[i] << " | "; //Print each element and a divider 
        }
        cout <<"\n"; //New line element after all elements have been produced or printed 
}

