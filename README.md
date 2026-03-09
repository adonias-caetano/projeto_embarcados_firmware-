# Sistema de Monitoramento e Controle de uma Estufa

## Descrição
Este projeto implementa um sistema embarcado para monitoramento e controle de uma estufa utilizando a placa Franzininho WiFi LAB01 com ESP32. O sistema realiza a leitura de temperatura, umidade e luminosidade, exibe os dados em um display OLED, permite ajuste de set point, grava logs em memória flash e disponibiliza leitura via comunicação serial.

## Objetivos
- Monitorar temperatura e umidade com DHT11
- Monitorar luminosidade com LDR
- Exibir dados em tempo real no display OLED
- Permitir ajuste de set point por menu
- Ativar e desativar o sistema de controle
- Registrar dados em arquivo log.txt
- Ler o arquivo de log via serial

## Hardware Utilizado
- Franzininho WiFi LAB01
- Sensor DHT11
- Sensor LDR
- Display OLED I2C
- LED ou relé para saída de controle
- Resistores e jumpers

## Software
- ESP-IDF
- SPIFFS ou LittleFS
- Ferramenta de terminal serial

## Estrutura do Projeto
- `main/`: inicialização principal
- `components/dht11_sensor`: leitura do DHT11
- `components/ldr_sensor`: leitura do LDR
- `components/oled_ui`: exibição no OLED
- `components/greenhouse_control`: lógica de controle
- `components/storage_log`: gravação e leitura de logs
- `components/serial_cmd`: interface serial
- `components/config_system`: integração com menuconfig

## Funcionalidades
- Exibição contínua dos sensores
- Controle ON/OFF
- Ajuste de temperatura de referência
- Registro em log.txt
- Leitura de logs pela serial

## Compilação
```bash
idf.py set-target esp32
idf.py menuconfig
idf.py build
idf.py flash monitor