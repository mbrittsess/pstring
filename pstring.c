#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct { size_t count; const char data[]; } pstring_t;
#define pstr( s ) ((pstring_t*)(&(struct { size_t count; const char data[ sizeof(s)-1 ]; }){ .count = ( sizeof(s)-1 ), .data = s }))

static int put_pstr ( pstring_t* string )
{
    return fwrite( &string->data, sizeof( char ), string->count, stdout );
};

int main ( int argc, char* argv[] )
{
    return ( ( put_pstr( pstr("Hello, world!\n") ) ) != EOF ) ? EXIT_SUCCESS : EXIT_FAILURE;
};
