#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Erro ao criar o processo filho\n");
        exit(1);
    }

    if (pid > 0) {
        // Processo pai
        printf("Processo pai - PID: %d\n", getpid());
        printf("Processo filho - PID: %d\n", pid);
        
        int status;
        wait(&status);
        printf("O processo filho terminou\n");
    } else {
        // Processo filho
        printf("Eu sou o processo filho - PID: %d\n", getpid());
        
        for (int i = 0; i < 5; i++) {
            printf("Mensagem do filho: %d\n", i + 1);
            sleep(1);
        }
    }

    return 0;
}
