Taller MPI
=====================
![malkam03](../malkam03.png) ![MPI](
mpi.png)   
Este es un repositorio informativo, con la información del taller de MPI que se realizó en la semana de computación 2017 del Tecnológico de Costa Rica. El taller busca transferir parte del conocimiento aprendido en la escuela de veranillo en HPC del CeNAT.

## Getting Started
En la [presentación](MPI-TALLER.pdf) del taller se puede encontrar los datos de la presentación que se usaron. Un resumen de las funciones de MPI se puede encontrar en la [hoja de "claves"](mpi-cheat-sheet.pdf) de MPI. Para este taller se utilizará mpich para manejar mpi. Para compilar los archivos se usa el comando mpicc y para correr mpirun:
```
mpicc main.c //compila y por defecto crea un archivo ejecutable a.out
mpirun -n 4 ./a.out //ejecuta el programa con 4 ranks
```

## Expositor

* **Malcolm Davis** - @[malkam03](https://github.com/malkam03)  

# Laboratorio 0 - Hola Mundo
El objetivo de este laboratorio es introducir la sintaxis de MPI con un hola mundo paralelo. Después de este laboratorio usted deberá ser capaz de crear, compilar y ejecutar un hola mundo en mpi. 
La solución de este laboratorio se puede encontrar en [soluciones/hello](soluciones/hello).

# Laboratorio 1
El objetivo de este laboratorio es introducir la comunicación entre ranks.  
En este laboratorio se debe de crear 2 programas. 
- Un ping pong paralelo que intercambie un número entero entre 2 procesos. El número se debe aumentar cada vez que el rank 1 lo reciba. Esto se debe de repetir 1000 veces.
- Crear un anillo de comunicación entre n procesos, que sume todos los aleatorio que se le asigne a cada rank. La comunicación sólo se puede dar con los ranks adyacentes.  
La solución de este laboratorio se puede encontrar en [soluciones/Lab1](soluciones/Lab1).


# Laboratorio 2
El objetivo de este lab es practicar la distribución de los datos entre los rancks. Se va a seguir el [template](template/par_identity.c)  preparado por Girotto.  
La solución de este laboratorio se puede encontrar en [soluciones/Lab2](soluciones/Lab2).

## Licencia
Este proyecto está licenciado bajo la licencia del MIT,  - ver [LICENSE.md](../LICENSE.md) para más detalles.


## Reconocimientos 
* http://netlib.org/ por el MPI Cheat Sheet.
* CNCA por los talleres en el CeNAT y el material. 
* I. Girotto por el material brindado.


## Descargo
Este repositorio es de mi propiedad [malkam03](https://github.com/malkam03), y aunque sea para un taller para la escuela de Computación del Tecnológico de Costa Rica, no es un sitio de información oficial de este ente, ni tampoco expresa las opiniones del mismo.
