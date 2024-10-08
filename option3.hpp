#include <cstdint>
#include <cstdlib>

// Implement a blitting function which supports color-keyed transparency.

unsigned int const COLOR_KEY = 0xFF000000;

struct PixelBuffer {
    uint32_t *pixels;
    int width;
    int height;
};

// Copies the entire image from `src` into a destination buffer `dest`.
// The pixel buffers have a top-left origin and are row-major.
// `offsetX` and `offsetY` denote the origin within `dest` where `src` should be copied.
// Any pixel that exactly matches `COLOR_KEY` should be skipped.
// You may assume input buffers are pre-allocated and sufficiently large to complete the requested operation.
void blit(PixelBuffer const* src, PixelBuffer* dest, size_t offsetX, size_t offsetY);
