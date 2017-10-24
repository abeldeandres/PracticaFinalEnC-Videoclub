#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "video.c"
#define TOTALVIDEOS 100


struct coleccion_videos
{
    struct video_t num_video[TOTALVIDEOS];
    int ultimo;
};

void inicializarArrayVideos( struct coleccion_videos *videos)
{
    /***********************************************************************************/
    /*Subprograma: inicializarArrayVideos.                        Tipo: Procedimiento. */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos.       */
    /*Objetivo: Inicializar (a cero) el array de videos.                               */
    /***********************************************************************************/

    videos->ultimo = 0; //ultimo = 0 significa que el array esta vacio.
}

int  buscar( struct coleccion_videos *videos, char codigo[5])
{
    /****************************************************************************************/
    /*Subprograma: buscar.                                   Tipo: Funcion.                 */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos y el codigo */
    /*                del video a buscar.                                                   */
    /*Objetivo: Inicializar (a cero) el array de videos.                                    */
    /****************************************************************************************/

    int indice;
	for (indice=0; indice< videos->ultimo; indice++)
	{
		if (strcmp (codigo, videos->num_video[indice].codigo)==0)
		{
			return indice;
		}
	}
	return 0;
}

void eliminarVideo( struct coleccion_videos *videos, int pos)
{
    /**********************************************************************************/
    /*Subprograma: eliminarVideo.                           Tipo: Procedimiento.      */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos y la  */
    /*                posicion del video a eliminar.                                  */
    /*Objetivo: Eliminar un video de la coleccion de videos.                          */
    /**********************************************************************************/

    int indice = 0;
    for ( indice = pos;  indice < videos->ultimo- 1; indice ++)
    {
        videos->num_video[indice] = videos->num_video[indice+1];
    }
    videos->ultimo = videos->ultimo - 1;
}


void rellenar( struct coleccion_videos *videos)
{
    /*****************************************************************************/
    /*Subprograma: rellenar.                           Tipo: Procedimiento.      */
    /*Prerrequisitos: Recibe una referencia a la estructura coleccion de videos. */
    /*Objetivo: Introducir unos videos en la coleccion de videos.                */
    /*****************************************************************************/

    strcpy( videos->num_video[0].codigo, "B123" );
    strcpy( videos->num_video[0].titulo, "tit 1");
    strcpy( videos->num_video[0].director, "dir 1");
    videos->num_video[0].anio = 2000;
    videos->num_video[0].prestado = 'N';

    strcpy( videos->num_video[1].codigo, "B124" );
    strcpy( videos->num_video[1].titulo, "tit 2" );
    strcpy( videos->num_video[1].director, "dir 2" );
    videos->num_video[1].anio = 2001;
    videos->num_video[1].prestado = 'N';

    strcpy( videos->num_video[2].codigo, "B125" );
    strcpy( videos->num_video[2].titulo, "tit 3"  );
    strcpy( videos->num_video[2].director, "dir 3"  );
    videos->num_video[2].anio = 2002;
    videos->num_video[2].prestado = 'S';
    videos->num_video[2].socio = 3000;
    strcpy( videos->num_video[2].fecha, "10/01/2013" );

    strcpy( videos->num_video[3].codigo, "B126" );
    strcpy( videos->num_video[3].titulo, "tit 2");
    strcpy( videos->num_video[3].director, "dir 2");
    videos->num_video[3].anio = 2001;
    videos->num_video[3].prestado = 'N';

    strcpy( videos->num_video[4].codigo, "B127" );
    strcpy( videos->num_video[4].titulo, "tit 3" );
    strcpy( videos->num_video[4].director, "dir 3" );
    videos->num_video[4].anio = 2002;
    videos->num_video[4].prestado = 'N';

    strcpy( videos->num_video[5].codigo, "B128" );
    strcpy( videos->num_video[5].titulo, "tit 3"  );
    strcpy( videos->num_video[5].director, "dir 3"  );
    videos->num_video[5].anio = 2002;
    videos->num_video[5].prestado = 'S';
    videos->num_video[5].socio = 3000;
    strcpy( videos->num_video[5].fecha, "23/12/2013" );

    strcpy( videos->num_video[6].codigo, "B129" );
    strcpy( videos->num_video[6].titulo, "tit 4");
    strcpy( videos->num_video[6].director, "dir 4");
    videos->num_video[6].anio = 1996;
    videos->num_video[6].prestado = 'N';

    strcpy( videos->num_video[7].codigo, "A345" );
    strcpy( videos->num_video[7].titulo, "tit 5" );
    strcpy( videos->num_video[7].director, "dir 5" );
    videos->num_video[7].anio = 1993;
    videos->num_video[7].prestado = 'N';

    strcpy( videos->num_video[8].codigo, "A897" );
    strcpy( videos->num_video[8].titulo, "tit 6"  );
    strcpy( videos->num_video[8].director, "dir 6"  );
    videos->num_video[8].anio = 1985;
    videos->num_video[8].prestado = 'S';
    videos->num_video[8].socio = 1447;
    strcpy( videos->num_video[8].fecha, "10/09/2013" );

    strcpy( videos->num_video[9].codigo, "C147" );
    strcpy( videos->num_video[9].titulo, "tit 7");
    strcpy( videos->num_video[9].director, "dir 7");
    videos->num_video[9].anio = 1994;
    videos->num_video[9].prestado = 'N';

    strcpy( videos->num_video[10].codigo, "F127" );
    strcpy( videos->num_video[10].titulo, "tit 8" );
    strcpy( videos->num_video[10].director, "dir 8" );
    videos->num_video[10].anio = 2001;
    videos->num_video[10].prestado = 'N';

    strcpy( videos->num_video[11].codigo, "F145" );
    strcpy( videos->num_video[11].titulo, "tit 10"  );
    strcpy( videos->num_video[11].director, "dir 10"  );
    videos->num_video[11].anio = 1998;
    videos->num_video[11].prestado = 'S';
    videos->num_video[11].socio = 8978;
    strcpy( videos->num_video[11].fecha, "10/10/2010" );

    strcpy( videos->num_video[12].codigo, "C147" );
    strcpy( videos->num_video[12].titulo, "tit 11");
    strcpy( videos->num_video[12].director, "dir 11");
    videos->num_video[12].anio = 1994;
    videos->num_video[12].prestado = 'S';
    videos->num_video[12].socio = 4587;
    strcpy( videos->num_video[12].fecha, "19/02/2005" );

    strcpy( videos->num_video[13].codigo, "Z369" );
    strcpy( videos->num_video[13].titulo, "tit 11" );
    strcpy( videos->num_video[13].director, "dir 11" );
    videos->num_video[13].anio = 2001;
    videos->num_video[13].prestado = 'N';

    strcpy( videos->num_video[14].codigo, "Q128" );
    strcpy( videos->num_video[14].titulo, "tit 12"  );
    strcpy( videos->num_video[14].director, "dir 12"  );
    videos->num_video[14].anio = 2000;
    videos->num_video[14].prestado = 'S';
    videos->num_video[14].socio = 1234;
    strcpy( videos->num_video[14].fecha, "15/05/2013" );

    strcpy( videos->num_video[15].codigo, "W187" );
    strcpy( videos->num_video[15].titulo, "tit 13"  );
    strcpy( videos->num_video[15].director, "dir 13"  );
    videos->num_video[15].anio = 1999;
    videos->num_video[15].prestado = 'S';
    videos->num_video[15].socio = 7896;
    strcpy( videos->num_video[15].fecha, "09/04/2000" );

    videos->ultimo = 15;
}
