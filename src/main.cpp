#include <Arduino.h>
#include <string.h> /*roda com funções do tipo*/ //! strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> 

void textoChar();
void textoString();

void setup() {
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop() {}

void textoChar(){
  const char cidade[] = "Sao Paulo";
/* 
* o caractere ' * ' significa que estamos trabalhando com um endereço
* Use o const char* quando o texto não será alterado
* Texto literal
*/

  Serial.println(cidade);

  /*
?  Descobrindo o tamanho do texto
?  strlen conta quantos caracteres antes do '\0'
? esse \0 ocupa 1 espaço na memoria
! str = String && len = Comprimento             */
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

//* Descobrindo o tamanho ocupado
//* sizeof() vê o tamanho da completo da variavel, contando o \0 junto
//* o sizeof() retornará um byte a mais que o comprimento por causa do '\0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaço utilizado: ");
  Serial.println(tamanhoVariavelCidade);

//TODO| quando trabalhamos com apenas 1 caractere usamos aspas simples
//TODO| e o sistema vai imprimir até encontrar o ' \0 ', quando encontrar tal, ele irá parar.
//TODO| o caracter ' \0 ' é colocado automaticamente quando escrevemos um texto entre aspas duplas ("")
  char vetorTexto[] = {'G', 'u', 'i', 'l', 'h', 'e', 'r', 'm', 'e', '\0'};
  Serial.println(vetorTexto);

// Comparar texto
// O '*' indica onde colocar na memoria, ele irá imprimir até chegar em \0
// o ponteiro conta a partir daqui ate achar o \0
  const char* cidade1 = "Sao Caetano";
  const char* cidade2 = "Sao Joao da Boa Vista";

  if(strcmp(cidade1, cidade2) == 0){
    Serial.println("Os textos sao iguais");
  } else{
    Serial.println("Os textos sao diferentes");
  }
/*
!| strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes
!| que a segunda o valor retornado será menor que zero, se a primeira palavra vem 
!| após a segunda o retorno será maior que zero */

/* 
? TEXTO EDITAVEL COM char[] */
char nomeAluno[20] = "Rique";
Serial.println(nomeAluno);

/*
? Alterando caracteres individualmente*/
nomeAluno[2] = 'i';
Serial.println(nomeAluno);
Serial.println(strlen(nomeAluno));

/*
todo COpiando outro texto para dentro do vetor
! CUIDADO: o vetor precisa ter espaço suficiente */

strcpy(nomeAluno, "Nicole");
Serial.println(nomeAluno);
Serial.println(strlen(nomeAluno));

//* Concatenando o texto ao final
char frase[40] = "Ola ";
strcat(frase, "Mundo!");
Serial.println(frase);

// Procurando um caractere no texto
// aqui ele acha a palavra procurando pelo endereço, no terminal ele iria colocar a palavra Mundo inteira, pois ele não encontrou
// o \0. Ou seja, se a frase fosse 'Ola Guilherme Tudo Bem', e eu busco pela letra G, ele iria retornar no monitor tudo depois de G
// até achar o \0.
char* posicaoLetra = strchr(frase, 'M');

if(posicaoLetra != NULL){
  Serial.println("Letra encontrada");
  Serial.println(posicaoLetra);
} else{
  Serial.println("Letra não encontrada");
}
//! Um ponteiro se faz assim ' char* '
//* O NULL significa o \0, eles são o primeiro caractere da tabela ASC

//todo Convertendo texto numérico para inteiro
char idadeTexto[] = "45"; // neste vetor com o valor 45, ele possui os seguintes valores de acordo com a tabela ASC: 52,53,\0
int idade = atoi(idadeTexto);
// atoi significa A = ASC / TO = Para / I = int
Serial.println(idade);
}

void textoString(){
//? USANDO String

String nome = "Henrique";
String curso = "Logica de Programacao";
String mensagem = "Ola";

// concatenação de Strings
mensagem = mensagem + ", " + nome + "! Bem-vindo ao curso de " + curso + ".";
Serial.println(mensagem);

//* tamanho da String
int tamanhoMensagem = mensagem.length();
Serial.println("Tamanho da String em letras: ");
Serial.println(tamanhoMensagem);

//! acessando um caractere em uma posição especifica
char primeiraLetra = mensagem.charAt(0);
Serial.print("Primeira letra: ");
Serial.println(primeiraLetra);

//! Tbm é possivel acessar com colchetes ^^
char segundaLetra = mensagem[1];
Serial.println(segundaLetra);

//TODO procurando um texto dentro da String
int posicaoTextoProcurado = mensagem.indexOf("curso");
Serial.println(posicaoTextoProcurado);

//? extraindo um texto de dentro da String
int inicioNomeCurso = posicaoTextoProcurado + 9;
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem));

// substituindo um texto dentro da String
mensagem.replace("Ola,", ("Oi, tudo bom? "));
Serial.println(mensagem);

//* convertendo para maiusculas
mensagem.toUpperCase();
Serial.println(mensagem);

//* convertendo para minusculas
mensagem.toLowerCase();
Serial.println(mensagem);


//! convertendo texto numerico para inteiro
String textoNumero = "23";
int numero = textoNumero.toInt();
Serial.println(numero * 2);

//TODO verificando se a String esta vazia
String textoVazio = " ";
if(textoVazio.length() == 0) Serial.println("O texto está vazio");
else Serial.println("O texto não esta vazio");

//? Convertendo String para const char
//? Isto é util quando alguma biblioteca espera texto do estilo C
const char* textoComoChar = mensagem.c_str();
Serial.println(textoComoChar);

// Montando texto
char buffer[100];
char* local = "Sala de aula";
int temperatura =26.4;
int umidade = 58;

snprintf(buffer, sizeof(buffer), "%s | Temp.: %f | Umid.: %d %%", local, temperatura, umidade);

//! Sala de Aula | Temp.: 26.4 | Umid.: 58 %


}