#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include<stdlib.h>
int check(int* a,int* b,int c,int d,int e)
{
int r=0,i,j;
     for(i=0;i<c-2;i++)
     if(a[i]==d && b[i]==e)
     {r=1;break;}
return r;
}


int getkey()
{
    int ch;

    ch=getch();
    if(ch==0||ch==224)
    {
    ch=getch();
    return ch;
    }
    return ch;
}
int main()
{
 int ya=380,ys,r,z=0,i,wb=1,hs=0,dir=4,len=3,score=0,*x,*y,bx;
 int speedfactor=3,speed=30;
char point[20],high[20],user[50];

 DWORD maxwidth = GetSystemMetrics(SM_CXSCREEN);
 DWORD maxheight = GetSystemMetrics(SM_CYSCREEN);
 initwindow(maxwidth,maxheight+10,"",-3,-3,true,false);
SetCursorPos(maxwidth,0);
//menu
menu:
setactivepage(1);
setvisualpage(1);
cleardevice();
settextstyle(TRIPLEX_FONT,0,9);
setcolor(LIGHTMAGENTA);
outtextxy(150,70,"SNAKE GAME");
settextstyle(BOLD_FONT,0,8);
setcolor(YELLOW);
outtextxy(200,380,"Start New Game");
outtextxy(200,475,"Settings");
outtextxy(200,570,"Exit to Windows");
cursor:
    setcolor(RED);
   outtextxy(50,ya,"->");

//moving along menu
input:settextstyle(BOLD_FONT,0,8);
      r=getkey();
    if(r==72 && ya-r>=380)
      {setcolor(BLACK);outtextxy(50,ya,"->");ya-=95;goto cursor;}
    else if(r==80 && ya+r<=570)
      {setcolor(BLACK);outtextxy(50,ya,"->");ya+=95;goto cursor;}
    else if(r==13 && ya==570)
      exit(0);
     else if(r==13 && ya==380)
      {if(wb==1)    goto with_box;
      else          goto without_box;}
     else if(r==13 && ya==475)
      goto settings;
     else
      goto input;

//settings menu

settings:
{
setactivepage(1);
setvisualpage(1);
cleardevice();
settextstyle(EUROPEAN_FONT,0,7);
setcolor(GREEN);
outtextxy(150,200,"Select Game Type");
outtextxy(150,400,"Speed");
settextstyle(BOLD_FONT,0,8);
ys=200;
mainsetting:
    setcolor(RED);
   outtextxy(50,ys,"->");
barinput:
int bget=getkey();
    if(bget==72 && ys==400)
      {setcolor(BLACK);outtextxy(50,ys,"->");ys-=200;goto mainsetting;}
    else if(bget==80 && ys==200)
      {setcolor(BLACK);outtextxy(50,ys,"->");ys+=200;goto mainsetting;}
    else if(bget==13 && ys==200)
      goto gametype;
    else if(bget==13 && ys==400)
      goto gamespeed;
     else if(bget==27)
      goto menu;
      else
       goto barinput;

gametype:
 {
setactivepage(1);
setvisualpage(1);
cleardevice();
settextstyle(EUROPEAN_FONT,0,9);
setcolor(GREEN);
outtextxy(150,100,"Select Game Style");

settextstyle(BOLD_FONT,0,8);
setcolor(CYAN);
outtextxy(200,400,"With Box");ys=400;
outtextxy(200,500,"Without box");
setcolor(RED);setfillstyle(SOLID_FILL,RED);
if(wb==1) fillellipse(650,440,30,30);
else fillellipse(800,540,30,30);
barsetting:
    setcolor(RED);
   outtextxy(50,ys,"->");
typeinput:
int typeget=getkey();
    if(typeget==72 && ys==500)
      {setcolor(BLACK);outtextxy(50,ys,"->");ys-=100;goto barsetting;}
    else if(typeget==80 && ys==400)
      {setcolor(BLACK);outtextxy(50,ys,"->");ys+=100;goto barsetting;}
    else if(typeget==13 && ys==500)
      {setcolor(BLACK);setfillstyle(SOLID_FILL,BLACK);fillellipse(650,440,30,30);setcolor(RED);setfillstyle(SOLID_FILL,RED);fillellipse(800,540,30,30);wb=0;goto barsetting;}
    else if(typeget==13 && ys==400)
      {setcolor(BLACK);setfillstyle(SOLID_FILL,BLACK);fillellipse(800,540,30,30);setcolor(RED);setfillstyle(SOLID_FILL,RED);fillellipse(650,440,30,30);wb=1;goto barsetting;}
     else if(typeget==27)
      goto settings;
      else
       goto typeinput;
}
gamespeed:
{
setactivepage(1);
setvisualpage(1);
cleardevice();
bx=speedfactor*100+200;
settextstyle(EUROPEAN_FONT,0,10);
setcolor(GREEN);
outtextxy(100,150,"Speed");
setcolor(CYAN);
//box
for(i=0;i<10;i++)
rectangle(200-i,400-i,1100+i,500+i);
barsettings:
setfillstyle(CLOSE_DOT_FILL,GREEN);
bar(200,400,bx,500);
char c[1];
  sprintf(c,"%d",bx/100-2);
  settextstyle(SCRIPT_FONT,0,10);
  outtextxy(640,580,c);
int speedget=getkey();
    if(speedget==77 && bx+speedget<=1100)
      {bx+=100;goto barsettings;}
    else if(speedget==75 && bx-speedget>=300)
      {setfillstyle(SOLID_FILL,BLACK);bar(200,400,bx,500);bx-=100;goto barsettings;}
     else if(speedget==27 || speedget==13)
      {speedfactor=bx/100-2;speed=(9-speedfactor)*10;goto settings;}
      else
       goto barsettings;
}
}





with_box:
{
sprintf(user,"C:/Users/%s/Documents/snake_1.dat",getenv("USERNAME"));
FILE *f;
f=fopen(user,"r");
if(f!=NULL)
     fscanf(f,"%d",&hs);
fclose(f);
 int fx=500,fy=300,sx=50,sy=30,pg=0;
 dir=4;len=3;score=0;
 y=(int*)malloc(3*sizeof(int));
 x=(int*)malloc(3*sizeof(int));
 for(i=0;i<3;i++)
     {x[i]=30+10*i;y[i]=30;}
int border[20]={0,0,maxwidth,0,maxwidth,maxheight,0,maxheight,0,0,30,30,maxwidth-30,30,maxwidth-30,maxheight-30,30,maxheight-30,30,30};
settextstyle(DEFAULT_FONT,0,2);
setcolor(YELLOW);
while(1)
{
setactivepage(pg);
setvisualpage(1-pg);
cleardevice();
setfillstyle(SOLID_FILL,LIGHTBLUE);
fillpoly(10,border);
snake:
     int xc=sx+textwidth("0")/2,yc=sy+textheight("0")/2;
  if((fx-xc)*(fx-xc)+(fy-yc)*(fy-yc)<=125)
     {    score+=10;++len;
          x=(int*)realloc(x,len*sizeof(int));
          y=(int*)realloc(y,len*sizeof(int));
          x[len-1]=sx;y[len-1]=sy;sx=sx;sy=sy;
       random:
            fx=rand()%(maxwidth-35-35+1)+35;
            fy=rand()%(maxheight-35-35+1)+35;
            if(check(x,y,len,fx,fy))
               goto random;
     }
fillellipse(fx,fy,5,5);
fflush(stdin);
if(kbhit())
{
  int k=getkey();
if( (k==72 || k==119) && dir!=2 )     dir=1;
else if( (k==115 || k==80) && dir!=1)    dir=2;
else if( (k==75 || k==97) && dir!=4)    dir=3;
else if( (k==77 || k==100) && dir!=3)    dir=4;
else if(k==27) {free(x);free(y);goto menu;}
}

{
 if(dir==1)           sy-=10;
 else if (dir==2)     sy+=10;
 else if (dir==3)     sx-=10;
 else if (dir==4)     sx+=10;
}

for(i=0;i<len-1;i++)
{
     x[i]=x[i+1];y[i]=y[i+1];
}
x[len-1]=sx;y[len-1]=sy;

delay(speed);
sprintf(point,"Score : %d",score);
sprintf(high,"High Score : %d",hs);
//settextstyle(SIMPLEX_FONT,0,3);
//setcolor(MAGENTA);
outtextxy(maxwidth-300,5,point);
outtextxy(maxwidth-300,maxheight-25,high);

//settextstyle(DEFAULT_FONT,0,2);
//setcolor(RED);
for(i=0;i<len-1;i++)
     outtextxy(x[i],y[i],"0");
//setcolor(YELLOW);
     outtextxy(x[len-1],y[len-1],"0");
//modified snake
/*if(dir==1)     outtextxy(x[len-1],y[len-1],"^");
else if(dir==2)     outtextxy(x[len-1],y[len-1],"v");
else if(dir==3)     outtextxy(x[len-1],y[len-1],"<");
else if(dir==4)     outtextxy(x[len-1],y[len-1],">");*/



     if((sx<30 || sx>maxwidth-41 || sy<30 || sy>maxheight-41) || check(x,y,len,sx,sy))
     {
          if(score>hs)
          {
               f=fopen(user,"w");
               fprintf(f,"%d\n",score);
               fclose(f);
          }
          free(x);free(y);
          setvisualpage(pg);settextstyle(BOLD_FONT,0,10);setcolor(RED);
               outtextxy(100,200,"G A M E");
               outtextxy(700,400,"O V E R");
               delay(3000);goto menu;
     }
pg=1-pg;

}
}

without_box:
{
 int fx0=500,fy0=600,sx0=50,sy0=30,hs0=0,pg0=0,xc0,yc0;
 dir=4;len=3;score=0;
 sprintf(user,"C:/Users/%s/Documents/snake_0.dat",getenv("USERNAME"));
 FILE *f0;
f0=fopen(user,"r");
if(f0!=NULL)
     fscanf(f0,"%d",&hs0);
fclose(f0);
 y=(int*)malloc(len*sizeof(int));
 x=(int*)malloc(len*sizeof(int));
 for(i=0;i<len;i++)
     {x[i]=30+10*i;y[i]=30;}
settextstyle(DEFAULT_FONT,0,2);setcolor(YELLOW);setfillstyle(SOLID_FILL,YELLOW);
while(1)
{
setactivepage(pg0);
setvisualpage(1-pg0);
cleardevice();
     xc0=sx0+textwidth("0")/2;yc0=sy0+textheight("0")/2;
  if((fx0-xc0)*(fx0-xc0)+(fy0-yc0)*(fy0-yc0)<=125)
     {    score+=10;++len;
          x=(int*)realloc(x,len*sizeof(int));
          y=(int*)realloc(y,len*sizeof(int));
          x[len-1]=sx0;y[len-1]=sy0;
      random0:
           fx0=rand()%(maxwidth-5-5+1)+5;
           fy0=rand()%(maxheight-5-5+1)+5;
           if(check(x,y,len,fx0,fy0))
               goto random0;
     }
//setfillstyle(SOLID_FILL,LIGHTGRAY);
fillellipse(fx0,fy0,5,5);
fflush(stdin);
if(kbhit())
{
  int k=getkey();
if( (k==72 || k==119) && dir!=2 )     dir=1;
else if( (k==115 || k==80) && dir!=1)    dir=2;
else if( (k==75 || k==97) && dir!=4)    dir=3;
else if( (k==77 || k==100) && dir!=3)    dir=4;
else if(k==27) {free(x);free(y);goto menu;}
}

{
 if(dir==1)           sy0-=10;
 else if (dir==2)     sy0+=10;
 else if (dir==3)     sx0-=10;
 else if (dir==4)     sx0+=10;
}

for(i=0;i<len-1;i++)
{
     x[i]=x[i+1];y[i]=y[i+1];
}
if(sx0<0) sx0+=(maxwidth-10);
sx0%=maxwidth-10;

if(sy0<0) sy0+=(maxheight-10);
sy0%=maxheight-10;


x[len-1]=sx0;y[len-1]=sy0;

delay(speed);
sprintf(point,"Score : %d",score);
sprintf(high,"High Score : %d",hs0);
//settextstyle(SIMPLEX_FONT,0,3);
//setcolor(MAGENTA);
outtextxy(maxwidth-300,5,point);
outtextxy(maxwidth-300,maxheight-25,high);

//settextstyle(DEFAULT_FONT,0,2);
//setcolor(RED);
for(i=0;i<len-1;i++)
     outtextxy(x[i],y[i],"0");
//setcolor(YELLOW);
     outtextxy(x[len-1],y[len-1],"0");
//modified snake
/*if(dir==1)     outtextxy(x[len-1],y[len-1],"^");
else if(dir==2)     outtextxy(x[len-1],y[len-1],"v");
else if(dir==3)     outtextxy(x[len-1],y[len-1],"<");
else if(dir==4)     outtextxy(x[len-1],y[len-1],">");*/


     if(check(x,y,len,sx0,sy0))
     {
          if(score>hs0)
          {
               f0=fopen(user,"w");
               fprintf(f0,"%d\n",score);
               fclose(f0);
          }
          free(x);free(y);
          setvisualpage(pg0);settextstyle(BOLD_FONT,0,10);setcolor(RED);
               outtextxy(100,200,"G A M E");
               outtextxy(700,400,"O V E R");
               delay(3000);goto menu;
     }
pg0=1-pg0;


}
}


return 0;
}
