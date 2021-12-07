#include<stdio.h>
#include<string.h>
#define MAX 100
#define m 30

typedef struct
{
    char operad[MAX];
    int tope;
}operparen;

void inicializapila(operparen *p);
void operaciones(int *num, char op[m]);
void recorridocadena(char op[m], operparen *p, int num);

int main()
{
    int numero;
    char operacion[m];
    operparen operad;
    inicializapila(&operad);
    operaciones(&numero, operacion);
    recorridocadena(operacion, &operad, numero);
}

void inicializapila(operparen *p)
{
    p->tope=-1;
}

void operaciones(int *num, char op[m])
{
    printf("Escriba su operacion: ");
    gets(op);
    *num = strlen(op);
    // La siguiente impresion fue para verificar que si regrese el tamaño de una cadena
    //printf("%d", *num);
}

void recorridocadena(char op[m], operparen *p, int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        if(op[i]!='*' || op[i]!='/' || op[i]!='+' || op[i]!='-' || op[i]!='(' || op[i]!=')')
            printf("%c", op[i]);
        else
        {
            if(op[i]!=')')
            {
               p->tope++;
               p->operad[p->tope] = op[i];
            }
              else
              {
                while(p->tope!=-1)
                {
                    if(p->operad[p->tope] != '(')
                       {
                        printf("%c", p->operad[p->tope]);
                        p->tope--;
                       }
                }
              }
        }
    }
}
