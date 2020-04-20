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
#include <png.h>

int x, y;

png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
png_bytep * row_pointers;

void write_png_file(char* file_name,int w,int k) {
  FILE *fp = fopen(file_name, "w");
  if (!fp)
    printf("[write_png_file] File %s could not be opened for writing", file_name);

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

  if (!png_ptr)
    printf("[write_png_file] png_create_write_struct failed");

  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
    printf("[write_png_file] png_create_info_struct failed");

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during init_io");

  png_init_io(png_ptr, fp);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing header");

  png_set_IHDR(png_ptr, info_ptr, k,w,
   bit_depth, color_type, PNG_INTERLACE_NONE,
   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing bytes");

  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during end of write");

  png_write_end(png_ptr, NULL);

  for (y=0; y<w; y++)
    free(row_pointers[y]);
  free(row_pointers);

  fclose(fp);
}

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

//generuje  nazwe pliku
void file_name(char *t,int h){
    strcpy(t,"Gen_");
        
        char x[3];
        sprintf(x,"%d",h+1);
        strcat(t,x);
        strcat(t,".png");
             
             
        
}

//zapisuje plansze do *.png
void process_file(int w,int k,int array[][k]) {
  bit_depth = 8;
  color_type = PNG_COLOR_TYPE_GRAY;

  row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * w);
  for (y=0; y<w; y++)
    row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * k);

  for (y=0; y<w; y++) {
    png_byte* row = row_pointers[y];
    for (x=0; x<k; x++) {
       if(array[y][x] == 0)
      row[x] =   0;
       else
           row[x] = 255;
    }
  }

}

void generacja_cyklu(int w,int k,int t1[][k],int t2[][k],int n){
    char file[25];
    for(int h=0;h<n;h++){
        file_name(file,h);
        generuj_jedna_plansze(w,k,t1,t2);
    process_file(w,k,t1);
    write_png_file(file,w,k);
        przepisz(w,k,t1,t2);
    }
}
