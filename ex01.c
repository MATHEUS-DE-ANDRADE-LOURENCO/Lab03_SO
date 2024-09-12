#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    }
    else if (pid == 0) {
        // Código do processo filho
        printf("Sou o processo filho. Meu PID é %d\n", getpid());
        
        // Loop que imprime uma mensagem 5 vezes com intervalo de 1 segundo
        for (int i = 0; i < 5; i++) {
            printf("Mensagem %d do processo filho\n", i + 1);
            sleep(1);
        }
    }
    else {
        // Código do processo pai
        printf("Sou o processo pai. Meu PID é %d e o PID do meu filho é %d\n", getpid(), pid);
        
        // Aguarda o término do processo filho
        int status;
        waitpid(pid, &status, 0);
        
        printf("O processo filho terminou\n");
    }

    return 0;
}
