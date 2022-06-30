#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "headers/stb_image_write.h"

enum img_channels {
    R, G, B, A
};

int main(void){
    int width, height, channels, pixel_index, c; 
    unsigned char *image = stbi_load("clock_0000.png", &width, &height, &channels, 0);
    unsigned char histogram[256][width];
    
    if(image == NULL){
        printf("Error Image didn't laod");
        exit(1);
    }
    
    printf("Image successfully loaded (%d, %d, %d)", width, height, channels);
    clock_t begin = clock();
    
    c = 0;
    memset(histogram, 0, sizeof(histogram));

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            pixel_index = (y * width + x) * channels;
            histogram[255-image[pixel_index+R]][x] += 1;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f ", time_spent);

    stbi_write_png("hist.png", width, 256, 1, histogram, width);
    stbi_image_free(image);
}