#include <iostream>
#include <stdio.h>

template <typename T>
T Min(T val_1, T val_2){
	//�������ق���Ԃ�
	return (val_1 > val_2) ? val_2 : val_1;
}

template <>
char Min<char>(char val_1, char val_2){
	std::cout << "�����ȊO�͑���ł��܂���" << std::endl;
	return '\0';
}


int main(){

	std::cout << Min<int>(7, 4) << std::endl;
	std::cout << Min<float>(7.0f, 5.0f) << std::endl;
	std::cout << Min<char>('a', 'b') << std::endl;

	// �I���O�ɃL�[���͑҂���ǉ�
	std::cin.get();
	return 0;
}