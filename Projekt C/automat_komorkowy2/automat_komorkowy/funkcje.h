//
//  funkcje.h
//  automat_komorkowy
//
//  Created by kasia on 3/14/20.
//  Copyright © 2020 kasia. All rights reserved.
//

#ifndef funkcje_h
#define funkcje_h
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

#include <stdio.h>

void przepisz(int w,int k,int t1[w][k],int t2[w][k]); //przepisuje  zjednej tablicy do drugiej

void zapisz(FILE *f,int w,int k,int t1[w][k],int t2[w][k]);
void generuj(int wiersze,int kolumny,int array[wiersze][kolumny],int array2[wiersze][kolumny],int h);


#endif /* funkcje_h */
