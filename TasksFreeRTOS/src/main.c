/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t Task3_Handle;


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
    xTaskCreate(&vTask3, "tudo ok", 1024, NULL, 1, &Task3_Handle);

    vTaskStartScheduler(); /** inicia o agendador de tarefas */
     
    return 0;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        printf("Task jonatas testando kernel\r\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void vTask2(void *pvParameters)
{
    int i = 0; 
    for (;;)
    {
        printf("Task kernel esta funcionando\r\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
	if(i == 2)
	{
	   vTaskResume(Task3_Handle);
	   i-=2;
	}
	i++;
    }
}

void vTask3(void *pvParameters)
{
	for (;;)
	{
		printf("tudo ok\r\n");
		vTaskDelay(pdMS_TO_TICKS(2000));
		vTaskSuspend(Task3_Handle);
	}


}
