# push_swap


<div align="center">
	<h1> Push_swap </h1>
	<p>Swap_push no suena tan natural</p>
	<img src="https://wakatime.com/badge/user/a0e860d2-9914-4fed-8143-b9fd5cf5e6c1/project/ff5bed0a-6c31-4609-95c8-643947ff70d3.svg?style=flat"/>
	<br />
	<img src="https://img.shields.io/badge/norme-OK-success?style=flat"/>
	<img src="https://img.shields.io/badge/leaks-Clear!-success?style=flat"/>
	<img src="https://img.shields.io/badge/-107%2F100-inactive?style=flat&logo=42&logoColor=000" />
</div>

<h2 align="center">📜 PROYECT DESCRIPTION 📜</h2>

El objetivo de este proyecto es crear un algoritmo que ordene números aleatorios en el menor número de movimientos posibles y utilizando solo
una lista concreta de movimientos (sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb). El objetivo de este proyecto es aprender a manejar 
algoritmos de ordenación.

<h2 align="center">🌲 PROYECT TREE 🌲</h2>

```Bash
.
├── Makefile
├── README.md
├── include/
│   ├── push_swap.h
│   └── push_swap_bonus.h
├── objs/
├── libft/
├── pyviz.py
└── src/
    ├── checker/
    │   ├── checker.c
    │   ├── checkerpush.c
    │   ├── checkerrotate.c
    │   ├── checkerrrotate.c
    │   └── checkerswap.c
    ├── chunksort.c
    ├── argumentscheck.c
    ├── main.c
    ├── push.c
    ├── rotate.c
    ├── rrotate.c
    ├── smallsort.c
    ├── stack_management.c
    ├── supersort.c
    └── swap.c

```

<h2 align="center">🚶🏻‍♂️ PROYECT ROADMAP 🚶</h2>

<h3 align="center"> 🧠 PREVIOUS BRAINSTORM</h3>

*  Crear una estructura para cada stack
*  Incluir en la estructura lo necesario
*  Informarse sobre algoritmos que sirvan en el proyecto y elegir uno
*  Implementar las operaciones en el código

<h2 align="center">⚙️ PROYECT GENERAL PROCEDURE ⚙️</h2>

Lo primero que hace el programa es pasar los argumentos a un array de strings. Si los argumentos se han recibido como un solo string entre comillas, los argumentos pasaran mediante la función split. Si los argumentos se han recibido ya como un array de punteros, lo unico que se hace es pasar el primer string (que es el nombre del programa).

 <h3 align="center"> 🔍 Comprobación de argumentos </h3>

Toda esta parte del proyecto esta dentro del archivo `argumentscheck.c`, la función principal de este archivo es `check_arguments`, que pasa por todos los numero en un bucle, ahí se comprueba que cada argumento sea un número (`ft_isnumber`, una modificación del atoi que en vez de devolver el numero devuelve verdadero o falso), compruebe que el numero no esté repetido (`ft_isrepeated`, función que va por los números previos y devuelve false si encuentra uno repetido) y comprueba que el número no sea mayor que el máximo entero.

<h3 align="center"> 🔢 Agregar los números al stack A </h3>
Después de comprobar que los números son válidos, es momento de inicializar los stacks, llenando el stack A con los números recibidos y dejando el stack B vacio.

Vamos a ver primero cómo esta hecha la estructura del stack y a entender un poco que es cada parte:

```C
typedef struct s_stack
{
	int	numbers[1024];
	int	top;
	int	size;
}	t_stack;
```
El stack tiene tres partes básicas: Un array de 1024 caracteres (el máximo), un entero `top` que indica el número de números que hay dentro de este stack y un entero `size` (que realmente solo se usa para saber cuantos números nos han enviado y así saber qué algoritmo usar)

Una vez visto esto ya podemos ver como se inicializan y se llenan los stacks. Esto esta dentro del archivo `stack_management.c`. Ahí nos encontramos la función `initialize_stack_a`, que va recogiendo los números desde el final hasta el principio y los va añadiendo a nuestro array numbers. 

**¿Porqué metemos los números desde el final?**

Hacemos eso para que así el primer número se quede en la posicion numbers[top], haciendo que a la hora de trabajar con los stacks sea más facil.

