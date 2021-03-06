#include "sys.h"
#include "config.h"
#include "ios_ao_drv_macro.h"
#include "ios_pd_drv_macro.h"


/* NFIO复用配置 */
#define NF_IOS_SYS_CONFIG() \
{\
}

#if PLATFORM==PLATFORM_V7R2_PORTING
/* SPI0 — Porting用SPI0复用配置,片选为CS1 */
#define SPI_IOS_SYS_CONFIG() \
{\
    CLR_IOS_GPIO2_28_CTRL1_1;\
    CLR_IOS_GPIO2_29_CTRL1_1;\
    CLR_IOS_GPIO2_30_CTRL1_1;\
    CLR_IOS_GPIO2_31_CTRL1_1;\
    \
    SET_IOS_SPI0_CTRL2_1;\
    SET_IOS_SPI0_4LINE_CTRL2_1;\
    \
    OUTSET_IOS_PD_IOM_CTRL45;\
    OUTSET_IOS_PD_IOM_CTRL46;\
    OUTSET_IOS_PD_IOM_CTRL48;\
    \
    CLR_IOS_GPIO3_4_CTRL1_1;\
    \
    SET_IOS_SPI0_CS1_CTRL3_1;\
    \
    OUTSET_IOS_PD_IOM_CTRL53;\
}
#else
/* SPI1 — ASIC用SPI1复用配置，片选为CS1 */
#define SPI_IOS_SYS_CONFIG() \
{\
    CLR_IOS_GPIO3_1_CTRL1_1;\
    CLR_IOS_GPIO3_2_CTRL1_1;\
    CLR_IOS_GPIO3_3_CTRL1_1;\
    \
    SET_IOS_SPI1_CTRL1_1;\
    SET_IOS_SPI1_4LINE_CTRL1_1;\
    \
    OUTSET_IOS_PD_IOM_CTRL50;\
    OUTSET_IOS_PD_IOM_CTRL52;\
    \
    CLR_IOS_GPIO2_23_CTRL1_1;\
    \
    SET_IOS_SPI1_CS1_CTRL3_3;\
    \
    OUTSET_IOS_PD_IOM_CTRL40;\
}
#endif

/* EMMC管管脚配置 */
#if PLATFORM==PLATFORM_V7R2_PORTING
#define EMMC_IOS_SYS_CONFIG() \
{\
    CLR_IOS_GPIO0_20_CTRL1_1;\
    CLR_IOS_GPIO0_21_CTRL1_1;\
    CLR_IOS_GPIO0_22_CTRL1_1;\
    CLR_IOS_GPIO0_23_CTRL1_1;\
    CLR_IOS_GPIO0_24_CTRL1_1;\
    CLR_IOS_GPIO0_25_CTRL1_1;\
    \
    SET_IOS_MMC1_CLK_CTRL1_1;\
    SET_IOS_MMC1_CTRL1_1;\
    \
    OUTSET_IOS_AO_IOM_CTRL24;\
    \
    NASET_IOS_AO_IOM_CTRL24;\
    NASET_IOS_AO_IOM_CTRL25;\
    PUSET_IOS_AO_IOM_CTRL25;\
    NASET_IOS_AO_IOM_CTRL26;\
    PUSET_IOS_AO_IOM_CTRL26;\
    NASET_IOS_AO_IOM_CTRL27;\
    PUSET_IOS_AO_IOM_CTRL27;\
    NASET_IOS_AO_IOM_CTRL28;\
    PUSET_IOS_AO_IOM_CTRL28;\
    NASET_IOS_AO_IOM_CTRL29;\
    PUSET_IOS_AO_IOM_CTRL29;\
}
#else
/* ASIC使用MMC0 */
#define EMMC_IOS_SYS_CONFIG() \
{\
    OUTSET_IOS_PD_IOM_CTRL21;\
    NASET_IOS_PD_IOM_CTRL21;\
    NASET_IOS_PD_IOM_CTRL26;\
    PUSET_IOS_PD_IOM_CTRL26;\
}
#endif

/* HsUart管脚配置 */
#define HSUART_IOS_SYS_CONFIG() \
{\
    CLR_IOS_GPIO2_18_CTRL1_1;\
    CLR_IOS_GPIO2_19_CTRL1_1;\
    CLR_IOS_GPIO2_20_CTRL1_1;\
    CLR_IOS_GPIO2_21_CTRL1_1;\
    \
    SET_IOS_HS_UART1_CTRL1_1;\
    SET_IOS_HS_UART2_CTRL1_1;\
    \
    OUTSET_IOS_PD_IOM_CTRL35;\
    OUTSET_IOS_PD_IOM_CTRL37;\
}

