# taks-FreeRTOS-Linux

## Resumo
O FreeRTOS é um simulador de kernel open source, usado para aplicações em tempo real. Esse projeto simula a criação de 3 tasks, que são equivalentes a threads. A função que executa a task 3 é utilizada para suspender a execução das outras tasks, que se não fossem interrompidas ficariam em loop infinito. A função vTaskSuspend() é utilizada para fazer essa interrupção, caso queira que as tasks voltem a rodar em loop se deve utilizar a função vTaskResume().

## Compilando e executanto

***Pré requisitos***

- Ter o FreeRTOS instalado como uma variável de ambiente
- ter o GCC instalado

**para compilar utilize o comando abaixo**

```bash
make
```

Ao fazer isso será gerada uma nova pasta chamada *build*. Dentro dessa pasta será gerado um arquivo chamado *modelo-posix-gcc*

**Para executar utilize**

```bash
./modelo-posix-gcc
```

### Autor
Jônatas Fernandes
