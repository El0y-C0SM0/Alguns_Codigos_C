#include <stdio.h>
#include <math.h>

/*
    código para calcula as raizes de uma equação do segundo grau.
    A saida informa o delta, as raizes, a direção da concavidade e o X e Y do vertice,
    isso se for posivel calcular.
*/


int delta(int A, int B, int C) {
    return (B * B) - 4 * A * C;
}
void calculaRaizes(int A, int B, double DELTA, double *X) {
    if(DELTA == 0) {
        X[0] = (-B) / (2 * A);
        X[1] = X[0];
    }
    else {
        X[0] = (-B + sqrt(DELTA)) / (2 * A);
        X[1] = (-B - sqrt(DELTA)) / (2 * A);
    }
}
double vetice_no_X(int A, int B) {
    double b = B;
    return (-b) / (2 * A);
}
double vetice_no_Y(int A, double DELTA) {
    return (-DELTA) / (4 * A);
}
void concavidade(int A) {
    if(A > 0)
        puts("concavidade da parabola e para cima");
    else
        puts("concavidade da parabola e para baixo");
}
void imprime(int A, double DELTA, double *X, double verticeX, double verticeY){
    printf("delta = %.0f\n", DELTA);
    concavidade(A);
    
    if(X[0] != X[1]) {
        printf("X1 = %.2f\n", X[0]);
        printf("X2 = %.2f\n", X[1]);
    }
    else
        printf("X = %.2f\n", X[0]);

    printf("vertice X = %.2f\n", verticeX);
    printf("vertice Y = %.2f\n", verticeY);
}
int encerraCodigo() {
    do {
        puts("digite 'fechar' para encerrar o programa ou 'continuar' para continuar calculando (sem as aspas)");

        char decisao[13];
        char fecha[7] = "fechar";
        char continua[9] = "continua";
        
        scanf("%s", decisao);

        if((decisao[1] == 'f') || (decisao[1] == 'c')){
            puts("eu disse sem aspas");
        }
        else {
            int contador[2] = {0, 0};
            for(int i = 0; i < 7; i++) {
                if(decisao[i] == fecha[i])
                    contador[0]++;
                else if(decisao[i] == continua[i])
                    contador[1]++;
                else{
                    puts("digita 'fechar' ou 'continuar', bobo");
                    break;
                }
                if(contador[0] == 6)
                    return 1;
                else if(contador[1] == 6)
                    return 0;
            }

        }
    } while(1);
}
int main() {
    int A, B, C;
    double X[2];

    do {
        puts("digite os coeficientes A, B e C da equacao do segundo grau (na ordem)");

        scanf("%d %d %d", &A, &B, &C);

        if(A == 0){
            printf("Nao e uma equacao do segundo grau");
            continue;
        }

        double DELTA = delta(A, B, C);

        if(DELTA < 0){
            puts("Nao foi posivel calcular as raizes da equacao");
            continue;
        }

        calculaRaizes(A, B, DELTA, X);    

        double verticeX = vetice_no_X(A, B);
        double verticeY = vetice_no_Y(A, DELTA);

        imprime(A, DELTA, X, verticeX, verticeY);

        if(encerraCodigo() == 1)
            break;

    } while(1);
    return 0;
}