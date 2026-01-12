#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define MAX_SIZE     100 
#define w 40
#define h 40




static char snake_game[w*h];
int snake[MAX_SIZE];
int snake_l = 1;

void game_init(){
   for(int i = 0;i<(w*h);i++){
         snake_game[i] = '.';
   }
}
// void clear(){
//     HANDLE ha = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     DWORD count;
//     DWORD cellCount;
//     COORD home = {0, 0};

//     if(ha == INVALID_HANDLE_VALUE) return;

//     GetConsoleScreenBufferInfo(ha, &csbi);
//     cellCount = csbi.dwSize.X * csbi.dwSize.Y;

//     FillConsoleOutputCharacter(ha, ' ', cellCount, home, &count);
//     FillConsoleOutputAttribute(ha, csbi.wAttributes, cellCount, home, &count);
//     SetConsoleCursorPosition(ha, home);
// }
void hide_cursor(){
    HANDLE ha= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(ha, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(ha, &ci);
}


void update(int food){
    COORD topLeft = {0,0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);
    game_init();
    for(int s = 0;s<snake_l;s++){
      snake_game[snake[s]] = '#';
    }
    snake_game[food] = '@';
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            printf("%c ", snake_game[y * w + x]);
        }
        printf("\n");
    }

    
    printf("Score: %d\n", snake_l - 1);
    printf("Press 'q' to quit\n");
    
}

int random_food() {
    int pos;
    bool ok;
    do {
        pos = rand() % (w*h);
        ok = true;

        for(int i=0;i<snake_l;i++){
            if(snake[i]==pos){
                ok = false;
                break;
            }
        }
    } while(!ok);
    return pos;
}

 typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;
 
int main(){
   
   srand(time(NULL));
   snake[0] = (h/2) * w + (w/2); 
   int s_food = random_food(); 
   bool run = true;
   int head =0;
   Direction dir = RIGHT;
   game_init();
   
   
   hide_cursor();
   system("cls");
   while (run)
   { 
      
      
      for(int i = 1; i < snake_l; i++){
               if(snake[i] == head){
                  printf("Game Over! You hit yourself!\n");
                  run = false;
                  break;
               }
      }
          
      
      
      if(_kbhit()){
            char key = _getch();
            switch(key){
               case 'a': if(dir != RIGHT) dir = LEFT;  break;
               case 'd': if(dir != LEFT)  dir = RIGHT; break;
               case 'w': if(dir != DOWN)  dir = UP;    break;
               case 's': if(dir != UP)    dir = DOWN;  break;
               case 'q': run = false;                  break;
            }  
      }

      switch(dir){ 
         case LEFT:  if(head%w > 0)     head--;    break;
         case RIGHT: if(head%w < w-1)   head++;    break;
         case UP:    if(head >= w)      head -= w; break;
         case DOWN:  if(head < w*(h-1)) head += w; break;
         }
         
      
      
      for(int i=snake_l-1;i>0;i--){
         snake[i] = snake[i-1];
      }
      snake[0] = head;
      if(snake[0]==s_food){
         snake_l++;
         if(snake_l >= MAX_SIZE) {
                printf("You Win! Maximum size reached!\n");
                run = false;
            } else {
                s_food = random_food();
         }
      }
      update(s_food);
      Sleep(30);
      
   }


 
 
 return 0;
}
