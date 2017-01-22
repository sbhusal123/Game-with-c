#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;

char input;
char load[50],scr[50];
bool brk=false;
int firstBallX=0,secondBallX=160,thirdBallX=600,thirdBallY=400,score;
int firstplay=0;

int main()
{

    int loading=0;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    if(firstplay==0)
    {
    setcolor(YELLOW);                       ///setting initial color
    setfillstyle(SOLID_FILL,9);
    rectangle(0,0,639,479);
    floodfill(358,239,YELLOW);

    outtextxy(200,10,"SHOOT THE TARGET");
    outtextxy(160,50,"Developed BY: Surya Bhusal");

    for(loading=100; loading<400; loading+=1)
    {
        setcolor(5);
        rectangle(100,340,400,350);
        rectangle(100,340,loading,350);
        delay(10);
        sprintf(load,"Loading:%d",loading/4+1);
        setcolor(11);
        outtextxy(500,340,load);
    }


    outtextxy(150,400,"Enter c to see controls or any key to begin game.");
    input=_getch();
    if(input=='c')
    {
    cleardevice();
    setcolor(YELLOW);                       ///show controls
    setfillstyle(SOLID_FILL,9);
    rectangle(0,0,639,479);
    floodfill(358,239,YELLOW);

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,RED);
    circle(200,20,10);                   ///red ball position in control screen
    floodfill(200,20,YELLOW);


    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,WHITE);
    circle(350,20,10);                   ///white ball position in control screen
    floodfill(350,20,YELLOW);


        setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(520,20,10);                   ///yellow ball position in control screen
    floodfill(520,20,YELLOW);

    setcolor(BLUE);                       ///show controls
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(80,70,380,280);
    floodfill(90,80,BLUE);

    setcolor(YELLOW);
    outtextxy(100,80,"Keys                                            ");
    outtextxy(300,80,"Controls");

    setcolor(RED);
    outtextxy(100,100,"  a                                               ");
    outtextxy(300,100,"Left         ");
    outtextxy(100,120,"  d                                               ");
    outtextxy(300,120,"Right       ");


    setcolor(WHITE);
    outtextxy(100,140,"  o                                               ");
    outtextxy(300,140,"Left         ");
    outtextxy(100,160,"  p                                               ");
    outtextxy(300,160,"Right       ");
    outtextxy(100,180,"  u                                               ");
    outtextxy(300,180,"Throw      ");

    setcolor(YELLOW);
    outtextxy(100,200,"  h                                               ");
    outtextxy(300,200,"Right       ");
       outtextxy(100,220,"  f                                               ");
    outtextxy(300,220,"Left         ");
    outtextxy(100,240,"  h                                               ");
    outtextxy(300,240,"Up           ");
       outtextxy(100,260,"  f                                               ");
    outtextxy(300,260,"Down       ");

      outtextxy(350,400,"Enter any key to play game.");


    input=_getch();
    }

    }

    while(input!='q')
    {


        if(95+firstBallX>252 || 95+firstBallX<10)          ///display error on moving beyound the support
        {
            outtextxy(200,400,"Can't move further this ball.");
        }


        if(input=='d' &&  95+firstBallX<252)           /// id d pressed move ball forward;
        {
            firstBallX=firstBallX+2;
            input=_getch();
        }


        if(input=='u')
        {
            int positionY=20;
            for(positionY=100; positionY<=385; positionY=positionY+20)
            {

                setcolor(WHITE);
                setfillstyle(SOLID_FILL,WHITE);
                circle(secondBallX,positionY,10);                   ///left top ball position
                floodfill(secondBallX,positionY,WHITE);




                setcolor(BLUE);
                setfillstyle(SOLID_FILL,BLUE);
                circle(secondBallX,positionY-20,10);                   ///clear the movement of ball from up to down
                floodfill(secondBallX,positionY-20,BLUE);
                delay(50);



            }


            if(positionY>380)
            {
                int angle = 0;
                double x=0, y=0;
                int ANGLE=0;
                double X=0,Y=0,dX,dY;                 /// dX and dY are collision vector.
                if(secondBallX<250 && secondBallX>10)
                {
                    if(secondBallX>135 && (secondBallX-(95+firstBallX)>20)  )
                    {

                        for(ANGLE=0; ANGLE<=90; ANGLE++)              /// rod movement.
                        {

                            setcolor(BLUE);            ///rod disappears from  initial position
                            line(10,390,250,390);
                            line(10,391,250,391);

                            Y=-50*sin((ANGLE*3.14)/180);
                               setcolor(RED);

                            circle(95+firstBallX,380+Y,10);                   ///Move red ball upward through support
                            line(20,400+Y-10,130,390);                        /// move support
                            line(20,400+Y-10-1,130,390);              /// to show the support line
                             line(20,400+Y-10-2,130,390);               /// to show the support line
                            line(130,390,260,getmaxy()-Y-83);
                             line(130,390,260,getmaxy()-Y-82);
                              line(130,390,260,getmaxy()-Y-81);
                             Y=-50*sin(((ANGLE-1)*3.14)/180);
                            setcolor(BLUE);
                            line(20,400+Y-10,130,390);                        /// move support
                            line(130,390,260,getmaxy()-Y-83);
                             delay(5);
                             setcolor(GREEN);
                        }

                        for(x = 95+firstBallX ; x < getmaxx(); x+=15)
                        {


                            y = ((secondBallX-130)+150)*sin(angle*3.141/(secondBallX));
                            /// secondBallX is used as the frequency of sine wave to maintain the Horizontal Distance
                            y = 474- (y+100);
                            setcolor(YELLOW);
                            setfillstyle(SOLID_FILL,RED);
                            circle(x, y+Y, 10);                 ///move red ball in parabolic path
                            floodfill(x,y+Y,YELLOW);



                            /// clear the previous parabolic path ball.

                            double yclr=((secondBallX-130)+150)*sin((angle-5)*3.141/(secondBallX));
                             yclr = 474- (yclr+100);
                            setcolor(BLUE);
                            setfillstyle(SOLID_FILL,BLUE);
                            circle(x-15, yclr+Y, 10);
                            floodfill(x-15,yclr+Y,BLUE);

                             setcolor(2);

                            delay(40);
                            angle=angle+5;              /// increase angle by five

                            dX=x-thirdBallX;                   ///collision vector
                            dY=y+Y-thirdBallY;


                            if(   (pow(dX,2)+pow(dY,2))<=400       ) /// if collides then win.
                            {
                                outtextxy(10,10,"You Have Won");
                                brk=true;
                                score++;
                                setcolor(YELLOW);  /// show increased score after win whose color is yellow
                                sprintf(scr,"Your Score Is=%d",score);
                                outtextxy(300,10,scr);
                                setcolor(BLUE);
                                break;
                            }

                            if(x>thirdBallX)              /// if goes beyond the third ball x position.
                            {
                                outtextxy(100,10,"You Loosed.");
                                brk=true;
                            }
                            if(brk==true) /// if lose or win.
                            {
                                break;
                            }
                        }
                        if(brk==true)
                        {
                            break;
                        }
                    }
                    if(brk==true)
                    {
                        break;
                    }
                }
                if(brk==true)
                {
                    break;
                }
            }
            if(brk==true)
            {
                break;
            }

        }

        if(brk==true)
        {
            break;
        }


        if(input=='p')           /// if p pressed move white ball forward;
        {
            secondBallX=secondBallX+2;
            input=_getch();
        }


        if(input=='o')           /// if o pressed move white ball forward;
        {
            secondBallX=secondBallX-2;
            input=_getch();
        }




        if(input=='a' && 95+firstBallX>10)  ///if a pressed red move ball backward
        {
            firstBallX=firstBallX-2;
            input=_getch();
        }


        if(input=='t')  ///if t pressed move yellow ball upward
        {
            thirdBallY=thirdBallY-2;
            input=_getch();
        }



        if(input=='g')  ///if g pressed move yellow ball downward
        {
            thirdBallY=thirdBallY+2;
            input=_getch();
        }


        if(input=='f')  ///if f pressed move yellow ball left
        {
            thirdBallX=thirdBallX-2;
            input=_getch();
        }



        if(input=='h')  ///if h pressed move yellow ball left
        {
            thirdBallX=thirdBallX+2;
            input=_getch();
        }



        cleardevice();            /// clear old screen


        /// display inside loop





        setcolor(RED);
        setfillstyle(SOLID_FILL,BLUE);
        setcolor(GREEN);                         ///   ///setting background color
        floodfill(95,410,RED);



        setcolor(RED);            ///stand support for red ball.
        line(10,390,250,390);
        line(10,391,250,391);


        outtextxy(100,30,"You can make your own target by moving yellow ball with control.");

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,RED);
        circle(95+firstBallX,380,10);                   ///red ball position
        floodfill(95+firstBallX,380,YELLOW);




        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,8);
        circle(130,390,3);                   ///center at support
       floodfill(130,390,YELLOW);


        sprintf(scr,"Your Score Is=%d",score);  /// display score
        outtextxy(300,10,scr);

        setcolor(GREEN);
        setfillstyle(SOLID_FILL,WHITE);
        circle(secondBallX,100,10);                   ///white ball
        floodfill(secondBallX,100,GREEN);

       line(0,110,800,110);
        line(0,111,800,111);                  /// white ball support

        setcolor(RED);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(thirdBallX,thirdBallY,10);                  /// yellow ball position.
        floodfill(thirdBallX,thirdBallY,RED);




        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,5);              /// bottom purple line.
        rectangle(0,460,638,477);
        floodfill(315,466,YELLOW);
        firstplay++;
       input= _getch();

    }
    outtextxy(200,200,"Do you want to play again?(y/n)");
    input=_getch();
    if(input=='y')
    {
        brk=false;
        firstBallX=0;
        secondBallX=20;
        thirdBallX=600;
        thirdBallY=400;
        cleardevice();
        closegraph();
        main();
    }
    closegraph();
}
