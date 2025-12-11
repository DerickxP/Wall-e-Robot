# Wall-e-Robot
Programação de um veículo robótico baseado em Arduino

# 🤖 Wall-E — Robô Seguidor de Linha com Desvio de Obstáculos

[![Made with Arduino](https://img.shields.io/badge/Made%20with-Arduino-blue)]()
![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white)
[![License](https://img.shields.io/badge/License-MIT-green)]()
[![Status](https://img.shields.io/badge/Status-Ativo-success)]()
[![Plataforma-ENTEC](https://img.shields.io/badge/Evento-13ª%20ENTEC%20UNINASSAU-orange)]()

Projeto desenvolvido para a **13ª edição da ENTEC UNINASSAU**, carinhosamente apelidado de **Wall-E**.  
O robô utiliza sensores infravermelhos para seguir linhas e um sensor ultrassônico para desviar automaticamente de obstáculos.

---

## 🚀 Funcionalidades

- Segue linha usando **4 sensores IR** (2 frontais e 2 laterais)
- Detecta obstáculos com **sensor ultrassônico**
- Realiza curvas suaves e acentuadas
- Sistema de motores controlado por **ponte H HW-095**
- Velocidades configuráveis
- Lógica robusta para retomada da linha

---

## 🔧 Componentes Utilizados

| Componente | Quantidade |
|-----------|------------|
| Arduino UNO / Nano | 1 |
| Ponte H HW-095 | 1 |
| Motores DC | 2 |
| Sensor Ultrassônico HC-SR04 | 1 |
| Módulo Seguidor de Linha (4 sensores) | 1 |
| Bateria 9–12V | 1 |

---

## 🧠 Como Funciona (Resumo)

- Os sensores IR retornam valores analógicos. Se o valor é maior que o **limiar**, considera-se que o sensor está vendo **preto**.
- A lógica verifica:
  - Linha central → anda reto  
  - Linha desviada → curva  
  - Linha lateral → curva acentuada  
  - Obstáculo < 15 cm → parar → desviar  

---

## ▶️ Como rodar

1. Abra o arquivo `carro.ino` no Arduino IDE.
2. Conecte o Arduino.
3. Faça upload.
4. Coloque o robô sobre a pista e divirta-se!

---

## 📜 Licença

Este projeto é distribuído sob a licença **MIT**.  
Você pode usar, modificar e compartilhar à vontade.

---

## 📸 Imagens

Use este formato para adicionar imagens após subi-las na pasta `/imagens`:

```md
![Equipe](imagens/image3.jpg)
```
```md
![Robô](imagens/image2.jpg)
```
```md
![Premiação](imagens/image1.jpg)
```
---

## 🎥 Vídeos / GIFs

```md
[![Circuito](imagens/demo.gif)](imagens/ROBOTICA2.mp4)
```

---

## ✨ Autores

- **Derick Portela**
- **Michael Domingos**
- **Raul Vitor**
