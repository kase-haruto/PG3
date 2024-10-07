#include <iostream>
#include <random>
#include <ctime>

// ���茋�ʂ�\������R�[���o�b�N�֐�
void JudgeResult(int diceNumber, int userGuess){
    // �o�ڂ�����������𔻒�
    bool isEven = (diceNumber % 2 == 0);

    // ���[�U�[�̗\�z�Əo�ڂ̋���v���邩�𔻒�
    if ((isEven && userGuess == 2) || (!isEven && userGuess == 1)){
        printf("�����I�T�C�R���̏o�ڂ� %d �ł����B\n", diceNumber);
    } else{
        printf("�s�����B�T�C�R���̏o�ڂ� %d �ł����B\n", diceNumber);
    }
}

// �T�C�R���̏o�ڂ������_���ɐ���
int RollDice(){
    // �����_���f�o�C�X�̍쐬
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);
    return dist(gen);
}

// �w�肵���b�������ҋ@����
void Delay(int seconds){
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds);
}

typedef void (*judgeResult)(int, int);

int main(){
    // �J��Ԃ��v���C���邩�ǂ����̃t���O
    char playAgain = 'y';

    // ���茋��
    judgeResult result;
    result = &JudgeResult;

    //y����������J��Ԃ��V�ׂ�
    while (playAgain == 'y'){
        // ���[�U�[�̓��͂��擾
        std::cout << "�T�C�R���̏o�ڂ���Ȃ� 1�A�����Ȃ� 2 �Ɠ��͂��Ă�������: ";
        int userGuess;
        std::cin >> userGuess;

        // �T�C�R���̏o�ڂ�����
        int diceNumber = RollDice();

        // 3�b�ҋ@
        std::cout << "�T�C�R����U���Ă��܂�..." << std::endl;
        Delay(3);

        // ���ʂ𔻒�
        result(diceNumber, userGuess);

        // �ēx�v���C���邩
        std::cout << "\n������x�v���C���܂����H (y/n): ";
        std::cin >> playAgain;
    }

    system("pause");
    return 0;
}
