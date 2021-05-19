#include "matrixfact.h"
#include <stdio.h>
int GAN (char* lol, PMATRIX don){
    FILE* F=fopen(lol,"r");
    if (F==NULL) return 1;
    int i,j;
    float t;
    for(i=0; i<4;i++)
        for(j=0;j<4;j++){
            if(fscanf(F, "%f", &t) !=1) return 2;
            (*don)[i][j]=t;
            }
fclose(F);
return 0;
}
/*!
	\brief Функция PLUS вычисляет сумму всех чисел выбранной части матрицы
	\param[in] PMATRIX don, int part – входящие параметры, указывающие на нужную часть матрицы
	\param[out] float S – исходящий параметр, обозначающий итоговый результат 
	\param int j1, j2, I, J – параметры, используемые для чтения нужных значений матрицы
*/
float PLUS(PMATRIX don, int part){
    float S=0;
    int j1, j2;
    int I, J;
    switch (part){
        case 1: j1=0; j2=3;
        break;
        case 2: j1=0; j2=3;
        break;
        case 3: j1=0; j2=0;
        break;
        case 4: j1=3; j2=3;
        break; 
    }     
    for(I=0; I<4; I++){
        for(J=j1;J<=j2;J++) S+= (*don)[I][J];

        switch (part){
            case 1: j2--;
            break;
            case 2: j1++;
            break;
            case 3: j2++;
            break;
            case 4: j1--;
            break; 
        } 
    }
    return S;
}
/*!
	\brief Функция MIN – вывод минимального числа из выбранной части матрицы
	\param[in] PMATRIX don, int part – входящие параметры, указывающие на нужную часть матрицы
	\param[out] float S – исходящий параметр, обозначающий итоговый результат 
	\param int j1, j2, I, J – параметры, используемые для чтения нужных значений матрицы
*/
float MIN(PMATRIX don, int part){
       float S=0;
    int j1, j2;
    int I, J;
    switch (part){
        case 1: j1=0; j2=3;
        break;
        case 2: j1=0; j2=3;
        break;
        case 3: j1=0; j2=0;
        break;
        case 4: j1=3; j2=3;
        break; 
    }
    S=(*don)[0][j1]; 
    for(I=0; I<4; I++){
        for(J=j1;J<=j2;J++) if (S > (*don)[I][J])
            S = (*don)[I][J];
    
        switch (part){
            case 1: j2--;
            break;
            case 2: j1++;
            break;
            case 3: j2++;
            break;
            case 4: j1--;
            break; 
        } 
    }
    return S;
}
/*!
	\brief Функция MAX – вывод максимального числа из выбранной части матрицы
	\param[in] PMATRIX don, int part – входящие параметры, указывающие на нужную часть матрицы
	\param[out] float S – исходящий параметр, обозначающий итоговый результат 
	\param int j1, j2, I, J – параметры, используемые для чтения нужных значений матрицы
*/
float MAX(PMATRIX don, int part){
           float S=0;
    int j1, j2;
    int I, J;
    switch (part){
        case 1: j1=0; j2=3;
        break;
        case 2: j1=0; j2=3;
        break;
        case 3: j1=0; j2=0;
        break;
        case 4: j1=3; j2=3;
        break; 
    }
    S=(*don)[0][j1]; 
    for(I=0; I<4; I++)
    {
        for(J=j1;J<=j2;J++) if (S < (*don)[I][J])
            S = (*don)[I][J];
    
        switch (part){
            case 1: j2--;
            break;
            case 2: j1++;
            break;
            case 3: j2++;
            break;
            case 4: j1--;
            break; 
        } 
    }
    return S;
}


