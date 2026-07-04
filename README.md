# 🚦 Semáforo Inteligente — Controle Adaptativo em C

Simulação em tempo real de um controlador de tráfego inteligente desenvolvido estritamente em linguagem C puro. O sistema emprega alocação dinâmica de memória no *Heap* e persistência de dados, evitando memory leaks em aplicações críticas.

## 🚀 Funcionalidades
- **Lógica de Controle Adaptativo**: Ajusta proporcionalmente o tempo de sinal verde com base no volume dinâmico de veículos detectados em cada via.
- **Prevenção Anticolisão (Mutex)**: Garante exclusividade lógica de cruzamento (apenas uma via por vez assume o sinal Verde).
- **Gerenciamento Estrito de Memória**: Abordagem cirúrgica de uso de `malloc` e `free` para arrays dinâmicos de structs em C puro, essencial para programação de hardware embarcado.
- **Histórico Persistente (Log)**: Geração de relatórios cronológicos de transição salvos diretamente em arquivo texto.

## 🛠️ Tecnologias Utilizadas
- **Linguagem C Puro**
- **Compilador GCC** (Para compilação do executável binário via CLI)
- **Bibliotecas Padrão**: `<stdio.h>`, `<stdlib.h>`, manipulação de ponteiros.

## ⚙️ Como Executar
1. Certifique-se de ter o GCC instalado em sua máquina (MinGW no Windows ou build-essentials no Linux).
2. Abra o terminal na pasta do projeto e compile o código:
   ```bash
   gcc main.c -o semaforo_inteligente
   ```
3. Inicie o sistema:
   ```bash
   ./semaforo_inteligente
   ```
4. Siga as instruções no console para informar a quantidade de vias e o fluxo de veículos. O log será salvo automaticamente em `historico_semaforo.txt`.

## 📸 Demonstração
*(Espaço reservado para visualização do terminal ou fluxograma estrutural)*
