// macro defines

#define CS_LOW()    P14 = 0//P5OUT &= ~0x10              // Card Select
#define CS_HIGH()   P14 = 1//SPI_TX_DONE; P5OUT |= 0x10  // Card Deselect

// Tokens (necessary  because at NPO/IDLE (and CS active) only 0xff is on the data/command line)
#define SD_START_DATA_BLOCK_TOKEN          0xfe   // Data token(標記) start byte, Start Single Block Read
#define SD_START_DATA_MULTIPLE_BLOCK_READ  0xfe   // Data token start byte, Start Multiple Block Read
#define SD_START_DATA_BLOCK_WRITE          0xfe   // Data token start byte, Start Single Block Write
#define SD_START_DATA_MULTIPLE_BLOCK_WRITE 0xfc   // Data token start byte, Start Multiple Block Write
#define SD_STOP_DATA_MULTIPLE_BLOCK_WRITE  0xfd   // Data toke stop byte, Stop Multiple Block Write


// an affirmative R1 response (no errors)
#define SD_R1_RESPONSE       0x00


// this variable will be used to track the current block length
// this allows the block length to be set only when needed
// unsigned long _BlockLength = 0;

// error/success codes
#define SD_SUCCESS           0x00
#define SD_BLOCK_SET_ERROR   0x01
#define SD_RESPONSE_ERROR    0x02
#define SD_DATA_TOKEN_ERROR  0x03
#define SD_INIT_ERROR        0x04
#define SD_CRC_ERROR         0x10
#define SD_WRITE_ERROR       0x11
#define SD_OTHER_ERROR       0x12
#define SD_TIMEOUT_ERROR     0xFF


// commands: first bit 0 (start bit), second 1 (transmission bit); CMD-number + 0ffsett 0x40
#define SD_GO_IDLE_STATE          0x40     //CMD0  設定SD記憶卡為SPI模式
#define SD_SEND_OP_COND           0x41     //CMD1  寫入暫存器OCR內的工作電壓定義(0有效)
#define SD_READ_CSD               0x49     //CMD9  讀取SCD暫存器
#define SD_SEND_CID               0x4a     //CMD10 寫入CID暫存器
#define SD_STOP_TRANSMISSION      0x4c     //CMD12 停止SD記憶卡傳輸工作
#define SD_SEND_STATUS            0x4d     //CMD13
#define SD_SET_BLOCKLEN           0x50     //CMD16 設定SD記憶卡區塊長度提供下次讀/寫
#define SD_READ_SINGLE_BLOCK      0x51     //CMD17 讀取SD記憶卡單一區塊的資料
#define SD_READ_MULTIPLE_BLOCK    0x52     //CMD18 讀取SD記憶卡多區塊的資料
#define SD_CMD_WRITEBLOCK         0x54     //CMD20 將資料寫入SD記憶卡單一區塊命令
#define SD_WRITE_BLOCK            0x58     //CMD24 將資料寫入SD記憶卡單一區塊
#define SD_WRITE_MULTIPLE_BLOCK   0x59     //CMD25 將資料寫入SD記憶卡多區塊
#define SD_WRITE_CSD              0x5b     //CMD27 寫入規劃CSD暫存器
#define SD_SET_WRITE_PROT         0x5c     //CMD28
#define SD_CLR_WRITE_PROT         0x5d     //CMD29
#define SD_SEND_WRITE_PROT        0x5e     //CMD30
#define SD_TAG_SECTOR_START       0x60     //CMD32
#define SD_TAG_SECTOR_END         0x61     //CMD33
#define SD_UNTAG_SECTOR           0x62     //CMD34
#define SD_TAG_EREASE_GROUP_START 0x63     //CMD35
#define SD_TAG_EREASE_GROUP_END   0x64     //CMD36
#define SD_UNTAG_EREASE_GROUP     0x65     //CMD37
#define SD_EREASE                 0x66     //CMD38
#define SD_READ_OCR               0x67     //CMD39
#define SD_CRC_ON_OFF             0x68     //CMD40





