#include <stdio.h>
#include <stdlib.h>


FILE * CrearFichero ( char *RutaConNombre)
{
    /*************************************************************/
    /*Subprograma: CrearFichero.                Tipo: Funcion.   */
    /*Prerrequisitos: Recibe la ruta donde se creara el fichero. */
    /*Objetivo: Crear un fichero de texto.                       */
    /*************************************************************/

    return fopen( RutaConNombre, "wt");
}

FILE * AbrirFichero ( char * RutaConNombre)
{
    /********************************************************/
    /*Subprograma: AbrirFichero.         Tipo: Funcion.     */
    /*Prerrequisitos: Recibe la ruta donde esta el fichero. */
    /*Objetivo: Abrir un fichero de texto.                  */
    /********************************************************/

    return fopen( RutaConNombre, "rt");
}

FILE * AniadirFichero ( char * RutaConNombre)
{
    /********************************************************/
    /*Subprograma: AniadirFichero.       Tipo: Funcion.     */
    /*Prerrequisitos: Recibe la ruta donde esta el fichero. */
    /*Objetivo: Modificar un fichero de texto.              */
    /********************************************************/

    return fopen( RutaConNombre, "at");
}

FILE * LecturaEscrituraFichero ( char * RutaConNombre)
{
    /********************************************************/
    /*Subprograma: LecturaEscrituraFichero.  Tipo: Funcion. */
    /*Prerrequisitos: Recibe la ruta donde esta el fichero. */
    /*Objetivo: Abrir un fichero de texto para lectura.     */
    /********************************************************/

    return fopen( RutaConNombre, "r+t");
}

FILE* AperturaFichero( char *RutaConNombre, char *ModoApertura )
{
    /********************************************************/
    /*Subprograma: AperturaFichero.         Tipo: Funcion.  */
    /*Prerrequisitos: Recibe la ruta donde esta el fichero  */
    /*                y el modo de apertura.                */
    /*Objetivo: Abrir un fichero con un modo determinado.   */
    /********************************************************/

    return fopen( RutaConNombre, ModoApertura);
    /* Ruta : las barras invertidas han de ser dobles */

    /* Modo de Apertura :
        r : solo lectura : apertura de entrada
        w : solo escritua : apertura de salida
        a : añade al final : apertura de salida

        b: Binario
        t: texto
    */
    /* Ejemplo   AbrirFichero ( "c:\\ejemplo\\fichero.txt", "r+t"); abre el fichero en modo texto para lectura y escritura */
}

int CerrarFichero( FILE *descriptor)
{
    /********************************************************/
    /*Subprograma: CerrarFichero.           Tipo: Funcion.  */
    /*Prerrequisitos: Recibe un fichero descriptor.         */
    /*Objetivo: Cerrar un fichero.                          */
    /********************************************************/

    return (fclose( descriptor ) == 0 );  /* 0 - si cierra correctamente, cualquier otro valor si no ha cerrado */
}

int GrabarRegistroBinario( void *reg, FILE *Out, int tamanioRegistro)
{
    /********************************************************/
    /*Subprograma: GrabarRegistroBinario.    Tipo: Funcion. */
    /*Prerrequisitos: Recibe un registro, un fichero de     */
    /*                salida y el tamanio del registro.     */
    /*Objetivo: Grabar un registro en un fichero binario.   */
    /********************************************************/

    return (fwrite( reg, tamanioRegistro, 1, Out) > 0 );
}

int LeerRegistroBinario( void *reg, FILE *In,  int tamanioRegistro )
{
    /********************************************************/
    /*Subprograma: LeerRegistroBinario.      Tipo: Funcion. */
    /*Prerrequisitos: Recibe un registro, un fichero de     */
    /*                entrada y el tamanio del registro.    */
    /*Objetivo: Leer un registro de un fichero binario.     */
    /********************************************************/

    return (fread( reg, tamanioRegistro, 1, In) > 0 );
}

int PosicionarEnRegistro ( FILE *descriptor, int NuevaPosicion , int tamanioRegistro)
{
    /*********************************************************/
    /*Subprograma: PosicionarEnRegistro.     Tipo: Funcion.  */
    /*Prerrequisitos: Recibe un fichero descriptor, la nueva */
    /*                posicion y el tamanio del registro.    */
    /*Objetivo: Colocar el cursor en un registro.            */
    /*********************************************************/

    return ( fseek( descriptor, NuevaPosicion * tamanioRegistro, SEEK_SET) == 0);
}

long NumeroRegistros ( FILE *descriptor, int tamanioRegistro )
{
    /********************************************************/
    /*Subprograma: NumeroRegistros.     Tipo: Funcion.      */
    /*Prerrequisitos: Recibe un fichero descriptor y el     */
    /*                tamanio del registro.                 */
    /*Objetivo: Indicar el numero de registros del fichero. */
    /********************************************************/

    long int posicionActual = ftell( descriptor);
    fseek( descriptor, 0L, SEEK_END);
    long registros =  ftell( descriptor)/ tamanioRegistro;
    fseek( descriptor, posicionActual, SEEK_SET);
    return registros;
}
