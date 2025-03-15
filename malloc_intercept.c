#include <stdio.h>
#include <stdlib.h>

long __real_malloc(size_t size);

long __wrap_malloc(size_t size)
{
    long ptr = __real_malloc(size);

    printf("!!! malloc_intercept.c; intercepted malloc(%zu) -> %p\n", size, ptr);

    return ptr;
}

long __real_realloc(void *obj, size_t size);

long __wrap_realloc(void *obj, size_t size)
{
    long ptr = __real_realloc(obj, size);

    printf("!!! malloc_intercept.c; intercepted realloc(%p, %zu) -> %p\n", obj, size, ptr);

    return ptr;
}

void __real_free(void *obj);

void __wrap_free(void *obj)
{
    printf("!!! malloc_intercept.c; intercepted free(%p, %zu)\n", obj);
}
