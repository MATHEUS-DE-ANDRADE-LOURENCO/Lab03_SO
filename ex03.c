# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) { 
        printf("\nHouve um erro na criação do processo.\n");
    } else if(pid == 0) {
        printf("\nProcesso filho:\n PID = %d;\n PPID = %d", getpid(), getppid());
        execl("/bin/ls", "ls", "-la", 0);
        printf("\nProcesso filho encerrado.");
    } else {
        printf("\nProcesso pai:\n PID = %d;\n PPID = %d", getpid(), getppid());
        sleep(1);
        printf("\nProcesso filho encerrado.");
    }
}
