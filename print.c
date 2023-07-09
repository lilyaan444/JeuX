#include<stdio.h>

// ANSI ESCAPE CODES POUR MAC OS X
// POUR LINUX OU WINDOWS : A VERIFIER

// les codes couleurs
// noir		: 30
// rouge	: 31
// vert		: 32
// jaune	: 33
// bleu		: 34
// magenta	: 35
// cyan		: 36
// blanc	: 37

// les codes effets
// RESET		0
// BOLD 		1
// DIM			2
// ITALIC		3
// UNDERLINE 	4
// BLINK 		5
// REVERSE		7
// HIDDEN		8


#define SOURIRE		"\U0001F642"
#define SUEURS		"\U0001F613"
#define REFLECHI	"\U0001F914"
#define MEDAILLE	"\U0001F947"

// '\e' = caractere escape

int main()
{
	char c='A';
	
	printf("\n\e[4mcouleurs normales :\e[0m\n");
	printf("\e[0;30m Hello World \e[0m\n");
	printf("\e[0;31m Hello World \e[0m\n"); 
	printf("\e[0;32m Hello World \e[0m\n"); 
	printf("\e[0;33m Hello World \e[0m\n"); 
	printf("\e[0;34m Hello World \e[0m\n"); 
	printf("\e[0;35m Hello World \e[0m\n"); 
	printf("\e[0;36m Hello World \e[0m\n"); 
	printf("\e[0;37m Hello World \e[0m\n"); 
	
	printf("\n\e[4mcouleurs gras :\e[0m\n");
	printf("\e[1;30m Hello World \e[0m\n");
	printf("\e[1;31m Hello World \e[0m\n"); //rouge
	printf("\e[1;32m Hello World \e[0m\n");
	printf("\e[1;33m Hello World \e[0m\n"); //jaune
	printf("\e[1;34m Hello World \e[0m\n"); //bleu 
	printf("\e[1;35m Hello World \e[0m\n");
	printf("\e[1;36m Hello World \e[0m\n");
	printf("\e[1;37m Hello World \e[0m\n");
	
	printf("\n\e[4mles différents effets :\e[0m\n");
	printf("bleu + effet 0 \e[0;34m Hello World \e[0m\n");
	printf("bleu + effet 1 \e[1;34m Hello World \e[0m\n");
	printf("bleu + effet 2 \e[2;34m Hello World \e[0m\n");
	printf("bleu + effet 3 \e[3;34m Hello World \e[0m\n");
	printf("bleu + effet 4 \e[4;34m Hello World \e[0m\n");
	printf("bleu + effet 5 \e[5;34m Hello World \e[0m\n");
	printf("bleu + effet 7 \e[7;34m Hello World \e[0m\n");
	printf("bleu + effet 8 \e[8;34m Hello World \e[0m\n");
	
	printf("\n\e[4mforeground - background:\e[0m\n");
	printf("texte bleu normal sur fond jaune normal   : \e[0;34;43m fg:bleu(34) - bg:jaune(47) \e[0m\n");
	printf("texte bleu normal sur fond jaune brillant : \e[0;94;103m fg:bleu(94) - bg:jaune(107) \e[0m\n");
	printf("texte bleu gras sur fond jaune normal     : \e[1;34;43m fg:bleu(34) - bg:jaune(47) \e[0m\n");
	printf("texte bleu gras sur fond jaune brillant   : \e[1;94;103m fg:bleu(94) - bg:jaune(107) \e[0m\n");

	printf("\n\e[4memoji :\e[0m\n");
	printf("%s %s %s %s\n\n", SOURIRE,SUEURS, REFLECHI, MEDAILLE);
	
}
