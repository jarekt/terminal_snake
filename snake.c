#include <time.h>
#include "../jlib/jlib.h"
#define BORDER '#'
#define FOOD '@'
#define SNAKE 'S'
#define INITIAL_SPEED 12
#define SPEED_INCREASE 0.5
#define SNAKE_LENGHT_LIMIT 2048

int score = 0;
clock_t timer;
typedef enum {north, south, west, east} dir_t;
struct
{
    coord_t xy[SNAKE_LENGHT_LIMIT];
    int lenght;
    dir_t direction;
    float speed;
    float speed_increase;
    coord_t food;
} Snake = { .xy = {{4,3},{3,3},{2,3}}, .lenght = 3, .direction = east, .speed = INITIAL_SPEED};

coord_t screensize = {0,0};

int redraw()
{
    if (returnscreensize().x != screensize.x || returnscreensize().y != screensize.y){
        screensize = returnscreensize();
        return 1;
    }
    return 0;
}
//checks if screensize has changed and updates the var


void gameOver()
{
    beep();
    cls();
    puts("Game over !");
    printf("your score was %d\n\n", score);
    exit(0);
}

void initSnake()
{
    Snake.speed = ((screensize.x + screensize.y)/2)/18;
    Snake.speed_increase = Snake.speed / 16;
}
//draws border, score and stuff

void updateScore()
{
    gotoxy(8,screensize.y-1);
    printf("%d ", score);
}


void drawRect(int x, int y, int x2, int y2, char ch)
{
    gotoxy(x,y);
    for(int i = 0; i < x2; i++) {putchar(ch);}
    gotoxy(x,y+y2-1);//
    for(int i = 0; i < x2; i++) {putchar(ch);}

    for(int i = 0; i < y2; i++)
    {
        gotoxy(x,y+i);
        putchar(ch);
        gotoxy(x+x2-1,y+i);//
        putchar(ch);
    }
    
}
//draws a rectange at x1y1 lenght of sides = x2y2

void drawSnake()
{
    for(int i = 0; i < Snake.lenght; i++)
    {
        gotoxy(Snake.xy[i].x, Snake.xy[i].y);
        //draw at coord
        putchar(SNAKE);
    }
    
}

void drawFood()//posibly not needed
{
    gotoxy(Snake.food.x, Snake.food.y);
    putchar(FOOD);
}

void moveSnake()//remove tail, move array, add new head based on direction
{
    int x = Snake.xy[0].x;
    int y = Snake.xy[0].y;
    //saves initial head for direction determination

    gotoxy(Snake.xy[Snake.lenght-1].x, Snake.xy[Snake.lenght-1].y);
    putchar(' ');//test
    //goes to snake tail and deletes it -- fix

    for(int i = Snake.lenght; i > 0; i--)
    {
        Snake.xy[i-1] = Snake.xy[i-2];//right??
    }
    //moves the snake array to the right

    switch (Snake.direction)
    {
        case north:
            y--;
            break;
        case south:
            y++;
            break;
        case west:
            x--;
            break;           
        case east:
            x++;
            break;    
        default:
            //wut??
            break;
    }
    Snake.xy[0].x = x;
    Snake.xy[0].y = y;
    //adds new snake head

    gotoxy(Snake.xy[0].x,Snake.xy[0].y);
    putchar(SNAKE);
    //draws new head
    
    gotoxy(1,screensize.y);
    printf("x: %d y: %d ", Snake.xy[0].x, Snake.xy[0].y);
}

void generateFood()
{
    int bol = 0;
    gotoxy(Snake.food.x,Snake.food.y);
    putchar(SNAKE);
    //removes last food
    do
    {
        srand(time(0));
        Snake.food.x = 2 + (rand() % (screensize.x -3)); //hopefully prevents out of bounds food
        Snake.food.y = 2 + (rand() % (screensize.y -4)); //-2 for score display
        //generates coords

        for(int i = 0; i < Snake.lenght; i++)
        {
            if (Snake.food.x == Snake.xy[i].x && Snake.food.y == Snake.xy[i].y) {
                bol = 1; //resets loop if collision detected
            }
            
        }
        
    } while (bol);//while colliding with snake
    drawFood();//maybe inline this
    
}

char getKeypress()//pause, change direction, 
{
    if (kbhit()) {
        switch (getch())
        {
            case 'w':
                if(Snake.direction != south){Snake.direction = north;}
                break;
            case 's':
                if(Snake.direction != north){Snake.direction = south;}
                break;
            case 'a':
                if(Snake.direction != east){Snake.direction = west;}
                break;
            case 'd':
                if(Snake.direction != west){Snake.direction = east;}
                break;
            case 'p':
                gotoxy(0,0);//necessary to hide echo? + maybe add more features
                getch();
                break;
            case 'q':
                gameOver();
                break;
            default:
                //do nothing
                break;
        }
    }
    
}

void detectCollision()//with self -> game over, food -> delete food add score (only head checks)
{
    if (Snake.xy[0].x == Snake.food.x && Snake.xy[0].y == Snake.food.y) {
        Snake.lenght++;
        Snake.speed = Snake.speed + SPEED_INCREASE;
        generateFood();
        beep();
        score++;
        updateScore();
    }
    //detect collision with food

    for(int i = 3; i < Snake.lenght; i++)
    {
        if (Snake.xy[i].x == Snake.xy[0].x && Snake.xy[i].y == Snake.xy[0].y) {
            gameOver();
        }
        
    }
    //detects collision of the head

    if (Snake.xy[0].x == 1 || Snake.xy[0].x == screensize.x || Snake.xy[0].y == 1 || Snake.xy[0].y == screensize.y-2) {
        gameOver();
    }
    //collision with wall
}



void mainloop()// must implement speed
{
    while(1){
        getKeypress();//changes head direction etc        
        if (clock() >= (1/Snake.speed * CLOCKS_PER_SEC + timer)) {
            moveSnake();//draws new snake position
            detectCollision();
            timer = clock();
        }
              
    }
}

int main(int argc, char const *argv[])
{
    cls();
    puts("Snake game, press anything pls");//make into draw intro
    getch();
    cls();
    redraw();
    drawRect(1,1,screensize.x,screensize.y-2, BORDER);//-2 for score display
    gotoxy(1,screensize.y-1);//
    puts("score: ");
    drawSnake();
    generateFood();
    drawFood();
    initSnake();
    timer = clock();

    mainloop();//make infinite
    return 0;
    
}
