#include <iostream>

using namespace std;

int main()
{
	const unsigned char isHungry = 0x01; // шестнадцатеричный литерал для 0000 0001
	const unsigned char isSad = 0x02; // шестнадцатеричный литерал для 0000 0010
	const unsigned char isMad = 0x04; // шестнадцатеричный литерал для 0000 0100
	const unsigned char isHappy = 0x08; // шестнадцатеричный литерал для 0000 1000
	const unsigned char isLaughing = 0x10; // шестнадцатеричный литерал для 0001 0000
	const unsigned char isAsleep = 0x20; // шестнадцатеричный литерал для 0010 0000
	const unsigned char isDead = 0x40; // шестнадцатеричный литерал для 0100 0000
	const unsigned char isCrying = 0x80; // шестнадцатеричный литерал для 1000 0000

	unsigned char me = 0; // все флаги/параметры отключены до старта
	me |= isHappy | isLaughing; // Я isHappy и isLaughing
	me &= ~isLaughing; // Я уже не isLaughing

	cout << "I am happy? " << (me & isHappy) << '\n';
	cout << "I am laughing? " << (me & isLaughing) << '\n';

}