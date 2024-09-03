# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) printf("\nHouve um erro na criação do processo.");
    if (pid == 0){
        printf("\nPROCESSO FILHO: pid = %d; pai = %d", getpid(), getppid());
        printf("\nFIM DO PROCESSO FILHO");
    }
    else {
        printf("\nPROCESSO PAI: pid = %d; pai = %d", getpid(), getppid());
        sleep(1);
        printf("\nFIM DO PROCESSO PAI");
    } 
}