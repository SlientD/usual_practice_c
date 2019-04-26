#define _CRT_SECURE_NO_WARNINGS 1
#include "short_distance.h"


int A[MaxSize + 1][MaxSize + 1];   /*迪杰斯特拉算法*/
int D[MaxSize + 1];/*起始最短路径*/
int S[MaxSize + 1],/*标志位，0没取出来呢，1已经取出来了*/P[MaxSize + 1]/*取出来的哪一个序号即课本上的k值*/;
int source, sink;/*起始，终点序号*/
int step = 1;






int top = -1;
int Stack[MaxSize + 1];


void init()

{

	int i, j;



	MGr.view[1].num = 1;

	strcpy(MGr.view[1].date.name, "西安工程大学正门");

	strcpy(MGr.view[1].date.number, "001");

	strcpy(MGr.view[1].date.introduce, "位于世界历史文化名城西安，是经国家教育部批准成立的中国西部地区一所以纺织服装为特色的普通本科高等学校，坐落于临潼区陕鼓大道58号，交通便利，旅游景点繁多，校训为：厚德弘毅，博学笃行");


	MGr.view[2].num = 2;

	strcpy(MGr.view[2].date.name, "人文楼");

	strcpy(MGr.view[2].date.number, "002");

	strcpy(MGr.view[2].date.introduce, "是英语专业的办公室所在地，招聘会所在地，文学交流所在地");



	MGr.view[3].num = 3;

	strcpy(MGr.view[3].date.name, "教学区");

	strcpy(MGr.view[3].date.number, "003");

	strcpy(MGr.view[3].date.introduce, "A-D座教学楼。");



	MGr.view[4].num = 4;

	strcpy(MGr.view[4].date.name, "喷泉");

	strcpy(MGr.view[4].date.number, "004");

	strcpy(MGr.view[4].date.introduce, "学校新建的美丽景观，为校庆迎新等做了完美的修饰");



	MGr.view[5].num = 5;

	strcpy(MGr.view[5].date.name, "图书馆");

	strcpy(MGr.view[5].date.number, "005");

	strcpy(MGr.view[5].date.introduce, "前身为西北纺织工学院纺织系资料室，有81年的历史，建馆时继承了大量的珍贵文献，拥有深厚的文化积淀。现可使用互联网进行一站式检索，给同学们提供了良好学习的环境");



	MGr.view[6].num = 6;

	strcpy(MGr.view[6].date.name, "大学生活动中心");

	strcpy(MGr.view[6].date.number, "006");

	strcpy(MGr.view[6].date.introduce, "是学校各大活动的举办场所，拥有着灯光音响等多种设施，丰富了同学的课余生活，且拥有历史悠久的校史馆");



	MGr.view[7].num = 7;

	strcpy(MGr.view[7].date.name, "餐厅1");

	strcpy(MGr.view[7].date.number, "007");

	strcpy(MGr.view[7].date.introduce, "适用于全体师生，负一层拥有超市，一二层均为餐厅，三楼拥有健身房、台球室、咖啡厅等其他娱乐场所");



	MGr.view[8].num = 8;

	strcpy(MGr.view[8].date.name, "学生公寓女");

	strcpy(MGr.view[8].date.number, "008");

	strcpy(MGr.view[8].date.introduce, "这一片均为生活区，是全体女同学的居住所在地");



	MGr.view[9].num = 9;

	strcpy(MGr.view[9].date.name, "学生公寓男");

	strcpy(MGr.view[9].date.number, "009");

	strcpy(MGr.view[9].date.introduce, "全体男同学居住所在地");



	MGr.view[10].num = 10;

	strcpy(MGr.view[10].date.name, "医务室");

	strcpy(MGr.view[10].date.number, "010");

	strcpy(MGr.view[10].date.introduce, "学校提供的为在校师生生病住院提供的地方，可使用大学生医保来进行优惠，拥有着充足的药物和医疗设备");





	MGr.view[11].num = 11;

	strcpy(MGr.view[11].date.name, "体育场");

	strcpy(MGr.view[11].date.number, "011");

	strcpy(MGr.view[11].date.introduce, "拥有羽毛球场，乒乓室，篮球场，跑道及其他运动设施，旁边就是游泳池所在地，是同学们健身锻炼的好地方");






	MGr.view[12].num = 12;

	strcpy(MGr.view[12].date.name, "餐厅2");

	strcpy(MGr.view[12].date.number, "012");

	strcpy(MGr.view[12].date.introduce, "拥有三层食堂，环境良好，适用于全体师生，并具有专为少数民族师生提供的民族餐厅");




	MGr.view[13].num = 13;

	strcpy(MGr.view[13].date.name, "学校东门");

	strcpy(MGr.view[13].date.number, "013");

	strcpy(MGr.view[13].date.introduce, "位于芷阳路，临近芷阳湖温泉，位于一条小吃街上，为同学们晚间夜宵提供了良好的环境");







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

	printf("请输入查询景点编号:\n");

	scanf("%d", &m); fflush(stdin);

	if (m >= 1 && m <= N){

		printf("景点编号:%s\t", MGr.view[m].date.number);

		printf("景点名称:%s\n", MGr.view[m].date.name);

		printf("景点简介:%s\n", MGr.view[m].date.introduce);
	}
	else printf("无该景点");

	printf("\n");

}










