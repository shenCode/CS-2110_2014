#include "my_malloc.h"

/* You *MUST* use this macro when calling my_sbrk to allocate the 
 * appropriate size. Failure to do so may result in an incorrect
 * grading!
 */
#define SBRK_SIZE 2048

/* If you want to use debugging printouts, it is HIGHLY recommended
 * to use this macro or something similar. If you produce output from
 * your code then you will receive a 20 point deduction. You have been
 * warned.
 */
#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x)
#endif


/* make sure this always points to the beginning of your current
 * heap space! if it does not, then the grader will not be able
 * to run correctly and you will receive 0 credit. remember that
 * only the _first_ call to my_malloc() returns the beginning of
 * the heap. sequential calls will return a pointer to the newly
 * added space!
 * Technically this should be declared static because we do not
 * want any program outside of this file to be able to access it
 * however, DO NOT CHANGE the way this variable is declared or
 * it will break the autograder.
 */
void* heap;

/* our freelist structure - this is where the current freelist of
 * blocks will be maintained. failure to maintain the list inside
 * of this structure will result in no credit, as the grader will
 * expect it to be maintained here.
 * Technically this should be declared static for the same reasons
 * as above, but DO NOT CHANGE the way this structure is declared
 * or it will break the autograder.
 */
metadata_t* freelist[8];
/**** SIZES FOR THE FREE LIST ****
 * freelist[0] -> 16
 * freelist[1] -> 32
 * freelist[2] -> 64
 * freelist[3] -> 128
 * freelist[4] -> 256
 * freelist[5] -> 512
 * freelist[6] -> 1024
 * freelist[7] -> 2048
 */

int firstCall = 1;
            
void* my_malloc(size_t size)
{
	metadata_t* freeBlock = NULL;
	metadata_t* block = NULL;
	int index = -1;
	int a = -1;
	char* returnAddress = NULL;
	int sizeBlock = -1;
	
    /*
      1) Figure out what size block you need to satisfy the user's request. Remember that the 'size' field in
      our metadata structure includes the size of the metadata structure itself, so take the user size and
      sizeof(metadata_t) into account as well as the legal sizes a block can be.
    */
    if ((size + sizeof(metadata_t)) <= 16) {sizeBlock =16; index = 0;}
    else if ((size + sizeof(metadata_t)) <= 32) {sizeBlock =32; index = 1;}
    else if ((size + sizeof(metadata_t)) <= 64) {sizeBlock =64; index = 2;}
    else if ((size + sizeof(metadata_t)) <= 128) {sizeBlock =128; index = 3;}
    else if ((size + sizeof(metadata_t)) <= 256) {sizeBlock =256; index = 4;}
    else if ((size + sizeof(metadata_t)) <= 512) {sizeBlock =512; index = 5;}
    else if ((size + sizeof(metadata_t)) <= 1024) {sizeBlock =1024; index = 6;}
    else if ((size + sizeof(metadata_t)) <= 2048) {sizeBlock =2048; index = 7;}
    /*
      2) If the user request exceeds 2048 bytes (note that this number is what is calculated *AFTER*
      my_malloc adds on the obligatory sizeof(metadata_t)), then return Null and set the error code.
      else {ERRNO = SINGLE_REQUEST_TOO_LARGE; return NULL;}
    */
    else {ERRNO = SINGLE_REQUEST_TOO_LARGE; return NULL;}
  
    if(!heap)
    {
        heap = my_sbrk(SBRK_SIZE);
        freelist[7] = (metadata_t *) heap;
        freelist[7]->in_use = 0;
        freelist[7]->size = SBRK_SIZE;
        freelist[7]->next = NULL;
        freelist[7]->prev = NULL;
    }
    
    if(freelist[index])
    {
        freeBlock = freelist[index];
        
        if(freelist[index]->next) {
            freelist[index] = freelist[index]->next;
            freelist[index]->prev = NULL;
        } else {
            freelist[index] = NULL;
        }
        
        freeBlock->next = NULL;
        freeBlock->in_use = 1;

        returnAddress = (char*)freeBlock;
        ERRNO= NO_ERROR;
        return returnAddress + sizeof(metadata_t);
        
    }
    
}

// Done
void* my_calloc(size_t num, size_t size)
{
    int i;
    if (num * size > 2048)
    {
        ERRNO = SINGLE_REQUEST_TOO_LARGE;
        return NULL;
    }
    
    char* p = my_malloc(num*size);
    for (i = 0; i < num*size; i++)
    {
        p[i] = 0;
    }
    ERRNO = NO_ERROR;
    return (void*) p;
    
}
void my_free(void* ptr)
{

}

// Done
void* my_memmove(void* dest, const void* src, size_t num_bytes)
{
    char *des = (char *) dest;
    char *source = (char *) src;
    int i = 0;
    
    if (des > source)
    {
    	for(i = 0; i < num_bytes; i++)
		{
			des[(num_bytes-1)-i] = source[(num_bytes-1)-i]; 
		}
    }
    else if (des < source)
    {
    	for (i = 0; i < num_bytes; i++)
    	{
    		des[i] = source[i];
    	}
    }

    ERRNO = NO_ERROR;
    return (void *) dest;
}
