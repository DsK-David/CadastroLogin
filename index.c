#include <stdio.h>
#include <string.h>

#define TAMANHO_ARRAY 100
#define TAMANHO_MAXIMO_USUARIO 20
#define TAMANHO_MAXIMO_SENHA 20

struct Usuario {
    char usuario[TAMANHO_MAXIMO_USUARIO];
    char senha[TAMANHO_MAXIMO_SENHA];
};

int cadastrarUsuario(struct Usuario usuarios[], int numUsuarios) {
    if (numUsuarios == TAMANHO_ARRAY) {
        printf("Nao e possivel cadastrar mais usuarios.\n");
        return numUsuarios;
    }

    struct Usuario novoUsuario;

    printf("Digite o nome de usuario: ");
    fgets(novoUsuario.usuario, sizeof(novoUsuario.usuario), stdin);
    novoUsuario.usuario[strcspn(novoUsuario.usuario, "\n")] = '\0'; // Remove a quebra de linha

    printf("Digite a senha: ");
    fgets(novoUsuario.senha, sizeof(novoUsuario.senha), stdin);
    novoUsuario.senha[strcspn(novoUsuario.senha, "\n")] = '\0'; // Remove a quebra de linha

    usuarios[numUsuarios] = novoUsuario;

    printf("Usuario cadastrado com sucesso.\n");

    return numUsuarios + 1;
}

int realizarLogin(struct Usuario usuarios[], int numUsuarios) {
    char entrada[TAMANHO_MAXIMO_USUARIO + TAMANHO_MAXIMO_SENHA];
    char usuario[TAMANHO_MAXIMO_USUARIO];
    char senha[TAMANHO_MAXIMO_SENHA];

    printf("Digite o nome de usuario: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // Remove a quebra de linha

    printf("Digite a senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0'; // Remove a quebra de linha

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(entrada, usuarios[i].usuario) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            printf("Login realizado com sucesso.\n");
            return 1; // Login bem-sucedido
        }
    }

    printf("Nome de usuario ou senha incorretos.\n");
    return 0; // Login falhou
}
void mostrarUsuarios(struct Usuario usuarios[], int numUsuarios) {
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("- %s\n", usuarios[i].usuario);
    }
}


int main() {
    struct Usuario usuarios[TAMANHO_ARRAY];
    int numUsuarios = 0;
    int opcao;

    do {
        printf("1 - Cadastrar usuario\n");
        printf("2 - Realizar login\n");
        printf("3 - Mostrar usuarios cadastrados\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada antes de ler a opção
        while (getchar() != '\n')
            ;

        switch (opcao) {
            case 1:
                numUsuarios = cadastrarUsuario(usuarios, numUsuarios);
                break;
            case 2:
                realizarLogin(usuarios, numUsuarios);
                break;
            case 3:
                mostrarUsuarios(usuarios, numUsuarios);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        printf("\n");
    } while (opcao != 4);

    return 0;
}