void input()

{

	int i;

	printf("\n请输入起始节点:");

	scanf("%d", &source);/*起始节点就是起始节点（v0)*/

	printf("\n请输入结束节点:");

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

		printf("没有路径存在!\n\n");

		exit(1);

	}

	else

		Stack[++top] = value;

}

int Pop()

{

	if (top < 0)

	{

		printf("没有路径存在!\n\n");

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

		printf("\n节点%d与节点%d之间没有路径存在！\n\n", source, sink);

		return;

	}

	printf("\n");



	while (node != source)

	{

		Push(node);/*从终点到起点压*/

		node = P[node];/*p【node】是node的上一个节点*/

	}

	printf("V%d到V%d的最短路径为:\n", source, sink);

	printf("  %s", MGr.view[source].date.name);

	while (node != sink)

	{

		node = Pop();

		printf(" --%ld-->", MGr.length[P[node]][node]);

		printf("%s", MGr.view[node].date.name);

	}

	printf("\n");

	printf("\n %d->%d的最短路径是： %ld\n", source, sink, D[sink]);/*总结总共是多少*/

	printf("\n");

}



void distance()

{

	int t, I;

	input();/*第一组数据存储及课本上的第一列*/

	for (step = 2; step <= N; step++)

	{



		t = minD();/*找这这一组的最小路径*/

		S[t] = VISITED;



		for (I = 1; I <= N; I++)/*更新最短路径的过程*/

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

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃┏━━━━━━━━┓┏━━━━━┓                      ┏━━━━━━━┓  ┃\n");
	printf("┃┃13.东门         ┃┃ 12.餐厅2 ┃━━━━━━━━━━━┫11.体育场     ┣━┃\n");
	printf("┃┗━━━━━━━━┛┗━━━━━┛        100m          ┗━━━━━━━┛  ┃\n");
	printf("┃ ┃       ┏━━━━━┓             300m                ┃         ┃      ┃\n");
	printf("┃  ━━━━┃10. 医务室┃━━━━━━━━━━━━━━━━━　    200m┃      ┃\n");
	printf("┃   100m   ┗━━━━━┛ ┃150m                                     ┃      ┃\n");
	printf("┃                  ┏━━━━━━┓                       30m┏━━━━━━┓┃\n");
	printf("┃                  ┃8.学生公寓女┃━━━━━━━━━      ━┃9.学生公寓男┃┃\n");
	printf("┃                  ┗━━━━━━┛      250m 　　  ┃     ┃┗━━━━━━┛┃\n");
	printf("┃           　                                      ┃    ┏━━━━━━┓   ┃\n");
	printf("┃                                300m          　    ━━ ┃  7.        ┃   ┃\n");
	printf("┃┏━━━━━━━━━┓━━━━━━━━━━━━━━━━━ ┃    餐厅    ┃   ┃\n");
	printf("┃┃6. 大学生活动中心 ┃━━━━━━━━              　　 ┃     1      ┃   ┃\n");
	printf("┃┗━━━━━━━━━┛      200m     ┃  　　　  　　　  ┃            ┃   ┃\n");
	printf("┃ ┏━━━━━━━━━┓           ┏━━━━━━┓       ┗━━━━━━┛   ┃\n");
	printf("┃ ┃                  ┃━━━━━ ┃5. 图书馆   ┃                          ┃\n");
	printf("┃ ┃                  ┃   50m     ┃            ┃                          ┃\n");
	printf("┃ ┃    3. 教         ┃           ┗━━━━━━┛                          ┃\n");
	printf("┃ ┃                  ┃                                                     ┃\n");
	printf("┃ ┃       学         ┃           ┏━━━━┓                              ┃\n");
	printf("┃ ┃                  ┃━━━━━ ┃ 4.     ┃                              ┃\n");
	printf("┃ ┃       楼         ┃   40m     ┃  喷泉  ┃                              ┃\n");
	printf("┃ ┃                  ┃           ┗━━━━┛   ┏━━━━━━┓           ┃\n");
	printf("┃ ┃                  ┃                          ┃     人     ┃           ┃\n");
	printf("┃ ┃                  ┃                          ┃ 2.  文     ┃           ┃\n");
	printf("┃ ┃                  ┃━━━━━━━━━━━━━┃     楼     ┃           ┃\n");
	printf("┃ ┗━━━━━━━━━┛           100m           ┗━━━━━━┛           ┃\n");
	printf("┃                   ┃                                 ┃                    ┃\n");
	printf("┃                    ━━━━━━                      ┃                    ┃\n");
	printf("┃                       120 m   ┃          ━━━━━━                     ┃\n");
	printf("┃                               ┃         ┃   100 m                        ┃\n");
	printf("┃                               ┃         ┃                                ┃\n");
	printf("┃                               ┃         ┃                                ┃\n");
	printf("┃                          ┏━━━━━━━━━┓                            ┃\n");
	printf("┃━━━━━━━━━━━━━┃1.西安工程大学正门┃━━━━━━━━━━━━━━┃\n");
	printf("┃                          ┗━━━━━━━━━┛                            ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	printf("\n");

	

}/*map*/



