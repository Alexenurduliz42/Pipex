
                    ██████╗ ██╗██████╗ ███████╗██╗  ██╗
                    ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
                    ██████╔╝██║██████╔╝█████╗   ╚███╔╝ 
                    ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ 
                    ██║     ██║██║     ███████╗██╔╝ ██╗
                    ╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝

---
# Pipex

    Este proyecto es una implementación del comando `pipe` en el lenguaje de programación C.

## Descripción

El comando `pipe` permite redirigir la salida de un programa a la entrada de otro programa, utilizando el operador de tuberías (`|`). Este proyecto busca replicar esta funcionalidad utilizando el lenguaje C.

Equivalente a escribir en shell `<infile> << <cmd1> | <cmd2> >> <outfie>`


## Instalación

- Compilador de C gcc o cc.
 ``` bash
 #Instalación en MAC
 curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh

 brew install gcc
```
```Bash
#Instalación en Linux
sudo apt-get install gcc

```
## Uso

Para compilar el programa, ejecuta el siguiente comando:
- Descargamos repositorio

- Ejecutamos Makefile para compilar el programa

- Aparecera un archivo binario `pipex`.

- Lo ejecutamos de la siguiente manera:
```Bash
# infile        -> Debemos darle un archivo de entrada
# cmd1, cmd2    -> comandos de bash a ejecutar
# outfile       -> Archivo dado o generado donde graba el resultado
./pipex <infile> <cmd1> <cmd2> <outfie>
```
