#pragma once
#include <stdint.h>


struct UdsCrcCtx
{
    uint32_t crc;
};


#ifdef __cplusplus
extern "C" {
#endif


void UdsCrc32Init(struct UdsCrcCtx *ctx);
uint32_t UdsCrc32Final(struct UdsCrcCtx *ctx);
void UdsCrcUpdate(struct UdsCrcCtx *ctx, const uint8_t* data, uint32_t len);

/* 分块校验，同时更新watchdog */
void UdsCrcUpdateWDT(struct UdsCrcCtx *ctx, const uint8_t* data, uint32_t len);


#ifdef   __cplusplus
}
#endif



