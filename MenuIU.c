#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "videosIU.c"
#include "FicheroStruct.c"
#define FicheroVideos "VIDEOS.DAT"


void SubMenuMantenimiento( struct coleccion_videos *videos )
{
    /*****************************************************************************/
    /*Subprograma: SubMenuMantenimiento.             Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Presenta en pantalla el submenu de mantenimiento.                */
    /*****************************************************************************/

    int opcion1;
    do{
        printf("\n----------SUBMENU MANTENIMIENTO----------\n");
        printf("1.- Alta de un video.\n");
        printf("2.- Baja de un video.\n");
        printf("3.- Modificar los datos de un video.\n");
        printf("4.- Prestar un video.\n");
        printf("5.- Devolver un video.\n");
        printf("0.- Volver al menu principal.\n\n");

        printf("Elija Opcion: ");
        scanf("%d",&opcion1);

        system("cls");

        switch(opcion1)
        {
            case 1:
                printf("Ha seleccionado la opcion 'Alta de un video'.\n\n");
                altaVideo(videos);
                Pausa();
                break;

            case 2:
                printf("Ha seleccionado la opcion 'Baja de un video'.\n\n");
                borrarVideo(videos);
                Pausa();
                break;

            case 3:
                printf("Ha seleccionado la opcion 'Modificar los datos de un video'.\n\n");
                editarVideo(videos);
                Pausa();
                break;

            case 4:
                printf("Ha seleccionado la opcion 'Prestar un video'.\n\n");
                prestarVideo(videos);
                Pausa();
                break;

            case 5:
                printf("Ha seleccionado la opcion 'Devolver un video'.\n\n");
                devolverVideo(videos);
                Pausa();
                break;

            case 0:
                break;

            default:
                printf("Opcion incorrecta. Intentelo de nuevo.\n\n");
                Pausa();
                break;
        }
    }
        while (opcion1 != 0);
}

void SubMenuListados( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: SubMenuListados.                  Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Presenta en pantalla el submenu de listados.                     */
    /*****************************************************************************/

    int i=0;
    int opcion2;
    do{
        printf("\n----------SUBMENU LISTADOS----------\n");
        printf("1.- Listado general.\n");
        printf("2.- Listado de videos no prestados.\n");
        printf("3.- Listado de videos prestados.\n");
        printf("4.- Busqueda de un video.\n");
        printf("5.- Importe total registrado en un mes concreto.\n");
        printf("6.- Importe total registrado.\n");
        printf("0.- Volver al menu principal.\n\n");

        printf("Elija Opcion: ");
        scanf("%d",&opcion2);

        system("cls");

        switch(opcion2)
        {
            case 1:
                printf("Ha seleccionado la opcion 'Listado general'.\n\n");
                mostrar(videos);
                Pausa();
                break;

            case 2:
                printf("Ha seleccionado la opcion 'Listado de videos no prestados'.\n\n");
                mostrarVideosNoPrestados(videos);
                Pausa();
                break;

            case 3:
                printf("Ha seleccionado la opcion 'Listado de videos prestados'.\n\n");
                mostrarVideosPrestados(videos);
                Pausa();
                break;

            case 4:
                printf("Ha seleccionado la opcion 'Busqueda de un video'.\n\n");
                buscarVideo(videos);
                Pausa();
                break;

            case 5:
                printf("Ha seleccionado la opcion 'Importe total registrado en un mes concreto'.\n\n");
                mostrarImporteUnMes (videos);
                Pausa();
                break;

            case 6:
                printf("Ha seleccionado la opcion 'Importe total registrado'.\n\n");
                mostrarImporteTotal(videos);
                Pausa();
                break;

            case 0:
                break;

            default:
                printf("Opcion incorrecta. Intentelo de nuevo.\n\n");
                Pausa();
                break;

        }
    }
    while (opcion2 != 0);
}

void menuPrincipal( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: menuPrincipal.                    Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Presenta en pantalla el menu principal.                          */
    /*****************************************************************************/

    int opcion = 0;

    do
    {
        MensajeBienvenida();
        printf("\n----------MENU----------\n");
        printf("1.- Mantenimiento.\n");
        printf("2.- Listados.\n");
        printf("0.- Terminar.\n\n");

        printf("Elija Opcion: ");
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
                case 1:
                    SubMenuMantenimiento(videos);
                    Pausa();
                    break;

                case 2:
                    SubMenuListados(videos);
                    Pausa();
                    break;

                case 0:
                    MensajeDespedida();
                    break;

                default:
                    printf("Opcion incorrecta. Intentelo de nuevo.\n\n");
                    Pausa();
                    break;
        }
    }
    while (opcion != 0);
}


void grabarFichero ( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: grabarFichero.                    Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Abre, graba los registros de videos y cierra el fichero.         */
    /*****************************************************************************/

    FILE *fichero = fopen( "VIDEOS.DAT", "wb" );
    if ( fichero == NULL)
    {
        return ;
    }
    int indice ;
    for ( indice = 0; indice < videos->ultimo; indice ++)
    {
        fwrite( videos->num_video[indice], sizeof(videos->num_video[indice]), 1, fichero);
    }
    CerrarFichero(fichero); //fclose (fichero);
}


void leerFichero ( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: leerFichero.                      Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Abre, lee el fichero y luego le cierra.                          */
    /*****************************************************************************/

    FILE *fichero = fopen( "VIDEOS.DAT", "rb" );
    if ( fichero == NULL)
    {
        return ;
    }
    int registros = NumeroRegistros(fichero, sizeof( struct video_t));
    int indice;
    for ( indice = 0 ; indice < registros; indice ++ )
    {
        fread( &videos->num_video[indice], sizeof(videos->num_video[indice] ), 1,  fichero);
    }
    videos->ultimo = registros;
    fclose(fichero);
}
