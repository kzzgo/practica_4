#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
//FUNCIO MY_TEE    
    // Comprovar arguments
    if (argc != 2) {
        printf(stderr, "Ús: %s <nom_arxiu>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Crear el fitxer amb permisos específics
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("Error creant el fitxer");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_llegits;

    // Llegir i escriure dades
    while ((bytes_llegits = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        // Escriure a la sortida estàndard
        if (write(STDOUT_FILENO, buffer, bytes_llegits) == -1) {
            perror("Error escrivint a la sortida estàndard");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Escriure al fitxer
        if (write(fd, buffer, bytes_llegits) == -1) {
            perror("Error escrivint al fitxer");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_llegits == -1) {
        perror("Error llegint de l'entrada estàndard");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Tancar el fitxer
    if (close(fd) == -1) {
        perror("Error tancant el fitxer");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;


//FUNCIO MY_CMP
    char arxiu1 = argv[1];
    char arxiu2 = argv[2];
    int descripcio_arxiu1 = open(arxiu1, O_RDONLY);
    int descripcio_arxiu2 = open(arxiu2, O_RDONLY);
    if (arxiu1 == -1 || arxiu2 == -1) {
        printf ("error en obrir l'arxiu")
        
    }
    else {
    while (read(descrpicio_arxiu1, , size_t count) < 0;){
        int lectura_arxiu1 = read(descrpicio_arxiu1, , size_t count)
        int lectura_arxiu2 = read(descrpicio_arxiu2, , size_t count)
        //cada cop que hi ha un return linies +=1
        //s'ha de tenir en compte que passa quan un arxiu s'acaba i l'altre no
        //s'ha de pensar bé que retorna en cada cas (bytes iguals / bytes diferents)

    }
    }
}
