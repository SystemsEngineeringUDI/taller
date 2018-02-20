#include <stdio.h>

/*
@autor:
 * Cesar villalobos
 * Estudiante: Ing.Sistemas UDI
*/

/* CASO 1: Cada nuevo termino de la serie de fibonacci es generado por la adicion de los terminos anteriores. Iniciando con 1,1, los primeros terminos son
1 1 2 3 5 8 13 21 34. Escriba un algoritmo que calcule la sumatoria de los números impares inferiores a un valor n dado por el usuario

CASO 2: Escriba un algoritmo que calcule la suma de los digitos del factorial de un numero n dado
por el usuario.

CASO 3: Un palindromo es un numero que se lee igual en ambas direcciones. el mayor palindromo
obtenido por la multiplicacion de dos numeros de dos digitos es:
9009 = 91 * 99
Encuentre el mayor palindromo que se obtiene como resultado de la multiplicacion de dos
numeros de tres digitos. */
 
int main(){
	int m;
	printf("Introduzca 1 para fibonacci, 2 para productoria y 3 para palindromo\n"); //Se pide la opción para entrar al switch
	scanf("%i",&m); // Se lee el numero
	int a=0,n,suma=1,b=1,c=0; //Declaraciones
	int l=1,f=1,o,sum=0;
	int num,resto,i,j,invertido=0,palindromo=0,pmayor=0,n1,n2;
	switch(m){
		case 1:
			printf("Ingrese el numero que desea establecer como limite\n");
			scanf("%i",&n);
			while(c<n){
				c=a+b; //Variable que guarda el digito siguiente de la serie
				a=b; //Variable que guarda el digito dos posiciones atrás en la serie correspondiente
				b=c; //Variable que guarda el digito una posición atrás de la serie correspondiente
				     /* para entender el comportamiento de este bucle hay que entender que en la serie 
				     las variables se van corriendo un puesto a la vez*/
				if(c%2!=0){ //Se analiza si el digito obtenido es impar 
					suma+=c; // De ser impar se guarda en un acumulador
				}
			} 
			printf("%i\n",suma); // Se imprime el acumulador						
		case 2:
			printf("Ingrese el numero a evaluar\n");
			scanf("%i",&o);
			while(f<=o){
				l*=f;
				f++; /*Una estructura sencilla para una productoria que se apoya en un contador que va aumentando 
				secuencialmente los numeros que se irán multiplicando hasta acabarse el bucle al llegar
				al numero pedido por el usuario*/
			}
			while(l>0){
				sum+=l%10; 
				l=l/10; /*Usando una acumulador se van sumando los digitos que van siendo descompuestos por la 
				estructura de control hasta que se satisfaga la condición*/
			}
			printf("%i\n",sum);
			return 0;			
		case 3:
			for(i=999;i>100;i--){
				for(j=i;j>=100;j--){ /*Se cubre el rango de todos los digitos de 3 cifras; se debe notar que
				                       una vez la variable i decrementa su valor a medida que el ciclo aumenta
				                       la variable j toma su valor para no perder tiempo de ejecución y no 
				                       repetir operaciones innecesariamente*/
					pmayor=0; 
					invertido=0;
					num=i*j; //Se hace el producto
					n=num; //Se guarda el valor en una variable temporal
					while(n!=0){
						resto=n%10;
						n=n/10; //Se realiza una descomposición básica de numeros en sus digitos
						invertido=invertido*10+resto;  //Y se guarda el numero anterior pero invertido
					}
					if(invertido==num){ //Se compara el numero y de ser igual se califica como palindromo
						palindromo=num;
						if(pmayor<=palindromo){ //Finalmente se ejecuta una tecnica de comparación para hallar el palindromo mayor
							pmayor=palindromo;
							n1=i;
							n2=j;
						}
					}
				}
			}					
	}	
	}
