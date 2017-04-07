/*******************************************************************************
Arboles colas por prioridad 
********************************************************************************/


/*
Cristian Eduardo Rios Guarin - 20141020058
Diego Alejandro Hernandez - 20141020271	
Ciencias 1
*/

#include<iostream> 
#include<math.h>

using namespace std;

int inO=0;int preO=0; int posO=0;

struct  Nodo{
	int info;
    int altura;
    int tam;
    Nodo *izq;
    Nodo *der;
};
 
void swap(int *a, int *b){
	int t = *a; *a = *b; *b = t;
}
 
int max(int a, int b){
	//condition ? value_if_true : value_if_false
    return (a>b)?a:b;
}
 
Nodo* crearNodo(int val){
    Nodo *temp = new Nodo();
    temp->info=val;
    temp->tam=1;
    temp->altura=0;
    temp->izq=NULL;
    temp->der=NULL;
}
 
int Tam(Nodo *t){
    if(t==NULL)
        return 0;
    else
        return t->tam;
}
 
int Altura(Nodo *t){
    if(t==NULL)
        return -1;
    else
        return t->altura;
}
 
void actualizarAyT(Nodo *t){
    t->altura = max(Altura(t->izq),
                        Altura(t->der))+1;
    t->tam = Tam(t->izq) + Tam(t->der)+1;
}
 
Nodo* insertar(Nodo *n, int info){
    if(n==NULL){
        n = crearNodo(info);
        return n;
    }
    if(n->izq==NULL ||
           Tam(n->izq)< int(pow(2, Altura(n->izq)+1))-1 ||
           Tam(n->der)==Tam(n->izq)) 
        n->izq = insertar(n->izq, info);
    else
        n->der = insertar(n->der,info);
 
    if((n->izq!=NULL && n->izq->info > n->info) ||
            (n->der!=NULL && n->der->info>n->info)){
        if(n->izq==NULL){
            swap(n->info, n->der->info);
        }
        else if(n->der==NULL)
            swap(n->info, n->izq->info);
        else{
            if(n->izq->info > n->der->info)
                swap(n->info, n->izq->info);
            else
                swap(n->info, n->der->info);
        }
    }
 
    actualizarAyT(n);
    return n;
}
 
int cabeza(Nodo *raiz){
    return raiz->info;
}
 
void organizar(Nodo *n){
    if(!n)
        return;
    while((n->izq!=NULL && n->izq->info>n->info) ||
              (n->der!=NULL && n->der->info>n->info)){
        if(n->izq==NULL){
            swap(n->info, n->der->info);
            n = n->der;
        }
        else if(n->der==NULL){
            swap(n->info, n->izq->info);
            n = n->izq;
        }
        else{
            if(n->izq->info > n->der->info){
                swap(n->info, n->izq->info);
                n = n->izq;
            }
            else{
                swap(n->info, n->der->info);
                n = n->der;
            }
        }
    }
}
 
Nodo* eliminar(Nodo *n, Nodo *raiz){
    if(n==NULL)
        return NULL;
    if(n->izq==NULL && n->der==NULL){
        swap(raiz->info, n->info);
        delete n;
        return NULL;
    }
    else if(Tam(n->izq) > Tam(n->der))
        n->izq = eliminar(n->izq, raiz);
    else
        n->der = eliminar(n->der, raiz);
 
    actualizarAyT(n);
}
 
void atender(Nodo **heap){
    *heap = eliminar(*heap, *heap);
    organizar(*heap);
}
 
void inorden(Nodo *x){
	if(inO==0){
		cout<<endl<<"--- Inorden ---"<<endl;
		inO=1;	
	} 
    if(x!= NULL){
    	inorden(x->izq);
		cout<<x->info<<endl;
		inorden(x->der);
	}
}

void preorden(Nodo *x){
	if(preO==0){
		cout<<endl<<"--- Preorden ---"<<endl;
		preO=1;
	} 
    if(x!= NULL){
    	cout<<x->info<<endl;
		preorden(x->izq);
		preorden(x->der);
	}	
}

void posorden(Nodo *x){
	if(posO==0){
		cout<<endl<<"--- Posorden ---"<<endl;
		posO=1;
	}
	if(x!= NULL){
		posorden(x->izq);
		posorden(x->der);
		cout<<x->info<<endl;
	}
}

int main(){
    Nodo *heap=NULL;
    int x;
    do{
    	cout<<"Ingrese los valores del arbol o ingrese 0 para finalizar: "; cin>>x;
        if(x!=0){
            heap = insertar(heap, x);
            //cout<<"Raiz --> "<<cabeza(heap)<<endl;
        }
    }while(x!=0);
    
    cout<<endl<<"Altura del Arbol: "<<Altura(heap)<<endl;
    cout<<"Numero de elementos en el Arbol: "<<heap->tam<<endl;
    inorden(heap);
    preorden(heap);
	posorden(heap);
    
	/*
	cout<<"\n----- Maxima Prioridad ------\n";
    while(heap){
        cout<<cabeza(heap)<<endl;
        atender(&heap);
    }
    */
    cout<<endl;
    return 0;
}
