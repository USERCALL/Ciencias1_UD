#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "conio.h"
#include <windows.h>
 
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
 
static int total_nodes;
// prints subset found
void printSubset(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%*d", 5, A[i]);
    }
 
    printf("\n");
}
 
// inputs
// s            - set vector
// t            - tuplet vector
// s_size       - set size
// t_size       - tuplet size so far
// sum          - sum so far
// ite          - nodes count
// target_sum   - sum to be found
void subset_sum(int s[], int t[],int s_size, int t_size,int sum, int ite,int const target_sum){
    total_nodes++;
    if( target_sum == sum ){
        // We found subset
        //printSubset(t, t_size);
        // Exclude previously added item and consider next candidate
        subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
        return;
    }else{
        // generate nodes along the breadth
        for( int i = ite; i < s_size; i++ ){
            t[t_size] = s[i];
            // consider next level node (along depth)
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}
 
// Wrapper to print subsets that sum to target_sum
// input is weights vector and target_sum
void generateSubsets(int s[], int size, int target_sum){
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
 
    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
 
    free(tuplet_vector);
}
 
int main(int argc, char** argv){
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	
    int weights[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = ARRAYSIZE(weights);
    
    // Crea un fichero de salida
	ofstream fs("subSum.txt"); 
    
    for(int i = 1; i <= 200; i++){
    	QueryPerformanceCounter(&t_ini);
    	
		generateSubsets(weights, size, i);
		
		QueryPerformanceCounter(&t_fin);
		
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%.16g milliseconds\n", secs * 1000.0);
		
		// Enviamos una cadena al fichero de salida:
		fs << (secs) << endl;
		
		printf("Nodes generated %d\n", total_nodes);
		printf("");
	}
	
	// Cerrar el fichero
	fs.close();
    
    return 0;
}
