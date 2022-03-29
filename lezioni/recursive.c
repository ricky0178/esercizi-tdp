#include <stdio.h>
#include <stdlib.h>

/*
    FUNZIONI RICORSIVE e RICORSIONE:
    -Domini definiti induttivamente:
        Esempio induttivo: I numeri naturali possono essere definiti induttivamente. 
        Se 0 appartiene ad n, ed n appartiene ai naturali allora anche n+1 appartiene allo stesso insieme.
        Una sequenza può essere definita induttivamente, se la sequenza vuota è sequenza, e quindi aggiunte
        alla sequenza è sempre una sequenza.
    -Funzioni ricorsive:
        Una funzione si dice ricorsiva se al suo interno contiene un attivazione di sè stessa, o indirettamente
        attraverso l'attivazione di altre funzioni. 
        ESEMPIO: La funzione fattoriale è ricorsiva! formato da caso base (fatt(n) = 1 con n = 0)
        e da caso ricorsivo (fatt (n) = n*fatt(n-1) con n > 0)

    STEP:
        -definire funzione
        -inserire il caso base (=> if (..) return n)
        -definire caso ricorsivo (=> else return f(n))


*/

//MODO NON RICORSIVO
int fattoriale1(int n){
    int fattoriale = 1;
    int i = n;
    while (i > 0){
        fattoriale *= i;
        i--;
    }
    return fattoriale;
}

//MODO RICORSIVO
int fattoriale2(int n){
    if (n == 0)
        return 1;
    else
        return n * fattoriale2(n-1);    //ricorsiva in quanto nella definizione viene chiamata la stessa funzione
}

void copiaRicorsiva(FILE* i, FILE* o){  //metodo ricorsivo per copiare file, se carattere == EOF si ferma
    char x = fgetc(i);
    if (x!= EOF){
        fputc(x, o);
        copiaRicorsiva(i,o);
    }
}

int main(){
    int n = 4;
    printf("Fattoriale (metodo non ricorsivo) di %d = %d\n", n, fattoriale1(n));
    printf("Fattoriale (metodo ricorsivo) di %d = %d\n", n, fattoriale2(n));
    FILE* f_in = fopen("./lezioni/in.txt", "r");
    FILE* f_out = fopen("./lezioni/out.txt", "w");
    if(f_in == NULL || f_out == NULL)
        exit(1);
    copiaRicorsiva(f_in, f_out);
    
    return 0;
}