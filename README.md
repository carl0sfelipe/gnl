Get Next Line (GNL)
Get Next Line (GNL) é um projeto da École 42 que visa criar uma função em C para ler linhas de texto de um arquivo, um descritor de arquivo ou a entrada padrão (stdin), até encontrar uma quebra de linha (\n) ou o final do arquivo. Essa função é uma ferramenta valiosa para a manipulação de arquivos e streams de dados em projetos futuros.

🚀 Funcionalidades
Lê linhas de texto de arquivos, descritores de arquivo ou entrada padrão (stdin)
Detecta e retorna linhas individuais, incluindo a quebra de linha (\n)
Gerencia a leitura de várias linhas em sequência
Alocação dinâmica de memória
A função é compatível com a biblioteca padrão C e utiliza funções básicas de manipulação de arquivos e memória
🛠️ Instalação
Para utilizar a função Get Next Line em seu projeto, siga os passos abaixo:

Clone este repositório em sua máquina local:
bash
Copy code
git clone https://github.com/carl0sfelipe/gnl.git
Copie os arquivos get_next_line.c, get_next_line.h, e get_next_line_utils.c para a pasta do seu projeto.

No arquivo .c onde você deseja usar a função Get Next Line, inclua o cabeçalho da seguinte forma:

c
Copy code
#include "get_next_line.h"
Compile seu projeto juntamente com os arquivos da função Get Next Line. Por exemplo:
bash
Copy code
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 seu_arquivo.c get_next_line.c get_next_line_utils.c -o seu_programa
⚠️ Atenção: Certifique-se de definir o BUFFER_SIZE ao compilar o projeto. O valor pode ser ajustado de acordo com suas necessidades e restrições de desempenho. Recomenda-se usar potências de 2, como 32, 64 ou 128.

📖 Uso
A função Get Next Line possui a seguinte assinatura:

c
Copy code
int get_next_line(int fd, char **line);
fd: O descritor de arquivo a partir do qual a linha deve ser lida. Pode ser um arquivo aberto ou 0 para a entrada padrão (stdin).
line: Um ponteiro para uma string onde a linha lida será armazenada.
A função retorna:

1 quando uma linha foi lida com sucesso
0 quando o final do arquivo foi alcançado
-1 em caso de erro
Exemplo de uso:

c
Copy code
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
´´´
int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line) > 0)
        {
            printf("%s\n", line);
            free(line);
        }
        close(fd);
    }
    return (0);
}´´´
