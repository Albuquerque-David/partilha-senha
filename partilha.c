#include <stdio.h>
struct parSenha {
	int num;
	int modulo;
};

#define TAM 1000

void main(){
	int n;
	int k;
	int M=1,N, Maux;
	int senha;
	int menu=1;
	
	
	int i;
	int j;
	
	printf("----------------------------CONFIGURACAO DO BANCO-----------------------------------\n");
	printf("Insira o numero de admins.\n");
	scanf("%d",&n);
	system("cls");
	printf("Insira o numero de admins necessarios para descobrir a senha.\n");
	scanf("%d",&k);
	system("cls");
	int f[n];
	printf("Insira os %d numero coprimos entre si para gerar o conjunto de possiveis senhas.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&f[i]);
	}
	
	N=f[0]*f[1];
	Maux=k-1;
	for(i=1;i<=Maux;i++){
		M*=f[n-i];
		
	}
	system("cls");
	printf("Escolha uma senha entre os numeros %d e %d.\n",M,N);
	scanf("%d",&senha);
	//FIM DO PRIMEIRO PASSO
	
	int chaves[n][2];
	for(i=0;i<n;i++){
		chaves[i][1] = f[i]; //modulo
		chaves[i][0] = senha%f[i]; //resto
	}

	system("cls");
	
	int numUsuarios;
	struct parSenha parSenha[TAM];
	int unlock=0;
	
	while(menu){
		printf("----------------------------BANCO-----------------------------------\n");
		printf("1 - Inserir senhas para abrir cofre.\n");
		printf("2 - Revelar senhas.\n");
		printf("3 - Limpar console.\n");
		printf("4 - Sair.")
		scanf("%d",&menu);
		if(menu==1){
			printf("Quantos usuarios irao inserir senhas?\n");
			scanf("%d",&numUsuarios);
			
			for(i=0;i<numUsuarios;i++){
				printf("Insira o modulo\n");
				scanf("%d",&parSenha[i].modulo);
				printf("Insira o numero\n");
				scanf("%d",&parSenha[i].num);
			}
			
			for(i=0;i<numUsuarios;i++){
				for(j=0;j<n;j++){
					if(parSenha[i].modulo==chaves[j][1]&&parSenha[i].num==chaves[j][0]){
						unlock++;
					}
				}
			}
			
			if(unlock>=k){
				printf("COFRE ABERTO");
				exit(0);
			}
			else{
				printf("SENHA ERRADA.\n");
			}
			unlock=0;
			
		}
		
		else if(menu==2){
			for(i=0;i<n;i++){
				printf("(%d,",chaves[i][1]);
				printf("%d)\n",chaves[i][0]);
			}
		}
		
		else if(menu==3){
			system("cls");
		}
		
		else if(menu==4){
			exit(0);
		}
	}	
	

}


