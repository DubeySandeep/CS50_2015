//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);
    
    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
        {
         double velocityX = 2*drand48();
         double velocityY = 1;
         updateScoreboard(window, label, points);
          waitForClick();
            // bounce forever
        while (true)
            {
             GEvent event = getNextEvent(MOUSE_EVENT);

                // if we heard one
            if (event != NULL)
                {
                    // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                    {
                        // ensure circle follows top cursor
                    double x = getX(event) ;
                    setLocation(paddle, x - 40, 550);
                     }
                 }
              move(ball, velocityX, velocityY);
              if (getX(ball) + getWidth(ball) >= getWidth(window)||getX(ball)<=0)
                velocityX = -velocityX;
              else if( getY(ball) <= 0)
                {
                 velocityY = -velocityY;
                }
              pause(5);
              GObject object = detectCollision(window, ball);
              if (object != NULL)
                {

                  if (object == paddle) 
                      {
                      velocityY = -velocityY;
                      }
                    
                 else if (strcmp(getType(object), "GRect") == 0 )
                    {
                    bricks--;
                    removeGWindow(window, object);
                    velocityY = -velocityY;
                    points++;
                   updateScoreboard(window, label, points); 
                    }
                }
        
           
 
                 if (getY(ball) + getHeight(ball) >= getHeight(window))   
                    {break;}
                  }   lives--;
                    
                     waitForClick();
                     setLocation(ball,200,300);
                     setLocation(paddle,120,550);
                    }
       
   // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}


/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
GRect rect;
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
            {
             rect = newGRect (j*40 + 5,i*20 + 60,32,10);
            add(window,rect);
            
             if(i==4)
            {setFilled(rect,true);setColor (rect,"YELLOW");}
            if(i==3)
            {setFilled(rect,true);setColor (rect,"ORANGE");}
            if(i==2)
            {setFilled(rect,true);setColor (rect,"GREEN");}
            if(i==1)
            {setFilled(rect,true);setColor (rect,"BLUE");}
            if(i==0)
            {setFilled(rect,true);setColor (rect,"RED");}
            
             }
    }
  
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval circle = newGOval(200, 300,20,20);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);
    return circle;
    // initial velocity
    
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect recta = newGRect(120,550,80,8);
    setColor(recta,"BLACK");
    setFilled(recta,true);
    add(window,recta);
    return recta;
    
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
   GLabel label = newGLabel("");
    setFont(label, "SansSerif-42");
    add(window, label);
    setColor (label,"LIGHT_GRAY");
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 *10, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * 10);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * 10, y + 2 * 10);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
