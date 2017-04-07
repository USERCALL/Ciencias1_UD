#include "Arbol.h"

 
 //constantes color
 
 const bool BLACK = true ;
 const bool RED = true ;
  
 
// heredando struct new:herencia
struct NODORJ:NODO{
	bool color; 
};

// heredando clase  class new: public: herencia
class ARBOLRJ:  public ARBOL {

 public :
	void ajustar (NODORJ *, NODORJ* );
	NODORJ* returnLeftOf(NODORJ* );
	NODORJ* returnRightOf(NODORJ *);
	NODORJ* returnFather(NODORJ *);
	NODORJ* root(NODORJ*a){
		NODO *t;
		t =  raiz_arbol(); 
		
		NODORJ *aux ; 
		aux  = new NODORJ;
		aux->info=t->info; 
		aux->izq = t->izq;
		aux->der = t->der; 
		return aux;  
	} ;
	void leftRotate(NODORJ *,NODORJ *);
	void rightRotate(NODORJ *,NODORJ *);
	bool isCorregir(NODORJ *);
	bool isBlack(NODORJ*);
	
};

bool ARBOLRJ::isBlack(NODORJ* nodo){
	if(nodo->color==0)
		return true;
	else 
		return false;
}

void ARBOLRJ::ajustar(NODORJ* A, NODORJ* x){
	// x -> nodo a eliminar
	//w -> nodo aux
	//p -> returnfather(x);
	
	NODORJ* p;
	p=returnFather(x);
	
	NODORJ* w;
	w=new NODORJ;
	
	while((root(A))&&(isBlack(x))){
		if(x==returnLeftOf(p)){
			w=returnRightOf(p);
			//C1
			if(!isBlack(x)){
				w->color=0;
				p->color=1;
				leftRotate(A,p);
				w=returnRightOf(p);
			}
			//C2:
			NODORJ* Wi;
			NODORJ* Wd;
			Wi=returnLeftOf(w);
			Wd=returnRightOf(w);
			if(isBlack(Wi)&&(isBlack(Wd))){
				w->color=1;
				x=returnFather(x);
			}else{
				if(isBlack(Wd)){
					//C3
					Wi->color=0;
					w->color=1;
					rightRotate(A,w);
					w=returnRightOf(p);
				}
				Wi=returnLeftOf(w);
				Wd=returnRightOf(w);
				w->color=p->color;
				p->color=0;
				Wd->color=0;
				leftRotate(A,p);
				x=root(A);
			}		
		}else{
			w=returnLeftOf(p);
			//C1
			if(!isBlack(x)){
				w->color=0;
				p->color=1;
				rightRotate(A,p);
				w=returnLeftOf(p);
			}
			//C2:
			NODORJ* Wi;
			NODORJ* Wd;
			Wi=returnLeftOf(w);//?
			Wd=returnRightOf(w);//?
			if(isBlack(Wi)&&(isBlack(Wd))){
				w->color=1;
				x=returnFather(x);
			}else{
				if(isBlack(Wd)){
					//C3
					Wi->color=0;
					w->color=1;
					leftRotate(A,w);
					w=returnLeftOf(p);
				}
				Wi=returnLeftOf(w);//?
				Wd=returnRightOf(w);//?
				w->color=p->color;
				p->color=0;
				Wd->color=0;
				rightRotate(A,p);
				x=root(A);
			}
		}
	}
x->color=0;
}
