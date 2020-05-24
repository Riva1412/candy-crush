#include <SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
int WindowWidth=740;
int WindowHeight=480;

using namespace sf;
using namespace std;
int a[25][25],xpos[10][10],ypos[10][10],iarr[10][10],jarr[10][10];
queue<int>fishchecki,fishcheckj,colchecki,colcheckj,rowchecki,rowcheckj,ostarchecki,ostarcheckj,Lletteri,Lletterj,Tletteri,Tletterj,Fletteri,Fletterj,Jletteri,Jletterj,oTletteri,oTletterj,oLletteri,oLletterj,starchecki,starcheckj,fourchecki,fourcheckj,ofourchecki,ofourcheckj;
int counter=0,game=77;
RenderWindow app(VideoMode(WindowWidth,WindowHeight),"candy crush",Style::Default|Style::Resize);
void start(int ,int);
void fishcheck(){
for(int i=0;i<9;i++){
    for(int j=0 ;j<9 ;j++){
        if (a[i][j]==a[i][j+1]&&a[i+1][j]==a[i][j]&&a[i+1][j+1]==a[i][j]){
            fishchecki.push(i);
            fishcheckj.push(j);
        }
    }
}
}
void fish (){
 while (fishchecki.size()>0){

        for (int i=fishchecki.front(); i>0; i--)
        {
            a[i][fishcheckj.front()]=a[i-1][fishcheckj.front()];
            a[i][fishcheckj.front()+1]=a[i-1][fishcheckj.front()+1];

        }
         a[0][fishcheckj.front()]=rand()%5+1;
          a[0][fishcheckj.front()+1]=rand()%5+1;
                for (int i=fishchecki.front()+1; i>0; i--)
        {
            a[i][fishcheckj.front()+1]=a[i-1][fishcheckj.front()];


        }
         a[0][fishcheckj.front()+1]=rand()%5+1;



if (a[ fishchecki.front()][fishcheckj.front()]==1)
a[ fishchecki.front()+1][fishcheckj.front()]=10+1;
if (a[ fishchecki.front()][fishcheckj.front()]==2)
a[fishchecki.front()+1][fishcheckj.front()]=10+2;
if (a[ fishchecki.front()][fishcheckj.front()]==3)
a[fishchecki.front()+1][fishcheckj.front()]=10+3;
if (a[ fishchecki.front()][fishcheckj.front()]==4)
a[fishchecki.front()+1][fishcheckj.front()]=10+4;
if (a[ fishchecki.front()][fishcheckj.front()]==5)
a[ fishchecki.front()+1][fishcheckj.front()]=10+5;



       fishchecki.pop();
        fishcheckj.pop();

    }
}
void fishdestroy (){
int i=rand()%10;
int j=rand()%10;
for (int k=i ;k>0 ;k++){
    a[k][j]=a[k-1][j];
}
a[0][j]=rand()%5+1;
}
void starcheck(){
    for (int i=0 ;i<9 ;i++){
        for (int j=0 ;j<9 ;j++){
if (a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]&&a[i][j+2]==a[i][j+3]&&a[i][j+3]==a[i][j+4]){
                starchecki.push(i);
                starcheckj.push(j);
            }
            else if(a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j]&&a[i+1][j]==a[i+3][j]&&a[i+1][j]==a[i+4][j]&&a[i+1][j]==a[i+5][j]){
                ostarchecki.push(i);
                ostarcheckj.push(j);
            }
        }
    }

}
void star(){
    while (starchecki.size()>0){
        cout<<"riva";
        for (int i=starchecki.front(); i>0; i--)
        {
            a[i][starcheckj.front()]=a[i-1][starcheckj.front()];
            a[i][starcheckj.front()+1]=a[i-1][starcheckj.front()+1];
            a[i][starcheckj.front()+3]=a[i-1][starcheckj.front()+3];
            a[i][starcheckj.front()+4]=a[i-1][starcheckj.front()+4];
        }
        a[0][starcheckj.front()]=rand()%5+1;




        a[0][starcheckj.front()+1]=rand()%5+1;


a[starchecki.front()][starcheckj.front()+2]=0;



        a[0][starcheckj.front()+3]=rand()%5+1;


        a[0][starcheckj.front()+4]=rand()%5+1;

       starchecki.pop();
        starcheckj.pop();

    }
}
void ostar (){
        while (ostarchecki.size()>0)
    {
        for (int i=ostarchecki.front(); i>0; i--)
        {
            a[i][ostarcheckj.front()]=a[i-1][ostarcheckj.front()];
        }
        a[0][ostarcheckj.front()]=rand()%5+1;


        for (int i=ostarchecki.front()+1; i>0; i--)

        {
            a[i][ostarcheckj.front()]=a[i-1][ostarcheckj.front()];
        }
        a[0][ostarcheckj.front()]=rand()%5+1;





        for (int i=ostarchecki.front()+2; i>0; i--)
        {
            a[i][ostarcheckj.front()]=a[i-1][ostarcheckj.front()];
        }
        a[0][ostarcheckj.front()]=rand()%5+1;

        for (int i=ostarchecki.front()+3; i>0; i--)
        {
            a[i][ostarcheckj.front()]=a[i-1][ostarcheckj.front()];
        }
        a[0][ostarcheckj.front()]=rand()%5+1;

a[ostarchecki.front()+4][ostarcheckj.front()]=0;

        ostarchecki.pop();
        ostarcheckj.pop();

    }
}
void stardestroy(int x){
    for (int i=0 ;i<9 ;i++){
        for (int j=0 ;j<9;j++){
            if (a[i][j]==x){
                for (int m=i; m>0; m--)
        {
            a[m][j]=a[m-1][j];
        }
        a[0][j]=rand()%5+1;
            }
        }
    }
}
void fourcheck (){
for (int i=0 ;i<9 ;i++){
    for (int j=0 ;j<9;j++){
      if (a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+3]){
        fourchecki.push(i);
        fourcheckj.push(j);
      }
      else if (a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j]&&a[i+3][j]==a[i][j]){
        ofourchecki.push(i);
        ofourcheckj.push(j);
      }
    }
}
}
void four(){
while (fourchecki.size()>0){
    for (int i= fourchecki.front();i>0 ;i++){
        a[i][fourcheckj.front()]=a[i-1][fourcheckj.front()];
         a[i][fourcheckj.front()+1]=a[i-1][fourcheckj.front()+1];

           a[i][fourcheckj.front()+3]=a[i-1][fourcheckj.front()+3];
    }
    a[fourchecki.front()][fourcheckj.front()]=1+rand()%5;
    a[fourchecki.front()][fourcheckj.front()+1]=1+rand()%5;
    a[fourchecki.front()][fourcheckj.front()+2]=-a[fourchecki.front()][fourcheckj.front()+2];
    a[fourchecki.front()][fourcheckj.front()+3]=1+rand()%5;
}
}
void fourdestroy(int j){

  for (int i=0 ;i<9 ;i++){
    a[i][j]=rand()%5+1;
  }

}
void ofour(){
while (ofourchecki.size()){
      for (int i=ofourchecki.front(); i>0; i--)
        {
            a[i][ofourcheckj.front()]=a[i-1][ofourcheckj.front()];
        }
        a[0][ofourcheckj.front()]=rand()%5+1;
         for (int i=ofourchecki.front()+1; i>0; i--)
        {
            a[i][ofourcheckj.front()]=a[i-1][ofourcheckj.front()];
        }
        a[0][ofourcheckj.front()+2]=rand()%5+1;
        for (int i=ofourchecki.front()+2; i>0; i--)
        {
            a[i][ofourcheckj.front()]=a[i-1][ofourcheckj.front()];
        }
        a[0][ofourcheckj.front()]=rand()%5+1;
        a[ofourchecki.front()+3][ofourcheckj.front()]= -a[ofourchecki.front()+3][ofourcheckj.front()]-10;
        ofourchecki.pop();
        ofourcheckj.pop();
}
}
void ofourdestroy(int i){
for (int j=0 ;j<9;j++){
    for (int k=i ; k>0;k--){
        a[k][j]=a[k-1][j];
    }
    a[0][j]=rand()%5+1;
}
}
void destroy()
{
    while (colchecki.size()>0)
    {
        for (int i=colchecki.front(); i>0; i--)
        {
            a[i][colcheckj.front()]=a[i-1][colcheckj.front()];

        }
        a[0][colcheckj.front()]=rand()%5+1;


        for (int i=colchecki.front(); i>0; i--)

        {
            a[i][colcheckj.front()+1]=a[i-1][colcheckj.front()+1];

        }
        a[0][colcheckj.front()+1]=rand()%5+1;





        for (int i=colchecki.front(); i>0; i--)
        {
            a[i][colcheckj.front()+2]=a[i-1][colcheckj.front()+2];

        }
        a[0][colcheckj.front()+2]=rand()%5+1;
        colchecki.pop();
        colcheckj.pop();

    }

};
void check (int& x,int& y)
{

    for (int i=0 ; i<9; i++)
    {
        for (int j=0 ; j<9 ; j++)

        {
            if (a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2])
            {
                colchecki.push(i);
                colcheckj.push(j);
            }
            else if (a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j])
            {
                rowchecki.push(i);
                rowcheckj.push(j);

            }

        }

    }
    x=rowchecki.size();
    y=colchecki.size();

}
void arrtexture(Sprite& sp,int x, int y)
{
    for (int i=0 ; i<9; i++)
    {
        for (int j=0 ; j<9 ; j++)
        {

            if (a[i][j]==1)
            {
                sp.setTextureRect(IntRect(0,0,x,y));
            }
            else  if (a[i][j]==2)
            {
                sp.setTextureRect(IntRect(0,y,x,y));
            }
            else  if (a[i][j]==3)
            {
                sp.setTextureRect(IntRect(x,0,x,y));
            }
            else  if (a[i][j]==4)
            {
                sp.setTextureRect(IntRect(x,y,x,y));
            }
            else  if (a[i][j]==5)
            {
                sp.setTextureRect(IntRect(x,y*2,x,y));
            }


            sp.setPosition(j*x,i*y);
            app.draw(sp);
        }
    }
};
void destroy2()
{
    while (rowchecki.size()>0)
    {
        for (int i=rowchecki.front(); i>0; i--)
        {
            a[i][rowcheckj.front()]=a[i-1][rowcheckj.front()];

        }
        a[0][rowcheckj.front()]=rand()%5+1;


        for (int i=rowchecki.front()+1; i>0; i--)

        {
            a[i][rowcheckj.front()]=a[i-1][rowcheckj.front()];

        }
        a[0][rowcheckj.front()]=rand()%5+1;





        for (int i=colchecki.front()+2; i>0; i--)
        {
            a[i][colcheckj.front()]=a[i-1][colcheckj.front()];

        }
        a[0][colcheckj.front()]=rand()%5+1;



        rowchecki.pop();
        rowcheckj.pop();

    }

};

