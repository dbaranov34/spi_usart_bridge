#include "test_sender.h"
#include <stdint.h>


#include "message_format.h"

static const uint8_t pDataBuffer[MAX_MESSAGE_DATA_BYTES] ;

static uint16_t generate_some_message(void) {
    static uint32_t header = 0;
    header++;

    // Cast pDataBuffer to a pointer to a Message_t structure
    Message_t *message = (Message_t *)pDataBuffer;

    // Populate the structure
    message->header = header;
    message->length = 17;

    // Assign the 'data' field directly to a string literal
    message->data = (uint8_t *)"somedata";

    return message->length;
}



void SendUsartMsg(UART_HandleTypeDef *huart){
    uint16_t msg_len = generate_some_message(); 
    HAL_StatusTypeDef  status =  HAL_UART_Transmit(&huart, &pDataBuffer, msg_len, TX_TIMEOUT);

}


void SendSpiMsg(SPI_HandleTypeDef *hspi){
    uint16_t msg_len = generate_some_message(); 
    HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi,&pDataBuffer,msg_len,TX_TIMEOUT);
}