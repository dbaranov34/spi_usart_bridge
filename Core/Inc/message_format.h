#include <stdint.h>



#define MAX_MESSAGE_DATA_BYTES 50
#define MAX_MESSAGE_LENGTH MAX_MESSAGE_DATA_BYTES + 8

#define TX_TIMEOUT 1000

typedef struct Message{
    uint32_t header;
    uint32_t length;
    uint8_t* data;
} Message_t;