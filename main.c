#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenuIU.c"


/*********************************************************************************
Alumno1: Monjas de Mercado Diego       Alumno2: de Andres Gomez Abel
Grupo: 02                              Fechas: Desde el 14-05-13 hasta el 02-06-13
**********************************************************************************/

int main()
{
    struct coleccion_videos videos;
    inicializarArrayVideos(&videos);
    rellenar(&videos);
    leerFichero(&videos);
    menuPrincipal(&videos);
    grabarFichero(&videos);
    return 0;
}
