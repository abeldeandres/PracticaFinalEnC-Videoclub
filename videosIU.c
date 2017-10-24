#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccionVideos.c"
#include "pantalla.c"

void verVideo ( struct video_t video )
{
    /**************************************************************/
    /*Subprograma: verVideo.            Tipo: Procedimiento.      */
    /*Prerrequisitos: Recibe los datos de una estructura video.   */
    /*Objetivo: Presenta en pantalla los datos del video.         */
    /**************************************************************/

    printf("\nLos datos del video son los siguientes:\n");
    printf("\tCodigo: %s\n",video.codigo);
    printf("\tTitulo: %s\n",video.titulo);
    printf("\tDirector: %s\n",video.director);
    printf("\tAnio: %d\n",video.anio);
    printf("\tPrestado: %c\n",video.prestado);
    if ( video.prestado == 'S')
    {
        printf("\tSocio: %d\n",video.socio);
        printf("\tFecha: %s\n",video.fecha);
    }
}

void altaVideo( struct coleccion_videos *videos)
{
    /*******************************************************************************/
    /*Subprograma: altaVideo.                   Tipo: Procedimiento.               */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Dar de alta un video (introduciendo todas sus caracteristicas).    */
    /*******************************************************************************/

    struct video_t video;
    char pregunta;
    if ( videos->ultimo < TOTALVIDEOS)
    {
        validarClave( video.codigo);
        validarTitulo( video.titulo);
        validarDirector( video.director);
        video.anio = validarAnio();
        video.prestado = 'N';
        printf("Datos correctos? ");
        fflush(stdin);
        scanf("%c", &pregunta);
        if (pregunta == 'S')
        {
            //printf( "%d", *i);
            if ( !buscar(videos, video.codigo  ))
            {
                videos->num_video[videos->ultimo] = video;
                videos->ultimo = videos->ultimo + 1;
                printf("Los datos se guardaron exitosamente!");
            }

        }
        else
        {
            printf("Los datos no se guardaron correctamente!");
        }
    }
    else
    {
        printf("La lista de videos esta llena!");
    }
    Pausa();

}

void borrarVideo(struct coleccion_videos *videos)
{
    /*******************************************************************************/
    /*Subprograma: borrarVideo.                   Tipo: Procedimiento.             */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Dar de baja un video (introduciendo todas sus caracteristicas).    */
    /*******************************************************************************/

    //variables locales
    int pos;
    char resp;
    char codigoABorrar[5];

    system("cls");
    fflush(stdin);
    printf("Introduzca codigo de video a borrar: " );
    gets(codigoABorrar);
    pos = buscar(videos, codigoABorrar); //Llama a la funcion para buscar el video

    if (pos != -1)
    {
        system("cls");
        //Si encuentra la clave, muestra en pantalla los datos del video seleccionado
        verVideo( videos->num_video[pos]);
        printf("\tRealmente desea borrar el video(S/N)?\n");
        fflush(stdin);
        scanf("%c",&resp);
        //Antes de borrar el video se pregunta al usuario para ver si esta seguro, una vez responda que si, se borra el video
        if ((resp =='s')||(resp =='S'))
        {
            eliminarVideo( videos, pos);
            printf("El video ha sido borrado con exito\n");
            getch();
        }
        else
            {
                //return 0;
            }
        system("cls");
    }
    else
        {
            printf("\n\tLa clave del video no existe\n");
            getch();
            system("cls");
        }
}

int editarVideo( struct coleccion_videos *videos )
{
    /*******************************************************************************/
    /*Subprograma: editarVideo.                   Tipo: Funcion.                   */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Modificar las caracteristica de un video (salvo el codigo).        */
    /*******************************************************************************/

    //variables locales
    int pos;
    char resp;
    char videoAEditar [5];

    system("cls");
    fflush(stdin);
    printf("Introduczca la clave del video que quiera modificar: ");
    gets(videoAEditar);
    pos = buscar(videos,videoAEditar); //Llama a la funcion para buscar el video

    if (pos != -1)
        {
            struct video_t auxiliar = videos->num_video[pos] ;
            system("cls");
            verVideo( videos->num_video[pos] ) ;
            printf("\tRealmente desea modificar el video(S/N)?\n");
            fflush(stdin);
            scanf("%c",&resp);
            //Antes de modificar el video se pregunta al usuario para ver si esta seguro, una vez responda que si, se modifica el video
            if ((resp =='s')||(resp =='S'))
            {
                //Si el usuario da a la tecla s o S, procedera a introducir los nuevos datos del video, que seran almacenados en el struct
                printf("\n\tIntroduzca los nuevos datos del video");

                validarTitulo(auxiliar.titulo);
                validarDirector( auxiliar.director);
                validarAnio( auxiliar.anio);

                printf("\n\t  Esta seguro de cambiar los datos ? \n");
                fflush( stdin );
                char respuesta = getch();
                if ( respuesta == 'S') {
                    videos->num_video[pos]  = auxiliar;
                    printf("\n\t Los datos del video han sido modificados \n");
                    fflush( stdin );
                    getch();
                }
                system("cls");
            }
            else
                {
                return(0);
                }
           system("cls");
        }
        else
            {
                //Si la clave del video no ha sido encontrada, muestra un mensaje en pantalla para comunicarselo al usuario
                printf("\n\tLa clave del video no existe\n");
                getch();
                system("cls");
            }
}

