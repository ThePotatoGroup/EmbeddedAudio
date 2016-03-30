//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_FIFO_H
#define EMBEDDEDAUDIO_FIFO_H

#include "EmbeddedAudioTypes.h"
#include "zedboard_freertos.h"

// ==========================================================
// ======================== REGISTERS =======================
// ==========================================================
#define FIFO_TX_VAC 0x0000000c  /**< Transmit Vacancy */
#define FIFO_TX_DATA 0x00000010  /**< Transmit Data */
#define FIFO_TX_LENGTH  0x00000014  /**< Transmit Length */
#define FIFO_TX_RESET 0x00000008  /**< Transmit Reset */
#define FIFO_TX_DES  0x0000002C  /**< Transmit Destination  */

#define FIFO_RX_VAC 0x0000001c  /**< Receive Occupancy */
#define FIFO_RX_DATA 0x00000020  /**< Receive Data */
#define FIFO_RX_RESET 0x00000018  /**< Receive Reset */
#define FIFO_RX_LENGTH  0x00000024  /**< Receive Length */
#define FIFO_RX_DES  0x00000030  /**< Receive Destination  */

#define FIFO_TX_RESET_VALUE 0x000000a5 /**< Transmit reset value */
#define FIFO_RX_RESET_VALUE 0x000000a5 /**< Receive reset value */

#define FIFO_LLR_OFFSET  0x00000028  /**< Local Link Reset */
#define FIFO_LLR_RESET_VALUE         0x000000a5 /**< Local Link reset value */

#define FIFO_INT_ENABLE  0x00000004  /**< Interrupt Enable Register */
#define FIFO_INT_STATUS  0x00000000  /**< Interrupt Enable Register */

/** bits within int status */
#define FIFO_INT_RFPE (0x01 << 19) /**< Receive FIFO Programmable Empty  */
#define FIFO_INT_RFPF (0x01 << 20) /**< Receive FIFO Programmable Full   */
#define FIFO_INT_TFPE (0x01 << 21) /**< Transmit FIFO Programmable Empty */
#define FIFO_INT_TFPF (0x01 << 22) /**< Transmit FIFO Programmable Full  */
// ==========================================================
// ==========================================================

typedef struct FIFO {
    u32 base_address;
} FIFO_t;

void FIFO_init(FIFO_t* pFIFO);

int FIFO_tx_write_u32(FIFO_t* pFIFO, u32* data);
int FIFO_tx_get_vacancies(FIFO_t* pFIFO);
void FIFO_tx_reset(FIFO_t* pFIFO);

int FIFO_rx_read_u32(FIFO_t* pFIFO, u32* data); // TODO Implement this if needed
int FIFO_rx_get_vacancies(FIFO_t* pFIFO);
void FIFO_rx_reset(FIFO_t* pFIFO);


bool FIFO_get_interrupt_status(FIFO_t *pFIFO, int interruptBitPosition);
void FIFO_clear_interrupt_status(FIFO_t *pFIFO, int interruptBitPosition);
void FIFO_enable_interrupt(FIFO_t *pFIFO, int interruptBitPosition);
void FIFO_disable_interrupt(FIFO_t *pFIFO, int interruptBitPosition);
void FIFO_enable_all_Interrupts(FIFO_t *pFIFO, int interruptBitPosition);
void FIFO_disable_all_Interrupts(FIFO_t *pFIFO, int interruptBitPosition);

#endif //EMBEDDEDAUDIO_FIFO_H
