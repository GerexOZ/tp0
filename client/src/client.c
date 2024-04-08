#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger("tp0.log","CLIENTE",1,LOG_LEVEL_INFO);
	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	escribir_log(logger, logger->detail, "Hola soy un log");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config("cliente.config");

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'
	ip = config_get_string_value(config,"IP");
	valor = config_get_string_value(config, "CLAVE");
	puerto = config_get_string_value(config, "PUERTO");
	// Loggeamos el valor de config
	escribir_log(logger, LOG_LEVEL_INFO,ip);
	escribir_log(logger, LOG_LEVEL_INFO,valor);
	escribir_log(logger, LOG_LEVEL_INFO,puerto);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}
//otra solcuion seria obtener un puntero de log (log->t_log_level) en el switch sacando el parametro del medio
void escribir_log(t_log* log, t_log_level level, char* mensaje){
	switch (level)
	{
	case LOG_LEVEL_INFO:
		log_info(log, mensaje);
		break;
	case LOG_LEVEL_DEBUG:
		log_debug(log, mensaje);
		break;
	case LOG_LEVEL_ERROR:
		log_error(log, mensaje);
		break;
	case LOG_LEVEL_TRACE:
		log_trace(log, mensaje);
		break;
	case LOG_LEVEL_WARNING:
		log_warning(log, mensaje);
		break;
	default:
		printf("Pusiste un tipo de log incorrecto!");
		break;
	}
}

t_log* iniciar_logger(char* nombreDelArchivo, char* nombreDelProceso, bool estaLaConsolaActiva, t_log_level nivel)
{
	t_log* nuevo_logger = log_create(nombreDelArchivo,nombreDelProceso,estaLaConsolaActiva,nivel);

	return nuevo_logger;
}

t_config* iniciar_config(char *direccion)
{
	t_config* nuevo_config = config_create(direccion);

	return nuevo_config;
}


void leer_consola(t_log* logger)
{
	char* leido;

	
	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while (strcmp(leido, "\0")){
		leido = readline("> ");

		if(!leido) break;
		printf("%s\n", leido);
		escribir_log(logger, LOG_LEVEL_INFO, leido);
		
	}
	free(leido);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	log_destroy(logger);
	config_destroy(config);
}
