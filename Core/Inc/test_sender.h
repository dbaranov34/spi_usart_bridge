#include "stdint.h"

#include "main.h"

void SendUsartMsg(UART_HandleTypeDef *huart);

void SendSpiMsg(SPI_HandleTypeDef *hspi);


void ReceiveUsartMsg(UART_HandleTypeDef *huart);

void ReceiveSpiMsg(SPI_HandleTypeDef *hspi);

void ForwardMessagesToUart(UART_HandleTypeDef *huart);

void ForwardMessagesToSpi(SPI_HandleTypeDef *hspi);