

// Crea unn sub arbol
tArbol Crea0(tEtiqueta et){
  tArbol raiz;
  
  raiz=(tArbol)malloc (sizeof(struct tipocelda));
  if (!raiz){
    error("Memoria Insuficiente.");}
  raiz->padre=NULL;
  raiz->hizqda=NULL;
  raiz->etiqueta=et;
  return raiz;
