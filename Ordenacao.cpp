#include <iostream>
#include <stdlib.h>
#include "sort.h"
#include "Timer.h"
#include <fstream>
#include "Ordenacao.h"

using namespace std;

void CriarVetorDec(int *v, int m, int n) // preenche vetor com dados em ordem decrescente
{
    for (int i=0; i<m ; i++)
        {
            v[i] = n;
            n --;
        }  
}

void CriarVetorDes(int *v, int n)// preenche um vetor com valores aleatrios e desordenados
{
    for (int i = 0; i < n; i++)
        v[i] = 100000*(1.0*rand()/RAND_MAX);
}

void Vetor_desordenado(int n) // recebe a qtd de testes a serem executado
{
    const int N = 100; // tamanho máximo de vetor
    int aux; // variável auxiliar
    media media; //estrutura que armazenará os resultados obtidos 
    
    int a[N]; // Vetor a ser ordenado
    
    ofstream carregar("Desordenado.txt"); //abre um arquivo para leitura 
    
    for(int i=0; i<n;i++) // contagem de tempo n vezes
    {
        aux = N; // variável guarda o tamanho mźximo do vetor
        int j = 0; // indice para os dados da strutura media
        
        // ordenacao do vetor, cada nova execucao ordena a metade de elementos
        for(aux;aux>9;aux/=1.08) // da execucao anterior
        {
            CriarVetorDes(a,aux); // preenche o vetor em ordem aleatoria
            
            Timer t;
            t.Start();

            InsertionSort           (a, 0, aux-1);

            t.Stop();
            
            media.InsertionDes[j] += t.Elapsedus(); //soma e guarda o tempo obtido
            j++; //j incrementa para ser somado e guardado o proximo tempo obtido
        }
        
        aux = N;
        j = 0;

        for(aux;aux>9;aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            InsertionSortAdaptativo (a, 0, aux-1);

            t.Stop();        
         
            media.InsertionAdapDes[j] += t.Elapsedus();
            j++;

        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
             CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            SelectionSort           (a, 0, aux-1);

            t.Stop();

          media.SeletionDes[j] += t.Elapsedus();
          j++;

        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
             CriarVetorDes(a,aux);

             Timer t;
             t.Start();

             BubbleSort              (a, 0, aux-1);

             t.Stop();

            media.BublleDes[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {

            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            ShellSort               (a, 0, aux-1);

            t.Stop();

            media.ShellDes[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            quicksort               (a, 0, aux-1);

            t.Stop();        

            media.QuickDes[j] += t.Elapsedus();
            j++;

        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            mergesort               (a, 0, aux-1);

            t.Stop();        

            media.MergeDes[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            mergesortBU             (a, 0, aux-1);

            t.Stop();

            media.MergeBUDes[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            PQSort                  (a, 0, aux-1);

            t.Stop();

            media.PQDes[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {
            CriarVetorDes(a,aux);

            Timer t;
            t.Start();

            HeapSort                (a, 0, aux-1);

            t.Stop();

            media.HeapDes[j] += t.Elapsedus();
            j++;
        }    
    }    
    
    aux = N;
    int i = 0;
    
        //divide os resulta
    carregar << "MEDIAS OBTIDAS COM " << n << " EXECUCOES." << endl;
    for (aux; aux>9;aux/=1.08)
    {
        carregar << endl;
        carregar << i+1 << "° vetor" << endl;
        media.InsertionDes[i] /= n; // divide as somas obtida por n vezes e escreve os resultados
        carregar << "Insertion Sort-------------------" << aux << "---elementos: "  << media.InsertionDes[i] << " microsengundos" << endl;
        media.InsertionAdapDes[i] /= n;
        carregar << "Insertion Sort Adaptativo--------" << aux << "---elementos: "  << media.InsertionAdapDes[i] << " microsengundos" << endl;
        media.SeletionDes[i] /= n;
        carregar << "Seletion Sort--------------------" << aux << "---elementos: "  << media.SeletionDes[i] << " microsengundos" << endl;
        media.BublleDes[i] /= n;
        carregar << "Bublle Sort----------------------" << aux << "---elementos: "  << media.BublleDes[i] << " microsengundos" << endl;
        media.ShellDes[i] /= n;
        carregar << "Shell Sort-----------------------" << aux << "---elementos: "  << media.ShellDes[i] << " microsengundos" << endl;
        media.QuickDes[i] /= n;
        carregar << "Quick Sort-----------------------" << aux << "---elementos: "  << media.QuickDes[i] << " microsengundos" << endl;
        media.MergeDes[i] /= n;
        carregar << "Merge Sort-----------------------" << aux << "---elementos: "  << media.MergeDes[i] << " microsengundos" << endl;
        media.MergeBUDes[i] /= n;
        carregar << "Merge Sort BU--------------------" << aux << "---elementos: "  << media.MergeBUDes[i] << " microsengundos" << endl;
        media.PQDes[i] /= n;
        carregar << "PQ Sort--------------------------" << aux << "---elementos: "  << media.PQDes[i] << " microsengundos" << endl;
        media.HeapDes[i] /= n;
        carregar << "Heap Sort------------------------" << aux << "---elementos: "  << media.HeapDes[i] << " microsengundos" << endl;
        carregar << endl;
        i++;
    }

}

void Vetor_ordenado_crescente(int n)
{
        
    const int N = 100;
    int aux;
    media media;
    aux = N;
    
    int a[N];
    
    ofstream carregar("Crescente.txt"); //abre um arquivo para leitura
    
    
    for (int i = 0; i < aux; i++) // preenche vetor em ordem crescente
        a[i] = i;    
    
    for(int i=0; i<n;i++)//testa programas n vezes
    {
        int j=0; // indice para os dados da estrutura media          
    
        for(aux ; aux>9 ; aux/=1.08)// a cada execucao ordena a metade de elementos 
        {                       // ordenados na execucao anterior   
            Timer t;
            t.Start();

            InsertionSort           (a, 0, aux-1);

            t.Stop();

            media.InsertionCres[j] += t.Elapsedus(); // soma e guarda os tempos obtidos
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            InsertionSortAdaptativo (a, 0, aux-1);

            t.Stop();

            media.InsertionAdapCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            SelectionSort           (a, 0, aux-1);

            t.Stop();

            //carregar << aux  << "    "  << t.Elapsedus() << endl;
            media.SeletionCres[j] += t.Elapsedus();
            j++;

        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            BubbleSort              (a, 0, aux-1);

            t.Stop();

            media.BublleCres[j] += t.Elapsedus();
            j++;

        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            ShellSort               (a, 0, aux-1);

            t.Stop();

            media.ShellCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {        
            Timer t;
            t.Start();

            quicksort               (a, 0, aux-1);

            t.Stop();

            media.QuickCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {            
            Timer t;
            t.Start();

            mergesort               (a, 0, aux-1);

            t.Stop();

            media.MergeCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {

            Timer t;
            t.Start();

            mergesortBU             (a, 0, aux-1);

            t.Stop();

            media.MergeBUCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            PQSort                  (a, 0, aux-1);

            t.Stop();

            media.PQCres[j] += t.Elapsedus();
            j++;
        }

        aux = N;
        j = 0;

        for(aux ; aux>9 ; aux/=1.08)
        {         
            Timer t;
            t.Start();

            HeapSort                (a, 0, aux-1);

            t.Stop();

            media.HeapCres[j] += t.Elapsedus();
            j++;
        }
    
    }    
    aux = N;
    int i = 0;
    
    carregar << "MEDIAS OBTIDAS COM " << n << " EXECUCOES." << endl;
    for (aux; aux>9;aux/=1.08)
    {
        carregar << endl;
        carregar << i+1 << "° vetor" << endl;
        media.InsertionCres[i] /= n;
        carregar << "Insertion Sort-------------------" << aux << "---elementos: "  << media.InsertionCres[i] << " microsengundos" << endl;
        media.InsertionAdapCres[i] /= n;
        carregar << "Insertion Sort Adaptativo--------" << aux << "---elementos: "  << media.InsertionAdapCres[i] << " microsengundos" << endl;
        media.SeletionCres[i] /= n;
        carregar << "Seletion Sort--------------------" << aux << "---elementos: "  << media.SeletionCres[i] << " microsengundos" << endl;
        media.BublleCres[i] /= n;
        carregar << "Bublle Sort----------------------" << aux << "---elementos: "  << media.BublleCres[i] << " microsengundos" << endl;
        media.ShellCres[i] /= n;
        carregar << "Shell Sort-----------------------" << aux << "---elementos: "  << media.ShellCres[i] << " microsengundos" << endl;
        media.QuickCres[i] /= n;
        carregar << "Quick Sort-----------------------" << aux << "---elementos: "  << media.QuickCres[i] << " microsengundos" << endl;
        media.MergeCres[i] /= n;
        carregar << "Merge Sort-----------------------" << aux << "---elementos: "  << media.MergeCres[i] << " microsengundos" << endl;
        media.MergeBUCres[i] /= n;
        carregar << "Merge Sort BU--------------------" << aux << "---elementos: "  << media.MergeBUCres[i] << " microsengundos" << endl;
        media.PQCres[i] /= n;
        carregar << "PQ Sort--------------------------" << aux << "---elementos: "  << media.PQCres[i] << " microsengundos" << endl;
        media.HeapCres[i] /= n;
        carregar << "Heap Sort------------------------" << aux << "---elementos: "  << media.HeapCres[i] << " microsengundos" << endl;
        carregar << endl;
        i++;
    }

}

void Vetor_ordenado_decrescente(int n)
{       
   const int N = 100;
   int aux1, aux2;
   media media;
   
   int a[N];

    ofstream carregar("Decrescente.txt"); //abre um arquivo para leitura
    
    for(int i=0; i<n;i++){// laco para fazer n testes
        
        aux1 = N;
        aux2 = aux1; // e criado a variavel aux2 para ser usada na funcao CriarVetorDec()
        int j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)//a cada nova execucao e ordenado a metade
        {                          // de elemendtos ordenados da execucao anterior                                                                                     
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);//preenche vetor com valores em ordem decrescente

            Timer t;
            t.Start();

            InsertionSort           (a, 0, aux1-1);

            t.Stop();

            media.InsertionDec[j] += t.Elapsedus();//soma e guarda dos tempos
            j++; 

        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            InsertionSortAdaptativo (a, 0, aux1-1);

            t.Stop();

            media.InsertionAdapDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            SelectionSort           (a, 0, aux1-1);

            t.Stop();

            media.SeletionDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            BubbleSort              (a, 0, aux1-1);

            t.Stop();

            media.BublleDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

           CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            ShellSort               (a, 0, aux1-1);

            t.Stop();

            media.ShellDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

         for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            quicksort               (a, 0, aux1-1);

            t.Stop();

            media.QuickDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            mergesort               (a, 0, aux1-1);

            t.Stop();

            media.MergeDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            mergesortBU             (a, 0, aux1-1);

            t.Stop();        

            media.MergeBUDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;

         for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            PQSort                  (a, 0, aux1-1);

            t.Stop();

            media.PQDec[j] += t.Elapsedus();
            j++;
        }

        aux1 = N;
        j = 0;
        
        for(aux1 ; aux1>9 ; aux1/=1.08)
        {
            aux2 = aux1;

            CriarVetorDec(a,aux1,aux2);

            Timer t;
            t.Start();

            HeapSort                (a, 0, aux1-1);

            t.Stop();        

            media.HeapDec[j] += t.Elapsedus();
            j++;
        }
    }
    
        aux1 = N;
        int i = 0;

        carregar << "MEDIAS OBTIDAS COM " << n << " EXECUCOES." << endl;
        for (aux1; aux1>9;aux1/=1.08)
        {
            carregar << endl;
            carregar << i+1 << "° vetor" << endl;
            media.InsertionDec[i] /= n;
            carregar << "Insertion Sort-------------------" << aux1 << "---elementos: "  << media.InsertionDec[i] << " microsengundos" << endl;
            media.InsertionAdapDec[i] /= n;
            carregar << "Insertion Sort Adaptativo--------" << aux1 << "---elementos: "  << media.InsertionAdapDec[i] << " microsengundos" << endl;
            media.SeletionDec[i] /= n;
            carregar << "Seletion Sort--------------------" << aux1 << "---elementos: "  << media.SeletionDec[i] << " microsengundos" << endl;
            media.BublleDec[i] /= n;
            carregar << "Bublle Sort----------------------" << aux1 << "---elementos: "  << media.BublleDec[i] << " microsengundos" << endl;
            media.ShellDec[i] /= n;
            carregar << "Shell Sort-----------------------" << aux1 << "---elementos: "  << media.ShellDec[i] << " microsengundos" << endl;
            media.QuickDec[i] /= n;
            carregar << "Quick Sort-----------------------" << aux1 << "---elementos: "  << media.QuickDec[i] << " microsengundos" << endl;
            media.MergeDec[i] /= n;
            carregar << "Merge Sort-----------------------" << aux1 << "---elementos: "  << media.MergeDec[i] << " microsengundos" << endl;
            media.MergeBUDec[i] /= n;
            carregar << "Merge Sort BU--------------------" << aux1 << "---elementos: "  << media.MergeBUDec[i] << " microsengundos" << endl;
            media.PQDec[i] /= n;
            carregar << "PQ Sort--------------------------" << aux1 << "---elementos: "  << media.PQDec[i] << " microsengundos" << endl;
            media.HeapDec[i] /= n;
            carregar << "Heap Sort------------------------" << aux1 << "---elementos: "  << media.HeapDec[i] << " microsengundos" << endl;
            carregar << endl;
            i++;
        }    
}