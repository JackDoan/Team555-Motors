/**
  ******************************************************************************
  * @file    dspin_config.h
  * @author  IPC Rennes
  * @version No version
  * @date    March 2, 2018
  * @brief   Header with configuration parameters for dspin.c module
  * @note    COPYRIGHT 2018 STMicroelectronics
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 STMicroelectronics</center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DSPIN_CONFIG_H
#define __DSPIN_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "dspin.h"

/* Exported constants --------------------------------------------------------*/

  /****************************************************************************/
  /***************** DSPIN chip type ******************************************/
  /****************************************************************************/
  #define L6472 (1)

  /****************************************************************************/
  /***************** Operation Mode Choice ************************************/
  /***************** 1 if daisy chain for one device or more, else 0 **********/
  /****************************************************************************/
  #define DAISY_CHAIN              (0)

  /****************************************************************************/
  /******************Daisy Chain Mode *****************************************/
  /****************************************************************************/

/* Exported constants --------------------------------------------------------*/

  /**************************** Slaves numbering ******************************/
        /* Number of dPIN slaves */
        #define NUMBER_OF_SLAVES         (1)
        /* Devices */
        /* The first device of the chain receives the last byte transmitted by the master */
        /* The last device of the chain receives the first byte transmitted by the master */
        #define DEVICE_1                 (NUMBER_OF_SLAVES-1)
#if (DEVICE_1>0)
        #define DEVICE_2                 (NUMBER_OF_SLAVES-2)
#else
        #define DEVICE_2                 (DEVICE_1)
#endif
#if (DEVICE_2>0)
        #define DEVICE_3                 (NUMBER_OF_SLAVES-3)
#else
        #define DEVICE_3                 (DEVICE_2)
#endif
#if (DEVICE_3>0)
        #define DEVICE_4                 (NUMBER_OF_SLAVES-4)
#else
        #define DEVICE_4                 (DEVICE_3)
#endif
#if (DEVICE_4>0)
        #define DEVICE_5                 (NUMBER_OF_SLAVES-5)
#else
        #define DEVICE_5                 (DEVICE_4)
#endif
#if (DEVICE_5>0)
        #define DEVICE_6                 (NUMBER_OF_SLAVES-6)
#else
        #define DEVICE_6                 (DEVICE_5)
#endif
#if (DEVICE_6>0)
        #define DEVICE_7                 (NUMBER_OF_SLAVES-7)
#else
        #define DEVICE_7                 (DEVICE_6)
#endif
#if (DEVICE_7>0)
        #define DEVICE_8                 (NUMBER_OF_SLAVES-8)
#else
        #define DEVICE_8                 (DEVICE_7)
#endif

  /****************************************************************************/
  /***** #define dSPIN_CONF_PARAM_XXX (DEVICE_N, DEVICE_N-1, ..., DEVICE_1) ***/
  /****************************************************************************/

  
