#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_MEMORY_CAPACITY 640000 // 64 Megabytes
#define UNIMPLEMENTED                                                          \
    do                                                                         \
    {                                                                          \
        fprintf(stderr, "%s, %d, UNIMPLEMENTED: %s is not implemented yet \n", \
                __FILE__, __LINE__, __func__);                                 \
        abort();                                                               \
    } while (0);

typedef struct
{
    size_t bytes_used;
    char memory[HEAP_MEMORY_CAPACITY];
} Heap_Memory;

Heap_Memory heap_memory = {.bytes_used = 0, .memory = {0}};

typedef struct
{
    size_t size;
    bool is_free;
    struct Block *next;
} Block;

typedef struct
{
    size_t size;
    bool is_free;
    struct Block_Header* next;
} Block_Header;

static Block_Header *free_list = NULL;

void initialize_free_list(){
    Block_Header memory_pool = {.size = HEAP_MEMORY_CAPACITY, .is_free=true, .next=NULL};
    *free_list = memory_pool;
}

Block_Header* find_free_block(){
    //iterate through free list looking for a free block and asks if it fits
    
}



void *allocate_memory(size_t bytes_requested)
{
    //Check if there is enough memory
    assert(bytes_requested < (HEAP_MEMORY_CAPACITY - heap_memory.bytes_used));
    if (free_list == NULL){
        initialize_free_list();
    }
    find_free_block()

}
void free_memory(void *ptr)
{
    UNIMPLEMENTED;
}



int main()
{
    printf("BELIEVE IN pendejo\n");

    void *p = allocate_memory(64);
    free_memory(p);
    return 0;
}