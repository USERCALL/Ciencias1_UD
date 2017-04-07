#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void MergeLists(int list[],int start1,int end1,int start2,int end2){
int finalStart = start1;
int finalEnd = end2;
int indexC = 1;
int result[end2];
while (start1 <= end1 && start2 <= end2){
   if (list[start1] < list[start2]){ 
      result[indexC] = list[start1];
      start1 = start1 + 1;
   }else{
      result[indexC] = list[start2];
      start2 = start2 + 1;
   }
   indexC = indexC + 1;
}

if (start1 <= end1){
   for (int i = start1;i<=end1;i++){
      result[indexC] = list[i];
      indexC = indexC + 1;
   }
   }else{
   for (int i = start2;i<=end2;i++){
      result[indexC] = list[i];
      indexC = indexC + 1;
   }
}
indexC = 1;
for (int i=finalStart;i<=finalEnd;i++) {
   list[i] = result[indexC];
   indexC = indexC + 1;
}
}

void MergeSort(int list[],int first,int last ){
int middle;
if (first < last){
   middle = ( first + last ) / 2;
   MergeSort( list, first, middle );
   MergeSort( list, middle + 1, last );
   MergeLists(list, first, middle, (middle + 1), last);
}
}

int main(int argc, char** argv) {
    int i,N;
    double ini,fin;
    //cout<<"Tamaño"<<endl;
    N = 10;//cin>>N;
    int a[N];
    //Mejor
    /*for (i=0;i<N;i++){
        a[i]=i+1;
    }*/
    //Peor
    for (i=0;i<N;i++){
        /*a[i]=N-i;
        cout<<a[i]<<endl;*/
        cin>>a[i];
    }
    cout<<"Algoritmo Merge Sort"<<endl;
    ini = clock();
	MergeSort(a,0,N-1);
	fin = clock();
	cout<<"El tiempo de ejecucion es de: "<<ini<<" "<<fin<<" "<<" "<<fin-ini<<endl;
	for (i=0;i<N;i++){
        cout<<a[i]<<endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
