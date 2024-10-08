#include <criterion/criterion.h>

#include "option3.hpp"

#include <cstdlib>
#include <cstdint>
#include <iostream>

Test(AlgoGroupTests, OneDimSrc_1) {
    uint32_t src_pixels[] = {2, 2, 2};
    uint32_t dest_pixels[] = {1, 1, 1, 1, 1, 1, 1, 1};

    PixelBuffer src = {src_pixels, 3, 1};
    PixelBuffer dest = {dest_pixels, 8, 1};

    size_t offsetX = 2;
    size_t offsetY = 0;

    blit(&src, &dest,offsetX, offsetY); 

    uint32_t expected[] = {1, 1, 2, 2, 2, 1, 1, 1};

    for (int i = 0; i < 8; i++) {
        cr_assert(dest.pixels[i] == expected[i]);
    }
}

Test(AlgoGroupTests, OneDimSrc_2) {
    uint32_t src_pixels[] = {3};
    uint32_t dest_pixels[] = {1, 2, 3, 4, 5, 6, 7, 8};

    PixelBuffer src = {src_pixels, 1, 1};
    PixelBuffer dest = {dest_pixels, 4, 2};

    size_t offsetX = 2;
    size_t offsetY = 1;

    blit(&src, &dest, offsetX, offsetY);

    uint32_t expected[] = {1, 2, 3, 4, 5, 6, 3, 8};

    for (int i = 0; i < 8; i++) {
        cr_assert(dest.pixels[i] == expected[i]);
    }
}


Test(AlgoGroupTests, TwoDimSrc_1) {
    uint32_t src_pixels[] = {1, 1, 1, 1};
    uint32_t dest_pixels[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    PixelBuffer src = {src_pixels, 2, 2};
    PixelBuffer dest = {dest_pixels, 4, 4};

    size_t offsetX = 0;
    size_t offsetY = 0;

    blit(&src, &dest, offsetX, offsetY);

    uint32_t expected[] = {1, 1, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    for (int i = 0; i < 16; i++) {
        cr_assert(dest.pixels[i] == expected[i]);
    }
}


Test(AlgoGroupTests, TwoDimSrc_2) {
    uint32_t src_pixels[] = {1, 1, 1, 1};
    uint32_t dest_pixels[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    PixelBuffer src = {src_pixels, 2, 2};
    PixelBuffer dest = {dest_pixels, 4, 4};

    size_t offsetX = 2;
    size_t offsetY = 2;

    blit(&src, &dest, offsetX, offsetY);

    uint32_t expected[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 1, 1};

    for (int i = 0; i < 16; i++) {
        cr_assert(dest.pixels[i] == expected[i]);
    }
}


Test(AlgoGroupTests, ColorSkip_1) {
    uint32_t src_pixels[] = {COLOR_KEY, 1, 2, COLOR_KEY, 3, 4};
    uint32_t dest_pixels[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    PixelBuffer src = {src_pixels, 3, 2};
    PixelBuffer dest = {dest_pixels, 4, 4};

    size_t offsetX = 1;
    size_t offsetY = 2;

    blit(&src, &dest, offsetX, offsetY);

    uint32_t expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 3, 4};
    
    for (int i = 0; i < 16; i++) {
        // std::cout << dest.pixels[i] << std::endl;
        cr_assert(dest.pixels[i] == expected[i]);
    }
}

Test(AlgoGroupTests, ColorSkip_2) {
    uint32_t src_pixels[] = {COLOR_KEY, 1};
    uint32_t dest_pixels[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 2};

    PixelBuffer src = {src_pixels, 2, 1};
    PixelBuffer dest = {dest_pixels, 4, 4};

    size_t offsetX = 2;
    size_t offsetY = 3;

    blit(&src, &dest, offsetX, offsetY);

    uint32_t expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 1};
    
    for (int i = 0; i < 16; i++) {
        // std::cout << dest.pixels[i] << std::endl;
        cr_assert(dest.pixels[i] == expected[i]);
    }
}
