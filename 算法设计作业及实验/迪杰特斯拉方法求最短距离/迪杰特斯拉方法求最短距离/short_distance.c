#define _CRT_SECURE_NO_WARNINGS 1
#include "short_distance.h"


int A[MaxSize + 1][MaxSize + 1];   /*�Ͻ�˹�����㷨*/
int D[MaxSize + 1];/*��ʼ���·��*/
int S[MaxSize + 1],/*��־λ��0ûȡ�����أ�1�Ѿ�ȡ������*/P[MaxSize + 1]/*ȡ��������һ����ż��α��ϵ�kֵ*/;
int source, sink;/*��ʼ���յ����*/
int step = 1;






int top = -1;
int Stack[MaxSize + 1];


void init()

{

	int i, j;



	MGr.view[1].num = 1;

	strcpy(MGr.view[1].date.name, "�������̴�ѧ����");

	strcpy(MGr.view[1].date.number, "001");

	strcpy(MGr.view[1].date.introduce, "λ��������ʷ�Ļ������������Ǿ����ҽ�������׼�������й���������һ���Է�֯��װΪ��ɫ����ͨ���Ƹߵ�ѧУ���������������¹Ĵ��58�ţ���ͨ���������ξ��㷱�࣬УѵΪ����º��㣬��ѧ����");


	MGr.view[2].num = 2;

	strcpy(MGr.view[2].date.name, "����¥");

	strcpy(MGr.view[2].date.number, "002");

	strcpy(MGr.view[2].date.introduce, "��Ӣ��רҵ�İ칫�����ڵأ���Ƹ�����ڵأ���ѧ�������ڵ�");



	MGr.view[3].num = 3;

	strcpy(MGr.view[3].date.name, "��ѧ��");

	strcpy(MGr.view[3].date.number, "003");

	strcpy(MGr.view[3].date.introduce, "A-D����ѧ¥��");



	MGr.view[4].num = 4;

	strcpy(MGr.view[4].date.name, "��Ȫ");

	strcpy(MGr.view[4].date.number, "004");

	strcpy(MGr.view[4].date.introduce, "ѧУ�½����������ۣ�ΪУ��ӭ�µ���������������");



	MGr.view[5].num = 5;

	strcpy(MGr.view[5].date.name, "ͼ���");

	strcpy(MGr.view[5].date.number, "005");

	strcpy(MGr.view[5].date.introduce, "ǰ��Ϊ������֯��ѧԺ��֯ϵ�����ң���81�����ʷ������ʱ�̳��˴�����������ף�ӵ�������Ļ������ֿ�ʹ�û���������һվʽ��������ͬѧ���ṩ������ѧϰ�Ļ���");



	MGr.view[6].num = 6;

	strcpy(MGr.view[6].date.name, "��ѧ�������");

	strcpy(MGr.view[6].date.number, "006");

	strcpy(MGr.view[6].date.introduce, "��ѧУ�����ľٰ쳡����ӵ���ŵƹ�����ȶ�����ʩ���ḻ��ͬѧ�Ŀ��������ӵ����ʷ�ƾõ�Уʷ��");



	MGr.view[7].num = 7;

	strcpy(MGr.view[7].date.name, "����1");

	strcpy(MGr.view[7].date.number, "007");

	strcpy(MGr.view[7].date.introduce, "������ȫ��ʦ������һ��ӵ�г��У�һ�����Ϊ��������¥ӵ�н�����̨���ҡ����������������ֳ���");



	MGr.view[8].num = 8;

	strcpy(MGr.view[8].date.name, "ѧ����ԢŮ");

	strcpy(MGr.view[8].date.number, "008");

	strcpy(MGr.view[8].date.introduce, "��һƬ��Ϊ����������ȫ��Ůͬѧ�ľ�ס���ڵ�");



	MGr.view[9].num = 9;

	strcpy(MGr.view[9].date.name, "ѧ����Ԣ��");

	strcpy(MGr.view[9].date.number, "009");

	strcpy(MGr.view[9].date.introduce, "ȫ����ͬѧ��ס���ڵ�");



	MGr.view[10].num = 10;

	strcpy(MGr.view[10].date.name, "ҽ����");

	strcpy(MGr.view[10].date.number, "010");

	strcpy(MGr.view[10].date.introduce, "ѧУ�ṩ��Ϊ��Уʦ������סԺ�ṩ�ĵط�����ʹ�ô�ѧ��ҽ���������Żݣ�ӵ���ų����ҩ���ҽ���豸");





	MGr.view[11].num = 11;

	strcpy(MGr.view[11].date.name, "������");

	strcpy(MGr.view[11].date.number, "011");

	strcpy(MGr.view[11].date.introduce, "ӵ����ë�򳡣�ƹ���ң����򳡣��ܵ��������˶���ʩ���Ա߾�����Ӿ�����ڵأ���ͬѧ�ǽ�������ĺõط�");






	MGr.view[12].num = 12;

	strcpy(MGr.view[12].date.name, "����2");

	strcpy(MGr.view[12].date.number, "012");

	strcpy(MGr.view[12].date.introduce, "ӵ������ʳ�ã��������ã�������ȫ��ʦ����������רΪ��������ʦ���ṩ���������");




	MGr.view[13].num = 13;

	strcpy(MGr.view[13].date.name, "ѧУ����");

	strcpy(MGr.view[13].date.number, "013");

	strcpy(MGr.view[13].date.introduce, "λ������·���ٽ���������Ȫ��λ��һ��С�Խ��ϣ�Ϊͬѧ�����ҹ���ṩ�����õĻ���");







	for (i = 1; i <= N; i++)

	{

		for (j = 1; j <= N; j++)

		{

			MGr.length[i][j] = MaxRoad;

		}

	}



	MGr.length[1][2] = MGr.length[2][1] = 100;

	MGr.length[1][3] = MGr.length[3][1] = 120;

	MGr.length[2][3] = MGr.length[3][2] = 100;

	MGr.length[3][4] = MGr.length[4][3] = 40;

	MGr.length[3][5] = MGr.length[5][3] = 50;

	MGr.length[5][6] = MGr.length[6][5] = 200;

	MGr.length[6][7] = MGr.length[7][6] = 300;

	MGr.length[7][9] = MGr.length[9][7] = 30;

	MGr.length[7][8] = MGr.length[8][7] = 250;

	MGr.length[8][10] = MGr.length[10][8] = 150;

	MGr.length[9][11] = MGr.length[11][9] = 200;

	MGr.length[10][11] = MGr.length[11][10] = 300;

	MGr.length[11][12] = MGr.length[12][11] = 100;

	MGr.length[10][13] = MGr.length[13][10] = 100;

	MGr.length[1][1] = MGr.length[2][2] = MGr.length[3][3] = MGr.length[4][4] = 0;

	MGr.length[5][5] = MGr.length[6][6] = MGr.length[7][7] = MGr.length[8][8] = 0;

	MGr.length[9][9] = MGr.length[10][10] = MGr.length[11][11] = MGr.length[12][12] = 0;

	MGr.length[13][13] = MGr.length[14][14] = MGr.length[15][15] = MGr.length[16][16] = 0;


}




