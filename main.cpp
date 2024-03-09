#include "stm32f10x.h"                  // Device header
#include <stdlib.h>

void dis(int r,int k);
int k=6,r=4,score=0;

int main() {
	
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
	
	GPIOA -> CRL |= GPIO_CRL_CNF;
	GPIOA -> CRL &=~ GPIO_CRL_MODE;
	GPIOA -> CRH |= GPIO_CRH_CNF;
	GPIOA -> CRH &=~ GPIO_CRH_MODE;
	
	GPIOB -> CRH |= GPIO_CRH_CNF;
	GPIOB -> CRH &=~ GPIO_CRH_MODE;
	
	GPIOB -> CRL = 0x8888; 
	
	
	bool gen = true;
	if(gen == true) {
		int k=6,r=4;
		int kr = rand() % 6,rr = rand() % 4;
		gen = false;
	}
	
	else {
		dis(k,r);
		if(GPIOB -> IDR & GPIO_IDR_IDR0){
			while(GPIOB -> IDR & GPIO_IDR_IDR0) {;}
			k++;
		}
		if(GPIOB -> IDR & GPIO_IDR_IDR1){
			while(GPIOB -> IDR & GPIO_IDR_IDR14) {;}
			k--;
		}
		if(GPIOB -> IDR & GPIO_IDR_IDR3){
			while(GPIOB -> IDR & GPIO_IDR_IDR14) {;}
			r++;
		}
		if(GPIOB -> IDR & GPIO_IDR_IDR4){
			while(GPIOB -> IDR & GPIO_IDR_IDR14) {;}
			r--;
		}
		
		if(k == kr && r == rr) {
			score++;
			efekat();
			
		}
		
		while(1) {
			
		}
	}
	
}

void dis(int r,int k) {
	switch(r) {
		case 0:
			GPIOA -> ODR |= (1<< 10);
			break;
		case 1:
			GPIOA -> ODR |= (1<< 9);
			break;
		case 2:
			GPIOA -> ODR |= (1<< 8);
			break;
		case 3: 
			GPIOB -> ODR |= (1<< 15);
			break;
		case 4:
			GPIOB -> ODR |= (1<< 14);
			break;
		case 5:
			GPIOB -> ODR |= (1<< 13);
			break;
		case 6:
			GPIOB -> ODR |= (1<< 12);
			break;
		default:
			break;
		
		switch(k) {
			case 0:
				GPIOA -> ODR &=~ (1<< 0);
				break;
			case 1:
				GPIOA -> ODR &=~ (1<< 1);
				break;
			case 2:
				GPIOA -> ODR &=~ (1<< 2);
				break;
			case 3:
				GPIOA -> ODR &=~ (1<< 3);
				break;
			case 4:
				GPIOA -> ODR &=~ (1<< 4);
			 break;
		}
	}
}