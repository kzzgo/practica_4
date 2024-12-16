#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
//FUNCIO MY_CMP

    char arxiu1 = argv[1];
    char arxiu2 = argv[2];
    int descripcio_arxiu1 = open(arxiu1, O_RDONLY);
    int descripcio_arxiu2 = open(arxiu2, O_RDONLY);
    if (arxiu1 == -1 || arxiu2 == -1) {
        printf ("error en obrir l'arxiu");
        
    }
    else {
    while (read(descrpicio_arxiu1, , ssize_t count) < 0;){
        int lectura_arxiu1 = read(descrpicio_arxiu1, buffer, ssize_t count);
        int lectura_arxiu2 = read(descrpicio_arxiu2, , ssize_t count);
        //cada cop que hi ha un return linies +=1
        //s'ha de tenir en compte que passa quan un arxiu s'acaba i l'altre no
        //s'ha de pensar bé que retorna en cada cas (bytes iguals / bytes diferents)

    }
    }
}