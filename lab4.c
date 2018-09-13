#include "lab4.h"
#include <stdlib.h>


/*coloque tua resposta aqui*/
FILE *abre_arquivo(const char *arquivo){
    if (arquivo == NULL){
        return NULL;
    }
    return fopen(arquivo, "rb");
}    

int fecha_arquivo(FILE *arq){
    if (arq == NULL){
            return 1;
    }
    if (fclose(arq) == 0){ 
         return 0;
    }
return 0;    
}
/*
 * Le os times que estao dentro do "arquivo" e retorna um vetor contendo os times com seus jogadores.
 * Retorna dentro de "numero_de_times" a quantidade de times existentes dentro do arquivo lido.
 */
times_t *le_times(const char *arquivo, unsigned int *numero_de_times){
    FILE *arq;
    arq = abre_arquivo(arquivo);
    if(arq == NULL){
        *numero_de_times =0;
    return NULL;
    }
    if(numero_de_times == NULL){
        return NULL;
    }
    int deusehtop = ftell(arq);
    *numero_de_times = deusehtop/sizeof(times_t);
    if (deusehtop== 0){
        return NULL;
    }
    rewind(arq);
    times_t *times = (times_t *)malloc(sizeof(times_t)*(*numero_de_times));
    if (times == NULL){
        *numero_de_times = 0;
        return NULL;
    } 
    
    int contador =1; 
    while (contador <(*numero_de_times)){
        fread(&arquivo,sizeof(times_t),1,arq);
        contador++;
    }
    fecha_arquivo(arq);
return (times);
}
/* 
 * Encontra o jogador com a maior relacao entre cartao vermelho e numero de jogos (proporcao entre cartoes vermelhos e numero de jogos).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador com essa maior relacao deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_cartao_vermelho_e_jogos(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
   
    float relacaos, hilfe, eoq;
        for (int i=0; i<num_times; i++){
            relacaos =0;
            for(int j=0; j<NUM_JOGADORES; j++){
                hilfe = (times[i].jogadores[j].cartoes_vermelhos);
                eoq = (times[i].jogadores[j].numero_jogos);
                hilfe = (hilfe/eoq);
                if (hilfe > relacaos){
                    relacaos = hilfe;
                    *time = &times[i];
                    *jogador = &times[i].jogadores[j];
                    
                }
            }
        }
}

/* 
 * Encontra o jogador artilheiro, aquele que fez mais gols. 
 * O ponteiro "times" contem o vetor com todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador artilheiro deve ser retornado dentro do ponteiro "jogador" e o time do artilheiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_artilheiro(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
    
            float brigadeiros;
            int mustela=0;
            for (int i =0; i<num_times; i++){
                for(int j=0; i<NUM_JOGADORES; i++){
                    brigadeiros = times[0].jogadores[0].gols_marcados;
                    if(brigadeiros > mustela){
                        mustela = brigadeiros;
                        *time = &times[i];
                        *jogador = &times[i].jogadores[j];
                        
                    
                    }
                }
            }
    
return;    
}

/* 
 * Encontra o jogador mais eficiente, aquele que fez mais gols em menos jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais eficiente deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_eficiente(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
   
        float queijos =0, panqueca =0, quocientes=0;
        
        for(int i=0; i<num_times; i++){
            for(int j=0; j<NUM_JOGADORES; j++){
                queijos = times[i].jogadores[j].gols_marcados;
                panqueca = times[i].jogadores[j].numero_jogos;
                if((queijos/panqueca) > quocientes){
                    queijos = (queijos/panqueca);
                    *jogador = &times[i].jogadores[j];
                    *time = &times[i];
                }
            }
        }
    
return;
}

/* 
 * Encontra o time que possui mais titulos, sendo uma proporcao entre o numero de titulos (soma de todos os titulos) e o ano de fundacao (considere apenas o ano).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.  
 * O time com mais titulos deve ser retornado dentro do ponteiro "time".
 */
void encontra_time_com_mais_titulos(times_t *times, unsigned int num_times, times_t **time){
if(time == NULL){
        return;
    }else{
        float estousemideias =0, realmentesem =0, yzma =0;
        for(int i=0; i<num_times; i++){
            estousemideias = (times[i].numero_tit_brasileiros + times[i].numero_copas_brasil + times[i].numero_tit_libertadores +times[i].numero_tit_estadual);
            realmentesem = estousemideias/(times[i].ano_fundacao);
            if(realmentesem > yzma){
                yzma = realmentesem;
                *time = &times[i];
            }
        }
    }
return;    
}

/* 
 * Encontra o goleiro que defendeu mais penaltis em funcao do numero de jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O goleiro que defendeu mais times deve ser retornado dentro do ponteiro "jogador" e o time desse goleiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_goleiro_que_defendeu_mais_penaltis(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
    if(time == NULL){
        return;
    }
    if(jogador == NULL){
        return;
    }else{
        float ponteirozito1 =0, ponteirozito2 =0;
        for(int i =0; i<num_times;i++){
            for(int j=0;j<NUM_JOGADORES;j++){
                ponteirozito1 = times[i].jogadores[j].penalti_defendidos;
                ponteirozito1 = ponteirozito1/(times[i].jogadores[j].numero_jogos);
                if(ponteirozito1 > ponteirozito2){
                    ponteirozito2 = ponteirozito1;
                    *time = &times[i];
                    *jogador = &times[i].jogadores[j];
                }
            }
        }
    }
    
}

/*
 * Encontra o jogador mais agressivo, considerando peso 5 para cartao vermelho, 1 para amarelo e 0.2 para faltas cometidas.
 * O ponteiro "times" contem o vetor contendo todos os timese a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais agressivo deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_agressivo(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
    
        float mascetabravalinda =0, yellowsubmarine =0, ue=0;
        float somatotal =0, resultado =0;
        for(int i=0; i<num_times; i++){
            for (int j=0; j< NUM_JOGADORES; j++){
                mascetabravalinda = (2*(times[i].jogadores[j].cartoes_vermelhos));
                yellowsubmarine = times[i].jogadores[j].cartoes_amarelos;
                ue = (0.2*(times[i].jogadores[j].faltas_cometidas));
                somatotal= mascetabravalinda + yellowsubmarine + ue;
                    if(somatotal >resultado){
                        resultado = somatotal;
                        *jogador = &times[i].jogadores[j];
                        *time = &times[i];
                        
                    }
            }
        }
  
}
