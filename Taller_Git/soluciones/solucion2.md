Solución Laboratorio 2
=============================
![malkam03](../imagenes/malkam03.png)
![CAS](../imagenes/CAS.jpg)
![junavarro](../imagenes/junavarro.png)
![Tec](../imagenes/tec.png)  
* Primero se deben de descargar los cambios que otros realizaron en el repositorio.
    - Una vez que tenemos la dirección del repositorio remoto podemos descargar con:
```
git pull origin master //Descarga los datos del repositorio remoto.
```
* Posteriormente se debe modificar este archivo [README](README.md) agregando sus datos a la tabla de asistentes.
    -   Para esto, en la sección de la tabla, se debe de agregar el nombre, el correo, un emoji (ver [emoji-cheat-sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet/)) y una frase que se le venga a la mente.
* Luego se agregaran los cambios al repositorio y se corregiran los errores.   
    -   Para agregar los cambios al repositorio :
```
git status
git add README.md 
git commit -m "Acabo de agregar mi nombre al repo." 
git push origin master //Envia los cambios del repo local al repo remoto
```
    -   Si no fue el primero en subir la modificación del archivo va a tener errores, para solucionarlos debe de realizar este proceso hasta que tenga éxito:
```
git pull origin master //Descarga los cambios realizados por el otro
//Editar el archivo para que ambos cambios se mantengan
git add README.md 
git commit -m "Acabo de resolver los conflictos." 
git push origin master //Envia los cambios del repo local al repo remoto
```
## Felicidades! Terminó el segundo laboratorio! 

# BONUS
Flujo de trabajo de git:
```
git branch <nombre> //Crea un nuevo Branch
git checkout <nombre> //Se mueve a ese branch
git add <file> 
git commit -m "Message"
git push --set-upstream origin <nombre> //Crea el branch en el remoto
git checkout master 
git merge <nombre> //Une los cambios del branch con el master
```