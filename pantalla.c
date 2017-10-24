#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Pausa()
{
    /****************************************************************/
    /*Subprograma: Pausa.                    Tipo: Procedimiento.   */
    /*Prerrequisitos:                                               */
    /*Objetivo: Mostrar un mensaje de pausa y limpiar la pantalla.  */
    /****************************************************************/

    printf("Presione <intro> para continuar...");
    fflush(stdin);
    getchar();
    system("cls");
}



void MensajeBienvenida()
{
    /****************************************************************/
    /*Subprograma: MensajeBienvenida.         Tipo: Procedimiento.  */
    /*Prerrequisitos:                                               */
    /*Objetivo: Mostrar un mensaje de bienvenida.                   */
    /****************************************************************/

    printf("--> BIENVENIDO A LA APLICACION 'GESTION DE VIDEOS' <--\n\n");
}

void MensajeDespedida()
{
    /****************************************************************/
    /*Subprograma: MensajeDespedida.          Tipo: Procedimiento.  */
    /*Prerrequisitos:                                               */
    /*Objetivo: Mostrar un mensaje de despedida.                    */
    /****************************************************************/

    printf("Ha seleccionado la opcion 'Salir'.\n\n");
    printf("Gracias por utilizar nuestro programa.\n\n");
    printf("ADIOS!\n");
}
