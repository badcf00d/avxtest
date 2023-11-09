#include <immintrin.h>
#include <stdio.h>

#define repeat(instruction, num) \
    asm volatile(                \
        ".rept " #num "\n\t"     \
        ".intel_syntax noprefix\n\t"      \
        instruction "\n\t"       \
        ".att_syntax\n\t"      \
        ".endr\n\t");


void __attribute__((noreturn)) avx() {
    while (1) {
        repeat("vfmadd132pd xmm0,xmm0,xmm0\n\t" 
               "vpxord      xmm0,xmm0,xmm0\n\t", 2);
    }
}

void __attribute__((noreturn)) avx2() {
    while (1) {
        repeat("vfmadd132pd ymm0,ymm0,ymm0\n\t" 
               "vpxord      ymm0,ymm0,ymm0\n\t", 2);
    }
}

void __attribute__((noreturn)) avx512() {
    while (1) {
        repeat("vfmadd132pd zmm0,zmm0,zmm0\n\t" 
               "vpxord      zmm0,zmm0,zmm0\n\t", 2);
    }
}


int main() {
    if (__builtin_cpu_supports("avx512f")) {
        puts("using avx512");
        avx512();
    }


    if (__builtin_cpu_supports("avx2")) {
        puts("using avx2");
        avx2();
    }

    if (__builtin_cpu_supports("avx")) {
        puts("using avx2");
        avx2();
    }
}
