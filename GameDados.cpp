#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include <tuple>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
std::tuple<std::string, std::string, std::string> states;
std::tuple<int, int> dice;
std::tuple<int, int> marcador;
int games = 1;
int play;
void throwDice();
void result();
void restart();

	
int main() {
 
	std::get<0>(states) = "[GANADOR] Has ganado esta tirada!! :)";
	std::get<1>(states) = "[PERDEDOR] La casa gana por punto medio!! ==__==";
	std::get<2>(states) = "[PERDEDOR] Has perdido esta tirada!! T__T";	
		
	std::cout<< "Listo para jugar Chicas y Grandes?? Genial"<<std::endl<<std::endl;
	std::cout<<"Digita 1 para iniciar el juego" <<std::endl;
	std::cin>>play;
	std::cout<<std::endl;
	if( play == 1){
		throwDice();
		play = 0;
	}
	

	return 0;
}
void throwDice(){
	std::cout<<"----------------------------------------------"<<std::endl;
	std::cout<<"[VECES] Este es el juego numero: "<<games<<std::endl;
	std::get<0>(dice)= (rand() % 6)+1;
	std::get<1>(dice)= (rand() % 6)+1;
		std::cout<<std::endl;
		std::cout<<"[DADO 1]En esta tirada el dado uno obtuvo: "<<std::get<0>(dice)<<std::endl;
		std::cout<<"[DADO 2]En esta tirada el dado dos obtuvo: "<<std::get<1>(dice)<<std::endl;
		std::cout<<std::endl;
	result();
}
void result(){
	int resultado =	std::get<0>(dice) + std::get<1>(dice);
	std::cout<<"[RESULTADO]La suma de ambos dados es "<<resultado<<std::endl;
	std::cout<<std::endl;
	
	if(resultado > 7){
			std::cout<<std::get<0>(states)<<std::endl;
			std::get<1>(marcador) += 1;
		std::cout<<std::endl;
		restart();
		} 
		
   if (resultado < 7){
			std::cout<<std::get<2>(states)<<std::endl;
			std::get<0>(marcador) += 1;
		std::cout<<std::endl;
		restart();
		} 
	if ( resultado == 7) {
		
			std::cout<<std::get<1>(states)<<std::endl;
			std::get<0>(marcador) += 1;
		std::cout<<std::endl;
		restart();
			}
	
	
}

void restart(){
	std::cout<<"////////////////////////////////////" <<std::endl;  
	std::cout<<"// [MARCADOR] Casa: "<<std::get<0>(marcador); 
	std::cout<<" Jugador: "<<std::get<1>(marcador);
	std::cout<<" //"<<std::endl;                 
	std::cout<<"///////////////////////////////////"<<std::endl;     
	
	
	std::cout<<"Quieres volver a jugar?? Digita 1"<<std::endl;
	std::cin>>play;
	if (play == 1) {
		play = 0;
		games += 1; 
		throwDice();
	}
}