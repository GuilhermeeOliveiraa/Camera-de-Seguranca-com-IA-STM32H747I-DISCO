# Câmera de Segurança com IA — STM32H747I-DISCO

Implementa um sistema embarcado de monitoramento com inteligência artificial utilizando a placa STM32H747I-DISCO.

## Objetivo
Capturar imagens pela câmera integrada, executar inferência local para detectar eventos (intrusão, pessoas, etc.) e registrar/alertar conforme necessário.

## Hardware
- Placa: STM32H747I-DISCO (Cortex-M7 + Cortex-M4)
- Câmera DCMI integrada (OV9655 ou compatível)
- LCD integrado para exibição de prévias e status
- Cartão SD para armazenamento local

## Funcionalidades
- Captura de imagem via DCMI + DMA
- Inferência no core M7 com modelo quantizado via STM32Cube.AI
- Exibição no LCD