Además de esto también iniciamos a 0 el stack B.

 <h3 align="center"> ⚙️ Algoritmos </h3>

 Después de haber pasado los argumentos al stack A, llega el momento de ordenarlos, hay dos funciones principales que se encargan de ordenarlos de una forma u otra en función de la cantidad de números que tengamos. Si tenemos menos de 6 usaremos la función `smallsort`, si por el contrario tenemos más números, pasamos a usar la función `supersort`. 

 <h4> ▪ smallsort </h4>

Dentro de esta parte hay que dividir a su vez en la cantidad de números que tenemos:

- 2️⃣ números: En caso de que no esten ordenados, hacemos *sa*.
- 3️⃣ números: La función `sort3` tiene los algoritmos para cada combinación posible.
- 4️⃣ números: Pasamos el número más pequeño de A a B (de forma optimizada) y aplicamos el `sort3`, despues devolvemos el más pequeño de vuelta.
- 5️⃣ números: Usamos la función `sort5`, lo que hace esta función es pasar los dos números más pequeños al stack B, aplicar la función `sort3` en los restantes y devolver los dos que se sacaron previamente.
- 6️⃣ números: Pasamos el más pequeño al stack B y aplicamos `sort5`.

 <h4> ▪ supersort </h4>
 El algoritmo usado en esta parte es el mismo, independientemente de la cantidad de números recibidos. Usaremos una modificación del <a href="https://en.wikipedia.org/wiki/Insertion_sort"> insertion sort algorithm</a>. La base de nuestro algoritmo es ir pasando al stack B números que formen parte de un chunk de números y luego ir devolviendo el más grande al stack A. Vamos a verlo más en profundidad:

- Primero se calcula el tamaño que va a tener cada chunk, para ello se coje el mayor número y se divide entre la cantidad de chunks a usar.

- Después de eso se ajustan los valores de comienzo y final del primer chunk. El valor de inicio será el menor número que tengamos y el final sera `start + size` una vez ajustado eso, pasamos a la función `chunksrt`. 

- La función `chunksrt` se encarga de, mientras siga habiendo números que pertenezcan a ese chunk (`still_chunk`), buscar desde el principio y el final del stack números pertenecientes al chunk y, despues de comprobar cual de los dos números encontrados cuesta menos pushear al stack B, lo hace.

- La función `supersort` va creando unos nuevos valores de chunk_start y chunk_end hasta que se llegue al número más alto. 

- Por ultimo, se pushean al Stack principal todos los números. Para ello se usan dos funciones que busquen el mayor número del stack B y se comprueba si el menor gasto de movimientos es llevarlo abajo o arriba. Una vez este en la posicion que queremos, pushea el número y busca el nuevo mayor número. Se hace esto hasta que el top del stack B esté a -1, de forma que se ha vaciado por completo el Stack B.

Despues de haber ordenado el stack A, solo queda cerrar el programa liberando la memoria de ambos stacks.

 <h3 align="center"> ➕ Parte bonus </h3>

 El bonus de este proyecto consiste en crear nuestro propio checker, de forma que escriba por pantalla OK si el programa funciona correctamente y KO si el programa no funciona correctamente. Para hacer este checker hacemos una función que vaya cogiendo las instrucciones que hace nuestro programa (usando la función `get_next_line` con el fd 0 ) y ir haciendo en el propio checker los movimientos. Si al terminar de leer lo que ha mostrado por pantalla el programa el stack A está ordenado, significa que ha funcionado correctamente.

  <h3 align="center"> 📊 pyviz </h3>

  Además de el proyecto, se incluye tambien un programa en python llamado pyviz que funciona como un visualizer. El creador de este programa es un compañero de 42 llamado <a href="https://github.com/o-reo/push_swap">eruaud</a>, el uso del visualizer es muy simple. Usamos el siguiente script:
  ```Bash
  python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
  ```
  y se abrira una ventana donde, de forma visual, podemos ver como se aplican los movimientos que muestra por pantalla nuestro programa.

  <h3 align="center"> 🤝 CREDITOS 🤝 </h3>

  Para sacar adelante este proyecto he utilizado como ayuda un <a href="https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a">artículo de medium </a> que explica como llevar a cabo el proyecto usando este algoritmo. También es muy util el repositorio de <a href="https://www.github.com/leogaudin/push_swap"> @leogaudin </a>, donde explica a la perfección su código.