void introduce()

{

	int m;

	printf("�������ѯ������:\n");

	scanf("%d", &m); fflush(stdin);

	if (m >= 1 && m <= N){

		printf("������:%s\t", MGr.view[m].date.number);

		printf("��������:%s\n", MGr.view[m].date.name);

		printf("������:%s\n", MGr.view[m].date.introduce);
	}
	else printf("�޸þ���");

	printf("\n");

}










void input()

{

	int i;

	printf("\n��������ʼ�ڵ�:");

	scanf("%d", &source);/*��ʼ�ڵ������ʼ�ڵ㣨v0)*/

	printf("\n����������ڵ�:");

	scanf("%d", &sink);



	for (i = 1; i <= N; i++)

	{

		S[i] = NOTVISITED;

		D[i] = MGr.length[source][i];

		P[i] = source;

	}

	S[source] = VISITED;

	D[source] = 0;

}

void Push(int value)

{

	if (top >= MaxSize)

	{

		printf("û��·������!\n\n");

		exit(1);

	}

	else

		Stack[++top] = value;

}

int Pop()

{

	if (top < 0)

	{

		printf("û��·������!\n\n");

		exit(1);

	}

	return Stack[top--];

}

int minD()

{

	int i, t = 0;

	long int minimum = Infinite;

	for (i = 1; i <= N; i++)

	if ((S[i] == NOTVISITED) && D[i] < minimum)

	{

		minimum = D[i];

		t = i;

	}

	return t;

}



