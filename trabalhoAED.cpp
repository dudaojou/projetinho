// Tema 5 - Congresso Nacional de Engenharia Mecânica e Industrial.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int cont=0, cont2=0;   //cont2 - verifica se alguma alteração foi feita.
int Quantidade_Max=10, Quantidade_Atual=0, ValorTotal=0;

struct Pessoas
{
	char nome[50], pais[50], email[50];
	string cpf;
	int valor=0;
	bool existe=false;
};

//Incluir.
void incluir (Pessoas X[], int i)
{
	if(X[i].existe==false){
		cout<<endl;
		cout<<"-------- Dados da inscricao: "<<(i+1)<<" --------"<<endl;
		cout<<endl;
		cout<<"Insira o nome completo:  "<<endl;
		cout<<endl;
		cin.ignore();
		cin.getline(X[i].nome, 50);
		cout<<endl;
		cout<<"Insira o pais de origem: "<<endl;
		cout<<endl;
		cin.getline(X[i].pais, 50);
		cout<<endl;
		cout<<"Insira um email para contato: "<<endl;
		cout<<endl;
		cin>>X[i].email;
		cout<<endl;
		cout<<"Insira o CPF apenas com numeros: "<<endl;
		cout<<endl;
		cin>>X[i].cpf;
		cout<<endl;
		X[i].existe=true;
		cont2++;
	}
}

