#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* funções auxiliares para implementação dos métodos de ordenação */

/* protótipo das funções auxiliares */
template <class Item> void exch(Item &A, Item &B);		/* inverte A com B */
template <class Item> void compexch(Item &A, Item &B); 	/* maior elemento em A, menor em B */

template <class Item>      
void exch(Item &A, Item &B) 
{ 
	Item t = A; 
	A = B; 
	B = t; 
}

template <class Item> 
void compexch(Item &A, Item &B) 
{ 
	if (B < A) 
		exch(A, B); 
}

#endif