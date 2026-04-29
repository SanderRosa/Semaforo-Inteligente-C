# 🚦 Semáforo Inteligente — Simulação em C

> Simulação de um sistema de semáforos inteligente e adaptativo, implementado em C puro com alocação dinâmica de memória e persistência em arquivo.

---

## 📋 Sobre o Projeto

O **Semáforo Inteligente** é uma simulação de um sistema de controle de tráfego desenvolvida em linguagem C. O sistema simula múltiplas vias urbanas com semáforos que se adaptam ao volume de carros detectado em cada via, calculando automaticamente o tempo de verde proporcional ao tráfego.

---

## ⚙️ Lógica de Controle Adaptativo

O tempo de verde de cada via é calculado dinamicamente com base na quantidade de veículos detectados:

| Quantidade de Carros | Tempo de Verde |
|---|---|
| `> 20 carros` | 30 segundos |
| `10 < carros ≤ 20` | 20 segundos |
| `≤ 10 carros` | 10 segundos |

**Regra de exclusividade:** Apenas **uma via por vez** tem o estado VERDE. As demais ficam em VERMELHO, eliminando conflitos.

---

## 🏗️ Estrutura do Código

```
Semaforo Inteligente - C/
└── main.c   # Código completo: estruturas, lógica e simulação
```

### Principais componentes:

- **`typedef enum EstadoSemaforo`** — Estados: `VERMELHO`, `AMARELO`, `VERDE`
- **`typedef struct Via`** — Representa uma via com nome, contagem de carros e estado
- **`atualizarTempoVerde()`** — Calcula o tempo de verde adaptativo
- **`simularCicloSemaforo()`** — Itera por todas as vias, coordenando os ciclos
- **`main()`** — Entrada de dados, alocação dinâmica e chamada da simulação

---

## 🚀 Como Compilar e Executar

### Compilar (GCC)
```bash
gcc main.c -o semaforo
```

### Executar
```bash
./semaforo
```

### Exemplo de uso
```
Quantas vias deseja simular? 3

Nome da via 1: Avenida Brasil
Quantidade de carros detectados: 25

Nome da via 2: Rua das Flores
Quantidade de carros detectados: 8

Nome da via 3: Rua XV de Novembro
Quantidade de carros detectados: 15

Iniciando simulacao do ciclo dos semaforos...
```

---

## 📄 Saída

O programa exibe o log da simulação no console **e** salva em `historico_semaforo.txt`:

```
[0s] Via: Rua das Flores | Estado: VERMELHO
[0s] Via: Rua XV de Novembro | Estado: VERMELHO
[0s] Via: Avenida Brasil | Estado: VERDE | Tempo Verde: 30s
[30s] Via: Avenida Brasil | Estado: AMARELO (3s)
...
```

---

## 🛠️ Tecnologias e Conceitos

| Conceito | Aplicação |
|---|---|
| **C Puro** | Linguagem principal |
| **`malloc` / `free`** | Alocação dinâmica de memória |
| **`enum` e `struct`** | Modelagem dos estados e vias |
| **Ponteiros e Arquivos** | Persistência via `fprintf` em `.txt` |
| **Lógica Adaptativa** | Tempo de verde proporcional ao tráfego |
