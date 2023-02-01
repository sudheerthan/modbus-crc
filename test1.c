#include <stdio.h>
#include <stdint.h>

/* Function to calculate MODBUS CRC */
uint16_t crc16_update(uint16_t crc, uint8_t a) {
    int i;

    crc ^= (uint16_t)a;
    for (i = 0; i < 8; ++i) {
        if (crc & 1)
            crc = (crc >> 1) ^ 0xA001;
        else
            crc = (crc >> 1);
    }

    return crc;
}

int main(void) {

    uint16_t crc;
    char ch;
    int i,num=0;
    int str[100];
    printf("enter values (with space) ");
    while(getchar() != '\n') {
         scanf("%x",&str[num]);
         num++;
    }
    

    /* MODBUS CRC initial value is 0xFFFF. */
    crc = 0xFFFF;
    for(i = 0; i < num; i++)
        crc = crc16_update(crc, str[i]);
   // printf("%04X\n", (int)crc);
    uint8_t crc1 = (int)crc;
    uint8_t crc2 = crc >> 8;
    printf("Output :- ");
    for(int k=0;k<num;k++){
    printf("%02X ",str[k]);
    }
    printf("%02X %02X",crc1,crc2);
    printf("\n");

}
