Solución Laboratorio 1
=============================
![malkam03](../imagenes/malkam03.png)
![CAS](../imagenes/CAS.jpg)
![junavarro](../imagenes/junavarro.png)
![Tec](../imagenes/tec.png)  
* En este laboratorio se debe de iniciar un repositorio local en una nueva carpeta.
    - Para iniciar un repositorio local, primero debemos crear la carpeta. Movernos a ella y por último inicializar el repo.
```
cd ..  //Para movernos una carpeta hacia atrás.
mkdir workdir //Crea una carpeta llamada workdir.
cd workdir  //Nos movemos a la carpeta recién creada.
git init //Inicializa un repositorio de git en la carpeta.
```
* Posteriormente se debe crear, agregar y subir al repositorio local un archivo de texto con un mensaje.
    -   Para esto, se puede crear cuálquier archivo con un editor de texto, agregarle datos y guardarlo en la carpeta workdir. O se puede hacer en terminal con los comandos:
```
nano hola-git-<nombre>.txt //Abre un editor de texto en terminal(OPCIÓN 1).
//Con esta opción hay que agregar un "Hola git soy <nombre>" en el editor, apretar ctrl+o para guadar y crtl+x para cerrar el editor.
echo "Hola git soy <nombre>" >> hola-git-<nombre>.txt //Le agrega el stream al un archivo nuevo(OPCIÓN 2).
```
    -   Para agregar el archivo al staging area:
```
git status //Para ver cambios realizados.
git add hola-git-<nombre>.txt //Para agregar el archivo al staging area.
```
    -   Para subir el archivo al repositorio LOCAL:
```
git status //Para ver cambios realizados.
git commit -m "Este es mi primer commit en git." //Para subir el archivo al repositorio LOCAL.
```
* Luego se volverá a modificar el archivo, se veran los cambios realizados desde el inicio y las diferencias con otros archivos.
    -   Para modificar el archivo tenemos las mismas opciones de antes.
```
nano hola-git-<nombre>.txt //Abre un editor de texto en terminal(OPCIÓN 1).
echo "ahora voy a agregar esta linea más." >> hola-git-<nombre>.txt //Le agrega el stream al un archivo nuevo(OPCIÓN 2). 
```
    -   Para ver los cambios realizados se usan los siguientes comandos:
```
git diff hola-git-<nombre>.txt // Para ver los cambios realizados en el archivo hola-git-<nombre>.txt.
git add hola-git-<nombre>.txt
git commit -m "Hicimos una modificación de prueba."
git log //Para ver los commits realizados hasta ahora
```
* Por último se va a agregar una dirección para el repositorio remoto.
    -   Para agregar el repositorio remoto usamos los siguientes comandos:
```
git remote add origin https://github.com/Taller-Git/CAS.git //Agrega el repositorio remoto para guardar los datos en la nube.
```
## Felicidades! Terminó el primer laboratorio! 