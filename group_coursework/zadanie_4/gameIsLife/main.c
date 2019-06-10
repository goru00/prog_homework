#include <time.h>
#include <stdio.h>

#define _WORLD_WIDTH_ 20// Высота игрового поля
#define _WORLD_HEIGHT_ 20//Ширина игрового поля
#define _SIZE_ 10 //Количество "миров" для определения цикличности

// Структура для хранения ячейки
struct point
{
	unsigned int is_live:1;
};
struct cycleWorld
{
	struct point w[_WORLD_WIDTH_][_WORLD_HEIGHT_];
};




struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]; // Мир =)
struct cycleWorld worlds[_SIZE_];

unsigned int randy(int min, int max); //Генерирует псевдослучайные значения от min до max
void initWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]); // Инициализация мира
void printWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]); //Печать мира
unsigned int get_live_count(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]); //Подсчет живых клеток
void readPointNeighbors(signed int nb[][2], unsigned int x, unsigned int y); //Получение координат соседей клетки
unsigned int countLiveNeighbors(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], unsigned int x, unsigned int y); //Сколько живых соседей у клетки (x,y)
void nextGenerations(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]); //Следующее поколение клеток
void copyWorld(struct point src[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point dect[_WORLD_WIDTH_][_WORLD_HEIGHT_]); //Копировать мир
int cmpWorlds(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]); //Сравнить миры 


unsigned int randy(int min, int max){
	//srand(time(NULL));
	return min + rand() % (max - min);
}

void initWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	int i,j,rnd = 0;
	srand(time(NULL)); //Randomagic! Инициализация генератора случайных величин
	for(i = 1; i < _WORLD_WIDTH_;i++){
		for(j = 1; j < _WORLD_HEIGHT_;j++){
			rnd = randy(0, 1001);
			//printf("%d\n",rnd );
			if (rnd%2 == 0){
				world[i][j].is_live = 0;
				//printf("%d ,%d\n", _WORLD_WIDTH_,_WORLD_HEIGHT_ );
			}
			else {
				world[i][j].is_live = 1;
			}
		}
	}
}
void printWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	int i,j=0;
	for(i = 1; i < _WORLD_WIDTH_;i++){
		printf("\n");
		for(j = 1; j <_WORLD_HEIGHT_;j++){
			  if (world[i][j].is_live == 1) {
                printf(" * ");
            } else {
                printf(" ");
            }
		}
	}
	printf("\n---------------------------------------------\n");
}
unsigned int getLiveCount(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	int i,j,count = 0;
	for(i = 1; i < _WORLD_WIDTH_;i++){
		for(j = 1; j < _WORLD_HEIGHT_;j++){
			if (world[i][j].is_live == 1){
				count++;
			}
		}
	}
	return count;
}
void readPointNeighbors(signed int nb[][2], unsigned int x, unsigned int y){
    unsigned int i, j, k = 0;
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
    }
}
unsigned int countLiveNeighbors(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], unsigned int x, unsigned int y){
	unsigned int count = 0;
    unsigned int i;
    signed int nb[8][2];
    signed int _x, _y;
    readPointNeighbors(nb, x, y);
    for (i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];
        if (_x < 0 || _y < 0) {
            continue;
        }
        if (_x >= _WORLD_WIDTH_ || _y >= _WORLD_HEIGHT_) {
            continue;
        }
        if (world[_x][_y].is_live == 1) {
            count++;
        }
    }
    return count;
}

void nextGenerations(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	unsigned int i, j;
    unsigned int live_nb;
    struct point p;
    for (i = 0; i < _WORLD_WIDTH_; i++) {
        for (j = 0; j < _WORLD_HEIGHT_; j++) {
            p = prev_world[i][j];
            live_nb = countLiveNeighbors(prev_world, i, j);
            if (p.is_live == 0) {
                if (live_nb == 3) {
                    world[i][j].is_live = 1;
                }
            } else {
                if (live_nb < 2 || live_nb > 3) {
                    world[i][j].is_live = 0;
                }
            }
        }
    }
}


void copyWorld(struct point src[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point dect[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	unsigned int i,j;
	for (i = 0; i < _WORLD_WIDTH_; i++) {
        for (j = 0; j < _WORLD_HEIGHT_; j++) {
     		dect[i][j]=src[i][j];
        }
    }
}

int cmpWorlds(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_], struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]){
	unsigned int i,j;
	for (i = 0; i < _WORLD_WIDTH_; i++) {
        for (j = 0; j < _WORLD_HEIGHT_; j++) {
 			if(world[i][j].is_live!=prev_world[i][j].is_live){
 				return -1;
 			}
 		}
    }
    return 1;
}


int main(int argc, char const *argv[])
{
	struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
	struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_];	
	initWorld(world);
	int live_points = -1;
	int opt, count = 0;
	int i, cycledCount = 0;
	do {
		printWorld(world);
		copyWorld(world, prev_world);
		copyWorld(world, worlds[cycledCount].w);	

		nextGenerations(world,prev_world);
		opt = cmpWorlds(world, prev_world);
		for (i=0; i<cycledCount;i++){
			if (cmpWorlds(world, worlds[i].w) == 1) {
				opt = 1;
				printf("Циклическая структура\n");
				break;
			}
		}
		live_points = getLiveCount(world);

		printf("Живых клеток - %d\n", live_points);
		if (live_points == 0){
			printf("Все клетки мертвы..=(\n");
		}
		if(cycledCount<_SIZE_){
			cycledCount++;
		}
		else{
			cycledCount = 0;
		}
		count++;
		sleep(1);
	} while (live_points != 0 && opt<0);
	if (opt==1){
			printf("Устойчивая конфигурация достигнута\nКоличество итераций %d\n", count);
		}
		
	
	return 0;
}