/**************************** Speed Profile *********************************/

	/* Register : ACC */
	/* Acceleration rate in step/s2, range 14.55 to 59590 steps/s2 */
    #define dSPIN_DC_CONF_PARAM_ACC {2008.164}

	/* Register : DEC */
	/* Deceleration rate in step/s2, range 14.55 to 59590 steps/s2 */
    #define dSPIN_DC_CONF_PARAM_DEC {2008.164}

	/* Register : MAX_SPEED */
	/* Maximum speed in step/s, range 15.25 to 15610 steps/s */
    #define dSPIN_DC_CONF_PARAM_MAX_SPEED {991.821}

	/* Register : MIN_SPEED */
	/* Minimum speed in step/s, range 0 to 976.3 steps/s */
    #define dSPIN_DC_CONF_PARAM_MIN_SPEED {0}

	/* Register : FS_SPD */
	/* Full step speed in step/s, range 7.63 to 15625 steps/s */
    #define dSPIN_DC_CONF_PARAM_FS_SPD {610.336}

	/************************ Phase Current Control *****************************/

  /* Register : TVAL_HOLD */
	/* Torque regulation DAC current when motor is stopped, range 31.25mA to 4000mA */
    #define dSPIN_DC_CONF_PARAM_TVAL_HOLD {1312.5}

	/* Register : TVAL_RUN */
	/* Torque regulation DAC current when motor is running, range 31.25mA to 4000mA */
    #define dSPIN_DC_CONF_PARAM_TVAL_RUN {1312.5}

	/* Register : KVAL_ACC */
  /* Torque regulation DAC current during motor acceleration, range 31.25mA to 4000mA */
    #define dSPIN_DC_CONF_PARAM_TVAL_ACC {1312.5}

	/* Register : TVAL_DEC */
	/* Torque regulation DAC current during motor deceleration, range 31.25mA to 4000mA */
    #define dSPIN_DC_CONF_PARAM_TVAL_DEC {1312.5}

	/* Register : T_FAST - field : FAST_STEP */
	/* Maximum fast decay and fall step times used by the current control system, range 2us to 32us */
    #define dSPIN_DC_CONF_PARAM_FAST_STEP {dSPIN_FAST_STEP_20us}

	/* Register : T_FAST - field : TOFF_FAST */
	/* Maximum fast decay and fall step times used by the current control system, range 2us to 32us */
    #define dSPIN_DC_CONF_PARAM_TOFF_FAST {dSPIN_TOFF_FAST_4us}

	/* Register : TON_MIN */
	/* Minimum ON time value used by the current control system, range 0.5us to 64us */
    #define dSPIN_DC_CONF_PARAM_TON_MIN {21}

	/* Register : TOFF_MIN */
	/* Minimum OFF time value used by the current control system, range 0.5us to 64us */
    #define dSPIN_DC_CONF_PARAM_TOFF_MIN {21}

/******************************* Others *************************************/
	/* Register : OCD_TH */
    /* Overcurrent threshold settings via enum dSPIN_OCD_TH_TypeDef */
    #define dSPIN_DC_CONF_PARAM_OCD_TH {dSPIN_OCD_TH_3375mA}

	/* Register : ALARM_EN */
	/* Alarm settings via bitmap enum dSPIN_ALARM_EN_TypeDef */
    #define dSPIN_DC_CONF_PARAM_ALARM_EN {dSPIN_ALARM_EN_OVERCURRENT | dSPIN_ALARM_EN_THERMAL_SHUTDOWN | dSPIN_ALARM_EN_THERMAL_WARNING | dSPIN_ALARM_EN_UNDER_VOLTAGE | dSPIN_ALARM_EN_SW_TURN_ON | dSPIN_ALARM_EN_WRONG_NPERF_CMD}

	/* Register : STEP_MODE - field : STEP_MODE */
    /* Step mode settings via enum dSPIN_STEP_SEL_TypeDef */
    #define dSPIN_DC_CONF_PARAM_STEP_MODE {dSPIN_STEP_SEL_1_16}

	  /* Register : STEP_MODE - Field : SYNC_MODE and SYNC_EN */
    /* Synch. Mode settings via enum dSPIN_SYNC_SEL_TypeDef */
    #define dSPIN_DC_CONF_PARAM_SYNC_MODE {dSPIN_SYNC_SEL_DISABLED}

    /* Register : CONFIG - field : PRED_EN */
    /* Predictive current control system enabling, enum dSPIN_CONFIG_PRED_EN_TypeDef */
    #define dSPIN_DC_CONF_PARAM_PRED {dSPIN_CONFIG_PRED_DISABLE}

    /* Register : CONFIG - field : TSW */
    /* Target Swicthing Period, enum dSPIN_CONFIG_TSW_TypeDef */
    #define dSPIN_DC_CONF_PARAM_TSW {dSPIN_CONFIG_TSW_044us}

    /* Register : CONFIG - field : POW_SR */
    /* Slew rate, enum dSPIN_CONFIG_POW_SR_TypeDef */
    #define dSPIN_DC_CONF_PARAM_SR {dSPIN_CONFIG_SR_110V_us}

	/* Register : CONFIG - field : OC_SD */
    /* Over current shutwdown enabling, enum dSPIN_CONFIG_OC_SD_TypeDef */
    #define dSPIN_DC_CONF_PARAM_OC_SD {dSPIN_CONFIG_OC_SD_ENABLE}

	  /* Register : CONFIG - field : EN_TQREG */
    /*  Torque regulation method, enum dSPIN_CONFIG_EN_TQREG_TypeDef  */
    #define dSPIN_DC_CONF_PARAM_TQ_REG {dSPIN_CONFIG_TQ_REG_TVAL_USED}

	/* Register : CONFIG - field : SW_MODE */
    /* External switch hard stop interrupt mode, enum dSPIN_CONFIG_SW_MODE_TypeDef */
    #define dSPIN_DC_CONF_PARAM_SW_MODE {dSPIN_CONFIG_SW_HARD_STOP}

	/* Register : CONFIG - field : OSC_CLK_SEL */
	/* Clock setting , enum dSPIN_CONFIG_OSC_MGMT_TypeDef */
    #define dSPIN_DC_CONF_PARAM_CLOCK_SETTING {dSPIN_CONFIG_INT_16MHZ_OSCOUT_2MHZ}


