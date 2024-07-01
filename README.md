# Proyecto_Estructura

▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄

Para ejecutar el codigo hay que ejecutar este comando:

gcc -o TamaGucci.exe src/main.c src/functions/TDAs/hashmap.c src/functions/effect/effect.c src/functions/saves/save.c src/functions/TDAs/list.c src/functions/structs/structs.h resources/icon/icon.res src/interaction/games/games.c src/img/design.c src/interaction/shop/shop.c

luego acceder a la carpeta y abrir TamaGucci.exe.

▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄

Structs: El juego está simentado en un sistema de guardado basado principalmente en structs, donde se almacenaran todos los datos del juego:

Estructura que guarda el estado de la mascota y sus estadisticas.
```c
typedef struct Tamagotchi {
    float comida;       Nivel de alimentación actual
    float descanso;     Nivel de descanso actual
    float animo;        Nivel de animo actual
    bool dormido;       Indica si la mascota está dormida
    bool vivo;          Indica si la mascota sigue con vida
} Tamagotchi;
```
Estructura para representar los items almacenados
```c
typedef struct Item {
    char nombre[30];
    int restantes;
} Item;
```
Estructura para definir los efectos que tendrán las acciones u objetos en las estadísticas
```c
typedef struct Efecto {
    int alteracion_comida;      cantidad a modificar a la variable comida del Tamagochi
    int alteracion_descanso;    cantidad a modificar a la variable descanso del Tamagochi
    int alteracion_animo;       cantidad a modificar a la variable animo del Tamagochi
    int coste;                  Valor del objeto, sin coste en interacciones
    char tipo[30];              Tipo objeto / interacción
} Efecto;
```
Estructura para almacenar variables de juego 
```c
typedef struct Juego {
    Tamagotchi mascota;                 Tamagotchi en juego
    int dinero;                         Dinero de juego
    List mochila;                        Mochila de Items almacenados
    time_t ultima_actualizacion;         Hora de última actualización
    time_t ultima_palmadita;             Hora de última palmadita
    time_t ultimo_pago;                  Hora del último pago de dinero
    List caricias_ultima_hora;           Lista con las horas de las últimas caricias
} Juego;
```

▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄

TDA´s: Se utilizan 2, Hashmap (almacenado en las bibliotecas hashmap.c y hashmap.h), y lista (almacenado en list.c y list.h). Conservan el funcionamiento promedio de cualquier Tda de estos dos estilos:

Hasmap: 

Función para crear un nuevo par
```c
Pair * create_pair( char * key,  Efecto * value);
```
Función para crear e inicializar un mapa
```c
HashMap * create_map(long capacity);
```
Función para insertar un par clave-valor al mapa
```c
void insert_map(HashMap * map, char * key, Efecto * value);
```
Función para eliminar un par clave-valor del mapa
```c
void erase_map(HashMap * map,  char * key);
```
Función para buscar un par por su clave dentro del mapa
```c
Pair * search_map(HashMap * map,  char * key);
```
Función para retornar el primer par de un mapa
```c
Pair * first_map(HashMap * map);
```
Función para recorrer el siguiente elemento del mapa
```c
Pair * next_map(HashMap * map);
```
Función para redimensionar tamaño de una tabla
```c
void enlarge(HashMap * map);
```
------------------------------------------------------------------------------------------------------------------------------------

List:

Esta función crea una lista vacía y devuelve un puntero a la lista.
```c
List *list_create();
```
Esta función devuelve un puntero al primer elemento de la lista.
```c
void *list_first(List *L);
```
Esta función mueve el puntero de la lista al siguiente elemento y devuelve un puntero a dicho elemento.
```c
void *list_next(List *L);
```
Esta función inserta un nuevo elemento al inicio de la lista.
```c
void list_pushFront(List *L, void *dato);
```
Esta función inserta un nuevo elemento al final de la lista.
```c
void list_pushBack(List *L, void *dato);
```
Esta función inserta un nuevo elemento a continuación del actual de la lista.
```c
void list_pushCurrent(List *L, void *dato);
```
Esta función elimina el primer elemento de la lista.
```c
void *list_popFront(List *L);
```
Esta función elimina el último elemento de la lista.
```c
void *list_popBack(List *L);
```
Esta función elimina el elemento actual de la lista.
```c
void *list_popCurrent(List *L);
```
Esta función elimina todos los elementos de la lista.
```c
void list_clean(List *L);
```
Función para insertar ordenado de acuerdo a la función lower_than
```c
void list_sortedInsert(List *L, void *data,
                       int (*lower_than)(void *data1, void *data2));
```                       
▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄

FUNCIONAMIENTO DEL PROGRAMA.

El programa te llevará a un menú donde podrás elegir la opción que te interesa:
==================
 1) Acciones
 2) Abrir Inventario
 3) Abrir Tienda
 4) Dormir


