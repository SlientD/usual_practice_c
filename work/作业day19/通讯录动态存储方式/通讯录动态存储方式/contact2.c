#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void InitDEAFULT(contact_pp _ct)
{
	*_ct = (contact_p)malloc(sizeof(*_ct) + sizeof(person_t)*LIST_DEFAULT);//对原ct进行修改，所以要传其地址
	if (NULL == *_ct)
	{
		printf("error(%d):%s\n", errno, strerror(errno));
		exit(1);
	}
	(*_ct)->cap = LIST_DEFAULT;                             //malloc后有空间才赋值
	(*_ct)->size = 0;
	printf("Init Contact Sucess!\n");

}
void InitFILE(contact_pp _ct, FILE* fp)
{
	contact_p ct,p;
	int size;
	ct=(contact_p)malloc(sizeof(contact_t));
	if (ct)
	{
		fread(ct, sizeof(contact_t), 1, fp);
		size = sizeof(contact_t)+ct->cap*sizeof(person_t);
		p = (contact_p)realloc(ct, size);
		if (p)
		{
			ct = p;
			fread(ct->list, ct->cap*sizeof(person_t), 1, fp);
			*_ct = ct;
			
		}
		else{
			printf("realloc fail\n");
		}
	}
	else{
		printf("melloc fail\n");
	}

}
void Lord(contact_pp _ct)
{
	FILE* fp = fopen(CT_FILE, "rb");
	if (NULL == fp)
	{
		printf("Init firstly!\n");
		InitDEAFULT(_ct);
		return;
	}
	else
	{
		printf("Read file!\n");
		InitFILE(_ct, fp);
	}
	fclose(fp);

}
static int ISFULL(contact_p ct)
{
	if (ct->cap >= ct->size)
	{
		return 1;
	}
	else
	{
		printf("IS full and");
		return 0;
	}
}
static int INC(contact_pp _ct)
{
	int new_size = sizeof(*_ct) + sizeof(person_t)*((*_ct)->cap + INC_DEFAULT);
	contact_p p = (contact_p)realloc(*_ct,new_size);              //realloc扩展空间，第一个参数为扩展空间的地址，第二个为扩展后的总大小
	if (!p)
	{
		printf("INC error!\n");
		printf("error(%d):%s\n", errno, strerror(errno));
		return 0;
	}
	else
	{
		*_ct = p;
		(*_ct)->cap += INC_DEFAULT;
		printf("INC Contact Success!\n");
		return 1;
	}

}


void Show(contact_p ct)
{
	int i ;
	for (i = 0; i < ct->size; i++)
	{ 
		printf("%-3d|", i + 1);
		printf("%-10s|", ct->list[i].name);
		printf(" %-2c|", ct->list[i].sex);
		printf("%-3u|", ct->list[i].age);
		printf("%-20s|", ct->list[i].telephone);
		printf("%-20s|\n", ct->list[i].address);
	}
}
void ADD(contact_pp _ct)
{
	contact_p ct = *_ct;
	int i=(ct->size)++;
	if (ISFULL(ct) || INC(_ct))
	{
		printf("Enter name:");
		scanf("%s", ct->list[i].name);
		printf("Enter sex:");
		scanf(" %c", &(ct->list[i].sex));
		printf("Enter age:");
		scanf("%d", &(ct->list[i].age));
		printf("Enter tel:");
		scanf("%s", ct->list[i].telephone);
		printf("Enter addr:");
		scanf("%s", ct->list[i].address);
	}

}
static Swap(person_p x, person_p y)
{
	person_t tmp = *x;
	*x = *y;
	*y = tmp;
}
void DEL(contact_p ct)
{
	int num=0;
	
	while (!num)
	{
		printf("请输入要删除的序号：");
		scanf("%d", &num);
		if (num > ct->size||num<=0)
		{
			printf("Enter error,please try agin:");
			num = 0;
		}
		else
		{

			Swap(&(ct->list[num - 1]), &(ct->list[ct->size - 1]));
			ct->size--;
		}
	}


}

void MOD(contact_p ct)
{
	int num=0;
	while (!num)
	{
		printf("请输入要修改的序号：");
		scanf("%d", &num);
		if (num > ct->size || num <= 0)
		{
			printf("Enter error,please try agin:");
			num = 0;
		}
		else
		{
			printf("Enter name:");
			scanf("%s", ct->list[num-1].name);
			printf("Enter sex:");
			scanf(" %c", &(ct->list[num-1].sex));
			printf("Enter age:");
			scanf("%d", &(ct->list[num-1].age));
			printf("Enter tel:");
			scanf("%s", ct->list[num-1].telephone);
			printf("Enter addr:");
			scanf("%s", ct->list[num-1].address);
		}

	}
}

void SEARCH(contact_p ct)
{
	printf("请输入被查询人的姓名");
	char pn[20],spn[20];
	scanf("%s", pn);
	int i;
	for (i = 0; i < ct->size; i++)
	{
		strcpy(spn, ct->list[i].name);
		if (!strcmp(pn, spn))
		{
			printf("%-3d|", i + 1);
			printf("%-10s|", ct->list[i].name);
			printf(" %-2c|", ct->list[i].sex);
			printf("%-3u|", ct->list[i].age);
			printf("%-20s|", ct->list[i].telephone);
			printf("%-20s|\n", ct->list[i].address);
			return 1;
		}
	}
		printf("查无此人\n");
}
static int p_cmp(const void* _px,const void* _py)
{
	char* px = ((person_p)_px)->name;
	char* py = ((person_p)_py)->name;
	return strcmp(px, py);

}
void SORT(contact_p ct)
{
	qsort(&(ct->list), ct->size, sizeof(person_t), p_cmp);

}
void CLEAR(contact_p ct)
{
	free(ct);
}

void Save(contact_p ct)
{
	FILE* fp = fopen(CT_FILE, "wb");
	if (NULL == fp)
	{
		printf("opening file error!\n");
		return;
	}
	int size = sizeof(contact_t)+sizeof(person_t)*(ct->cap);
	fwrite(ct, size, 1, fp);
	fclose(fp);
}