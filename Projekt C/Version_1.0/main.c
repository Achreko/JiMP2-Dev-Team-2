//
//  main.c
//  automat_komorkowy
//
//  Created by kasia on 3/7/20.
//  Copyright © 2020 kasia. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funkcje.h"

int main(int argc, const char * argv[]) {
    //otwieranie pliku z planszą
    FILE *in= fopen(argv[1],"r");
   
    //sprawdzenie czy plik się otworzył
    if(in==NULL){
        printf("Nie mogę otworzyc pliku !!!\n");
        exit(0);
    }
    
    //inicjalizacja zmiennych przechowywujacych wiersze i kolumny
    int kolumny = 0,wiersze = 0;
    pobierz_wiersze_i_kolumny(in,&wiersze,&kolumny);
   //pierwsza dana w pliku to kolumna, druga to wiersz
    
    
   //inicjalizacja tablic przechowywujących generacje
    int array[wiersze][kolumny];//tablica przechowywujaca generacje
    int array2[wiersze][kolumny];//tablica porownujaca stany komorek
    
    //zapisanie danych z pliku do array
    zapisz(in,wiersze,kolumny,array);
  
    //zamknięcie pliku z planszą
    fclose(in);
  
    
    //skopiowanie elementów z array do array2
    przepisz(wiersze,kolumny,array,array2);
   
    
    
    //ile generacji ma byc wykonanych
    int n;
    printf("ile generacji chcesz wykonac?\n");
    scanf("%d",&n);
   
    
  
    generacja_cyklu(wiersze,kolumny,array,array2, n);
    
    return 0;
   
    
    
}
    
    