/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

  /****************************************************************************/
  /******************No Daisy Chain Mode **************************************/
  /****************************************************************************/

/* Exported constants --------------------------------------------------------*/
  
/**************************** Speed Profile *********************************/

	/* Register : ACC */
	/* Acceleration rate in step/s2, range 14.55 to 59590 steps/s2 */
    #define dSPIN_CONF_PARAM_ACC (2008.164)

	/* Register : DEC */
	/* Deceleration rate in step/s2, range 14.55 to 59590 steps/s2 */
    #define dSPIN_CONF_PARAM_DEC (2008.164)

	/* Register : MAX_SPEED */
	/* Maximum speed in step/s, range 15.25 to 15610 steps/s */
    #define dSPIN_CONF_PARAM_MAX_SPEED (991.821)

	/* Register : MIN_SPEED */
	/* Minimum speed in step/s, range 0 to 976.3 steps/s */
    #define dSPIN_CONF_PARAM_MIN_SPEED (0)

	/* Register : FS_SPD */
	/* Full step speed in step/s, range 7.63 to 15625 steps/s */
    #define dSPIN_CONF_PARAM_FS_SPD (610.336)

	/************************ Phase Current Control *****************************/

  /* Register : TVAL_HOLD */
	/* Torque regulation DAC current when motor is stopped, range 31.25mA to 4000mA */
    #define dSPIN_CONF_PARAM_TVAL_HOLD (1312.5)

	/* Register : TVAL_RUN */
	/* Torque regulation DAC current when motor is running, range 31.25mA to 4000mA */
    #define dSPIN_CONF_PARAM_TVAL_RUN (1312.5)

	/* Register : KVAL_ACC */
  /* Torque regulation DAC current during motor acceleration, range 31.25mA to 4000mA */
    #define dSPIN_CONF_PARAM_TVAL_ACC (1312.5)

	/* Register : TVAL_DEC */
	/* Torque regulation DAC current during motor deceleration, range 31.25mA to 4000mA */
    #define dSPIN_CONF_PARAM_TVAL_DEC (1312.5)

	/* Register : T_FAST - field : FAST_STEP */
	/* Maximum fast decay and fall step times used by the current control system, range 2us to 32us */
    #define dSPIN_CONF_PARAM_FAST_STEP (dSPIN_FAST_STEP_20us)

	/* Register : T_FAST - field : TOFF_FAST */
	/* Maximum fast decay and fall step times used by the current control system, range 2us to 32us */
    #define dSPIN_CONF_PARAM_TOFF_FAST (dSPIN_TOFF_FAST_4us)

	/* Register : TON_MIN */
	/* Minimum ON time value used by the current control system, range 0.5us to 64us */
    #define dSPIN_CONF_PARAM_TON_MIN (21)

	/* Register : TOFF_MIN */
	/* Minimum OFF time value used by the current control system, range 0.5us to 64us */
    #define dSPIN_CONF_PARAM_TOFF_MIN (21)

