//
//  funkcje.c
//  automat_komorkowy
//
//  Created by kasia on 3/14/20.
//  Copyright © 2020 kasia. All rights reserved.
//

#include "funkcje.h"
#include<stdlib.h>
#include<string.h>
#include <stdio.h>


void pobierz_wiersze_i_kolumny(FILE *t,int *w,int *k){
    
    fscanf(t,"%d",k);
    fscanf(t,"%d",w);
}



void zapisz(FILE *f,int w,int k,int t1[][k]){

for(int i=0;i<w;i++){
    for(int j=0;j<k;j++){
        fscanf(f,"%d",&t1[i][j]);
    }
    }
    
}

void przepisz(int w,int k,int t1[][k],int t2[][k]){
    
   for(int i=0;i<w;i++){
   for(int j=0;j<k;j++){
       t2[i][j]=t1[i][j];
   }
   }
}








void generuj_jedna_plansze(int wiersze,int kolumny,int array[wiersze][kolumny],int array2[wiersze][kolumny]){
    
   
    for(int i=0;i<wiersze;i++){
    for(int j=0;j<kolumny;j++){
    int l=0; //liczy zywe komorki
            
            
            //zliczanie zywych komorek
            for(int w=i-1;w<=i+1;w++){
            for(int k=j-1;k<=j+1;k++){
                    if(w==-1||w==wiersze||k==-1||k==kolumny)
                    {
                     ;
                    }else{
                     if(w==i&&k==j);
                     else   {
                         if(array2[w][k]==1)l++;
                            }
                    }
            }
            }
            //zmiana stanu badanej komorki
            if(array2[i][j]==0)
            {
                if(l==3)array[i][j]=1;
            }else{
                if(l==2||l==3);
                else{
                    array[i][j]=0;
                }
            }
            
        
    }
    }
           
            
    }


void generuj_plik(int h,int wiersze,int kolumny,int array[][kolumny]){
            
        char nazwa_pliku[25]="plik_";
        char x[3];
        sprintf(x,"%d",h+1);
        strcat(nazwa_pliku,x);
        strcat(nazwa_pliku,".txt");
        

            
            //generacja pliku z nowym stanem
            FILE *plik;
            plik=fopen(nazwa_pliku,"w");
    
            if(plik==NULL){
                printf("nie moge otworzyc pliku");
                exit(0);
            }
            
            for(int i=0;i<wiersze;i++){
            for(int j=0;j<kolumny;j++){
                fprintf(plik,"%d ",array[i][j]);
                                    }
                fprintf(plik,"\n");
            
            
            }
            fclose(plik);
           
             
             
             
}


void generacja_cyklu(int w,int k,int t1[][k],int t2[][k],int n){
    
    for(int h=0;h<n;h++){
        generuj_jedna_plansze(w,k,t1,t2);
        generuj_plik(h,w,k,t1);
        przepisz(w,k,t1,t2);
    }
}
