// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Plantilla para el ejercicio de cálculo de PI
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include "fun_tiempo.h"

using namespace std ;

// ---------------------------------------------------------------------
// constante y variables globales (compartidas entre hebras)

const unsigned long m = long(1024)*long(1024) ;  // número de muestras (un millón)
const unsigned n      = 4 ;                      // número de hebras

double resultado_parcial[n] ; // tabla de sumas parciales (una por hebra)

// ---------------------------------------------------------------------
// implementa función $f$

double f( double x )       
{ 
   return 4.0/(1+x*x) ;     // $~~~~f(x)\,=\,4/(1+x^2)$
}
// ---------------------------------------------------------------------
// cálculo secuencial

double calcular_integral_secuencial( )
{  
   double suma = 0.0 ;                      // inicializar suma
   for( unsigned long i = 0 ; i < m ; i++ ) // para cada $i$ entre $0$ y $m-1$
      suma += f( (i+0.5)/m );               // $~~~~~$ añadir $f(x_i)$ a la suma actual

   return suma/m ;                          
}
// ---------------------------------------------------------------------
// función que ejecuta cada hebra

void * funcion_hebra( void * ih_void ) 
{  
   unsigned long ih = (unsigned long) ih_void ; // número o índice de esta hebra
   double sumap = 0.0 ;
   // calcular suma parcial en "sumap"
   for( unsigned long i = (m / n) * ih  ; i < (m / n)*ih + m/n ; i++)
        sumap += f( (i+0.5)/m );
   
   resultado_parcial[ih] = sumap ; // guardar suma parcial en vector.

   return NULL ;
}
// ---------------------------------------------------------------------
// cálculo concurrente

double calcular_integral_concurrente( )
{  

    double res_ent = 0.0;
   // crear y lanzar $n$ hebras, cada una ejecuta "funcion\_concurrente"
   pthread_t hebra[n];

   for(int i = 0; i < n; i++){
        void* argumento = (void*)i;       // Transformamos la i a void
        pthread_create(&hebra[i], NULL, funcion_hebra, argumento);
   }
   // esperar (join) a que termine cada hebra, sumar su resultado                            
   for(int j = 0; j < n; j++){
        pthread_join(hebra[j], NULL);
        res_ent += resultado_parcial[j];
   }
   // devolver resultado completo
   
   return res_ent/m ; // (cambiar)
}

// ---------------------------------------------------------------------

int main()
{
   cout << "Ejemplo 4 (cálculo de PI)" << endl ;
   double pi_sec = 0.0, pi_conc = 0.0 ;
   
    timespec inicio = ahora();
   pi_sec  = calcular_integral_secuencial() ;
    timespec fin = ahora();
    cout << "Tiempo transcurrido en secuencial == " << duracion( &inicio, &fin ) << " seg." << endl ;
     inicio = ahora();
   pi_conc = calcular_integral_concurrente() ;
     fin = ahora();
    cout << "Tiempo transcurrido en hebras == " << duracion( &inicio, &fin ) << " seg." << endl ;
   
   cout << "Valor de PI (calculado secuencialmente)  == " << pi_sec  << endl 
        << "Valor de PI (calculado concurrentemente) == " << pi_conc << endl ; 

   return 0 ;
}
// ---------------------------------------------------------------------



// ----------------------------------------------------------------------------
