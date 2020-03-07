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

int main(int argc, const char * argv[]) {
    FILE *in= fopen(argv[1],"r");
    int kolumny,wiersze;
  fscanf(in,"%d",&kolumny);
     fscanf(in,"%d",&wiersze);
    
    //zapisze komorki z pliku do tablicy
    
    int array[wiersze][kolumny];//tablica przechowywujaca generacje
    int array2[wiersze][kolumny];//tablica porownujaca stany komorek
    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++){
            fscanf(in,"%d",&array[i][j]);
        }
    }
    
    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++){
            array2[i][j]=array[i][j];
        }
    }
    
    //ile generacji ma byc wykonanych
    int n;
    printf("ile generacji chcesz wykonac?\n");
    scanf("%d",&n);
   
    
  
    // sprawdzanie i zmiana stanu komorek
    for(int h=0;h<n;h++){
    
    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++){
             int l=0; //liczy zywe komorki
            
            
            //zliczanie zywych komorek
            for(int w=i-1;w<=i+1;w++)
    {
                for(int k =j-1;k<=j+1;k++)
        {
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
            //char nazwa_pliku[6]="plik_\0";
           // char numer_pliku[5];
            //itoa(n,numer_pliku,10);
            //strcat(nazwa_pliku,numer_pliku);
            
            
            
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
                return 2;
            }
            
            for(int i=0;i<wiersze;i++){
            for(int j=0;j<kolumny;j++){
                fprintf(plik,"%d ",array[i][j]);
                                    }
                fprintf(plik,"\n");
            
            
            }
            fclose(plik);
           
             
             
             
            
            
        
        
        
        //wypisywanie poszczegolnych generacji na stdout
        /*
        
            for(int i=0;i<wiersze;i++){
            for(int j=0;j<kolumny;j++){
                printf("%d ",array[i][j]);
            }
                printf("\n");
            
            }
        printf("\n");
            
       */
            
        //przepisanie nowych komorek z array do array2
            for(int i=0;i<wiersze;i++){
            for(int j=0;j<kolumny;j++){
                array2[i][j]=array[i][j];
            }
            }
            
            
    }
       
    }
   
    
    
    
    
    

