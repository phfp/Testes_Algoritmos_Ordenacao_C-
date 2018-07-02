/* 
 * File:   Ordenacao.h
 * Author: ph
 *
 * Created on 1 de Novembro de 2011, 19:41
 */

#ifndef ORDENACAO_H
#define	ORDENACAO_H

void CriarVetorDes(); //Preenche vetor com valores em ordem aleatoria
void CriarVetorDec(); //Preenhe vetor com valores em ordem decrescente
void Vetor_desordenado(int); // funcao que mede tempo de ordenacao de vetores desordenados
void Vetor_ordenado_crescente(int); // mede tempo de ordenacao de vetores em ordem crescente
void Vetor_ordenado_decrescente(int); // mede tempo de ordenacao de vetores em ordem decrescente
struct media //estrutura que guarda os valores obtidos;
{
    double InsertionDes[110]; // sao guardados resultados de ordenacao de vetores
    double InsertionAdapDes[110];
    double SeletionDes[110];
    double BublleDes[110];
    double ShellDes[110];
    double QuickDes[110];
    double MergeDes[110];
    double MergeBUDes[110];
    double PQDes[110];
    double HeapDes[110];
    double InsertionCres[110];
    double InsertionAdapCres[110];
    double SeletionCres[110];
    double BublleCres[110];
    double ShellCres[110];
    double QuickCres[110];
    double MergeCres[110];
    double MergeBUCres[110];
    double PQCres[110];
    double HeapCres[110];
    double InsertionDec[110];
    double InsertionAdapDec[110];
    double SeletionDec[110];
    double BublleDec[110];
    double ShellDec[110];
    double QuickDec[110];
    double MergeDec[110];
    double MergeBUDec[110];
    double PQDec[110];
    double HeapDec[110];
};
#endif	/* ORDENACAO_H */