void output_path()

{

	int node = sink;



	if ((sink == source) || (D[sink] == Infinite))

	{

		printf("\n�ڵ�%d��ڵ�%d֮��û��·�����ڣ�\n\n", source, sink);

		return;

	}

	printf("\n");



	while (node != source)

	{

		Push(node);/*���յ㵽���ѹ*/

		node = P[node];/*p��node����node����һ���ڵ�*/

	}

	printf("V%d��V%d�����·��Ϊ:\n", source, sink);

	printf("  %s", MGr.view[source].date.name);

	while (node != sink)

	{

		node = Pop();

		printf(" --%ld-->", MGr.length[P[node]][node]);

		printf("%s", MGr.view[node].date.name);

	}

	printf("\n");

	printf("\n %d->%d�����·���ǣ� %ld\n", source, sink, D[sink]);/*�ܽ��ܹ��Ƕ���*/

	printf("\n");

}



void distance()

{

	int t, I;

	input();/*��һ�����ݴ洢���α��ϵĵ�һ��*/

	for (step = 2; step <= N; step++)

	{



		t = minD();/*������һ�����С·��*/

		S[t] = VISITED;



		for (I = 1; I <= N; I++)/*�������·���Ĺ���*/

		if ((S[I] == NOTVISITED) && (D[t] + MGr.length[t][I] <= D[I]))

		{

			D[I] = D[t] + MGr.length[t][I];

			P[I] = t;

		}

	}

	output_path();

}





void map()

{

	printf("��������������������������������������������������������������������������������\n");
	printf("������������������������������������                      ������������������  ��\n");
	printf("����13.����         ���� 12.����2 ��������������������������11.������     �ǩ���\n");
	printf("������������������������������������        100m          ������������������  ��\n");
	printf("�� ��       ��������������             300m                ��         ��      ��\n");
	printf("��  ����������10. ҽ���ҩ�������������������������������������    200m��      ��\n");
	printf("��   100m   �������������� ��150m                                     ��      ��\n");
	printf("��                  ����������������                       30m������������������\n");
	printf("��                  ��8.ѧ����ԢŮ��������������������      ����9.ѧ����Ԣ�Щ���\n");
	printf("��                  ����������������      250m ����  ��     ��������������������\n");
	printf("��           ��                                      ��    ����������������   ��\n");
	printf("��                                300m          ��    ���� ��  7.        ��   ��\n");
	printf("���������������������������������������������������������� ��    ����    ��   ��\n");
	printf("����6. ��ѧ������� ������������������              ���� ��     1      ��   ��\n");
	printf("������������������������      200m     ��  ������  ������  ��            ��   ��\n");
	printf("�� ����������������������           ����������������       ����������������   ��\n");
	printf("�� ��                  ������������ ��5. ͼ���   ��                          ��\n");
	printf("�� ��                  ��   50m     ��            ��                          ��\n");
	printf("�� ��    3. ��         ��           ����������������                          ��\n");
	printf("�� ��                  ��                                                     ��\n");
	printf("�� ��       ѧ         ��           ������������                              ��\n");
	printf("�� ��                  ������������ �� 4.     ��                              ��\n");
	printf("�� ��       ¥         ��   40m     ��  ��Ȫ  ��                              ��\n");
	printf("�� ��                  ��           ������������   ����������������           ��\n");
	printf("�� ��                  ��                          ��     ��     ��           ��\n");
	printf("�� ��                  ��                          �� 2.  ��     ��           ��\n");
	printf("�� ��                  ������������������������������     ¥     ��           ��\n");
	printf("�� ����������������������           100m           ����������������           ��\n");
	printf("��                   ��                                 ��                    ��\n");
	printf("��                    ������������                      ��                    ��\n");
	printf("��                       120 m   ��          ������������                     ��\n");
	printf("��                               ��         ��   100 m                        ��\n");
	printf("��                               ��         ��                                ��\n");
	printf("��                               ��         ��                                ��\n");
	printf("��                          ����������������������                            ��\n");
	printf("������������������������������1.�������̴�ѧ���ũ�������������������������������\n");
	printf("��                          ����������������������                            ��\n");
	printf("��                                                                            ��\n");
	printf("��������������������������������������������������������������������������������\n");

	printf("\n");

	

}/*map*/