El funcionamiento de este menú resulta sencillo, espera que ingreses uno de las 4 opciones y presiones enter.
```c
while (true) {

    ...
    
    scanf("%d", &opcion);
    while (getchar() != '\n');

        switch(opcion) {
            case 1:
                // Interacciones
                ...
            case 2:
                //Inventario
                ...
            case 3:
                //Tienda
                ...
            case 4:
                // Salir
                ...
            default:
                // Opción no válida
                ...
        }
    actualizar_estado(juego);
    guardar_estado(juego, filename);
}
```
cada opción tiene una función distinta auto descriptiva. Empezando por la primera(1), que nos llevara al menu de interacciones; la segunda(2), que nos dirigira al inventario; la tercera(3), que nos lleva a la tienda; y por ultimo una opcion para sali del menu de interacciones(4), que nos devuelve al menu anterior.

(1) ACCIONES:

 1) Jugar
 2) Acariciar
 3) Palmaditas
 4) Iluminacion
 5) Salir
```c
void menuInteracciones(HashMap * mapa_accion_efecto, Juego * juego) {

    ...

    switch(opcion) {
        case 1:
            //Jugar
            ...
        case 2:
            // Acariciar
            ...
        case 3:
            // Palmaditas
            ...
        case 4:
            ...
        case 5:
            //Salir
            ...
        default:
            // Opción no válida
            ...
        }
}
```
este menu de interacciones tiene varias opciones a nuestra disposicion, las explicaremos una a una:

(1.1). Jugar: accederas al juego de piedra papel y tijeras, donde una victoria representa ganar dinero y subir el animo de tu mascora. El codigo de este juego está implementado en las bibliotecas games.c y games.h .
(1.2). Acariciar: Se muestra la animacion predeterminada para el acariciado y se sube la estadistica de animo. Esta accion solo surte efecto un numero limitado de veces hasta pasado un tiempo.
(1.3). Palmaditas: Se muestra la animacion predeterminada para las palmaditas y se sube la estadistica de descanso. Esta accion solo surte efecto un numero limitado de veces hasta pasado un tiempo antes de ser contraproducente.

(1.4). Salir: te devuelve al menu principal.

------------------------------------------------------------------------------------------------------------------------------------

(2)INVENTARIO  (shop.c): 

El menú de inventario funciona gracias a un arreglo inicializado el cuál contiene los siete objetos pensados para el programa, los cuales serían: Pescado, Hamburguesa, Sushi, Caja de arena, Proteína, Redbull y finalmente una gata a domicilio, de los cuales cada ítem tiene sus pros y contrar respecto a las estadísticas que otorga a la mascota. El arreglo contiene tres variables, el nombre (string) la cantidad restante (int) y el coste (int).
```c
void menuInventario(Item lista[ARR_SIZE], Juego * juego, HashMap * mapa_acciones, Tamagotchi * mascota) {
  
    // Crear una lista temporal de objetos con restantes > 0
    Item listaTemp[ARR_SIZE];
    int numObjetos = 0;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (lista[i].restantes > 0) {
            strcpy(listaTemp[numObjetos].nombre, lista[i].nombre);
            listaTemp[numObjetos].coste = lista[i].coste;
            listaTemp[numObjetos].restantes = lista[i].restantes;
            numObjetos++;
        }
    }
}
```
El arreglo servirá tanto para el menú del inventario cómo para el menú de tienda, solo que habrán un par de condiciones para mostrar cada uno, por lo mismo, el arreglo es inicializado con todos los siete items existentes, y aquellos que no posea el usuario, quedarían con cantidad = 0.

En este caso, para el menú del inventario solo se imprimirán los objetos que posea el usuario, osea, todos los items cuya cantidad restante sean mayor a 0. Además, cuando selecciones uno de los objetos se consumirá, lo que es igual a aplicar el efecto del objeto y modificar las estadísticas de la mascota.

------------------------------------------------------------------------------------------------------------------------------------

(3) TIENDA: El menú de la tienda posee un funcionamiento muy parecido al del inventario, pero con un par de condiciones menos, ya que en vez de imprimir solo aquellos que tienen cantidad restante mayor a 0, aquí se imprimirán todos los items del arreglo, pero se ocultará la cantidad restante, por lo que se mostrarán todos los ítems disponibles (los inicializados en el arreglo), y su nombre.
````c
void menuTienda(Item lista[ARR_SIZE], Juego * juego) {
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("   ║ %2d) %-30s $%d  ║\n", i + 1, lista[i].nombre, lista[i].coste);
    }
    printf("   ║ %2d) %-30s     ║\n", ARR_SIZE + 1, "Salir");
    printf("   ╚════════════════════════════════════════╝\n");

    // Leer la opción del usuario
    int opcion;
    printf("\n   Selecciona una opción: ");

    if (scanf("%d", &opcion) != 1) {
        printf("\n   Error: entrada no válida. Saliendo de la tienda.\n");
        esperarInput2();
        return;
    }
}
````
Ahora, a diferencia del menú inventario, que consume un objeto cada vez que se selecciona, aquí se compraría un objeto, lo que es igual a incrementar por uno la cantidad restante del objeto en el arreglo.

------------------------------------------------------------------------------------------------------------------------------------