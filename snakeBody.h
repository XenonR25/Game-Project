#include <graphics.h>

enum DIR {LEFT , UP , RIGHT , DOWN};        // ENUM MAKES THE WORK EASY BY PROVIDING NAMES INSTEAD OF NUMBERS

////// POSITION STRUCTURE ////// -- ESPICIALLY TO BE USED IN SNAKE ONLY DUE TO ITS PRESET VALUES
struct POS
{
       int x,y;
       POS()
       {
            x = -50;
            y = 0;
       }
};

////// SNAKE CLASS //////
class snakeBody
{
private:
        POS arr[31];            // THIHS ARRAY IS GOING TO CONTAIN THE POSITIONS OF WHOLE SNAKE
        int direction;          // WORKING WITH ENUM !!!
        int length;             // OBVIOUSLY LENGTH
public :
        snakeBody()
        {
              arr[0].x =30 ;
              arr[0].y = 30;
              length = 2;
              direction = RIGHT;
        }
        void drawSnake();
        void appendSnake();
        void changeDirTo(int);
        int update();
        int getPosx();
        int getPosy();
        int getlength();

};

void snakeBody::drawSnake()
{
    for(int i=0; i<length ; i++)
     {
          setcolor(BLUE);

          if(i==0){setcolor(YELLOW);

                  circle(arr[i].x+15 , arr[i].y+15 ,15);
                  setfillstyle(SOLID_FILL , YELLOW);
                    floodfill(arr[i].x+15 , arr[i].y+15 , YELLOW);

                    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL, MAGENTA);

    fillellipse(arr[i].x+20 , arr[i].y+9, 2, 4);
    fillellipse(arr[i].x+10 , arr[i].y+9, 2, 4);

      setcolor(DARKGRAY);

    ellipse(arr[i].x+15, arr[i].y+10, 225, 310 , 20, 10);
     ellipse(arr[i].x+15, arr[i].y+8, 217, 323, 16, 17);
     setfillstyle(SOLID_FILL , DARKGRAY);



                  }
          else   {
        rectangle(arr[i].x+1 , arr[i].y+1 , arr[i].x+30 , arr[i].y+30);
                  setfillstyle(SOLID_FILL , LIGHTGREEN);
          floodfill(arr[i].x+15 , arr[i].y+15 , BLUE);
          }
     }
}


void snakeBody::appendSnake()
{
     if(length < 30)
        length++;
}

void snakeBody::changeDirTo(int newdir)
{
     if(newdir == LEFT || newdir == RIGHT)
     {
            if(direction == UP || direction == DOWN)
                         direction = newdir;
     }
     else if(newdir == UP || newdir == DOWN)
     {
            if(direction == LEFT || direction == RIGHT)
                         direction = newdir;
     }
}

int snakeBody::update()
{
     for(int i=1 ; i<length ; ++i)
     {
             if(arr[0].x == arr[i].x && arr[0].y == arr[i].y)
             {
                         return 0;
             }
     }
     for(int i=length ; i>=0 ; --i)
     {
             if(i==0)
             {
                     arr[1].x = arr[0].x;
                     arr[1].y = arr[0].y;
             }
             else
             {
                     arr[i].x = arr[i-1].x;
                     arr[i].y = arr[i-1].y;
             }
     }
     if(direction == LEFT)
     {
                  arr[0].x -= 30;
                  if(arr[0].x == 0)
                  {
                              arr[0].x = 450;
                  }
     }
     else if(direction == RIGHT)
     {
                  arr[0].x += 30;
                  if(arr[0].x == 480)
                  {
                              arr[0].x = 30;
                  }
     }
     else if(direction == UP)
     {
                  arr[0].y -= 30;
                  if(arr[0].y == 0)
                  {
                              arr[0].y = 450;
                  }
     }
     else if(direction == DOWN)
     {
                  arr[0].y += 30;
                  if(arr[0].y == 480)
                  {
                              arr[0].y = 30;
                  }
     }
     return 1;
}

int snakeBody::getPosx()
{
    return arr[0].x;
}

int snakeBody::getPosy()
{
    return arr[0].y;
}

int snakeBody::getlength()
{
    return length;
}
