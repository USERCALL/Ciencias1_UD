#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>

using namespace std;

double tiempo;

//llenar mayor a menor
void mayoramenor (int *b,int m){
	int k = m;
	for(int i=0;i<m;i++){
	b[k-1] = i+1;
	k--;
	}
}

//llenar menor a mayor
void menoramayor(int *b,int m){
	for(int i=0;i<m;i++){
		b[i] = i+1;
	} 
}

//funcion para mostrar el arreglo
void imprimir(int *b, int m){
	for(int i=0;i<m;i++){
		cout <<	b[i] << " ";
	}	cout << endl;
}


void MergeLists(int list[], int start1,int end1,int start2,int end2, int result[]){
	
	int finalStart, finalEnd,indexC;
	finalStart = start1;
	finalEnd = end2;
	indexC = 1;

	
		
	while ((start1 <= end1) && (start2 <= end2)){
		if (list[start1] < list[start2]){
			result[indexC] = list[start1];
			start1 = start1 + 1;
		}
		else{
			result[indexC] = list[start2];
      		start2 = start2 + 1;
  		}
   	indexC = indexC + 1;   	
	}	
	//imprimir(result,6);	
	if (start1 <= end1){
		for (int i = start1; i <= end1;i++){
     		result[indexC] = list[i];
      		indexC = indexC + 1;
		}
	}
	else{
		for (int i = start2; i <=end2;i++){
     		result[indexC] = list[i];
     		indexC = indexC + 1;
  		}
	}
	
	indexC = 1;
	for (int i = finalStart; i <= finalEnd;i++){
		list[i] = result[indexC];
   		indexC = indexC + 1;
	}
}

// Algoritmo MergeSort
void MergeSort(int a[], int first, int last, int result[]){
	int middle;
	if (first < last ){
		imprimir(a,last);
		middle = (( first + last ) / 2);
		MergeSort(a, first, middle,result );
		MergeSort(a, middle + 1, last, result );
		MergeLists(a, first, middle, (middle+1) ,last,result);
	}
}

//Funcion para el tiempo
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


int main(){
	int n;
	cout<<"ingrese el valor de n: ";
	cin>>n;
		

	int z[n];
	//z = new int[n];
	int result[n];
 
	imprimir(z,n);
	MergeSort(z,0,n-1,result);

	imprimir(z,n);
	
	system("Pause");
	return 0;
}
