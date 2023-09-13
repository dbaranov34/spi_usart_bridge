#include "test_sender.h"
#include <stdint.h>
#include <stdbool.h>


#include "message_format.h"

static uint8_t tx_DataBuffer[MAX_MESSAGE_DATA_BYTES] ;
static uint8_t uart_to_spi_DataBuffer[MAX_MESSAGE_DATA_BYTES] ;
static uint8_t spi_to_uart_DataBuffer[MAX_MESSAGE_DATA_BYTES] ;

static bool received_new_spi_msg = false;
static bool received_new_uart_msg = false;



static uint16_t generate_some_message(void) {
    static uint32_t header = 0;
    header++;
    Message_t *message = (Message_t *)tx_DataBuffer;

    // Populate the structure
    message->header = header;
    message->length = 17;

    // Assign the 'data' field directly to a string literal
    message->data = (uint8_t *)"somedata";

    return message->length;
}



void SendUsartMsg(UART_HandleTypeDef *huart){
    uint16_t msg_len = generate_some_message(); 
    HAL_StatusTypeDef  status =  HAL_UART_Transmit(huart, tx_DataBuffer, msg_len, TX_TIMEOUT);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
    HAL_UART_Receive_DMA(huart, uart_to_spi_DataBuffer, 17); 
    received_new_spi_msg = true;
}

void HAL_SPI_Rx_CpltCallback(SPI_HandleTypeDef *hspi){
    HAL_SPI_Receive_DMA(hspi,uart_to_spi_DataBuffer, 17);
    received_new_spi_msg = true;
}


void ReceiveUsartMsg(UART_HandleTypeDef *huart){
      HAL_UART_Receive_DMA(huart, uart_to_spi_DataBuffer, 17); 
}

void ReceiveSpiMsg(SPI_HandleTypeDef *hspi){
    HAL_UART_Receive_DMA(hspi, uart_to_spi_DataBuffer, 17); 
}



void SendSpiMsg(SPI_HandleTypeDef *hspi){
    uint16_t msg_len = generate_some_message(); 
    HAL_StatusTypeDef status = HAL_SPI_Transmit(hspi,tx_DataBuffer,msg_len,TX_TIMEOUT);
}





void ForwardMessagesToUart(UART_HandleTypeDef *huart){
    if (received_new_spi_msg){
        HAL_UART_Transmit_DMA(huart, tx_DataBuffer, 17);

        received_new_spi_msg = false;
    }


}

void ForwardMessagesToSpi(SPI_HandleTypeDef *hspi){
    if (received_new_uart_msg){
        HAL_SPI_Transmit_DMA(hspi, tx_DataBuffer, 17);
        received_new_uart_msg = false;
    }
}