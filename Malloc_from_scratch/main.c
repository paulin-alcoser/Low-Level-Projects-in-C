#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024

typedef struct{
    void *start;
    size_t size;
} Heap_Chunk;

//This is metadata array for keeping start of each memory chunk and its size
Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP];
char heap[HEAP_CAP] = {0};
size_t heap_size = 0;
size_t heap_alloced_size = 0;

void *heap_alloc(size_t size)
{
    assert(heap_size + size <= HEAP_CAP);
    void *result = heap + heap_size;
    heap_size += size;
    //Add allocation to metadata
    Heap_Chunk chunk = {
        .start = result,
        .size = size,
    };
    assert(heap_alloced_size < HEAP_ALLOCED_CAP);
    heap_alloced[heap_alloced_size++] = chunk;
    return result;
}

void heap_dump_alloced_chunks(void){
    printf("allocated Chunks(%zu):\n", heap_alloced_size);
    for(size_t i = 0; i < heap_alloced_size; ++i) {
        printf(" start: %p, size: %zu\n", heap_alloced[i].start, heap_alloced[i].size);
    }
}

void heap_free(void *ptr)
{
    (void) ptr;
    assert(false && "TODO: heap_free is not implemented");
    //1) correct ptr
    //2) incorrect ptr -> throw an error
}

void heap_collect()
{
    assert(false && "TODO: heap_free is not implemented");
}

int main(){
    char *root = heap_alloc(26);
    for (int i = 0; i < 26; ++i){
        root[i] = i + 'A';
    }
    heap_dump_alloced_chunks();
    return 0;
}