void prestarVideo(struct coleccion_videos *videos)
{
    /*******************************************************************************/
    /*Subprograma: prestarVideo.                   Tipo: Procedimiento.            */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Prestar un video (introduciendo la clave).                         */
    /*******************************************************************************/

    //variables locales
    int pos;
    char resp;
    char codigoAPrestar[5];
    char fechaPrestamo[11];
    int socioPrestamo;

    system("cls");
    fflush(stdin);
    printf("Introduzca codigo de video a prestar: " );
    gets(codigoAPrestar);
    pos = buscar(videos, codigoAPrestar); //Llama a la funcion para buscar el video

    if (pos != -1)
    {
        system("cls");
        //Si encuentra la clave, muestra en pantalla los datos del video seleccionado
        verVideo( videos->num_video[pos]);
        printf("\tRealmente desea prestar el video(S/N)?\n");
        fflush(stdin);
        scanf("%c",&resp);
        //Antes de prestar el video se pregunta al usuario para ver si esta seguro, una vez responda que si, se presta el video
        if (((resp =='s')||(resp =='S'))&& (videos->num_video[pos].prestado == 'N'))
        {
            printf("\nIntroduzca la fecha del prestamo: ");
            fflush(stdin);
            scanf("%s", &fechaPrestamo);
            //printf("%s", fechaPrestamo);
            strcpy(videos->num_video[pos].fecha, fechaPrestamo);

            printf("\nIntroduzca la clave del socio a prestar: ");
            fflush(stdin);
            scanf("%d", &socioPrestamo);
            //printf("%d", socioPrestamo);
            videos->num_video[pos].socio = socioPrestamo;

            videos->num_video[pos].prestado = 'S';

            printf("\nEl video ha sido prestado con exito\n");
            getch();
        }
        else
            {
                //return 0;
            }
        system("cls");
    }
    else
        {
            printf("\n\tLa clave del video no existe\n");
            getch();
            system("cls");
        }
}

void devolverVideo(struct coleccion_videos *videos)
{
    /*******************************************************************************/
    /*Subprograma: devolverVideo.                   Tipo: Procedimiento.           */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Devolver un video (introduciendo la clave).                        */
    /*******************************************************************************/

    //variables locales
    int pos;
    char resp;
    char codigoADevolver[5];

    system("cls");
    fflush(stdin);
    printf("Introduzca codigo de video a devolver: " );
    gets(codigoADevolver);
    pos = buscar(videos, codigoADevolver); //Llama a la funcion para buscar el video

    if (pos != -1)
    {
        system("cls");
        //Si encuentra la clave, muestra en pantalla los datos del video seleccionado
        verVideo( videos->num_video[pos]);
        printf("\tRealmente desea devolver el video(S/N)?\n");
        fflush(stdin);
        scanf("%c",&resp);
        //Antes de devolver el video se pregunta al usuario para ver si esta seguro, una vez responda que si, se devuelve el video
        if (((resp =='s')||(resp =='S'))&& (videos->num_video[pos].prestado == 'S'))
        {
            videos->num_video[pos].prestado = 'N';
            printf("\nEl video ha sido devuelto con exito\n");
            getch();
        }
        else
            {
                //return 0;
            }
        system("cls");
    }
    else
        {
            printf("\n\tLa clave del video no existe\n");
            getch();
            system("cls");
        }
}

void buscarVideo  ( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: buscarVideo.                   Tipo: Procedimiento.           */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Buscar y Mostrar los datos de un video (salvo el codigo).        */
    /*****************************************************************************/

    //variables locales
    int pos;
    char resp;
    char videoAEditar[5];

    system("cls");
    fflush(stdin);
    printf("Introduzca la clave del video que quiera buscar: ");
    gets(videoAEditar);
    pos = buscar(videos,videoAEditar); //Llama a la funcion para buscar el video

    if (pos != -1)
        {
            struct video_t auxiliar = videos->num_video[pos] ;
            system("cls");
            verVideo( videos->num_video[pos] ) ;
        }
    else
    {
        printf("Error video no encontrado");
    }
}

