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
    FILE *in= fopen(argv[1],"r");
    if(in==NULL){
        printf("nie moge otworzyc pliku\n");
        exit(9);
    }
    int kolumny,wiersze;
  fscanf(in,"%d",&kolumny);
     fscanf(in,"%d",&wiersze);
    
    //zapisze komorki z pliku do tablicy
    
    int array[wiersze][kolumny];//tablica przechowywujaca generacje
    int array2[wiersze][kolumny];//tablica porownujaca stany komorek
    zapisz(in,wiersze,kolumny,array,array2);
    
  
    
    //ile generacji ma byc wykonanych
    int n;
    printf("ile generacji chcesz wykonac?\n");
    scanf("%d",&n);
   
    
  
    // sprawdzanie i zmiana stanu komorek
    for(int h=0;h<n;h++){
    
        generuj(wiersze,kolumny,array,array2,h);
            
            
        //przepisanie nowych komorek z array do array2
        przepisz(wiersze,kolumny,array,array2);
            
    }
       
    }
   
    
    
    
    
    

