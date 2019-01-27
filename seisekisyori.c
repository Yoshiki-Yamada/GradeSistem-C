#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define seisekiMAX 256


int seisekiCount = 0;

struct Seiseki{
	char name[256];
	int kokugo;
	int sansu;
	int rika;
};

struct Seiseki seiseki[seisekiMAX];

/*struct Seiseki* newSeiseki(char name[256],int kokugo,int sansu,int rika){
	struct Seiseki* nSeiseki = (struct Seiseki*)malloc(sizeof(struct Seiseki));
	nSeiseki->name[256]=name[256];
	nSeiseki->kokugo=kokugo;
	nSeiseki->sansu=sansu;
	nSeiseki->rika=rika;
	return nSeiseki;
}*/



void swap(int *x,int *y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

void putSeisekiArray(struct Seiseki *seiseki){
	char buf[256];
	char name[256];
	int kokugo;
	int sansu;
	int rika;
	FILE* fp;
	fp = fopen("data.txt","r");
	if(fp==NULL){
		printf("not file.\n");
		exit(1);
	}
	int i = 0;
	while(fgets(buf,sizeof(buf),fp)!=NULL){
		sscanf(buf,"%s%d%d%d",name,&kokugo,&sansu,&rika);
		strcpy(seiseki[i].name,name);
		seiseki[i].kokugo = kokugo;
		seiseki[i].sansu = sansu;
		seiseki[i].rika = rika;
		i++;
	}
	seisekiCount = i;
	fclose(fp);
	return;
}


void sort(struct Seiseki *seiseki){
	int i,j;
	struct Seiseki temp;
	for(i = 0;i<seisekiCount;i++){
		for(j = seisekiCount-1;j>i;j--){
			if(seiseki[j].kokugo>seiseki[j-1].kokugo){
				temp = seiseki[j];
				seiseki[j] = seiseki[j-1];
				seiseki[j-1] = temp;
			}
		}
	}
	return;
}

void view(){
	int i = 0;
	while(i!=seisekiCount){
		printf("名前：%s,国語：%d,算数：%d,理科：%d\n",seiseki[i].name,seiseki[i].kokugo,seiseki[i].sansu,seiseki[i].rika);
		i++;
	}
	return;
}

void quickSortDown(int left,int right){
	int i,j;

	if(left >= right){
		return;
	}
	i = left + 1;
	j = right;

	while(1){
		while(seiseki[i].kokugo <= seiseki[left].kokugo && i < right){
			i++;
		}

		while(seiseki[j].kokugo >= seiseki[left].kokugo && j > left){
			j--;
		}

		if(i >= j){
			break;
		}

		swap(&seiseki[i].kokugo,&seiseki[j].kokugo);
	}

	swap(&seiseki[left].kokugo,&seiseki[j].kokugo);

	quickSortDown(left,j-1);
	quickSortDown(j+1,right);
}

void quickSortUp(int left,int right){
	int i,j;

	if(left <= right){
		return;
	}
	i = left + 1;
	j = right;

	while(1){
		while(seiseki[i].kokugo > seiseki[left].kokugo && i >= right){
			i++;
		}

		while(seiseki[j].kokugo < seiseki[left].kokugo && j <= left){
			j--;
		}

		if(i <= j){
			break;
		}

		swap(&seiseki[i].kokugo,&seiseki[j].kokugo);
	}

	swap(&seiseki[left].kokugo,&seiseki[j].kokugo);

	quickSortUp(left,j-1);
	quickSortUp(j+1,right);
}

int main(){
	int count;
	char kamoku;

	putSeisekiArray(seiseki);

	printf("ーーーーーーーーー成績一覧ーーーーーーーーーーー\n");
	view();

	while(1){
		printf("ソートする科目を入力");
		scanf("%s",&kamoku);
		printf("整頓方法選択\n");
		scanf("%d",&count);
		if(strcmp(kamoku,"kokugo") == 0){
			if(count == 1){
				printf("ーーーーーーーーー降順に整頓ーーーーーーーーーー\n");
				quickSortDown(0,seisekiCount);
				view();
			}else if(count ==2){
				printf("---------------昇順に整頓----------------\n");
				quickSortUp(0,seisekiCount);
				view();
			}
		}else if(strcmp(kamoku,"sansu") == 0){
				if(count == 1){
				printf("ーーーーーーーーー降順に整頓ーーーーーーーーーー\n");
				quickSortDown(0,seisekiCount);
				view();
			}else if(count ==2){
				printf("---------------昇順に整頓----------------\n");
				quickSortUp(0,seisekiCount);
				view();
			}
		}else if(strcmp(kamoku,"rika") == 0){
				if(count == 1){
				printf("ーーーーーーーーー降順に整頓ーーーーーーーーーー\n");
				quickSortDown(0,seisekiCount);
				view();
			}else if(count ==2){
				printf("---------------昇順に整頓----------------\n");
				quickSortUp(0,seisekiCount);
				view();
			}
		}

	return 0;
}
