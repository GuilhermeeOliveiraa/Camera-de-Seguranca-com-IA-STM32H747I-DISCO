# Câmera de Segurança com IA — STM32H747I-DISCO

Implementa um sistema embarcado de monitoramento com inteligência artificial utilizando a placa STM32H747I-DISCO.

## Objetivo
Capturar imagens pela câmera integrada, executar inferência local para detectar eventos (intrusão, pessoas, etc.) e registrar/alertar conforme necessário.

## Funcionalidades
- Captura de imagem via DCMI + DMA
- Inferência no core M7 com modelo quantizado via STM32Cube.AI
- Exibição no LCD

# Deployment de Modelo de Detecção de Objetos no STM32

Este guia explica como **implantar um modelo pré-treinado** ou **usar seu próprio dataset** para detecção de objetos em placas **STM32** usando o **STM32Cube.AI**.

---

## 1. Pré-requisitos

### **Hardware**
- Placa **STM32H747I-DISCO** (Cortex-M7 + Cortex-M4)
- Câmera DCMI integrada (OV5640)
- LCD integrado para exibição de prévias e status (B-LCD40-DSI1)

### **Software**
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [STM32Cube.AI](https://www.st.com/en/embedded-software/x-cube-ai.html) *(ou usar **STM32 Developer Cloud**)*
- [STM32 Model Zoo](https://github.com/STMicroelectronics/stm32-modelzoo) *(coleção de modelos pré-treinados)*
- [STM32 Model Zoo Services](https://stm32ai-cs.st.com/) *(serviço online para treinamento, avaliação e quantização)*


### **Modelo**
- Formato **TFLite** quantizado (int8)  
- Entrada `uint8`, saída `float`

---

## 2. Configuração para Deployment

### Exemplo `user_config.yaml`
```yaml
general:
  project_name: coco_person_detection
  model_type: ssd_mobilenet_v2_fpnlite
  model_path: ./pretrained_models/model.tflite

operation_mode: deployment

dataset:
  name: person_dataset
  class_names: [person]

preprocessing:
  resizing:
    aspect_ratio: fit
    interpolation: nearest
  color_mode: rgb

postprocessing:
  confidence_thresh: 0.6
  NMS_thresh: 0.5
  IoU_eval_thresh: 0.4
  max_detection_boxes: 10

deployment:
  c_project_path: ../application_code/object_detection/STM32H7/
  IDE: GCC
  hardware_setup:
    serie: STM32H7
    board: STM32H747I-DISCO
```

---

## 3. Deployment

1. Conecte a câmera ao **STM32H747I-DISCO** e a placa ao PC via USB.
2. Execute:
```bash
python stm32ai_main.py
```
Ou especificando configuração:
```bash
python stm32ai_main.py --config-path ./src/config_file_examples/ --config-name deployment_config.yaml
```
Para **quantizar e implantar**:
```bash
python stm32ai_main.py --config-path ./src/config_file_examples/ --config-name chain_qd_config.yaml
```

**Ao rodar, o display mostrará**:
- Vídeo da câmera
- Caixas delimitadoras, confiança e classes
- Número de objetos detectados
- FPS do modelo

---

## 4. Usando seu próprio Dataset

### **Passo 1 – Converter para formato YOLO Darknet**
Se o dataset estiver em **COCO** ou **Pascal VOC**:

```yaml
dataset:
  format: coco_format
  class_names: [classe1, classe2]

coco_format:
  images_path: <caminho-imagens>
  json_annotations_file_path: <caminho-anotacoes-json>
  export_dir: <caminho-exportacao>
```
Rodar:
```bash
python converter.py dataset_config.yaml
```
> Repita para **treino**, **validação** e **teste**, se necessário.

---

### **Passo 2 – Configurar `user_config.yaml`**
```yaml
dataset:
  dataset_name: meu_dataset
  class_names: [classe1, classe2]
  training_path: <caminho-yolo-treino>
  validation_path: <caminho-yolo-validacao>
  validation_split: 0.2
  test_path: <caminho-yolo-teste>
  quantization_path: <caminho-yolo-quantizacao>
```

---

### **Passo 3 – (Opcional) Otimizar Dataset**
- `dataset_analysis` → analisa distribuição de classes  
- `dataset_create_tfs` → cria arquivos `.tfs` para acelerar treinamento  

---

✅ **Pronto!** Agora você pode **treinar, quantizar e implantar** seu modelo personalizado na placa STM32.
