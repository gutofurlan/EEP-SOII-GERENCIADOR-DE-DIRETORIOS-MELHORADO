# EEP-SOII-GERENCIADOR-DE-DIRETORIOS-MELHORADO


### Funcionalidades Herdadas do projeto de SO I
Criar diretórios (mkdir)
Navegar pelos diretórios (cd dir, cd ..)
Remover diretórios (rmdir dir, diretórios devem estar vazios)
Entrar as entradas (ls)
Exibir posição na estrutura de diretórios (pwd)
Comandos devem ser digitados em uma linha de comando (prompt)
Estrutura de diretórios virtual criada em memória

### Novas Funcionalidades *USUÁRIOS*
Identificação do usuário para usar o software
Adicionar usuários (adduser username)
Remover usuários (deluser username)           
Bloquear usuários (lock username)                 
Desbloquear usuários (unlock username)       
Exibir informação do usuário (id username)
Encerrar a sessão (logout)
O usuário deve enxergar e manipular o seu diretório e abaixo dele

### Novas Funcionalidades *SISTEMA*
Encerrar o programa (poweroff)
Exibir a data (date)
Exibir a hora (time)
Exibir os nomes dos membros da equipe (copyright)

### Informações Complementares
Somente o root pode executar os comandos: adduser, deluser, lock, unlock e poweroff.
Não volatilidade da estrutura de diretórios e das contas de usuários.
Ao listar (ls) as entradas de um diretório deverá ser exibidas as seguintes informações.

/*
nome_diretório	data - hora	proprietário
nome_diretório	data - hora	proprietário
*/


### Dados sobre o usuário
username (até 8 caracteres/minúsculos)
nome_completo
estado

### Como rodar
cc main.c -o prog1
./prog1



