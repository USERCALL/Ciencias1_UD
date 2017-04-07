
//Torres de Hanoi
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
 
void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }
    else
    {
        hanoi(num-1,A,B,C);
        cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}
 
 
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


 
 
 main()
{
	
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	
        int n;
        char A,B,C;
 
        cout<<"Los clavijas son A B C\n";
        cout<<"Numero de discos: ";
        cin>>n;
    
    ofstream fs("datos.txt"); 
     for(int i=1; i<n;i++){
		QueryPerformanceCounter(&t_ini);
  		hanoi(i,'A','C','B'); 	
		QueryPerformanceCounter(&t_fin);
		cout<<endl;
		secs = performancecounter_diff(&t_fin, &t_ini);
    	fs<<secs<<endl; 
     	printf("%.16g milliseconds\n", secs * 1000.0);
	  
	}
	   
}

