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
void pobierz_wiersze_i_kolumny(FILE *t,int *w,int *k);
void zapisz(FILE *f,int w,int k,int t1[][k]);
void przepisz(int w,int k,int t1[][k],int t2[][k]);
void generuj_jedna_plansze(int wiersze,int kolumny,int array[wiersze][kolumny],int array2[wiersze][kolumny]);
void generuj_plik(int h,int wiersze,int kolumny,int array[][kolumny]);
void generacja_cyklu(int w,int k,int t1[][k],int t2[][k],int n);

#endif /* funkcje_h */
