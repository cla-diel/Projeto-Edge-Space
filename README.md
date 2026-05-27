# Projeto-Edge-Space
----------------------------------- Global Solution 1 -----------------------------------
Indústria Espacial: O código que move o universo 
Trabalho da disciplina de Edge Computing FIAP, Engenharia de Software, Semi Presencial RJ 
Professor da disciplina: Vitor Amadeu Souza 
Maio de 2026 

Integrantes: 
Clara Diel Gama Secco, RM: 571679 
Anna Júlia Elias Andrade, RM: 573453 
Lucas Rodrigues de Carvalho, RM: 573788

Desafio Proposto: 
Tema: Sistemas de Missão Crítica e Autonomia de Bordo O Desafio Imagine que sua nave acabou de passar para o lado escuro de um planeta. O sinal sumiu. A Terra está a milhões de quilômetros de distância. Não há nuvem, não há operador, não há segunda chance. Nesse momento, a única coisa que separa a missão do fracasso é o código que você escreveu. Em missões espaciais reais, a conectividade é um luxo, não uma garantia. Blackouts de comunicação podem durar minutos ou horas e o sistema precisa continuar funcionando sozinho durante todo esse tempo. É exatamente isso que define o Edge Computing de missão crítica: a capacidade de monitorar, decidir e atuar localmente, sem depender de nenhum recurso externo. Seu desafio é construir esse sistema. Usando Arduino no simulador Wokwi ou Tinkercad, você vai criar uma aplicação capaz de ler sensores, processar decisões e comandar atuadores em tempo real, tudo de forma autônoma, como se estivesse, de fato, orbitando.

# 🚀 PROJETO: Sistema Autônomo de Sobrevivência da Nave (SASN) 
Sistema embarcado autônomo capaz de manter a integridade estrutural, energética e operacional de uma nave durante blackout de comunicação! 

## ⚠️ Problemática da Missão

Em ambientes críticos como missões espaciais, a comunicação com centros de controle na Terra não é instantânea nem garantida. Fatores como grande distância, interferências e atrasos na transmissão de dados tornam inviável depender exclusivamente de comandos remotos para a tomada de decisões.

Nesse contexto, surge a necessidade de sistemas embarcados capazes de operar de forma autônoma, analisando o ambiente em tempo real e reagindo a situações críticas sem intervenção externa.

Este projeto aborda essa problemática ao simular um sistema de navegação que:

- Detecta obstáculos próximos utilizando sensor ultrassônico
- Interpreta dados localmente sem intervenção externa
- Executa ações pelo servo motor para evitar colisões
- Fornece feedback contínuo ao operador por meio de interface local (LCD)

Dessa forma, o sistema demonstra como soluções embarcadas podem aumentar a segurança, eficiência e confiabilidade em cenários onde a dependência de comunicação externa representa um risco operacional.

---

## 🎯 Objetivo

Desenvolver um sistema embarcado robusto capaz de:

- Monitorar o ambiente continuamente em tempo real 
- Reagir a eventos críticos (obstáculos próximos)
- Garantir funcionamento independente de comunicação externa

---

## 🧰 Componentes Utilizados

- Arduino Uno R3
- Leds (vermelha, amarela e verde) 
- Resistores (220 ohms cada)
- Sensor de Distância Ultrassônico 
- Sensor de Temperatura (TMP36)
- Micro Servo Motor (posicional) 
- Display LCD 16x2
- Potenciômetro (age/funciona como uma bateria no sistema)
- Jumpers
- Protoboard

---

## 🔌 Esquema de Ligação

### 📟 LCD 16x2
- RS → pino 12
- E → pino 11
- D4 → pino 5
- D5 → pino 4
- D6 → pino 3
- D7 → pino 2
- GND → GND
- VCC → 5V
- V0 → GND 
- RW → GND

### 📡 Sensor de Distância Ultrassônico
- Sinal → pino 9
- 5V Potência → 5V
- GND → GND

### ⚙️ Micro Servo Motor 
- Sinal → pino 6
- Potência → 5V
- GND → GND

### 🌡️ Sensor de Temperatura (TMP36)
VCC → 5V
GND → GND
OUT → A1

### 🎛️ Potenciômetro (Bateria)
Terminal 1 → GND
Terminal 2 → 5V
Limpador → A0

### 💡 LEDs (Indicadores de Status)
LED 1 Verde (Ex: sistema ativo - estável)
Anodo (+) → resistor (220Ω) → pino 7
Catodo (-) → GND
LED 2 Amarela (Ex: Bateria do sistema abaixo de 300) 
Anodo (+) → resistor (220Ω) → pino 8
Catodo (-) → GND
LED 3 Vermelha (Ex: Temperatura acima de 35 graus celsius) 
Anodo (+) → resistor (220Ω) → pino 13
Catodo (-) → GND

---

## ▶️ Execução

1. Monte o circuito conforme esquema
2. Abra o código no Arduino IDE
3. Faça upload para a placa
4. Observe:
 - LCD exibindo distância
 - Servo reagindo a obstáculos
