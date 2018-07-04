
int main() {
  char matriz[TAM][TAM], op_fim_jogo = 'S', op, op2, jogador1[tam_nome_jogador],
  jogador2[tam_nome_jogador];
  int i, alguem_ganhou, starter;
  do {
  system("cls");
  limpa_matriz(matriz);
  printf("Bem vindo ao jogo da velha.\n");
  do {
    printf("1 - Jogador x Jogador.\n2 - Jogador x Computador.\nDigite 1 ou 2: ");
    op = getche();
    if (op != '1' && op != '2') {
      printf("Opcao invalida.\n");
    }
  } while (op != '1'; && op != '2');
  switch (op) {
      case '1':
    system("cls");
    printf("Digite nome do jogador 1: ");
    preencher_nome_jogador(jogador1);
    system("cls");
    printf("Digite o nome do jogador 2: ");
    preencher_nome_jogador(jogador2);
    system("cls");
    comecar_jogo(&starter);
    printf("O jogador %d iniciara o jogo.\n", starter);
    tabela(matriz);

  alguem_ganhou = jogo_da_velha(matriz, starter, op, op2);
  if (alguem_ganhou == 1) {
    printf("Jogador %s vence.\n", jogador1);
  }
  else if (alguem_ganhou == 2){
    printf("Jogador %s vence.\n", jogador2);
  }
  else {
    printf("Empate.\n");
  }
  break;
  
     case '2':
    system("cls");
    printf("Digite o nome do jogador: ");
    preencher_nome_jogador(jogador1);
    system("cls");
    printf("1 - Facil.\n2 - Medio: \n");
    scanf( %c, &op2);
    switch (op2) {
    case '1':
    comecar_jogo(&starter);
    tabela(matriz);
    alguem_ganhou = jogo_da_velha(matriz, starter, op, op2);
    if (alguem_ganhou == 1) {
      printf("Jogador %s vence.\n", jogador1);
    }
    else if (alguem_ganhou == 2) {
      printf("CPU vence.\n");
    }
    else {
      printf("Empate.\n");
    }
    break;

    case '2:
    comecar_jogo(&starter);
    tabela(matriz);
    alguem_ganhou = jogo_da_velha(matriz, starter, op, op2);
    if (alguem_ganhou == 1) {
      printf("Jogador %s vence.\n", jogador1);
    }
    else if (alguem_ganhou == 2) {
      printf("CPU vence.\n");
    }
    else {
      printf("Empate.\n");
    }
    break;
  }

}
  printf("Deseja jogar novamente?(S/N): ");
  scanf(%c, &op_fim_jogo);
  } while (op_fim_jogo != 'N');
  return 0;
}//fim do main