int main()
{ Font font;
sf::Text text,time;
font.loadFromFile("Stoehr Numbers.ttf");

                text.setPosition(500, 50);
                text.setCharacterSize(70);
                text.setFont(font);
                 time.setPosition(500, 100);
                time.setCharacterSize(70);
               time.setFont(font);
                Clock clock;

    app.setFramerateLimit(100);
Text score;
    int click=0;
    srand(time(0));
    Vector2i pos;

    Texture gems,background;
    background.loadFromFile("bg.png");
    Sprite sp,bg;
    int x1,x2,y1,y2;

    bg.setTexture(background);
    gems.loadFromFile("LPCSeasonedTrees.png");
    Vector2u gemsize = gems.getSize();
    gemsize.x/=2;
    gemsize.y/=3;
    sp.setTexture(gems);
    int x=0,y=0;
    start(gemsize.x,gemsize.y);
    for (int i=0 ;i<9 ;i++){
    for(int j=0 ;j<9;j++){
        cout<<a[i][j]<<' ';
    }
    cout<<endl;
}
    while(app.isOpen())
    {
        Event event;

        while(app.pollEvent(event))
        {

            if (event.type==Event::Closed)
                app.close();

            if (event.type==  Event::Resized)
            {
                FloatRect visiblearea(0,0,event.size.width,event.size.height);
                app.setView(View(visiblearea));
            }
            if (event.type==Event::MouseButtonPressed)
            {
                if (event.key.code==Mouse::Left)
                {
                    click++;
                    pos=Mouse::getPosition(app);
                }

            }
        }


    std::ostringstream oss,cloc;
                oss << game;



                text.setString(oss.str());
                text.setColor(sf::Color::Black);


      app.draw(bg);
          arrtexture(sp,gemsize.x,gemsize.y);
        if (counter==0)
        {


            counter++;
        }
//do{
        if (click==1)
        {
            x1=pos.y/gemsize.y;
            y1=pos.x/gemsize.x;
        }
        else if (click==2)
        {
            x2=pos.y/gemsize.y;
            y2=pos.x/gemsize.x;


   swap(a[x1][y1],a[x2][y2]);
   game--;

   click=0;



        }
//}while(game>0);


               app.draw(text);

/*for (int i=0 ;i<9 ;i++){
    for (int j=0 ;j<9;j++){
        int dx,dy;
        dx=xpos[i][j]-jarr[i][j]*gemsize.x;
          dy=ypos[i][j]-iarr[i][j]*gemsize.y;
          if(dx)xpos[i][j]-=dx/abs(dx);
          if(dy)ypos[i][j]-=dy/abs(dy);
    }

}*/
Time elapsed =clock.getElapsedTime();
cloc<< elapsed;

                time.setString(cloc.str());
                time.setColor(sf::Color::Black);

cout <<elapsed .asSeconds()<<endl;

app.display();
        check(x,y);

        while(x>0||y>0)
              {

                  destroy();
                  destroy2();

                  check(x,y);
                 arrtexture(sp,gemsize.x,gemsize.y);
                 for (int i=0 ;i<9 ;i++){
    for(int j=0 ;j<9;j++){
        cout<<a[i][j]<<' ';
    }
    cout<<endl;
}
cout<<endl<<endl;

              }



    }

    return 0;
}

void start(int x,int y)
{
    for (int i=0 ; i<9; i++)
        for (int j=0; j<9; j++)
        {

            a[i][j]=rand()%5+1;
            xpos[i][j]=j*x;
            ypos[i][j]=i*y;
            iarr[i][j]=i;
            jarr[i][j]=j;


        }
};
