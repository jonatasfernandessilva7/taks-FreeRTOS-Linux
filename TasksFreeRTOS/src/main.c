/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);

int main(void)
{
    xTaskCreate(&vTask1, /** tarefa ou função a ser executada */
		"Task jonatas testando kernel",  /** nome da tarefa ou função */
		 1024, /** tamanho da pilha  */
		 NULL, /** parametro de entrada */ 
		 1, /** prioridade da tarefa */ 
		 NULL /** identificador da tarefa */
		 );
    xTaskCreate(&vTask2, "kernel foi", 1024, NULL, 1, NULL);
    xTaskCreate(&vTask3, "teste finalizado", 1024, NULL, 1, NULL);

    vTaskStartScheduler(); /** inicia o agendador de tarefas */
    TaskHandle_t xHandle;
     
    vTaskSuspend( xHandle );

 


    return 0;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        printf("Task jonatas testando kernel\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        printf("kernel foi\r\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void vTask3(void *pvParameters)
{
	for (int i = 0;i < 1; i++)
	{
		printf("kernel finalizado\r\n");
		vTaskDelay(pdMS_TO_TICKS(6000));

	}

}
