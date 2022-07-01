#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "headers/stb_image_write.h"

enum img_channels {
    R, G, B
};

int main(void){
    int width, height, channels, pixel_index, c; 
    unsigned char *image = stbi_load("clock_0000.png", &width, &height, &channels, 0);

    /* craete an array for the histogram */ 

    unsigned char histogram[256][width][3]; 
    
    if(image == NULL){
        printf("Error Image didn't load");
        exit(1);
    }
    
    printf("Image successfully loaded (%d, %d, %d)", height, width, channels);

    
    memset(histogram, 0, sizeof(histogram));

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            pixel_index = (y * width + x) * channels;
            histogram[255-image[pixel_index+R]][x][R] += 1;
            histogram[255-image[pixel_index+G]][x][G] += 1;
            histogram[255-image[pixel_index+B]][x][B] += 1;
        }
    }

    stbi_write_png("hist.png", width, 256, 3, histogram, width * 3);
    stbi_image_free(image);
}