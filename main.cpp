#include <iostream>

//��ʓI�Ȓ����`�Ԃ̏ꍇ�̒���
int CalculateWage(int hour){
	return 1072 * hour;
}

//�ċA�I�Ȓ����`��
int RecursiveWage(int hour){
	// �ŏ���1���Ԃ̎�����100�~
	if (hour == 1){
		return 100;
	}
	// limitTime��2���Ԉȏ�̏ꍇ�̒����v�Z
	return RecursiveWage(hour - 1) * 2 - 50;
}

// ���v�������v�Z����֐�
int CalculateTotalRecursiveWage(int hours){
	int totalWage = 0;
	for (int hour = 1; hour <= hours; ++hour){
		totalWage += RecursiveWage(hour);
	}
	return totalWage;
}

int main(){
	int workingHours = 8;

	printf("�J�����Ԃ�%d����\n",workingHours);
	printf("��ʓI�Ȓ����`��:%d\n", CalculateWage(workingHours));
	printf("�ċA�I�Ȓ����`��:%d\n", CalculateTotalRecursiveWage(workingHours));
	
	if (CalculateWage(workingHours)> CalculateTotalRecursiveWage(workingHours)){
		printf("%s\n", "��ʓI�Ȓ����`�Ԃ̂ق���������");
	} else{
		printf("%s\n", "�ċA�I�Ȓ����`�Ԃ̂ق���������");
	}
	

	// �I���O�ɃL�[���͑҂�
	std::cin.get();
	return 0;
}