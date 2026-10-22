# Wall-E: robô seguidor de linha com desvio de obstáculos

![Arduino](https://img.shields.io/badge/Arduino-00878F?logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![ENTEC](https://img.shields.io/badge/13%C2%AA%20ENTEC-UNINASSAU%202025-orange)
![License](https://img.shields.io/badge/license-MIT-green)

Robô em Arduino que segue uma linha preta usando quatro sensores infravermelhos e
para e desvia quando um sensor ultrassônico detecta um obstáculo à frente. Projeto
desenvolvido em equipe e apresentado na **13ª ENTEC UNINASSAU**.

## Componentes

| Componente | Uso |
|---|---|
| Arduino | Controle (código em `codigo/carro.ino`) |
| Módulo seguidor de linha com 4 sensores IR | 2 frontais e 2 laterais, lidos como entradas analógicas |
| Sensor ultrassônico HC-SR04 | Distância até obstáculos |
| Ponte H HW-095 | Acionamento dos motores esquerdo e direito com controle de velocidade (PWM) |
| Motores DC | Tração |
| Bateria 9–12 V | Alimentação |

### Ligações

| Sinal | Pino |
|---|---|
| Sensor frontal esquerdo / direito | A4 / A5 |
| Sensor lateral esquerdo / direito | A2 / A3 |
| Ponte H: ENA, IN1, IN2 (motor esquerdo) | 5, 8, 9 |
| Ponte H: ENB, IN3, IN4 (motor direito) | 6, 10, 11 |
| Ultrassônico: TRIG / ECHO | 4 / 3 |

## Como funciona

A cada ciclo (cerca de 20 ms) o robô lê os quatro sensores IR e a distância do
ultrassônico. Um sensor com leitura acima do limiar (`LIMIAR = 250`) está vendo preto.

1. **Obstáculo a menos de 15 cm:** para por 200 ms e faz uma curva por 300 ms.
2. **Os dois sensores frontais na linha:** segue em frente.
3. **Só um sensor frontal na linha:** curva suave para o lado da linha, reduzindo a
   velocidade de um dos motores.
4. **Linha em um sensor lateral:** curva acentuada, com um dos motores em ré.
5. **Nenhuma das situações acima:** segue em frente em velocidade reduzida.

As velocidades (`velNormal`, `velCurva`) e o limiar ficam no início do código para
ajuste conforme a pista e a bateria.

## Como rodar

1. Abra `codigo/carro.ino` no Arduino IDE. A IDE pede para colocar o arquivo numa
   pasta `carro/`; aceite.
2. Conecte o Arduino, selecione a placa e a porta e faça o upload.
3. Coloque o robô sobre a pista. O monitor serial está configurado em 9600 baud.

## Limitações

- O desvio de obstáculo é uma curva de tempo fixo; o robô não contorna o obstáculo
  nem procura a linha de volta.
- O limiar dos sensores IR é fixo e precisa ser recalibrado conforme a iluminação e a pista.
- Nas funções de curva acentuada, o motor que vai em ré é o do lado oposto ao do nome
  da função. Vale conferir contra a fiação dos motores antes de alterar.

## Equipe

- Derick Portela ([@DerickxP](https://github.com/DerickxP))
- Michael Domingos ([@mmichaeldomingos](https://github.com/mmichaeldomingos))
- Raul Vitor

| Equipe | Robô | Apresentação na ENTEC |
|--------|------|-----------|
| <img src="imagens/image3.jpeg" width="250"> | <img src="imagens/image2.jpeg" width="250"> | <img src="imagens/image1.jpeg" width="250"> |

[Vídeo do robô no circuito](imagens/ROBOTICA2.mp4)

## Licença

[MIT](LICENSE)
