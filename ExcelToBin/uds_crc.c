#include <stdio.h>
#include <stdlib.h>
//#include "r_cg_wdt.h"
//#include "common.h"
//#include "platform.h"
//#include "hw_flash.h"
#include "uds_crc.h"



///////////////////////////////////////////////////////////////////////////
// Code flash
///////////////////////////////////////////////////////////////////////////
//擦除地址32K字节对齐
#define FLASH_CODE_ERASE_SHIFT      15
#define FLASH_CODE_ERASE_SIZE       (0x01 << FLASH_CODE_ERASE_SHIFT)
#define FLASH_CODE_ERASE_ADDR_MASK  ((~0UL) << FLASH_CODE_ERASE_SHIFT)



void UdsCrc32Init(struct UdsCrcCtx *ctx)
{
	ctx->crc = 0xffffffff;
    return;
}

uint32_t UdsCrc32Final(struct UdsCrcCtx *ctx)
{
	return ctx->crc ^ 0xffffffff;
}

void UdsCrcUpdate(struct UdsCrcCtx *ctx, const uint8_t* data, uint32_t len)
{	
	uint32_t dataIdx;
	uint32_t crc32, byteTmp;
	uint8_t bitLoop;
	uint32_t CrcPoly = 0x04C11DB7;

	crc32 = ctx->crc;
	for (dataIdx = 0; dataIdx < len; dataIdx++) {

		byteTmp = (uint32_t)(data[dataIdx]) & 0x000000ff;

		for (bitLoop = 0; bitLoop < 8; bitLoop++) {

			if (((crc32 ^ byteTmp) & 1) != 0)
				crc32 = ((crc32 >> 1) & 0x7fffffff) ^ CrcPoly;
			else
				crc32 = ((crc32 >> 1) & 0x7fffffff);

			byteTmp = (byteTmp >> 1) & 0x7fffffff;
		}
	}
	ctx->crc = crc32;
	return;
}

/* 分块校验，同时更新watchdog */
void UdsCrcUpdateWDT(struct UdsCrcCtx *ctx, const uint8_t* data, uint32_t len)
{
    uint32_t offset;
    uint32_t crclen;

    for(offset = 0; offset < len; offset += crclen){
        crclen = len - offset;
        if (crclen > FLASH_CODE_ERASE_SIZE){
            crclen = FLASH_CODE_ERASE_SIZE;
        }
        //R_WDT0_Restart();
        UdsCrcUpdate(ctx, data + offset, crclen);
    }

    //R_WDT0_Restart();
    return;
}


