#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"


t_log* iniciar_logger(char* nombreDelArchivo, char* nombreDelProceso, bool estaLaConsolaActiva, t_log_level nivel);
t_config* iniciar_config(void);
void leer_consola(t_log*);
void paquete(int);
void terminar_programa(int, t_log*, t_config*);
void escribir_log(t_log* log, t_log_level level, char* mensaje);
#endif /* CLIENT_H_ */
