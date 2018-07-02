#ifndef SORT_H
#define SORT_H

#include "functions.h"
#include "priority_queue.h"

const int maxN = 60000;	/* tamanho máximo do vetor estático */
						/* usado mo mergesort */

/* protótipo das funções auxiliares */
inline int min(int A, int B); 										/* retorna o menor elemento */
template <class Item> int partition (Item a[], int l, int r);		/* quicksort */
template <class Item> void merge(Item a[], int l, int m, int r);	/* mergesort */

/* protótipo das funções de ordenação */
template <class Item> void InsertionSort           (Item a[], int l, int r);
template <class Item> void InsertionSortAdaptativo (Item a[], int l, int r);
template <class Item> void SelectionSort           (Item a[], int l, int r);
template <class Item> void BubbleSort              (Item a[], int l, int r);
template <class Item> void ShellSort               (Item a[], int l, int r);
template <class Item> void quicksort               (Item a[], int l, int r);
template <class Item> void mergesort               (Item a[], int l, int r);
template <class Item> void mergesortBU             (Item a[], int l, int r);
template <class Item> void PQSort                  (Item a[], int l, int r);
template <class Item> void HeapSort                (Item a[], int l, int r);


inline int min(int A, int B) 
{ 
	return (A < B) ? A : B; 
}

template <class Item>    
void InsertionSort(Item a[], int l, int r)
{ 
	for (int i = l+1; i <= r; i++)
		for (int j = i; j > l; j--)
			compexch(a[j-1], a[j]);
}

template <class Item>
void InsertionSortAdaptativo(Item a[], int l, int r)
{ 
	int i;
	//Garantindo que a[0] contém menor elemento
	for (i = r; i > l; i--) compexch(a[i-1], a[i]);

    //Para os demais elementos, insertion sort
	for (i = l+2; i <= r; i++)
	{ 
		int j = i; Item v = a[i]; 
        while (v < a[j-1])
		{ 
			a[j] = a[j-1]; 
			j--; 
		}
        a[j] = v; 
	} 
}

template <class Item>
void SelectionSort(Item a[], int l, int r)
{
	for (int i = l; i < r; i++)
	{ 
		int min = i;
		for (int j = i+1; j <= r; j++) 
			if (a[j] < a[min]) min = j; 
		exch(a[i], a[min]);
	} 
}

template <class Item>
void BubbleSort(Item a[], int l, int r)
{ 
	for (int i = l; i < r; i++)
		for (int j = r; j > i; j--)
			compexch(a[j-1], a[j]);
}

template <class Item>
void ShellSort(Item a[], int l, int r)
{ 
	int h; 
	for (h = 1; h <= (r-l)/9; h = 3*h+1) ; 
	for ( ; h > 0; h /= 3)
		for (int i = l+h; i <= r; i++)
		{ 
			int j = i; 
			Item v = a[i]; 
			while (j >= l+h && v < a[j-h])
			{ 
				a[j] = a[j-h]; 
				j -= h; 
			}
			a[j] = v; 
		} 
}

template <class Item>
void quicksort(Item a[], int l, int r)
{
	if (r <= l) return;
	int i = partition(a, l, r);
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}

template <class Item>
int partition(Item a[], int l, int r) 
{
	int i = l-1, j = r; Item v = a[r];
	for (;;) 
	{ 
		while (a[++i] < v) ;
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
		exch(a[i], a[j]);
	}
	exch(a[i], a[r]);
	return i;
}

template <class Item>
void merge(Item a[], int l, int m, int r)
{ 
	int i, j;
	static Item aux[maxN]; /*vetor permanece alocado*/
	for (i = m+1; i > l; i--) aux[i-1] = a[i-1];
	for (j = m; j < r; j++) aux[r+m-j] = a[j+1];
	for (int k = l; k <= r; k++)
		if (aux[j] < aux[i]) 
			a[k] = aux[j--]; else a[k] = aux[i++];
}

template <class Item>
void mergesort(Item a[], int l, int r)
{ 
	if (r <= l) return;
	int m = (r+l)/2;
	mergesort(a, l, m);  
	mergesort(a, m+1, r);
	merge(a, l, m, r);
}

template <class Item>
void mergesortBU(Item a[], int l, int r)
{
	for (int m = 1; m <= r-l; m = m+m)
		for (int i = l; i <= r-m; i += m+m)
			merge(a, i, i+m-1, min(i+m+m-1, r));
}

template <class Item>
void PQSort(Item a[], int l, int r)
{ 
	int k;
	PriorityQueue<Item> pq(r-l+1);
	for (k=l; k<=r; k++) pq.insert(a[k]);
	for (k=r; k>=l; k--) a[k] = pq.getmax();
}

template <class Item>
void HeapSort(Item a[], int l, int r)
{ 
	int k, N = r-l+1;
	Item *pq = a+l-1;
	for (k = N/2; k >= 1; k--) 
		fixDown(pq, k, N);
	while (N > 1) 
	{ 
		exch(pq[1], pq[N]); 
		fixDown(pq, 1, --N); 
	}
}


#endif