#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "functions.h"

template <class Item> void fixUp  (Item a[], int k);
template <class Item> void fixDown(Item a[], int k, int N);

template <class Item>
class PriorityQueue 
{
private:
    Item *pq; 
    int N;
public:
	PriorityQueue(int maxN){ pq = new Item[maxN+1]; N = 0; }
	~PriorityQueue(){ delete pq; }
    int empty() { return N == 0; }
    void insert(Item item){ pq[++N] = item; fixUp(pq,N); }
    Item getmax() { 
          exch(pq[1], pq[N]); 
          fixDown(pq, 1, N-1); 
          return pq[N--]; 
    }
};

template <class Item>
void fixUp(Item a[], int k)
{
	while (k > 1 && a[k/2] < a[k])
	{ 
		exch(a[k], a[k/2]); 
		k = k/2; 
	}
}

template <class Item>
void fixDown(Item a[], int k, int N)
{
	while (2*k <= N)
	{ 
		int j = 2*k;
		if (j < N && a[j] < a[j+1]) j++;
		if (!(a[k] < a[j])) break;
		exch(a[k], a[j]); k = j;
	}
}


#endif

