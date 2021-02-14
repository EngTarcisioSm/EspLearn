#include <stdio.h>
#include <string.h>

//-(1)Estruturas ou Struct são representação de um objeto do mundo real
//-(1)Abaixo é criado uma estrutura pessoa que tenta abstrair a essencia de uma pessoa, criando suas caracteristicas, como primeiro nome, ultimo nome e idade 
struct Person
{
  char firstName[20];
  char lastName[50];
  int age;
};

//(5) CRIANDO A STRUCT DE FORMA QUE NÃO HAJA NECESSIDADE DA PALAVRA STRUCT QUANDO UMA FOR CRIADA AO LONGO DO CÓDIGO 
//  -O NOME DA ESTRUTURA SEGUIDO DE _STRUCT É APENAS PARA FINS DE ORGANIZAÇÃO
//  -APOS A CRIAÇÃO DA STRUCT DESTA FORMA ELA PODE SER CRIADA PELO NOME DE PERSON2
typedef struct Person_struct{
  char firstName[20];
  char lastName[50];
  int age;
}Person2;

//(8) ao utilizar um parametro em forma de ponteiro utilize o asterisco na frente do nome do parametro
void updatePersonBarbara(Person2 *person){
  strcpy(person->firstName,"Barbara");
  strcpy(person->lastName, "Kely Vasconcelos");
  person->age = 29;
}
//(9)DA MESMA FORMA SERVIRIA PASSAR UM PONTEIRO DO ARRAY, COMO JÁ DESCRITO NO MATERIAL, A LINGUAGEM C TRATA ARRAY COMO PARAMETRO COMO UM ENDEREÇO PASSADO E NÃO UMA CÓPIA DO CONTEÚDO, ENTRETANTO NÃO SE DEVE UTILIZAR O CARACTERE "&" NO CHAMAMENTO DA FUNÇÃO, O PROGRAMA SERÁ EXECUTADO POREM OCASIONANDO MENSAGENS INFORMANDO ESTE ERRO QUE N IMPEDE DE SER COMPILADO (COMPILARÁ MAIS SEMPRE MOSTRARÁ A MENSGEM DE ERRO ), DESTA FORMA NESTE CASO NÃO SE UTILIZA O "&"
//void exclamIt(char *phrase) // também funcionaria 
void exclamIt(char phrase[])
{
  strcat(phrase,"!");
}

void app_main(void)
{
  //-(2)Para se criar uma estrutura dentro do código fazemos da forma abaixo 
  struct Person person;

  //(3)-Escrever sobre um valor da estrutura
  //  -para acessar o conteudo de uma estrutura efetuamos o processo da seguinte maneira, o nome da estrutura criada ponto e em seguinda o nome do conteúdo da estrutura a ser acessado, seja para escrever ou ler
  //  -como dois conteúdos da estrutura criada acima são array de caracteres escreveremos sobre os mesmos da utilizando o metodo strcpy presente na biblioteca string
  strcpy(person.firstName, "Tarcisio");
  strcpy(person.lastName, "Souza de Melo");
  person.age = 32;

  //(4)printando o conteúdo da estrutura 
  printf("person: %s %s is %d years old\n", person.firstName, person.lastName, person.age);

  //(6)é possivel criar uma estrutura sem a palavra struct na frente sem acarretar problemas para a aplicação 
  Person2 personBryan;
  strcpy(personBryan.firstName, "Bryan");
  strcpy(personBryan.lastName, "Vasconcelos de Melo");
  personBryan.age = 5;
  printf("person: %s %s is %d years old \n", personBryan.firstName, personBryan.lastName, personBryan.age);


  //(7)ao criar uma função que recebera uma estrutura é importante caso deseje que a função modifique o valor que será passado como parametro, a utilização de ponteiros, pois de outra forma sa função apenas receberá uma cópia da variavel ou estrutura, não alterando o valor do parametro passado 
  //  - ao utilizar uma estrutura ou variavel como ponteiro de uma função, a função deve estar preparada para receber aquele valor como ponteiros e ao passar o ponteiro deve-se utilizar na frente do nome o caractere "&"
  //  - o ponteiro quando é passado ao inves da função efetuar uma cópia do valo, estará recebendo um endereço da variavel e desta forma a variavel passada como parametro pode sofrer alterações dentro da função que permanecerão 
  Person2 personBarbara;
  updatePersonBarbara(&personBarbara);
  printf("person: %s %s is %d years old \n", personBarbara.firstName, personBarbara.lastName, personBarbara.age);

  //(8) passando um array como parametro 
  char phrase[20] = {"HELLO WORLD"};
  exclamIt(phrase);
  printf("function output: %s\n", phrase);

}