/******************************* Others *************************************/
	/* Register : OCD_TH */
    /* Overcurrent threshold settings via enum dSPIN_OCD_TH_TypeDef */
    #define dSPIN_CONF_PARAM_OCD_TH (dSPIN_OCD_TH_3375mA)

	/* Register : ALARM_EN */
	/* Alarm settings via bitmap enum dSPIN_ALARM_EN_TypeDef */
    #define dSPIN_CONF_PARAM_ALARM_EN (dSPIN_ALARM_EN_OVERCURRENT | dSPIN_ALARM_EN_THERMAL_SHUTDOWN | dSPIN_ALARM_EN_THERMAL_WARNING | dSPIN_ALARM_EN_UNDER_VOLTAGE | dSPIN_ALARM_EN_SW_TURN_ON | dSPIN_ALARM_EN_WRONG_NPERF_CMD)

	/* Register : STEP_MODE - field : STEP_MODE */
    /* Step mode settings via enum dSPIN_STEP_SEL_TypeDef */
    #define dSPIN_CONF_PARAM_STEP_MODE (dSPIN_STEP_SEL_1_16)

	  /* Register : STEP_MODE - Field : SYNC_MODE and SYNC_EN */
    /* Synch. Mode settings via enum dSPIN_SYNC_SEL_TypeDef */
    #define dSPIN_CONF_PARAM_SYNC_MODE (dSPIN_SYNC_SEL_DISABLED)

    /* Register : CONFIG - field : PRED_EN */
    /* Predictive current control system enabling, enum dSPIN_CONFIG_PRED_EN_TypeDef */
    #define dSPIN_CONF_PARAM_PRED (dSPIN_CONFIG_PRED_DISABLE)

    /* Register : CONFIG - field : TSW */
    /* Target Swicthing Period, enum dSPIN_CONFIG_TSW_TypeDef */
    #define dSPIN_CONF_PARAM_TSW (dSPIN_CONFIG_TSW_044us)

    /* Register : CONFIG - field : POW_SR */
    /* Slew rate, enum dSPIN_CONFIG_POW_SR_TypeDef */
    #define dSPIN_CONF_PARAM_SR (dSPIN_CONFIG_SR_110V_us)

	/* Register : CONFIG - field : OC_SD */
    /* Over current shutwdown enabling, enum dSPIN_CONFIG_OC_SD_TypeDef */
    #define dSPIN_CONF_PARAM_OC_SD (dSPIN_CONFIG_OC_SD_ENABLE)

	  /* Register : CONFIG - field : EN_TQREG */
    /*  Torque regulation method, enum dSPIN_CONFIG_EN_TQREG_TypeDef  */
    #define dSPIN_CONF_PARAM_TQ_REG (dSPIN_CONFIG_TQ_REG_TVAL_USED)

	/* Register : CONFIG - field : SW_MODE */
    /* External switch hard stop interrupt mode, enum dSPIN_CONFIG_SW_MODE_TypeDef */
    #define dSPIN_CONF_PARAM_SW_MODE (dSPIN_CONFIG_SW_HARD_STOP)

	/* Register : CONFIG - field : OSC_CLK_SEL */
	/* Clock setting , enum dSPIN_CONFIG_OSC_MGMT_TypeDef */
    #define dSPIN_CONF_PARAM_CLOCK_SETTING (dSPIN_CONFIG_INT_16MHZ_OSCOUT_2MHZ)


/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
#endif /* __DSPIN_CONFIG_H */

/******************* (C) COPYRIGHT 2013 STMicroelectronics *****END OF FILE****/
