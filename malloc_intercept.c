#include <stdio.h>
#include <stdlib.h>

long __real_malloc(size_t size);

long __wrap_malloc(size_t size)
{
    void *ptr = (void *)__real_malloc(size);

    printf("!!! malloc_intercept.c; intercepted malloc(%zu) -> %p\n", size, ptr);

    return (long)ptr;
}

long __real_realloc(void *obj, size_t size);

long __wrap_realloc(void *obj, size_t size)
{
    void *ptr = (void *)__real_realloc(obj, size);

    printf("!!! malloc_intercept.c; intercepted realloc(%p, %zu) -> %p\n", obj, size, ptr);

    return (long)ptr;
}

void __real_free(void *obj);

void __wrap_free(void *obj)
{
    __real_free(obj);

    printf("!!! malloc_intercept.c; intercepted free(%p)\n", obj);
}
