// OPTION 3 (HARDER) - GREEN SCREEN
// DO NOT SHARE

#include "option3.hpp"

// Copies the entire image from `src` into a destination buffer `dest`.
// The pixel buffers have a top-left origin and are row-major.
// `offsetX` and `offsetY` denote the origin within `dest` where `src` should be copied.
// Any pixel that exactly matches `COLOR_KEY` should be skipped.
// You may assume input buffers are pre-allocated and sufficiently large to complete the requested operation.
void blit(PixelBuffer const* src, PixelBuffer* dest, size_t offsetX, size_t offsetY) {
    for (int i = 0; i < src->height; i++) {
        for (int j = 0; j < src->width; j++) {
            // position of src pixel in destination image
            int destX = offsetX + j;
            int destY = offsetY + i;

            int dest_idx = destY * dest->width + destX;
            int src_idx = i * src->width + j;

            // copy pixel IF it is not the special color
            if (src->pixels[src_idx]!= COLOR_KEY) {
                dest->pixels[dest_idx] = src->pixels[src_idx];
            }
        }
    }
}
