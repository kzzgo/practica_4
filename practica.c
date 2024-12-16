#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
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
}
