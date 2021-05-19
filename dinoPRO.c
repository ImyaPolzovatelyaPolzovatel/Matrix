#include <matrixfact.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//Справка 
void printhelp(){
    printf("Cправка\n\n\n"); 
    printf("Рабочий вызов: \n");
    printf("dinoPRO -c <имя файла> -f <номер фрагмента> -n <номер операции> \n\n");
	printf("Вызов справки: \n");
	printf("dinoPRO -h \n\n");
	printf("Номер фрагмента: \n");
	printf("1-левая верхняя часть \n");
	printf("2-правая верхняя часть \n");
	printf("3-левая нижняя часть \n");
	printf("4-правая нижняя часть \n\n");
	printf("Операция: \n");
	printf("MAX- вывод максимального числа \n");
	printf("MIN- вывод минимального числа \n");
	printf("PLUS- сумма всех чисел данной части матрицы \n\n");
}
void printerror(){
    printf("ошибка\n -h -вызов справки\n");
}
int main(int argc, char *argv[]){
    
    TMATRIX A;
    char Fname[100]="";
    int Fnom=5;
    char Fdiv[5]="";

    int rs;
    //opterr=0;
    while ((rs=getopt(argc,argv, ":c:f:n:h")) !=-1)
        switch (rs){
            case 'c':strcpy(Fname, optarg); break;
            case 'f':Fnom=atoi(optarg); break;
            case 'n':strcpy(Fdiv, optarg); break;
            case 'h':printhelp(); return 0;     
            default:printerror(); return 1;
        }
    printf("%s\n", Fname);
    printf("%d\n", Fnom);
    printf("%s\n", Fdiv);
    if (Fname[0]==0)
        {
        printerror(); return 1;
        }
    if (!((strcmp(Fdiv,"PLUS")==0) ||
    (strcmp(Fdiv,"MIN")==0) ||
    (strcmp(Fdiv,"MAX")==0)))
            {
            printerror(); return 1;
            }
    if ((Fnom<1) || (Fnom>4))
            {
            printerror(); return 1;
            }
if(GAN(Fname,&A)!=0)
    {
        printf("ошибка чтения\n");
        return 1;
    }

if(strcmp(Fdiv,"PLUS")==0){
printf("сумма равна %f\n", PLUS(&A,Fnom));
return 0;
}

if(strcmp(Fdiv,"MIN")==0){
printf("минимум равен %f\n", MIN(&A,Fnom));
return 0;
}

if(strcmp(Fdiv,"MAX")==0){
printf("максимум равен %f\n", MAX(&A,Fnom));
return 0;
}

}

