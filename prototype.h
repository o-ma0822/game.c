#pragma once
//�J�n�̕���
void begin();
void jobtestbegin();

//�S���e�X�g����p�֐�
void psycotestrun();

//�S���e�X�g�̓_�p�֐�
void scorejudge();

//�S���e�X�g���ʂ̍ő�l�v�Z�p�֐�
void maxcalculate(int m, int* max);

//�E�Ɣ���ƐE�ƃX�e�[�^�X�ǂݍ��ݗp�֐�
void jobdecide(int max, int tensei);

//�E�Ƃ̓��Z�Ɖ��`�\���p�֐�



//�o�g���p�֐���

//���݂̃o�g�����A���g�ƓG�X�e�[�^�X�������p�֐�
void battlestart(int stage, int c, int* count);

//�^�[���I��p�֐�
int moveselect(int tensei);

//�f��������p�֐�
int agijudge();

//������������
int winjudge();
int loosejudge();

//�ʏ�U���v�Z�p�֐�
void firstattack(int* winloose);
void secondattack(int* winloose);

//�X�e�[�^�X�\���p�֐�
void pstatuscheck();
void estatuscheck();

//�������������֐�
void winprocess(int c, int s, int* count, int* stage);
int looseprocess(int ten);

//�G����̍U���v�Z�����֐�
void enemyattack();

//���Z�v�Z�p�֐�
void tubamegaesi();
void kakyuu();
void tukaimakyouka();
void kaifuku();
void tatetossin();
//�o�������Z�𔻒f��A�����p�֐�
void tokugiact(int* winloose);

//���`�v�Z�p�֐�
void zansin();
void syuuennohonoo();
void sinjyuusyoukan();
void sintoumekkyaku();
void seinarutate();
//�o�������`�𔻒f��A�����p�֐�
void ougiact(int* winloose);