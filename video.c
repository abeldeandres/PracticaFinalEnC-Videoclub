#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct video_t
{
    char codigo[5];
    char titulo[31];
    char director[26];
    int anio;
    char prestado;
    int socio ;
    char fecha[11];
};

char * Copiar( char *cadena, int desde, int elementos)
{
    /*******************************************************************/
    /*Subprograma: Copiar.                     Tipo: Funcion.          */
    /*Prerrequisitos: recibe la cadena a copiar, la posicion desde     */
    /*                donde quieres que copie y el numero de elementos */
    /*Objetivo: Copiar una cadena a otra.                              */
    /*******************************************************************/

    char c[100];
    int indice = 0;
    for ( indice = 0; indice+desde < strlen(cadena) && indice < elementos; indice++ )
    {
        c[indice] = cadena[desde+indice];
    }
    c[elementos] = '\0';
    return c;
}

char* MesDeVideo ( struct video_t video)
{
    /*******************************************************************/
    /*Subprograma: MesDeVideo.                     Tipo: Funcion.      */
    /*Prerrequisitos: recibe la estructura video.                      */
    /*Objetivo: Obtener el mes de alquiler a partir de la fecha.       */
    /*******************************************************************/

    char mes [3];
    mes[0] = video.fecha[3];
    mes[1] = video.fecha[4];
    mes[2] = '\0';
    return  mes;
}

int EsDigito ( int caracter)
{
    /*******************************************************************/
    /*Subprograma: EsDigito.                       Tipo: Funcion.      */
    /*Prerrequisitos: recibe un caracter.                              */
    /*Objetivo: Comprobar si el caracter es un numero.                 */
    /*******************************************************************/

    //printf( "%c", caracter);
    return ( (caracter >= '0') && (caracter <= '9'));
}

int EsCaracter ( int caracter )
{
    /*******************************************************************/
    /*Subprograma: EsCaracter.                     Tipo: Funcion.      */
    /*Prerrequisitos: recibe un caracter.                              */
    /*Objetivo: Comprobar si el caracter es una letra.                 */
    /*******************************************************************/

    //printf( "%c", caracter);
    return ( (caracter >= 'A') && (caracter <= 'Z'));
}

int validarCodigo ( char *codigo )
{
    /*******************************************************************/
    /*Subprograma: validarCodigo.                     Tipo: Funcion.   */
    /*Prerrequisitos: recibe una referencia al codigo.                 */
    /*Objetivo: Comprobar si el codigo tiene el formato especificado   */
    /*******************************************************************/

    int resultado = 0;
    resultado  = ( ( EsCaracter ( codigo[0])) &&
                   ( EsDigito( codigo[1])) &&
                   ( EsDigito( codigo[2])) &&
                   ( EsDigito( codigo[3]))
                  );
    return resultado;
}

int validarClave(char *clave)
{
    /***********************************************************************/
    /*Subprograma: validarClave.                      Tipo: Funcion.       */
    /*Prerrequisitos: recibe una referencia a la clave.                    */
    /*Objetivo: Comprobar que la clave tenga 4 caracteres y esté validada. */
    /***********************************************************************/

    do
    {
        printf("Introduzca la clave del video con el formato B123: ");
        fflush(stdin);
        gets( clave);
        //printf( "%s %d\n", clave, strlen(clave));
    }
    while ((strlen(clave) != 4) || (!validarCodigo(clave)));
    return 1;
}

int validarTitulo( char *titulo)
{
    do
    {
        printf("Introduzca el titulo de la pelicula: ");
        fflush(stdin);
        gets(titulo);
    }
    while(strlen(titulo) > 30);
    return 1;
}

int validarDirector( char *director)
{
    /*******************************************************************************/
    /*Subprograma: validarClave.                           Tipo: Funcion.          */
    /*Prerrequisitos: recibe una referencia al director.                           */
    /*Objetivo: Comprobar que el nombre del director tenga menos de 25 caracteres. */
    /*******************************************************************************/

    do
    {
        printf("Introduzca el nombre del director: ");
        fflush(stdin);
        gets(director);
    }
    while(strlen(director) > 25);
    return 1;
}

int validarAnio ( )
{
    /***************************************************************/
    /*Subprograma: validarAnio.                Tipo: Funcion.      */
    /*Prerrequisitos:                                              */
    /*Objetivo: Comprobar que el año este entre el 1980 y el 2013. */
    /***************************************************************/

    int anio;
    do
    {
        printf("Introduzca el anio: ");
        fflush(stdin);
        scanf("%d", &anio);
    }
    while( (anio < 1980 ) || (anio > 2013) );
    return anio;
}