//Tarifa
void tarifa (Pessoas X[], int i, int Aux, int Incluir)
{
	system("cls||clear");          //limpa terminal.
	cout<<"Quantas novas inscricoes deseja incluir?"<<endl;
	cout<<endl;
	cin>>Incluir;
	Aux=(Incluir+cont);
	cout<<endl;
	
	system("cls||clear");          //limpa terminal.
	if((Quantidade_Atual+Incluir)<=Quantidade_Max){
		for(i=cont;i<Aux;i++){
			cout<<"-------- Tarifas de inscricao --------"<<endl;
			cout<<endl;
			cout<<"(1)....Profissionais (com Visita Tecnica): R$ 300,00"<<endl;
			cout<<"(2)....Profissionais (sem Visita Tecnica): R$ 270,00"<<endl;
			cout<<"(3)....Profissionais da UNIVILLE e CEAJ (com Visita Tecnica): R$ 270,00)"<<endl;
			cout<<"(4)....Profissionais da UNIVILLE e CEAJ (sem Visita Tecnica): R$ 240,00)"<<endl;
			cout<<"(5)....Academicos (com Visita Tecnica): R$ 100,00"<<endl;
			cout<<"(6)....Academicos (sem Visita Tecnica): R$ 70,00"<<endl;
			cout<<"(7)....Academicos da UNIVILLE e Membros do Crea-Jr (com Visita Tecnica): R$ 80,00"<<endl;
			cout<<"(8)....Academicos da UNIVILLE e Membros do Crea-Jr (sem Visita Tecnica): R$ 50,00"<<endl;
			cout<<endl;
			int Escolha;
			cin>>Escolha;
			if(Escolha==1){
				X[i].valor=300.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==2){
				X[i].valor=270.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==3){
				X[i].valor=270.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==4){
				X[i].valor=240.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==5){
				X[i].valor=100.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==6){
				X[i].valor=70.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==7){
				X[i].valor=80.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else if(Escolha==8){
				X[i].valor=50.00;
				ValorTotal+=X[i].valor;
				incluir(X, i);
			}else{
				cout<<endl;
				cout<<"Comando invalido.";
				cout<<endl;
			}
		}
		Quantidade_Atual=Quantidade_Atual+Incluir;
		cont=(cont+Incluir);
		system("cls||clear");          //limpa terminal.
		cout<<endl;
		cout<<"-------- Cadastro(s) realizado(s) com sucesso! --------"<<endl;
		cout<<endl;
		}else{
		system("cls||clear");          //limpa terminal.
		cout<<endl;
		cout<<"A quantidade de inscricoes desejadas supera a quantidade maxima de participantes!"<<endl;
		cout<<"vagas disponiveis: "<<(Quantidade_Max-Quantidade_Atual)<<endl;
	}
}

//Excluir.
bool excluir (Pessoas X[])
{
	system("cls||clear");          //limpa terminal.
	string cpfE;
	cout<<endl;
	cout<<"Insira o CPF do participante cadastrado: "<<endl;
	cout<<endl;
	cin>>cpfE;
	cout<<endl;
	int j=0, pos=0;
	for(j=0;j<Quantidade_Atual;j++){
		if(X[j].existe==true){
			if(X[j].cpf==cpfE){
				X[j].existe=false;
				ValorTotal-=X[j].valor;
				cont--;
				Quantidade_Atual--;
				cont2++;
				for(pos=j;pos<Quantidade_Max-1;pos++){
					X[pos]=X[pos+1];
				}
				X[Quantidade_Max-1].existe=false;
				return true;
			}
		}
	}
	return false;
}

//Listar.
void listar (Pessoas X[])
{
	system("cls||clear");          //limpa terminal.
	cout<<"-------- Cadastros Atuais --------"<<endl;
	cout<<endl;
	for(int i=0;i<Quantidade_Max;i++){
		if(X[i].existe==true){
			cout<<X[i].nome<<endl;
			cout<<X[i].pais<<endl;
			cout<<X[i].email<<endl;
			cout<<X[i].cpf<<endl;
			cout<<endl;
		}
	}
	cout<<" - - - - - - - - - - - - "<<endl;
	cout<<endl;
}

//Alterar.
void alterar (Pessoas X[])
{
	system("cls||clear");          //limpa terminal.
	string alte;
	cout<<endl;
	cout<<"Insira o CPF do {} cadastro: "<<endl;
	cout<<endl;
	cin>>alte;
	cout<<endl;
	int cont3=0;
	for(int j=0;j<Quantidade_Atual;j++){
		if(alte==X[j].cpf){
			cout<<"Insira o nome completo:  "<<endl;
			cout<<endl;
			cin.ignore(); // não pega o \n do enter 
			cin.getline(X[j].nome, 50);
			cout<<endl;
			cout<<"Insira o pais de origem: "<<endl;
			cout<<endl;
			cin.getline(X[j].pais, 50);
			cout<<endl;
			cout<<"Insira um email para contato: "<<endl;
			cout<<endl;
			cin>>X[j].email;
			cout<<endl;
			cout<<"Insira o CPF apenas com numeros: "<<endl;
			cout<<endl;
			cin>>X[j].cpf;
			cout<<endl;
			X[j].existe=true;
			cont2++;
			cont3++;
		}
	}
	if(cont3==0) {
		cout<<"Usuario nao encontrado"<<endl;
	}
}

//Totalizar.
void totalizar ()
{
	system("cls||clear");          //limpa terminal.
	cout<<"Inscricoes atuais: "<<endl;
	cout<<Quantidade_Atual<<" vaga(s) ocupada(s) de "<<Quantidade_Max<<endl;
	cout<<endl;
	cout<<"Montante arrecadado: "<<endl;
	cout<<"R$ "<<ValorTotal<<",00"<<endl;
	cout<<" - - - - - - - - - - - - "<<endl;
}

//Gravar Dados.
void gravar (Pessoas X[])
{
	ofstream saida("Log-DadosAed.dat",ios::binary);
	saida.write((char*)&cont, sizeof(int));
	saida.write((char*)&Quantidade_Atual, sizeof(int));
	saida.write((char*)&ValorTotal, sizeof(int));
	
	for(int j=0;j<Quantidade_Atual;j++){
		if(X[j].existe==true){
			saida.write((char *) &X[j], sizeof(Pessoas));
		}
	}

	cont2=0;
	saida.close();
}

//Ler Dados.
void ler (Pessoas X[])
{
	ifstream entrada("Log-DadosAed.dat",ios::binary);
	entrada.read((char*)&cont, sizeof(int));
	entrada.read((char*)&Quantidade_Atual, sizeof(int));
	entrada.read((char*)&ValorTotal, sizeof(int));
	
	for(int j=0;j<Quantidade_Atual;j++){
		entrada.read((char *) &X[j], sizeof(Pessoas));
	}

	entrada.close();
}

int main()
{	
	int Entrada=0;
	int i=0, Aux=0, Incluir=0;
	Pessoas X[Quantidade_Max];
	
	ler(X);
	
	cout<<"Inscricoes atuais: "<<endl;
	cout<<Quantidade_Atual<<" vaga(s) ocupada(s) de "<<Quantidade_Max<<endl;
	cout<<endl;
	cout<<"Menu:"<<endl;
	cout<<endl;
	cout<<"Incluir............(1)"<<endl;
	cout<<"Excluir............(2)"<<endl;
	cout<<"Listar.............(3)"<<endl;
	cout<<"Alterar............(4)"<<endl;
	cout<<"Totalizar..........(5)"<<endl;
	cout<<"Gravar Dados.......(6)"<<endl;
	cout<<"Sair...............(7)"<<endl;
	cout<<endl;
	
	cin>>Entrada;
	cout<<endl;
	
	while(Entrada!=7){  //Loop Infinito - Até que o usuario manifeste interesse em sair.
		
		if(Entrada==1){           //Incluir.
			if(Quantidade_Atual<Quantidade_Max){
				tarifa(X, i, Aux, Incluir);
				Entrada=0;
			}else{
				system("cls||clear");          //limpa terminal.
				cout<<endl;
				cout<<"-------- Quantidade maxima de participantes atingida! --------"<<endl;
				cout<<endl;
			}
			
			
		}else if(Entrada==2){     //Excluir.
			bool exclui = excluir(X);
			system("cls||clear");          //limpa terminal.
			if(exclui){
				cout<<endl;
				cout<<"-------- Cadastro excluido com sucesso! --------"<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<"-------- Cadastro inexistente! --------"<<endl;
				cout<<endl;
			}
			
		}else if(Entrada==3){     //Listar.
			listar(X);
			
			
		}else if(Entrada==4){     //Alterar.
	
			alterar (X);
			
		}else if(Entrada==5){     //Totalizar.
			totalizar();
			
		}else if(Entrada==6){     //Gravar Dados.
			gravar(X);
			ler(X);
			//cont2=0;
			
			
		}else{
			cout<<"Comando invalido.";
		}
		
		cout<<endl;
		cout<<" - - - - - - - - - - - - "<<endl;
		cout<<endl;
		cout<<"Inscricoes atuais: "<<endl;
		cout<<Quantidade_Atual<<" vaga(s) ocupada(s) de "<<Quantidade_Max<<endl;
		cout<<endl;
		cout<<"Menu:"<<endl;
		cout<<endl;
		cout<<"Incluir............(1)"<<endl;
		cout<<"Excluir............(2)"<<endl;
		cout<<"Listar.............(3)"<<endl;
		cout<<"Alterar............(4)"<<endl;
		cout<<"Totalizar..........(5)"<<endl;
		cout<<"Gravar Dados.......(6)"<<endl;
		cout<<"Sair...............(7)"<<endl;
		cout<<endl;
		
		cin>>Entrada;
		cout<<endl;
		
	}
	
	if(cont2!=0){
		system("cls||clear");          //limpa terminal.
		string x;
		cout<<"Deseja salvar as alteracoes antes de sair?"<<endl;
		cout<<endl;
		cout<<"                S ou N"<<endl;
		cin>>x;
		if ((x=="S") or (x=="s")){
			gravar(X);
			system("cls||clear");          //limpa terminal.
			cout<<"Salvo com sucesso!"<<endl;
			cout<<endl;
			cout<<"Ate logo!";
			return 0;
		}
		if ((x=="N") or (x=="n")){
			system("cls||clear");          //limpa terminal.
			cout<<"Ate logo!";
			return 0;
		}else{
			cout<<endl;
			cout<<"Comando invalido.";
		}
	}
	else{
		system("cls||clear");          //limpa terminal.
		cout<<"Ate logo!";
		return 0;
	}
}