void mostrar ( struct coleccion_videos *videos)
{
    /*******************************************************************************/
    /*Subprograma: mostrar.                   Tipo: Procedimiento.                 */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.   */
    /*Objetivo: Presenta en pantalla un listado con los datos de todos los videos. */
    /*******************************************************************************/

	int i=0;
	printf("    LISTADO GENERAL DE VIDEOS   \n");
    printf("\n\nClave      Titulo              Director      Anio   Prestado   Fecha      Socio\n");
    printf("________________________________________________________________________________\n");
	for (i=0; i<videos->ultimo; i++){
		printf ("%4s %15s %15s %10d %5c",    videos->num_video[i].codigo,
                                             videos->num_video[i].titulo,
                                             videos->num_video[i].director,
                                             videos->num_video[i].anio,
                                             videos->num_video[i].prestado);
		if ( videos->num_video[i].prestado == 'S' )
		{
            printf ("%20s %4d", videos->num_video[i]. fecha, videos->num_video[i].socio);
        }
        else {
            printf ("              ---------" );
        }
        printf ("\n");
	}
}

void mostrarVideosNoPrestados ( struct coleccion_videos *videos)
{
    /**************************************************************************************/
    /*Subprograma: mostrarVideosNoPrestados.                     Tipo: Procedimiento.     */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.          */
    /*Objetivo: Presenta en pantalla un listado con los datos de los videos no prestados. */
    /**************************************************************************************/

	int i=0;
	printf("    LISTADO DE VIDEOS NO PRESTADOS   \n");
    printf("\n\nClave      Titulo                Director        Anio\n");
    printf("_________________________________________________________\n");
	for (i=0; i<videos->ultimo; i++){
	    if ( videos->num_video[i].prestado == 'N' )
		{
            printf ("%4s %15s %15s %10d",   videos->num_video[i].codigo,
                                            videos->num_video[i].titulo,
                                            videos->num_video[i].director,
                                            videos->num_video[i].anio);
        }
        printf ("\n");
	}
}

void mostrarVideosPrestados ( struct coleccion_videos *videos)
{
    /***********************************************************************************/
    /*Subprograma: mostrarVideosPrestados.                       Tipo: Procedimiento.  */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.       */
    /*Objetivo: Presenta en pantalla un listado con los datos de los videos prestados. */
    /***********************************************************************************/

	int i=0;
	printf("    LISTADO DE VIDEOS PRESTADOS   \n");
    printf("\n\nClave      Titulo              Director      Anio   Prestado   Fecha      Socio\n");
    printf("________________________________________________________________________________\n");
	for (i=0; i<videos->ultimo; i++){
	    if ( videos->num_video[i].prestado == 'S' )
	    {
            printf ("%6s %22s %15s %5d   %c    %10s    %4d",    videos->num_video[i].codigo,
                                                                videos->num_video[i].titulo,
                                                                videos->num_video[i].director,
                                                                videos->num_video[i].anio,
                                                                videos->num_video[i].prestado,
                                                                videos->num_video[i].fecha,
                                                                videos->num_video[i].socio);
        }
        printf ("\n");
	}
}

void mostrarImporteUnMes ( struct coleccion_videos *videos)
{
    /***************************************************************************************/
    /*Subprograma: mostrarImporteUnMes.                        Tipo: Procedimiento.        */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.           */
    /*Objetivo: Presenta en pantalla el importe total que ha percibido la asociacion en el */
    /*          mes y anio especificados por el usuario.                                   */
    /***************************************************************************************/

    char Mes[3];
    char Anio[5];
    int videosPrestadosEnElMes = 0;
    int indice = 0;
    fflush(stdin);
    printf("Introduzca mes ( mm ): " );
    gets(Mes);
    printf("Introduzca Anio ( aaaa ): " );
    gets(Anio);
    for ( indice = 0; indice < videos->ultimo; indice ++)
    {
        char mesDelPrestamo [3];
        char AnioDelPrestamo [5];
        strcpy( mesDelPrestamo, MesDeVideo( videos->num_video[indice]));
        strcpy( AnioDelPrestamo, Copiar( videos->num_video[indice].fecha, 6,4));


        if ( ( videos->num_video[indice].prestado == 'S' ) &&
               (strcmp(Mes, mesDelPrestamo ) == 0) &&
                (strcmp(Anio, AnioDelPrestamo ) == 0)
            )
               videosPrestadosEnElMes = videosPrestadosEnElMes + 1;
    }
    printf("El importe el mes %s del anio %s es de %d Euros. ", Mes, Anio, videosPrestadosEnElMes * 5 );
    printf("\n\n");
}

void mostrarImporteTotal ( struct coleccion_videos *videos)
{
    /**********************************************************************************/
    /*Subprograma: mostrarImporteTotal.                  Tipo: Procedimiento.         */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.      */
    /*Objetivo: Presenta en pantalla el importe total que ha percibido la asociacion. */
    /**********************************************************************************/

    int videosPrestados = 0;
    int indice = 0;
    fflush(stdin);

    for ( indice = 0; indice < videos->ultimo; indice ++)
    {
        if ( videos->num_video[indice].prestado == 'S' )
            videosPrestados = videosPrestados + 1;
    }
    printf("El importe total es de %d Euros. ", videosPrestados * 5 );
    printf("\n\n");
}
