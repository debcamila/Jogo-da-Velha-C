
void preencher_nome_jogador(char jogador[]) {
  int i;
  for (i = 0; i &lt; tam_nome_jogador; i++) {
    jogador[i] = getche();
    if (jogador[i] == 13) {
      break;
    }
  }
jogador[i] = '\0';
}

void comecar_jogo(int *starter) {
  srand(time(0));
  *starter = 1 + (rand() % 2);
}

void conversao(char i_char, char j_char, int *i, int *j) {
  *i = i_char - 48;
  *j = j_char - 48;
}

int jogo_da_velha(char matriz[][TAM], int starter, char op, char op2) {
  int aux = starter, i, j, eh_dig, alguem_ganha = 0, verificador_vitoria,i_jogada_cpu, j_jogada_cpu;
  char i_char, j_char;
  limpa_matriz(matriz);
  
  while (alguem_ganha == 0 && alguem_ganha != 3) {
    if (op == '1') {
      if (aux == 1 ){
      do {
        printf("Jogador %d.\nDigite a linha: ", aux);
        scanf("%c", &i_char);
        printf("\nDigite a coluna: ");
        scanf("%c",&j_char);
        eh_dig = eh_numero(i_char, j_char);
        conversao(i_char, j_char, &i, &j);
        i = i - 1;
        j = j - 1;
      } while (matriz[i][j] == 'X'|| matriz[i][j] == 'O' || eh_dig == 0);
        
        matriz[i][j] = 'X';
        system("cls");
        tabela(matriz);
        alguem_ganha = vitoria_jogador1(matriz);
        if (alguem_ganha == 1) {
          break;
        }
        alguem_ganha = empate(matriz);
        if (alguem_ganha == 3) {
          break;
        }
        aux++;
        }else {
          do {
            printf("\nJogador %d.\nDigite a linha: ", aux);
            scanf("%c", &i_char);
            printf("\nDigite a coluna: ");
            scanf("%c", &j_char);
            eh_dig = eh_numero(i_char, j_char);
            conversao(i_char, j_char, &i, &j);
            i = i - 1;
            j = j - 1;
          } while (matriz[i][j] == 'X' || matriz[i][j] == 'O' || eh_dig == 0);
          matriz[i][j] = 'O';
          system("cls");
          tabela(matriz);
          alguem_ganha = vitoria_jogador2(matriz);
          if (alguem_ganha == 2) {
            break;
          }
          alguem_ganha = empate(matriz);
          if (alguem_ganha == 3) {
            break;
          }
          aux--;
          }
      }
      if (op == '2') {
        if (op2 == '1') {
          if (aux == 1) {
            do {
              printf("\nJogador %d.\nDigite a linha: ", aux);
              scanf("%c", &i_char);
              printf("\nJogador %d.\nDigite a linha: ", aux);
              scanf(" %c", &i_char);
              printf("\nDigite a coluna: ");
              scanf(" %c", &j_char);
              eh_dig = eh_numero(i_char, j_char);
              conversao(i_char, j_char, &i, &j);
              i = i - 1;
              j = j - 1;
            } while (matriz[i][j] == 'X' || matriz[i][j] == 'O' || eh_dig == 0);
              matriz[i][j] = 'X';
              system("cls");
              tabela(matriz);
              alguem_ganha = vitoria_jogador1(matriz);
              if (alguem_ganha == 1) {
              break;
        }
        alguem_ganha = empate(matriz);
        if (alguem_ganha == 3) {
          break;
        }
        aux++;
        }
        else {
          printf("Jogada da CPU.");
          Sleep(3000);
          system("cls");
          posicao_aleatoria_cpu(matriz);
          tabela(matriz);
          alguem_ganha = vitoria_jogador2(matriz);
          if (alguem_ganha == 2) {
          break;
          }
          alguem_ganha = empate(matriz);
          if (alguem_ganha == 3) {
             break;
          }
          aux--;
        }
      }
      else {
        if (aux == 1) {
          do {
            printf("\nJogador %d.\nDigite a linha: ", aux);
            scanf(" %c", &i_char);
            printf("\nDigite a coluna: ");
            scanf(" %c", &j_char);
            eh_dig = eh_numero(i_char, j_char);
            conversao(i_char, j_char, &i, &j);
            i = i - 1;
            j = j - 1;
          } while (matriz[i][j] == 'X' || matriz[i][j] == 'O' || eh_dig == 0);
          matriz[i][j] = 'X';
          system("cls");
          tabela(matriz);
          alguem_ganha = vitoria_jogador1(matriz);
          if (alguem_ganha == 1) {
          break;
        }
        alguem_ganha = empate(matriz);
        if (alguem_ganha == 3) {
        break;
        }
        aux++;
      }
      else {
        printf("Jogada da CPU.");
        Sleep(3000);
        system("cls");
        verificador_vitoria = verifica_jogada_cpu(matriz, &i_jogada_cpu, &j_jogada_cpu);
        if (verificador_vitoria == 0) {
          posicao_aleatoria_cpu(matriz);
        }else {
          i = i_jogada_cpu;
          j = j_jogada_cpu;
          matriz[i][j] = 'O';
        }
        tabela(matriz);
        alguem_ganha = vitoria_jogador2(matriz);
        if (alguem_ganha == 2) {
          break;
        }
        alguem_ganha = empate(matriz);
        if (alguem_ganha == 3) {
          break;
        }
        aux--;
        }
      }
    }
  }
  return alguem_ganha;
}

