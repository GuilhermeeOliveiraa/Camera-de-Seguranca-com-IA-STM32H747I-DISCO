/**
  ******************************************************************************
  * @file    network_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-05-27T19:51:12+0000
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef NETWORK_DATA_PARAMS_H
#define NETWORK_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_NETWORK_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_network_data_weights_params[1]))
*/

#define AI_NETWORK_DATA_CONFIG               (NULL)


#define AI_NETWORK_DATA_ACTIVATIONS_SIZES \
  { 18428, 311996, 266256, }
#define AI_NETWORK_DATA_ACTIVATIONS_SIZE     (596680)
#define AI_NETWORK_DATA_ACTIVATIONS_COUNT    (3)
#define AI_NETWORK_DATA_ACTIVATION_1_SIZE    (18428)
#define AI_NETWORK_DATA_ACTIVATION_2_SIZE    (311996)
#define AI_NETWORK_DATA_ACTIVATION_3_SIZE    (266256)



#define AI_NETWORK_DATA_WEIGHTS_SIZES \
  { 691856, }
#define AI_NETWORK_DATA_WEIGHTS_SIZE         (691856)
#define AI_NETWORK_DATA_WEIGHTS_COUNT        (1)
#define AI_NETWORK_DATA_WEIGHT_1_SIZE        (691856)



#define AI_NETWORK_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_network_activations_table[1])

extern ai_handle g_network_activations_table[3 + 2];



#define AI_NETWORK_DATA_WEIGHTS_TABLE_GET() \
  (&g_network_weights_table[1])

extern ai_handle g_network_weights_table[1 + 2];


#endif    /* NETWORK_DATA_PARAMS_H */
