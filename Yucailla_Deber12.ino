/*
 * DEBER 12
 * YUCAILLA VIVIANA
 */

#include "datos.h"

// datos de prueba
int datos_prueba [5]={1,4,4,2,2};
//cambio de variable
int respuesta;
int knn (int k, int etiquetas, int tam_col, int col_fil); // definir la func
void setup() {
Serial.begin(9600);
respuesta=knn(3,3,5,131);
switch(respuesta){
  case 1:
    Serial.println(" CARRO REGULAR");
  break;
  case 2:
    Serial.println("CARRO BUENO");
  break;
   case 3:
    Serial.println("CARRO MUY BUENO");
  break;
  }
}

void loop() {
}

int knn (int k, int etiquetas, int tam_col, int tam_fil){
int col;
int fil=0;
int i=0;
int j;

int aux;
int aux_etiqueta;
int potencia;
int raiz;
int label;
String salida="";
/*  
 *   matriz de k-vecinos
 *   |1   |2   |3  | -> # vecinos mas cercanos
 *   | 1  |   1| 2 | -> etiqueta correspondiente
 *   |0.12|0.18|025|-> valor de las k distancias menores
 */
 int matriz_k [3][k];
 for(;i<k;i++){
  matriz_k[0][i]=i+1.00;  //  |   1 |   2   |   3   |
  matriz_k[1][i]=0; //     |  0  |   0   |   0   |
  matriz_k[2][i]=2500.0+i;// |2500 | 25001 | 25002 | 
  }
  i=0;
 /*
  *  matriz de etiquetas
  *  |1  |2  |3  | -> # de etiquetas
  *  |2  |1  |0  | -> el conteo de cada una de ellas con respecto a matriz k_vecinos   
  */
  int matriz_eti[2][etiquetas];
  for(;i<etiquetas;i++){
      matriz_eti[0][i]=i+1.0; // |  1 |  2 |  3  |
      matriz_eti[1][i]=0.0;   // |  0 |  0 |  0  |
    }

   for(;fil<tam_fil;fil++){
      for(col=0;col<tam_col-1;col++){ // menos la ultima columna que corresponde a la etiqueta
          potencia=potencia+pow(matriz[fil][col]-datos_prueba[col],2);
        }
        raiz=sqrt(potencia);
        potencia=0;
        // comparacion de la nueva distancia con solo la mayor distancia almacenada en matriz_k
        if(raiz<matriz_k[2][k-1]){
          matriz_k[2][k-1]=raiz;
          matriz_k[1][k-1]=matriz[fil][tam_col-1]; 
          // ordenar matriz por metodo de burbuja
          for(i=0;i<k;i++){
             for(j=i+1;j<k;j++){
               if(matriz_k[2][i]>matriz_k[2][j]){
                 // distancia
                  aux=matriz_k[2][i];
                  matriz_k[2][i]=matriz_k[2][j];
                  matriz_k[2][j]=aux;
                  //etiqueta
                  aux_etiqueta=matriz_k[1][i];
                  matriz_k[1][i]=matriz_k[1][j];
                  matriz_k[1][j]=aux_etiqueta;
                }//end if
              } //end for j
            } // end for i
        } // end if
    } // end lectura matriz.h
    //buscar etiqueta con mayor repitencia
    for(i=0;i<etiquetas;i++){
      for(j=0;j<k;j++){
          if(matriz_eti[0][i]==matriz_k[1][j]){
            matriz_eti[1][i]++;
          }
        }
      }

    for(i=0;i<etiquetas-1;i++){
       if(matriz_eti[1][i]<matriz_eti[1][i+1]) // buscar el valor menor entre conteo de etiquetas
        label=(int)matriz_eti[0][i+1];    //asgina a label la etiqueta de mayor valor
        else 
        label=(int)matriz_eti[0][i];      //asgina a label la etiqueta de mayor valor
      }  
 return label;
};