void limpa_matriz(char matriz[][tam_matriz]) {
  int i,j;
  for (i = 0; i < tam_matriz; i++) {
    for (j = 0; j < tam_matriz; j++) {
      matriz[i][j] = ' ';
    }
  }
}

void posicao_aleatoria_cpu(char matriz[][TAM]) {
  int i;
  int j;
  srand(time(0));
  i = rand() % 3;
  j = rand() % 3;
  while (matriz[i][j] == 'X' || matriz[i][j] == 'O') {
    i = rand() % 3;
    j = rand() % 3;
  }
  matriz[i][j] = 'O';
}

void tabela(char matriz[][tam_matriz]) {
  int l, k;
  for (l = 0; l < tam_matriz; l++) {
    for (k = 0; k < tam_matriz; k++) {
      if (k == 0) {
      printf("%c |", matriz[l][k]);
      }
      if (k == 1) {
        printf(" %c ", matriz[l][k]);
      }
      if (k == 2) {
        printf("| %c", matriz[l][k]);
      }
    }
    printf("\n_____________\n");
  }
}
 
int verifica_jogada_cpu(char matriz[][tam_matriz], int *i_cpu_nivel_medio, int *j_cpu__nivel_medio) {
  int verificação, i, j, k, aux = 0, jogador_pc = 1;
  if (jogador_pc == 1) {
  aux = 0;
  for (i = 0; i <tam_matriz; i++) { // verificação por linha
    for (j = 0; j < tam_matriz; j++) {
      if (matriz[i][j] == 'O') {
        aux++;
      }
      if (aux == 2) {
        break;
      }
    }
    if (aux == 2) {
      break;
    }
    else {
      aux = 0;
    }
  }
  if (aux == 2) {
    for (j = 0; j < tam_matriz; j++) {
      if (matriz[i][j] == ' ') {
        *i_cpu_nivel_medio = i;
        *j_cpu__nivel_medio = j;
        return 1;
      }
    }
  }
  aux = 0;
  for (j = 0; j <tam_matriz; j++) { // verificação por coluna
      for (i = 0; i < tam_matriz; i++) {
        if (matriz[i][j] == 'O') {
          aux++;
        }
        if (aux == 2) {
          break;
        }
      }
      if (aux == 2) {
        break;
      }
      else {
        aux = 0;
      }
    }
    if (aux == 2) {
       for (i = 0; i < tam_matriz; i++) {
          if (matriz[i][j] == ' ') {
          *i_cpu_nivel_medio = i;
          *j_cpu__nivel_medio = j;
          return 1;
          }
      }
    }
    aux = 0;
    j = 0;
    for (i = 0; i <tam_matriz; i++) { // verificação por diagonal principal
        if (matriz[i][j] == 'O') {
        aux++;
        }
        j++;
    }
    j = 0;
    if (aux == 2) {
      for (i = 0; i < tam_matriz; i++) {
        if (matriz[i][j] == ' ') {
        *i_cpu_nivel_medio = i;
        *j_cpu__nivel_medio = j;
        return 1;
        }
        j++;
       }
      }
      aux = 0;
      j = 2;
      for (i = 0; i < tam_matriz; i++) { // verificação por diagonal secundaria
      if (matriz[i][j] == 'O') {
        aux++;
      }
       j--;
     }
     j = 2;
      if (aux == 2) {
        for (i = 0; i < tam_matriz; i++) {
            if (matriz[i][j] == ' ') {
            *i_cpu_nivel_medio = i;
            *j_cpu__nivel_medio = j;
            return 1;
            }
            j--;
          }
        }
      }
      jogador_pc++;
      if (jogador_pc == 2) {
      aux = 0;
      for (i = 0; i <tam_matriz; i++) { // verificação por linha
          for (j = 0; j < tam_matriz; j++) {
            if (matriz[i][j] == 'X') {
            aux++;
            }
            if (aux == 2) {
              break;
             }
            }
            if (aux == 2) {
              break;
            }
            else {
              aux = 0;
            }
           }
            if (aux == 2) {
              for (j = 0; j < tam_matriz; j++) {
                if (matriz[i][j] == ' ') {
                *i_cpu_nivel_medio = i;
                *j_cpu__nivel_medio = j;
                return 1;
                }
              }
            }
            aux = 0;
            for (j = 0; j <tam_matriz; j++) { // verificação por coluna
              for (i = 0; i < tam_matriz; i++) {
                if (matriz[i][j] == 'X') {
                  aux++;
                }
                if (aux == 2) {
                  break;
                }
               }
                if (aux == 2) {
                  break;
                }
                else {
                  aux = 0;
                }
              }
              if (aux == 2) {
                for (i = 0; i < tam_matriz; i++) {
                  if (matriz[i][j] == ' ') {
                  *i_cpu_nivel_medio = i;
                  *j_cpu__nivel_medio = j;
                  return 1;
                  }
              }
            }
            aux = 0;
            j = 0;
            for (i = 0; i <tam_matriz; i++) { // verificação por diagonal principal
               if (matriz[i][j] == 'X') {
                aux++;
                }
                j++;
            }
            j = 0;
            if (aux == 2) {
              for (i = 0; i < tam_matriz; i++) {
                if (matriz[i][j] == ' ') {
                *i_cpu_nivel_medio = i;
                *j_cpu__nivel_medio = j;
                return 1;
                }
                j++;
              }
            }
            aux = 0;
            j = 2;
            for (i = 0; i <tam_matriz; i++) { // verificação por diagonal secundaria
              if (matriz[i][j] == 'X') {
                  aux++;
              }
              j--;
            }
            j = 2;
            if (aux == 2) {
              for (i = 0; i < tam_matriz; i++) {
                if (matriz[i][j] == ' ') {
                *i_cpu_nivel_medio = i;
                *j_cpu__nivel_medio = j;
                return 1;
                }
                j--;
              }
            }
          }
          return 0;
        }
        
