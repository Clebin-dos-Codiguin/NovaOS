#include <stdio.h>
#include <stdlib.h>

int main() {
    // Comando para bloquear todo tráfego ICMP (ping)
    char* command = "sudo iptables -A INPUT -p icmp -j DROP";
    
    // Executar o comando
    int result = system(command);
    
    if (result == -1) {
        printf("Erro ao executar o comando.\n");
        return 1;
    } else if (WEXITSTATUS(result) != 0) {
        printf("O comando falhou com status %d.\n", WEXITSTATUS(result));
        return 1;
    }

    printf("Regra de firewall adicionada com sucesso para bloquear ICMP.\n");
    
    // Mostrar regras atuais
    system("sudo iptables -L");

    return 0;
}
