#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <png.h>

int i, j;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
png_bytep * row_pointers;

void write_png_file(char* file_name) {
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

  png_set_IHDR(png_ptr, info_ptr, width, height,
   bit_depth, color_type, PNG_INTERLACE_NONE,
   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing bytes");

  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during end of write");

  png_write_end(png_ptr, NULL);

  for (j=0; j<height; j++)
    free(row_pointers[j]);
  free(row_pointers);

  fclose(fp);
}

void process_file(int width, int height) {
  bit_depth = 8;
  color_type = PNG_COLOR_TYPE_GRAY;
  row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
  for (j=0; j<height; j++)
    row_pointers[j] = (png_byte*) malloc(sizeof(png_byte) * width);

  for (j=0; j<height; j++) {
    png_byte* row = row_pointers[j];
    for (i=0; i<width; i++) 
      row[i] = (i+j)%2? 255 : 0;
    
  }
}


int main(int argc, char **argv) {
	width = argc > 1 ? atoi(argv[1]):50;
	height = argc > 2 ? atoi(argv[2]:50;
	process_file(width,height);
	write_png_file("gen.png");

	return 0;
}