int vitoria_jogador1(char matriz[][tam_matriz]) {
  int i, j, aux = 0, k;
  for (i = 0; i < tam_matriz; i++) { // verificação por linha
    for (j = 0; j < tam_matriz; j++) {
      if (matriz[i][j] == 'X') {
        aux++;
      }
    }
    if (aux == 3) {
      return 1;
    }
    else {
      aux = 0;
    }
   }
  for (i = 0; i < tam_matriz; i++) { // verificação por coluna
     for (j = 0; j < tam_matriz; j++) {
      if (matriz[j][i] == 'X') {
        aux++;
      }
    }
     if (aux == 3) {
      return 1;
    }
    else {
      aux = 0;
    }
  }
  k = 0;
  for (i = 0; i < tam_matriz; i++) { // verificação por diagonal principal
    if (matriz[i][k] == 'X') {
      aux++;
    }
    k++;
   }
    if (aux == 3) {
      return 1;
    }
    else {
      aux = 0;
    }
    k = 2;
    for (i = 0; i < tam_matriz; i++) { // verificação por diagonal secundaria;
      if (matriz[i][k] == 'X') {
        aux++;
      }
      k--;
     }
    if (aux == 3) {
      return 1;
    }
    else {
      aux = 0;
    }
    return 0; 
  }
 
int empate(char matriz[][tam_matriz]) {
  int i, j, aux = 0, k;
  for (i = 0; i < tam_matriz; i++) { // verificação por linha
    for (j = 0; j < tam_matriz; j++) {
      if (matriz[i][j] == 'X' || matriz[i][j] == 'O') {
        aux++;
      }
    }
  }
  if (aux == 9) {
     return 3;
  }
  else {
    return 0;
  }
}

int vitoria_jogador2(char matriz[][tam_matriz]) {
  int i, j, aux = 0 , k;
  for (i = 0; i < tam_matriz; i++) { // verificação por linha
    for (j = 0; j < tam_matriz; j++) {
    if (matriz[i][j] == 'O') {
      aux++;
    }
  }
  if (aux == 3) {
    return 2;
  }
  else {
    aux = 0;
  }
}
for (i = 0; i < tam_matriz; i++) { // verificação por coluna
  for (j = 0; j < tam_matriz; j++) {
    if (matriz[j][i] == 'O') {
    aux++;
    }
  }
  if (aux == 3) {
    return 2;
  }
  else {
    aux = 0;
  }
 }
 k = 0;
 for (i = 0; i < tam_matriz; i++) { // verificação por diagonal principal
  if (matriz[i][k] == 'O') {
  aux++;
  }
  k++;
 }
 if (aux == 3) {  
  return 2;
  }
  else {
    aux = 0;
  }
  k = 2;
  for (i = 0; i < tam_matriz; i++) { // verificação por diagonal secundaria;
    if (matriz[i][k] == 'O') {
    aux++;
  }
  k--;
 }
if (aux == 3) {
  return 2;
}
else {
  aux = 0;
}
  return 0;
}
 
int eh_numero(char i, char j) {
  if ((i == 49 || i == 50 || i == 51) && (j == 49 || j == 50 || j == 51)) {
  return 1;
}
else {
return 0;
}
}
