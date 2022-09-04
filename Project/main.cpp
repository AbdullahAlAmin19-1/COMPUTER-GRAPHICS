/*
Group Members Information:

Name	            ID
Abdullah Al Amin	19-39502-1
Rezaul Karim	    19-39521-1
Dip Roy	            19-39544-1


Button Interaction

Mouse Left Button  : Wave Start
Mouse Right Button : Wave Stop

Button D : Day Mode
Button N : Night Mode
Button B : Boat Start
Button H : Helicopter Start
Button T : Trump Start
Button R : Rain Mode Starts in City View
Button S : Rain Stop
Button R : Snow Mode Starts in Sea-Mountain View
Button S : Snow Stop

Special Button Right(->) : City View
Special Button Left(<-)  : Sea-Mountain View
Special Button Up(^)     : Day Mode
Special Button Down      : Night Mode
*/

#include <Windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

char mini_shop_1_text[] = "Sweets";
char mini_shop_2_text[] = "Cakes";
char car_shop_text[] = "Arbho Cars & Motors";
char shop_text[] = "Roy General Store";
char station_text[] = "Station";
float heli_movex= 0.0f;
float heli_movey= 0.0f;
float trump_move, trump_1_move = 0.0f;
float trump_speed = 0.0f;
float heli_angle = 0.0f;
float car1_angle = 0.0f;
float car1_move,truck_move_1 = 0.0f;
float truck_tire_rotate_left, van1_tire_rotate_right=0.0f;
float front_car_move, truck_move, van1_move, plane_move,lake_move=0.0f;
float boat_1_move_right,boat_2_move_left,boat_move_right,ship_1_move_right,ship_2_move_left,boat_21_move_right=0.0f;
float cloud_1_move_right=0.0f,cloud_2_move_right=0.0f,cloud_3_move_right=0.0f,cloud_4_move_right=0.0f;
float cloud_5_move_right=0.0f,cloud_6_move_right=0.0,cloud_7_move_right=0.0,cloud_8_move_right=0.0;
float _move1 = 0.0f;
float _angle1 = 0.0f;
float sun_move,moon_move =0.0f;
float station_clock_hour_move,station_clock_minute_move =0.0f;
float rain_move_y,rain_move_x,rain_move_cloud,rain_move_cloud_2=0.0f;
float snow_speed;
float snow_move_y,snow_move_x,snow_move_y1,snow_move_x1,snow_move_cloud,snow_move_cloud_2=0.0f;
float snow_cover=0.0f;
char state='d';
char rise, rain_state;
char snow_state='n';
char show='p';
char snow_value='n';
char lake1='n';
char lake2='n';
int snow_int=0;

void snow_update1(int x);
void disback(int x);
void disback_day(int x);
void disback_night(int x);
void disback_1(int x);


void init()
{
   glLoadIdentity();
   gluOrtho2D(-192, 192, -100, 100);
   //gluOrtho2D(-384, 384, -200, 200);
}

void text_HELVETICA( float x, float y, char *st, int z)
{
    int l,i;
    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,1.0,0.7);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        if(z==10){glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, st[i]);}
        if(z==12){glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);}
        if(z==18){glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);}
    }
}

void text_8_9_BY( float x, float y, char *st, int z)
{
    int l,i;
    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,1.0,0.7);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        if(z==13){glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);}
        if(z==15){glutBitmapCharacter(GLUT_BITMAP_9_BY_15, st[i]);}
    }
}

void star1()         //010101 //2-components,2-serial,2-extra part,1-update
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(240.0f,240.0f,240.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-180,y+95);
        }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-179.3f,95.8f);
    glVertex2f(-180.7f,95.8f);
    glVertex2f(-180.0f,97.5f);
    glEnd();
    glTranslatef(-180.0f,95.0f,0.0f);
    glRotatef(72,0.0f, 0.0f, 1.0f);
    glTranslatef(180.0f,-95.0f,0.0f);
    glColor3ub(240.0f,240.0f,240.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-179.3f,95.8f);
    glVertex2f(-180.7f,95.8f);
    glVertex2f(-180.0f,97.5f);
    glEnd();
    glTranslatef(-180.0f,95.0f,0.0f);
    glRotatef(72,0.0f, 0.0f, 1.0f);
    glTranslatef(180.0f,-95.0f,0.0f);
    glColor3ub(240.0f,240.0f,240.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-179.3f,95.8f);
    glVertex2f(-180.7f,95.8f);
    glVertex2f(-180.0f,97.5f);
    glEnd();
    glTranslatef(-180.0f,95.0f,0.0f);
    glRotatef(72,0.0f, 0.0f, 1.0f);
    glTranslatef(180.0f,-95.0f,0.0f);
    glColor3ub(240.0f,240.0f,240.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-179.3f,95.8f);
    glVertex2f(-180.7f,95.8f);
    glVertex2f(-180.0f,97.5f);
    glEnd();
    glTranslatef(-180.0f,95.0f,0.0f);
    glRotatef(72,0.0f, 0.0f, 1.0f);
    glTranslatef(180.0f,-95.0f,0.0f);
    glColor3ub(240.0f,240.0f,240.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-179.3f,95.8f);
    glVertex2f(-180.7f,95.8f);
    glVertex2f(-180.0f,97.5f);
    glEnd();
    glPopMatrix();
}

void star3()         //010102
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5f,0.5f,0.0f);
    glTranslatef(-180.0f,90.0f,0.0f);
    star1();
    glPopMatrix();
}

void star2()         //010103
{
    star3();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f+72,0.0f,0.0f);
    star3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f+144,0.0f,0.0f);
    star3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f+216,0.0f,0.0f);
    star3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f+288,0.0f,0.0f);
    star3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f+360,0.0f,0.0f);
    star3();
    glPopMatrix();
}

void star()         //0101
{
    star2();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-30.0f,0.0f);
    star2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.9f,0.9f,0.0f);
    glTranslatef(30.0f,-5.0f,0.0f);
    star2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(35.0f,-50.0f,0.0f);
    star2();
    glPopMatrix();
}

void sky()         //0201
{
    if(show=='p')
    {
        glColor3ub(135.0f,206.0f,250.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-192.0f,35.0f);
        glVertex2f(192.0f,35.0f);
       glColor3ub(95.0f,145.0f,235.0f);
        glVertex2f(192.0f,100.0f);
        glVertex2f(-192.0f,100.0f);
        glEnd();
    }
    if(show=='n')
    {
    if(state=='d')
    {
        glColor3ub(65.0f,105.0f,225.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-192.0f,30.0f);
        glVertex2f(192.0f,30.0f);
        glColor3ub(135.0f,206.0f,250.0f);
        glVertex2f(192.0f,100.0f);
        glVertex2f(-192.0f,100.0f);
        glEnd();
    }
    if(state=='n')
    {
        glColor3ub(59.0f,60.0f,72.0f);
        //glColor3ub(25.0f,25.0f,112.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-192.0f,30.0f);
        glVertex2f(192.0f,30.0f);
        //glColor3ub(133.0f,89.0f,187.0f);
        glColor3ub(25.0f,25.0f,112.0f);
        glVertex2f(192.0f,100.0f);
        glVertex2f(-192.0f,100.0f);
        glEnd();
        if(rain_state!='y'){star();}
    }
	//grass
	if(state=='d'){glColor3ub(0.0f,170.0f,0.0f);}
    if(state=='n'){glColor3ub(0.0f,140.0f,0.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-192.0f,0.0f);
	glVertex2f(192.0f,0.0f);
	glVertex2f(192.0f,30.0f);
	glVertex2f(-192.0f,30.0f);
	glEnd();
    }
}

void mountain()    //0301
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //left

    glColor3ub(66.0f,105.0f,47.0f);
    //glColor3ub(140.0f,255.0f,240.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-80.0f,35.0f);
    glVertex2f(0.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(-40.0f,80.0f);
    glEnd();
    //left left
   glColor3ub(140.0f,240.0f,255.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-110.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(-30.0f,35.0f);
    glVertex2f(-60.0f,85.0f);
    glEnd();

      //left left left

    glBegin(GL_TRIANGLES);
    glColor3ub(66.0f,105.0f,47.0f);
    glVertex2f(-140.0f,35.0f);
    glColor3ub(204.0f,255.0f,255.0f);
    glVertex2f(-70.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(-100.0f,75.0f);
    glEnd();
      //left left left left
      glColor3ub(140.0f,240.0f,255.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-180.0f,35.0f);
    glVertex2f(-100.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(-130.0f,85.0f);
    glEnd();
    //middle mountain
   glColor3ub(204.0f,255.0f,255.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-60.0f,35.0f);
     glColor3ub(66.0f,105.0f,47.0f);
    glVertex2f(50.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(0.0f,90.0f);
    glEnd();
    //right
  glColor3ub(140.0f,255.0f,240.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(90.0f,35.0f);

    glVertex2f(40.0f,80.0f);
    glEnd();
        //right right right

    glColor3ub(66.0f,105.0f,47.0f);
 //glColor3ub(140.0f,255.0f,240.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(60.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(150.0f,35.0f);

    glVertex2f(105.0f,75.0f);
    glEnd();
    //right right
    glColor3ub(140.0f,240.0f,240.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(120.0f,35.0f);
    glVertex2f(30.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(70.0f,85.0f);
    glEnd();

      //right right right right
   glColor3ub(140.0f,240.0f,255.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0f,35.0f);
    glVertex2f(180.0f,35.0f);
    glColor3ub(250.0f,250.0f,250.0f);
    glVertex2f(140.0f,85.0f);
    glEnd();


    glPopMatrix();
}

void glacier()         //0401
{
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(235.0f,240.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.5;
            float x = 77*r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y+35);
        }
    glEnd();
}

void grass()         //0501
{
    glColor3ub(235.0f,240.0f,255.0f);
    glBegin(GL_POLYGON);
	glVertex2f(132.0f,3.0f);
	glVertex2f(132.0f,-25.0f);
	glVertex2f(165.0f,-49.0f);
	glVertex2f(192.0f,-53.0f);
	glVertex2f(192.0f,3.0f);
	glEnd();
	glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30;
            float x = 1.1*r * cos(A);
            float y = 0.8* r * sin(A);
            glVertex2f(x+165,y-25);
        }
    glEnd();
}

void bridge()         //0601
{
    glLineWidth(5);
    glColor3ub(150.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-16.0f,-54.0f);
    glVertex2f(-16.0f,-100.0f);
    glVertex2f(-22.0f,-58.0f);
    glVertex2f(-22.0f,-100.0f);
    glVertex2f(16.0f,-54.0f);
    glVertex2f(16.0f,-100.0f);
    glVertex2f(22.0f,-58.0f);
    glVertex2f(22.0f,-100.0f);
    glEnd();
    for(int i=0;i<5;i++)
    {
        glColor3ub(150.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-16.0f,-54.0f-i*10);
        glVertex2f(-22.0f,-58.0f-i*10);
        glVertex2f(-22.0f,-58.0f-i*10);
        glVertex2f(-16.0f,-66.0f-i*10);
        glEnd();
        glColor3ub(150.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(16.0f,-54.0f-i*10);
        glVertex2f(22.0f,-58.0f-i*10);
        glVertex2f(22.0f,-58.0f-i*10);
        glVertex2f(16.0f,-66.0f-i*10);
        glEnd();
    }
}

void bridge_1()         //0602
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLineWidth(0.1);
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<110;i++)
            {
                if(snow_cover>1){glColor3ub(215.0f,228.0f,242.0f);}
                else{glColor3ub(130.0f,130.0f,142.0f);}

                glBegin(GL_POLYGON);
                glVertex2f(-189.0f+i*3,0.0f-j*3);
                glVertex2f(-192.0f+i*3,0.0f-j*3);
                glColor3ub(130.0f,130.0f,142.0f);
                glVertex2f(-192.0f+i*3,1.5f-j*3);
                glVertex2f(-189.0f+i*3,1.5f-j*3);
                glEnd();
            }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<110;i++)
            {
                //glColor3ub(182.0f,170.0f,170.0f);

                if(snow_cover>2){glColor3ub(215.0f,228.0f,242.0f);}
                else{glColor3ub(130.0f,130.0f,142.0f);}
                glBegin(GL_POLYGON);
                glVertex2f(-193.5f+i*3,1.5f-j*3);
                glVertex2f(-190.5f+i*3,1.5f-j*3);
                glColor3ub(130.0f,130.0f,142.0f);
                glVertex2f(-190.5f+i*3,3.0f-j*3);
                glVertex2f(-193.5f+i*3,3.0f-j*3);
                glEnd();
            }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<110;i++)
            {
                glColor3ub(82.0f,70.0f,70.0f);
                glBegin(GL_LINES);
                glVertex2f(-193.5f+i*3,1.5f-j*3);
                glVertex2f(-190.5f+i*3,1.5f-j*3);
                glVertex2f(-193.5f+i*3,0.0f-j*3);
                glVertex2f(-193.5f+i*3,1.5f-j*3);
                glEnd();
            }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<110;i++)
            {
                glColor3ub(82.0f,70.0f,70.0f);
                glBegin(GL_LINES);
                glVertex2f(-192.0f+i*3,3.0f-j*3);
                glVertex2f(-189.0f+i*3,3.0f-j*3);
                glVertex2f(-192.0f+i*3,3.0f-j*3);
                glVertex2f(-192.0f+i*3,1.5f-j*3);
                glEnd();
            }
    }
    glPopMatrix();
}

void road()         //0701
{
    if(show=='p')
    {
        glColor3ub(150.0f,150.0f,165.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-192.0f,3.0f);
	glVertex2f(192.0f,3.0f);
	glVertex2f(192.0f,33.0f);
	glVertex2f(-192.0f,33.0f);
	glEnd();
    }
    else if(show=='n')
    {
    glColor3ub(60.0f,60.0f,60.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-192.0f,5.0f);
	glVertex2f(192.0f,5.0f);
	glVertex2f(192.0f,-25.0f);
	glVertex2f(-192.0f,-25.0f);
	glEnd();
	glColor3ub(60.0f,60.0f,60.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-16.0f,6.0f);
	glVertex2f(-16.0f,-100.0f);
	glVertex2f(16.0f,-100.0f);
	glVertex2f(16.0f,6.0f);
	glEnd();
	glColor3ub(150.0f,158.0f,113.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-192.0f,14.0f);
	glVertex2f(192.0f,14.0f);
	glVertex2f(192.0f,5.0f);
	glVertex2f(-192.0f,5.0f);
	glEnd();
	//trumline
	glLineWidth(2);
	glColor3ub(80.0f,96.0f,100.0f);
	glBegin(GL_LINES);
	glVertex2f(192.0f,8.0f);
	glVertex2f(-192.0f,8.0f);
	glVertex2f(192.0f,11.0f);
	glVertex2f(-192.0f,11.0f);
	glEnd();
    }
}

void roadsign()         //0801
{
    if(show=='p')
    {
    glColor3ub(255.0f,255.0f,255.0f);
    glLineWidth(1.5);

	glBegin(GL_LINES);
	glVertex2f(-192.0f,5.0f);
	glVertex2f(192.0f,5.0f);
	glVertex2f(192.0f,24.0f);
	glVertex2f(-192.0f,24.0f);
	glEnd();
	for(int i=0;i<39;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-192.0f+i*10,15.0f);
        glVertex2f(-188.0f+i*10,15.0f);
        glEnd();
    }
	//trainline
	for(int i=0;i<128;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-191.0f+i*3,26.0f);
        glVertex2f(-190.5f+i*3,26.0f);
        glVertex2f(-190.5f+i*3,31.0f);
        glVertex2f(-191.0f+i*3,31.0f);
        glEnd();
    }
    glLineWidth(2);
	glColor3ub(80.0f,96.0f,100.0f);
	glBegin(GL_LINES);
	glVertex2f(192.0f,27.0f);
	glVertex2f(-192.0f,27.0f);
	glVertex2f(192.0f,30.0f);
	glVertex2f(-192.0f,30.0f);
	glEnd();
    }
    if(show=='n'){
    glLineWidth(1.5);
    glColor3ub(255.0f,255.0f,255.0f);
	glBegin(GL_LINES);
	glVertex2f(-192.0f,5.5f);
	glVertex2f(192.0f,5.5f);

	glVertex2f(-192.0f,-24.0f);
	glVertex2f(-15.0f,-24.0f);
	glVertex2f(15.0f,-24.0f);
	glVertex2f(192.0f,-24.0f);
	glVertex2f(15.0f,-100.0f);
	glVertex2f(15.0f,-24.0f);
	glVertex2f(-15.0f,-100.0f);
	glVertex2f(-15.0f,-24.0f);
	glEnd();
	for(int i=0;i<6;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(0.0f,-40.0f-i*10);
        glVertex2f(0.0f,-44.0f-i*10);
        glEnd();
    }
    for(int i=0;i<17;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-31.0f-i*10,-10.0f);
        glVertex2f(-35.0f-i*10,-10.0f);
        glEnd();
    }
    for(int i=0;i<17;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(31.0f+i*10,-10.0f);
        glVertex2f(35.0f+i*10,-10.0f);
        glEnd();
    }
    //Zebra Crossing
    for(int i=0;i<10;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-14.0f+i*3,-26.0f);
        glVertex2f(-12.0f+i*3,-26.0f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(-14.0f+i*3,-36.0f);
        glVertex2f(-12.0f+i*3,-36.0f);
        glEnd();
    }
    for(int i=0;i<10;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-17.0f,-24.0f+i*3);
        glVertex2f(-17.0f,-22.0f+i*3);
        glEnd();
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-27.0f,-24.0f+i*3);
        glVertex2f(-27.0f,-22.0f+i*3);
        glEnd();
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(17.0f,-24.0f+i*3);
        glVertex2f(17.0f,-22.0f+i*3);
        glEnd();
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(27.0f,-24.0f+i*3);
        glVertex2f(27.0f,-22.0f+i*3);
        glEnd();
    }
    for(int i=0;i<10;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(14.5f-i*3,-27.0f);
        glVertex2f(14.5f-i*3,-35.0f);
        glVertex2f(12.5f-i*3,-35.0f);
        glVertex2f(12.5f-i*3,-27.0f);
        glEnd();
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-18.0f,-23.5f+i*3);
        glVertex2f(-26.0f,-23.5f+i*3);
        glVertex2f(-26.0f,-21.5f+i*3);
        glVertex2f(-18.0f,-21.5f+i*3);
        glEnd();
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(18.0f,-23.5f+i*3);
        glVertex2f(26.0f,-23.5f+i*3);
        glVertex2f(26.0f,-21.5f+i*3);
        glVertex2f(18.0f,-21.5f+i*3);
        glEnd();
    }
    }
}

void traffic()         //0901
{
    glPointSize(3);
    glLineWidth(2.5);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-29.0f,14.5f);
	glVertex2f(-28.0f,23.0f);
	glVertex2f(-17.f,-38.0f);
	glVertex2f(-19.f,-30.0f);
	glVertex2f(-19.f,-30.0f);
	glVertex2f(-3.f,-30.0f);
	glVertex2f(29.f,-20.0f);
	glVertex2f(28.f,-27.0f);
	glVertex2f(29.f,-20.0f);
	glVertex2f(29.f,-11.0f);
	//zebra
    glVertex2f(-32.0f,18.0f);
    glVertex2f(-32.0f,15.0f);
    glVertex2f(32.0f,-23.0f);
    glVertex2f(32.0f,-26.0f);
    glVertex2f(-17.0f,-23.0f);
    glVertex2f(-17.0f,-26.0f);
    glEnd();
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-33.0f,22.0f);
    glVertex2f(-31.0f,22.0f);
    glVertex2f(-31.0f,18.0f);
    glVertex2f(-33.0f,18.0f);
    glEnd();
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-18.0f,-23.0f);
    glVertex2f(-16.0f,-23.0f);
    glVertex2f(-16.0f,-19.0f);
    glVertex2f(-18.0f,-19.0f);
    glEnd();
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(33.0f,-23.0f);
    glVertex2f(31.0f,-23.0f);
    glVertex2f(31.0f,-19.0f);
    glVertex2f(33.0f,-19.0f);
    glEnd();
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-32.0f,19.0f);
    glVertex2f(32.0f,-22.0f);
    glVertex2f(-17.0f,-22.0f);
    glVertex2f(-8.f,-30.0f);
    glVertex2f(29.f,-16.0f);
    glEnd();
    glColor3ub(255.0f,255.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-32.0f,20.0f);
    glVertex2f(32.0f,-21.0f);
    glVertex2f(-17.0f,-21.0f);
    glVertex2f(-6.f,-30.0f);
    glVertex2f(29.f,-14.0f);
    glEnd();
    glColor3ub(0.0f,150.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-32.0f,21.0f);
    glVertex2f(32.0f,-20.0f);
    glVertex2f(-17.0f,-20.0f);
    glVertex2f(-4.f,-30.0f);
    glVertex2f(29.f,-12.0f);
    glEnd();
}

void traffic1()         //0902
{
    glLineWidth(2.5);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(-28.0f,23.0f);
	glVertex2f(-28.0f,-5.0f);
	glEnd();
	glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-28.0f,1.0f);
    glEnd();
    glColor3ub(255.0f,255.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-28.0f,-1.0f);
    glEnd();
    glColor3ub(0.0f,150.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-28.0f,-3.0f);
    glEnd();
}

void ralling1()         //1001
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    for(int i=0;i<80;i++)
    {
    glColor3ub(82.0f,70.0f,70.0f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-194.0f+i*5,-6.5f);
	if(snow_cover>0){
	glColor3ub(215.0f,228.0f,242.0f);}
    glVertex2f(-194.0f+i*5,-11.5f);
    glEnd();
    glLineWidth(3);
    glColor3ub(82.0f,70.0f,70.0f);
    glBegin(GL_LINES);
    glVertex2f(-194.0f+i*5,-10.0f);
    glVertex2f(-189.0f+i*5,-10.0f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-194.0f+i*5,-8.5f);
    glVertex2f(-189.0f+i*5,-8.5f);
    glEnd();
    }
    glPopMatrix();
}

void ralling2()         //1002
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,21.5f,0.0f);
    ralling1();
    glPopMatrix();
}

void ralling3()         //1003
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,28.5f,0.0f);
    ralling1();
    glPopMatrix();
}

void fence()         //1101
{

    glColor3ub(50.0f,50.0f,50.0f);
    //left
    for(int i=0;i<54;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(-190.0f+i*2,-28.0f);
    glVertex2f(-192.0f+i*2,-28.0f);
    glVertex2f(-190.0f+i*2,-26.0f);
    glVertex2f(-192.0f+i*2,-26.0f);
    glVertex2f(-192.0f+i*2,-30.0f);
    glVertex2f(-192.0f+i*2,-26.0f);
    glVertex2f(-190.0f+i*2,-30.0f);
    glVertex2f(-190.0f+i*2,-26.0f);
    glEnd();
    }

    for(int i=0;i<26;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(-74.0f+i*2,-28.0f);
    glVertex2f(-72.0f+i*2,-28.0f);
    glVertex2f(-74.0f+i*2,-26.0f);
    glVertex2f(-72.0f+i*2,-26.0f);
    glVertex2f(-72.0f+i*2,-30.0f);
    glVertex2f(-72.0f+i*2,-26.0f);
    glVertex2f(-74.0f+i*2,-30.0f);
    glVertex2f(-74.0f+i*2,-26.0f);
    glEnd();
    }

    for(int i=0;i<14;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(-21.0f,-30.0f-i*2);
    glVertex2f(-25.0f,-32.0f-i*2);
    glVertex2f(-23.0f,-31.0f-i*2);
    glVertex2f(-23.0f,-34.0f-i*2);
    glVertex2f(-25.0f,-32.0f-i*2);
    glVertex2f(-25.0f,-34.0f-i*2);
    glVertex2f(-21.0f,-32.0f-i*2);
    glVertex2f(-25.0f,-34.0f-i*2);
    glEnd();
    }

    //right
    for(int i=0;i<85;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(190.0f-i*2,-28.0f);
    glVertex2f(192.0f-i*2,-28.0f);
    glVertex2f(190.0f-i*2,-26.0f);
    glVertex2f(192.0f-i*2,-26.0f);
    glVertex2f(190.0f-i*2,-30.0f);
    glVertex2f(190.0f-i*2,-26.0f);
    glEnd();
    }

    for(int i=0;i<3;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(21.0f,-32.0f-i*2);
    glVertex2f(25.0f,-34.0f-i*2);
    glVertex2f(21.0f,-30.0f-i*2);
    glVertex2f(25.0f,-32.0f-i*2);
    glVertex2f(23.0f,-33.0f-i*2);
    glVertex2f(23.0f,-31.0f-i*2);
    glVertex2f(25.0f,-34.0f-i*2);
    glVertex2f(25.0f,-32.0f-i*2);
    glEnd();
    }

    for(int i=0;i<9;i++)
    {
    glBegin(GL_LINES);
    glVertex2f(15.0f,-36.0f-i*2);
    glVertex2f(20.0f,-38.0f-i*2);
    glVertex2f(15.0f,-38.0f-i*2);
    glVertex2f(20.0f,-40.0f-i*2);
    glVertex2f(18.0f,-40.0f-i*2);
    glVertex2f(18.0f,-37.0f-i*2);
    glVertex2f(20.0f,-40.0f-i*2);
    glVertex2f(20.0f,-38.0f-i*2);
    glEnd();
    }
}

void fence_train_top()         //1102
{
    for(int i=0;i<83;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(26.0f+i*2,14.5f);
    glVertex2f(28.0f+i*2,14.5f);
    glVertex2f(26.0f+i*2,16.0f);
    glVertex2f(28.0f+i*2,16.0f);
    glVertex2f(26.0f+i*2,13.0f);
    glVertex2f(26.0f+i*2,16.0f);
    glEnd();
    }

   for(int i=0;i<17;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-16.0f+i*2,14.5f);
    glVertex2f(-18.0f+i*2,14.5f);
    glVertex2f(-16.0f+i*2,16.0f);
    glVertex2f(-18.0f+i*2,16.0f);
    glVertex2f(-18.0f+i*2,13.0f);
    glVertex2f(-18.0f+i*2,16.0f);
    glVertex2f(-16.0f+i*2,13.0f);
    glVertex2f(-16.0f+i*2,16.0f);
    glEnd();
    }
    for(int i=0;i<52;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-130.0f+i*2,14.5f);
    glVertex2f(-132.0f+i*2,14.5f);
    glVertex2f(-130.0f+i*2,16.0f);
    glVertex2f(-132.0f+i*2,16.0f);
    glVertex2f(-130.0f+i*2,13.0f);
    glVertex2f(-130.0f+i*2,16.0f);
    glEnd();
    }
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-132.0f,13.0f);
    glVertex2f(-132.0f,16.0f);
    glEnd();
}

void fence_train_bottom()         //1103
{
    for(int i=0;i<83;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(26.0f+i*2,7.5f);
    glVertex2f(28.0f+i*2,7.5f);
    glVertex2f(26.0f+i*2,9.0f);
    glVertex2f(28.0f+i*2,9.0f);
    glVertex2f(26.0f+i*2,6.0f);
    glVertex2f(26.0f+i*2,9.0f);
    glEnd();
    }

   for(int i=0;i<17;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-16.0f+i*2,7.5f);
    glVertex2f(-18.0f+i*2,7.5f);
    glVertex2f(-16.0f+i*2,9.0f);
    glVertex2f(-18.0f+i*2,9.0f);
    glVertex2f(-18.0f+i*2,6.0f);
    glVertex2f(-18.0f+i*2,9.0f);
    glVertex2f(-16.0f+i*2,6.0f);
    glVertex2f(-16.0f+i*2,9.0f);
    glEnd();
    }

   for(int i=0;i<82;i++)
    {
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.0f+i*2,7.5f);
    glVertex2f(-192.0f+i*2,7.5f);
    glVertex2f(-190.0f+i*2,9.0f);
    glVertex2f(-192.0f+i*2,9.0f);
    glVertex2f(-190.0f+i*2,6.0f);
    glVertex2f(-190.0f+i*2,9.0f);
    glEnd();
    }
}

void lampost_top_1()         //1201
{
    glLineWidth(2.0);
    glPointSize(3.0);
    //top
    for(int i=0;i<14;i++)
    {
        if(snow_cover>0){glColor3ub(215.0f,228.0f,242.0f);}
        else{glColor3ub(0.0f,0.0f,0.0f);}
        glBegin(GL_LINES);
        glVertex2f(-190.0f+i*30,10.0f);
        glColor3ub(0.0f,0.0f,0.0f);
        glVertex2f(-190.0f+i*30,17.0f);
        glVertex2f(-190.0f+i*30,17.0f);
        glVertex2f(-188.0f+i*30,19.0f);
        glVertex2f(-188.0f+i*30,19.0f);
        glVertex2f(-186.0f+i*30,19.0f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(255.0f,255.0f,255.0f);
        glVertex2f(-187.0f+i*30,18.2f);
        glEnd();
    }
}

void lampost_bottom_1()         //1202
{
    glLineWidth(2.0);
    glPointSize(3.0);

        //bottom
        for(int i=0;i<14;i++)
    {
        if(snow_cover>0){glColor3ub(215.0f,228.0f,242.0f);}
        else{glColor3ub(0.0f,0.0f,0.0f);}
        glBegin(GL_LINES);
        glVertex2f(-190.0f+i*30,-11.0f);
        glColor3ub(0.0f,0.0f,0.0f);
        glVertex2f(-190.0f+i*30,-4.0f);
        glVertex2f(-190.0f+i*30,-4.0f);
        glVertex2f(-188.0f+i*30,-2.0f);
        glVertex2f(-188.0f+i*30,-2.0f);
        glVertex2f(-186.0f+i*30,-2.0f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(255.0f,255.0f,255.0f);
        glVertex2f(-187.0f+i*30,-3.0f);
        glEnd();
    }

}

void lampost()         //1203
{
    glLineWidth(2.0);
    glPointSize(3.0);
    //bottom_right
    for(int i=0;i<6;i++)
    {
        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(190.0f-i*30,-30.0f);
        glVertex2f(190.0f-i*30,-23.0f);
        glVertex2f(190.0f-i*30,-23.0f);
        glVertex2f(188.0f-i*30,-21.0f);
        glVertex2f(188.0f-i*30,-21.0f);
        glVertex2f(186.0f-i*30,-21.0f);
        glEnd();
        glBegin(GL_POINTS);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
        glVertex2f(187.0f-i*30,-21.8);
        glEnd();
    }
    //bottom_left
    for(int i=0;i<6;i++)
    {
        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-190.0f+i*30,-30.0f);
        glVertex2f(-190.0f+i*30,-23.0f);
        glVertex2f(-190.0f+i*30,-23.0f);
        glVertex2f(-188.0f+i*30,-21.0f);
        glVertex2f(-188.0f+i*30,-21.0f);
        glVertex2f(-186.0f+i*30,-21.0f);
        glEnd();
        glBegin(GL_POINTS);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
        glVertex2f(-187.0f+i*30,-21.8f);
        glEnd();
    }
    //upper part
    glLineWidth(1.3);
    glPointSize(2.5);
    for(int i=0;i<6;i++)
    {
        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-180.0f+i*30,19.0f);
        glVertex2f(-180.0f+i*30,25.0f);
        glVertex2f(-180.0f+i*30,25.0f);
        glVertex2f(-182.0f+i*30,26.0f);
        glVertex2f(-182.0f+i*30,26.0f);
        glVertex2f(-183.5f+i*30,26.0f);
        glEnd();
        glBegin(GL_POINTS);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
        glVertex2f(-182.8f+i*30,25.7f);
        glEnd();
    }
    for(int i=0;i<7;i++)
    {
        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(3.0f+i*30,19.0f);
        glVertex2f(3.0f+i*30,25.0f);
        glVertex2f(3.0f+i*30,25.0f);
        glVertex2f(0.0f+i*30,26.0f);
        glVertex2f(0.0f+i*30,26.0f);
        glVertex2f(-1.5f+i*30,26.0f);
        glEnd();
        glBegin(GL_POINTS);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
        glVertex2f(-0.8f+i*30,25.7f);
        glEnd();
    }
}

void tree_1()         //1301
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-215.0,10.0f,0.0f);

    glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(179.5f,-48.5f);
	glVertex2f(179.5f,-36.0f);
	glVertex2f(181.0f,-36.0f);
	glVertex2f(181.0f,-48.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+180,y-36);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+177.5,y-38);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+182.5,y-38);
        }
    glEnd();

     glPopMatrix();
}

void tree_2()         //1302
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-218.0,10.0f,0.0f);

    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(190.0f,-49.5f);
	glVertex2f(190.0f,-42.0f);
	glVertex2f(191.0f,-42.0f);
	glVertex2f(191.0f,-49.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(187.0f,-47.5f);
	glVertex2f(190.5f,-39.0f);
	glVertex2f(194.0f,-47.5f);
	glEnd();

	    glPopMatrix();
}

void tree_3()         //1303
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-345.0,5.0f,0.0f);

    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(169.0f,-46.5f);
	glVertex2f(169.0f,-34.0f);
	glVertex2f(170.0f,-34.0f);
	glVertex2f(170.0f,-46.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+169.5,y-36);
        }
    glEnd();
    glPopMatrix();
}

void tree_4()         //1304
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-150.0,2.0f,0.0f);

    tree_1();
    glPopMatrix();
}

void tree_5()         //1305
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-160.0,-2.0f,0.0f);
    tree_2();
    glPopMatrix();
}

void tree_6()         //1306
{
    glColor3ub(102.0f,51.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-187.5f,32.5f);
	glVertex2f(-187.5f,20.0f);
	glVertex2f(-189.0f,20.0f);
	glVertex2f(-189.0f,32.5f);
	glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(5.0f,105.0f,5.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-188,y+34);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(5.0f,105.0f,5.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-185.5,y+32);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(5.0f,105.0f,5.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-190.5,y+32);
        }
    glEnd();
}

void tree_7()         //1307
{
    glColor3ub(102.0f,51.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-183.5f,30.0f);
	glVertex2f(-183.5f,20.0f);
	glVertex2f(-185.5f,20.0f);
	glVertex2f(-185.5f,30.0f);
	glEnd();
    glColor3ub(0.0f,172.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-179.0f,27.0f);
	glVertex2f(-190.0f,27.0f);
	glColor3ub(123.0f,225.0f,30.0f);
	glVertex2f(-184.5f,40.0f);
	glEnd();
}

void tree_8()         //1308
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3ub(102.0f,51.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-117.5f,32.5f);
	glVertex2f(-117.5f,20.0f);
	glVertex2f(-119.0f,20.0f);
	glVertex2f(-119.0f,32.5f);
	glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(34.0f,142.0f,34.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-118,y+41);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(34.0f,142.0f,34.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-114.0,y+35);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(34.0f,142.0f,34.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-122.0,y+35);
        }
    glEnd();
    glPopMatrix();
}

void tree_9()         //1309
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(330.0,-45.0f,0.0f);
    glColor3ub(51.0f,25.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-185.5f,30.0f);
	glVertex2f(-183.5f,30.0f);
	if(snow_cover>-1){
	glColor3ub(215.0f,228.0f,242.0f);}
	glVertex2f(-183.5f,20.0f);
	glVertex2f(-185.5f,20.0f);
	glEnd();
    glColor3ub(66.0f,105.0f,47.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-179.0f,27.0f);
	glVertex2f(-190.0f,27.0f);
	if(snow_cover>0){
	//glColor3ub(215.0f,228.0f,242.0f);
	glColor3ub(100.0f,100.0f,100.0f);}
	glVertex2f(-184.5f,40.0f);
	glEnd();
	glPopMatrix();
}

void field_tree()         //1310
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    tree_1();
    tree_2();
    tree_3();
    tree_4();
    tree_5();
    glPopMatrix();
}

void field_tree1()         //1311
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(30.0,0.0f,0.0f);
    tree_4();
    tree_5();
    tree_3();
    glPopMatrix();
}

void field_tree2()         //1312
{
    tree_6();
    tree_8();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(19.0,0.0f,0.0f);
    tree_8();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(57.0,0.0f,0.0f);
    tree_8();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(130.0,0.0f,0.0f);
    tree_6();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(136.0,0.0f,0.0f);
    tree_8();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(225.0,3.5f,0.0f);
    tree_6();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(215.0,0.0f,0.0f);
    tree_7();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(170.0,0.0f,0.0f);
    tree_8();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(240.0,0.0f,0.0f);
    tree_8();
    glPopMatrix();
}

void field_tree3()         //1313
{
    tree_7();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(52.0,0.0f,0.0f);
    tree_7();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(94.0,0.0f,0.0f);
    tree_7();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(168.0,0.0f,0.0f);
    tree_7();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(270.0,0.0f,0.0f);
    tree_7();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(312.0,-1.0f,0.0f);
    tree_7();
    glPopMatrix();
}

void field_tree4()         //1314
{
    tree_9();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(20.0,0.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(40.0,0.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-5.0,-10.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(10.0,-8.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(30.0,-5.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3.0,-20.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(18.0,-15.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(28.0,-20.0f,0.0f);
    tree_9();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(38.0,-17.0f,0.0f);
    tree_9();
    glPopMatrix();

}

void park_tree()         //1315
{
    //1
    glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(179.5f,-48.5f);
	glVertex2f(179.5f,-36.0f);
	glVertex2f(181.0f,-36.0f);
	glVertex2f(181.0f,-48.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+180,y-36);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+177.5,y-38);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+182.5,y-38);
        }
    glEnd();

    //2
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(149.5f,-43.5f);
	glVertex2f(149.5f,-31.0f);
	glVertex2f(151.0f,-31.0f);
	glVertex2f(151.0f,-43.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+150,y-31);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+147.5,y-33);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+152.5,y-33);
        }
    glEnd();

     //3
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(169.0f,-46.5f);
	glVertex2f(169.0f,-34.0f);
	glVertex2f(170.0f,-34.0f);
	glVertex2f(170.0f,-46.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+169.5,y-36);
        }
    glEnd();

     //4
    	 	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(125.5f,-46.5f);
	glVertex2f(125.5f,-34.0f);
	glVertex2f(127.0f,-34.0f);
	glVertex2f(127.0f,-46.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+126,y-34);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+123.5,y-36);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+128.5,y-36);
        }
    glEnd();


     //6
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(190.0f,-49.5f);
	glVertex2f(190.0f,-42.0f);
	glVertex2f(191.0f,-42.0f);
	glVertex2f(191.0f,-49.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(187.0f,-47.5f);
	glVertex2f(190.5f,-39.0f);
	glVertex2f(194.0f,-47.5f);
	glEnd();

        //7

    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(140.0f,-45.5f);
	glVertex2f(140.0f,-38.0f);
	glVertex2f(141.0f,-38.0f);
	glVertex2f(141.0f,-45.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(137.0f,-43.5f);
	glVertex2f(140.5f,-33.0f);
	glVertex2f(144.0f,-43.5f);
	glEnd();

	//8
	glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(80.0f,-48.5f);
	glVertex2f(80.0f,-36.0f);
	glVertex2f(82.0f,-36.0f);
	glVertex2f(82.0f,-48.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+81,y-36);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+78.5,y-38);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+83.5,y-38);
        }
    glEnd();

    //8
     	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(99.0f,-45.5f);
	glVertex2f(99.0f,-38.0f);
	glVertex2f(100.0f,-38.0f);
	glVertex2f(100.0f,-45.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(96.0f,-43.5f);
	glVertex2f(99.5f,-33.0f);
	glVertex2f(103.0f,-43.5f);
	glEnd();

	//11

    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(70.0f,-46.5f);
	glVertex2f(70.0f,-34.0f);
	glVertex2f(71.0f,-34.0f);
	glVertex2f(71.0f,-46.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+70.5,y-36);
        }
    glEnd();
      //13
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40.0f,-49.5f);
	glVertex2f(40.0f,-38.0f);
	glVertex2f(41.0f,-38.0f);
	glVertex2f(41.0f,-49.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+40.5,y-39);
        }
    glEnd();
    //15
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(50.0f,-49.5f);
	glVertex2f(50.0f,-42.0f);
	glVertex2f(51.0f,-42.0f);
	glVertex2f(51.0f,-49.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(47.0f,-47.5f);
	glVertex2f(50.5f,-39.0f);
	glVertex2f(54.0f,-47.5f);
	glEnd();


    //16
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(29.5f,-48.5f);
	glVertex2f(29.5f,-36.0f);
	glVertex2f(31.0f,-36.0f);
	glVertex2f(31.0f,-48.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+30,y-36);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+27.5,y-38);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+32.5,y-38);
        }
    glEnd();

    //17
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(181.5f,-63.5f);
	glVertex2f(181.5f,-51.0f);
	glVertex2f(183.0f,-51.0f);
	glVertex2f(183.0f,-63.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+182,y-51);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+179.5,y-53);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+184.5,y-53);
        }
    glEnd();

    //18
     glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(188.0f,-70.5f);
	glVertex2f(188.0f,-58.0f);
	glVertex2f(189.0f,-58.0f);
	glVertex2f(189.0f,-70.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+188.5,y-60);
        }
    glEnd();

    //19
        	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(160.0f,-68.5f);
	glVertex2f(160.0f,-56.0f);
	glVertex2f(161.0f,-56.0f);
	glVertex2f(161.0f,-68.5f);
	glEnd();

	  glColor3ub(0.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(157.0f,-66.5f);
	glVertex2f(160.5f,-55.0f);
	glVertex2f(164.0f,-66.5f);
	glEnd();

	//20
	  //2
    	 glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(149.5f,-63.5f);
	glVertex2f(149.5f,-51.0f);
	glVertex2f(151.0f,-51.0f);
	glVertex2f(151.0f,-63.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+150,y-51);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+147.5,y-53);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+152.5,y-53);
        }
    glEnd();

    //
     glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(133.0f,-58.5f);
	glVertex2f(133.0f,-46.0f);
	glVertex2f(134.0f,-46.0f);
	glVertex2f(134.0f,-58.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+133.5,y-48);
        }
    glEnd();
}

void mini_shop_side()         //1401
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-95.0, 50.0f, 0.0f);
    glScalef(0.8f,0.8f,0.0f);

    glTranslatef(-8.0, 13.0f, 0.0f);
    //tree
    glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(179.5f,-48.5f);
	glVertex2f(179.5f,-36.0f);
	glVertex2f(181.0f,-36.0f);
	glVertex2f(181.0f,-48.5f);
	glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+180,y-36);
        }
    glEnd();
       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+177.5,y-38);
        }
    glEnd();
          glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
             glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+182.5,y-38);
        }
    glEnd();
    glTranslatef(8.0, -13.0f, 0.0f);

    //banch
    glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(160.0f,-33.0f);
	glVertex2f(170.0f,-33.0f);
	glVertex2f(170.0f,-34.0f);
	glVertex2f(160.0f,-34.0f);
	glEnd();

	glLineWidth(1.0);
    glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(160.5f,-32.0f);
	glVertex2f(169.5f,-32.0f);

	glVertex2f(160.5f,-31.0f);
	glVertex2f(169.5f,-31.0f);

    glVertex2f(160.5f,-30.0f);
	glVertex2f(169.5f,-30.0f);

	glVertex2f(161.5f,-29.0f);
	glVertex2f(161.5f,-36.0f);

	glVertex2f(168.5f,-29.0f);
	glVertex2f(168.5f,-36.0f);
    glEnd();
    glPopMatrix();
}

void Bush_1()         //1502
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(18.0,0.0f,0.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+100,y-60);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+102,y-59);
        }
    glEnd();

      glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();


       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+106,y-59);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+107,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+105,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+103,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+101,y-61);
        }
    glEnd();

     glPopMatrix();
}

void Bush_2()         //1503
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-13.0,28.0f,0.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+100,y-60);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+102,y-59);
        }
    glEnd();

      glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();


       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+106,y-59);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+107,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+105,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+103,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+101,y-61);
        }
    glEnd();

     glPopMatrix();
}

void Bush_3()         //1504
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-43.0,16.0f,0.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+100,y-60);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+102,y-59);
        }
    glEnd();

      glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();


       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+106,y-59);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+107,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+105,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+103,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+101,y-61);
        }
    glEnd();

     glPopMatrix();
}

void Bush_4()         //1505
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(5.0,14.0f,0.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+100,y-60);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+102,y-59);
        }
    glEnd();

      glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+104,y-58.5);
        }
    glEnd();


       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+106,y-59);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+107,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+105,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+103,y-61);
        }
    glEnd();

     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
               glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+101,y-61);
        }
    glEnd();

     glPopMatrix();
}

void Bush_5()         //1506
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-155.0,17.0f,0.0f);
    Bush_1();
    glPopMatrix();
}

void Bush_6()         //1507
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-285.0,25.0f,0.0f);
    Bush_1();
    glPopMatrix();
}

void bush()         //1501
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Bush_1();
    Bush_2();
    Bush_3();
    Bush_4();
    Bush_5();
    Bush_6();
    glPopMatrix();
}

void Dusbin()         //1601
{
    glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(25.0f,-49.0f);
	glVertex2f(24.0f,-46.0f);
	glVertex2f(28.0f,-46.0f);
	glVertex2f(27.0f,-49.0f);

	glEnd();

	glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(95.0f,-49.0f);
	glVertex2f(94.0f,-46.0f);
	glVertex2f(98.0f,-46.0f);
	glVertex2f(97.0f,-49.0f);

	glEnd();

	glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(175.0f,-49.0f);
	glVertex2f(174.0f,-46.0f);
	glVertex2f(178.0f,-46.0f);
	glVertex2f(177.0f,-49.0f);

	glEnd();

	glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(185.0f,-35.0f);
	glVertex2f(184.0f,-32.0f);
	glVertex2f(188.0f,-32.0f);
	glVertex2f(187.0f,-35.0f);

	glEnd();

	glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(135.0f,-35.0f);
	glVertex2f(134.0f,-32.0f);
	glVertex2f(138.0f,-32.0f);
	glVertex2f(137.0f,-35.0f);

	glEnd();

	glColor3ub(60.0f,60.0f,145.0f);
	glBegin(GL_POLYGON);
	glVertex2f(63.0f,-35.0f);
	glVertex2f(62.0f,-32.0f);
	glVertex2f(66.0f,-32.0f);
	glVertex2f(65.0f,-35.0f);

	glEnd();
}

void post_box_park()         //1701
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-2.0, -23.0f, 0.0f);
    glScalef(0.5f,0.4f,0.0f);
    //top
    glLineWidth(1.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+45.0f,y-5.0f);
        }
    glEnd();

    //body
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(43.0f,-15.0f);
    glVertex2f(47.0f,-15.0f);
    glVertex2f(47.0f,-5.0f);
    glVertex2f(43.0f,-5.0f);
    glEnd();

    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(48.0f,-6.0f);
    glVertex2f(42.0f,-6.0f);
    glEnd();

    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(46.0f,-8.0f);
    glVertex2f(44.0f,-8.0f);
    glEnd();

    glColor3ub(255.0f,255.0f,255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(44.0f,-13.0f);
    glVertex2f(46.0f,-13.0f);
    glVertex2f(46.0f,-10.0f);
    glVertex2f(44.0f,-10.0f);
    glEnd();


    //bottom
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(42.0f,-17.0f);
    glVertex2f(48.0f,-17.0f);
    glVertex2f(47.0f,-15.0f);
    glVertex2f(43.0f,-15.0f);
    glEnd();
    glPopMatrix();
}

void post_box_trump()         //1702
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-152.5, 43.0f, 0.0f);
    glScalef(1.0f,0.8,0.0f);
    post_box_park();
    glPopMatrix();
}

void footpath()         //1801
{
    //buttom
    if(state=='d'){glColor3ub(255.0f,130.0f,130.0f);}
    if(state=='n'){glColor3ub(230.0f,105.0f,105.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-192.0f,-25.0f);
	glVertex2f(-192.0f,-30.0f);
	glVertex2f(-16.0f,-30.0f);
	glVertex2f(-16.0f,-25.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-16.0f,-30.0f);
	glVertex2f(-21.0f,-30.0f);
	glVertex2f(-21.0f,-56.5f);
	glVertex2f(-16.0f,-53.5f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(192.0f,-25.0f);
	glVertex2f(192.0f,-30.0f);
	glVertex2f(16.0f,-30.0f);
	glVertex2f(16.0f,-25.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(16.0f,-30.0f);
	glVertex2f(21.0f,-30.0f);
	glVertex2f(21.0f,-56.5f);
	glVertex2f(16.0f,-53.5f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glVertex2f(-192.0f,14.0f);
	glVertex2f(-192.0f,19.0f);
	glVertex2f(192.0f,19.0f);
	glVertex2f(192.0f,14.0f);
	glEnd();
	glLineWidth(2.5);
    if(state=='d'){glColor3ub(168.0f,134.0f,135.0f);}
    if(state=='n'){glColor3ub(148.0f,94.0f,95.0f);}
	glBegin(GL_LINES);
	glVertex2f(-192.0f,14.0f);
	glVertex2f(192.0f,14.0f);
	glVertex2f(-16.0f,-25.0f);
	glVertex2f(-192.0f,-25.0f);
	glVertex2f(16.0f,-53.5f);
	glVertex2f(16.0f,-25.0f);
	glVertex2f(16.0f,-25.0f);
	glVertex2f(192.0f,-25.0f);
	glVertex2f(-16.0f,-53.5f);
	glVertex2f(-16.0f,-25.0f);
	glEnd();
}

void park_road()         //1901
{
    if(state=='d'){glColor3ub(255.0f,130.0f,130.0f);}
    if(state=='n'){glColor3ub(230.0f,105.0f,105.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(21.0f,-36.0f);
	glVertex2f(192.0f,-36.0f);
	glVertex2f(192.0f,-41.0f);
	glVertex2f(21.0f,-41.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(21.0f,-50.0f);
	glVertex2f(192.0f,-50.0f);
	glVertex2f(192.0f,-55.0f);
	glVertex2f(21.0f,-55.0f);
	glEnd();
}

void park_bench()         //2001
{
    //1
	  glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(160.0f,-33.0f);
	glVertex2f(170.0f,-33.0f);
	glVertex2f(170.0f,-34.0f);
	glVertex2f(160.0f,-34.0f);
	glEnd();

	glLineWidth(1.0);
	  glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
   glVertex2f(160.5f,-32.0f);
	glVertex2f(169.5f,-32.0f);

	glVertex2f(160.5f,-31.0f);
	glVertex2f(169.5f,-31.0f);

    glVertex2f(160.5f,-30.0f);
	glVertex2f(169.5f,-30.0f);

	glVertex2f(161.5f,-29.0f);
	glVertex2f(161.5f,-36.0f);

	glVertex2f(168.5f,-29.0f);
	glVertex2f(168.5f,-36.0f);
    glEnd();

    //2
      glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(100.0f,-33.0f);
	glVertex2f(110.0f,-33.0f);
	glVertex2f(110.0f,-34.0f);
	glVertex2f(100.0f,-34.0f);
	glEnd();

	glLineWidth(1.0);
	  glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
   glVertex2f(100.5f,-32.0f);
	glVertex2f(109.5f,-32.0f);

	glVertex2f(100.5f,-31.0f);
	glVertex2f(109.5f,-31.0f);

    glVertex2f(100.5f,-30.0f);
	glVertex2f(109.5f,-30.0f);

	glVertex2f(101.5f,-29.0f);
	glVertex2f(101.5f,-36.0f);

	glVertex2f(108.5f,-29.0f);
	glVertex2f(108.5f,-36.0f);
    glEnd();

      //3
      glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40.0f,-33.0f);
	glVertex2f(50.0f,-33.0f);
	glVertex2f(50.0f,-34.0f);
	glVertex2f(40.0f,-34.0f);
	glEnd();

	glLineWidth(1.0);
	  glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
   glVertex2f(40.5f,-32.0f);
	glVertex2f(49.5f,-32.0f);

	glVertex2f(40.5f,-31.0f);
	glVertex2f(49.5f,-31.0f);

    glVertex2f(40.5f,-30.0f);
	glVertex2f(49.5f,-30.0f);

	glVertex2f(41.5f,-29.0f);
	glVertex2f(41.5f,-36.0f);

	glVertex2f(48.5f,-29.0f);
	glVertex2f(48.5f,-36.0f);
    glEnd();

    //4
	  glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(170.0f,-63.0f);
	glVertex2f(180.0f,-63.0f);
	glVertex2f(180.0f,-64.0f);
	glVertex2f(170.0f,-64.0f);
	glEnd();


	glLineWidth(1.0);
	  glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
   glVertex2f(170.5f,-62.0f);
	glVertex2f(179.5f,-62.0f);

	glVertex2f(170.5f,-61.0f);
	glVertex2f(179.5f,-61.0f);

    glVertex2f(170.5f,-60.0f);
	glVertex2f(179.5f,-60.0f);

	glVertex2f(171.5f,-59.0f);
	glVertex2f(171.5f,-66.0f);

	glVertex2f(178.5f,-59.0f);
	glVertex2f(178.5f,-66.0f);
    glEnd();

     //5
	  glColor3ub(153.0f,76.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(130.0f,-63.0f);
	glVertex2f(140.0f,-63.0f);
	glVertex2f(140.0f,-64.0f);
	glVertex2f(130.0f,-64.0f);
	glEnd();


	glLineWidth(1.0);
	  glColor3ub(153.0f,76.0f,0.0f);
    glBegin(GL_LINES);
   glVertex2f(130.5f,-62.0f);
	glVertex2f(139.5f,-62.0f);

	glVertex2f(130.5f,-61.0f);
	glVertex2f(139.5f,-61.0f);

    glVertex2f(130.5f,-60.0f);
	glVertex2f(139.5f,-60.0f);

	glVertex2f(131.5f,-59.0f);
	glVertex2f(131.5f,-66.0f);

	glVertex2f(138.5f,-59.0f);
	glVertex2f(138.5f,-66.0f);
    glEnd();
}

void dock()         //2101
{
    //body
    glLineWidth(0.1);
    glColor3ub(170.0f,100.0f,70.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-58.0f,-45.0f);
	glVertex2f(-107.0f,-45.0f);
	glVertex2f(-107.0f,-52.0f);
	glVertex2f(-58.0f,-52.0f);
	glEnd();
	glColor3ub(170.0f,100.0f,70.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-73.0f,-45.0f);
	glVertex2f(-83.0f,-45.0f);
	glVertex2f(-83.0f,-30.0f);
	glVertex2f(-73.0f,-30.0f);
	glEnd();
	for(int i=0;i<3;i++)
    {
        glColor3ub(170.0f,100.0f,70.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-93.0f+i*14,-52.0f);
        glVertex2f(-100.0f+i*14,-52.0f);
        glVertex2f(-100.0f+i*14,-65.0f);
        glVertex2f(-93.0f+i*14,-65.0f);
        glEnd();
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-93.0f+i*14,-52.0f);
        glVertex2f(-93.0f+i*14,-65.0f);
        glVertex2f(-100.0f+i*14,-52.0f);
        glVertex2f(-100.0f+i*14,-65.0f);
        glVertex2f(-93.0f+i*14,-65.0f);
        glVertex2f(-100.0f+i*14,-65.0f);
        glEnd();
    }
    //border
	glColor3ub(102.0f,51.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-73.0f,-45.0f);
    glVertex2f(-73.0f,-30.0f);
    glVertex2f(-83.0f,-45.0f);
	glVertex2f(-83.0f,-30.0f);
    glVertex2f(-83.0f,-45.0f);
	glVertex2f(-107.0f,-45.0f);
	glVertex2f(-58.0f,-45.0f);
	glVertex2f(-73.0f,-45.0f);
	glVertex2f(-107.0f,-45.0f);
	glVertex2f(-107.0f,-52.0f);
	glVertex2f(-107.0f,-52.0f);
	glVertex2f(-100.0f,-52.0f);
	glVertex2f(-93.0f,-52.0f);
	glVertex2f(-86.0f,-52.0f);
	glVertex2f(-79.0f,-52.0f);
	glVertex2f(-72.0f,-52.0f);
	glVertex2f(-65.0f,-52.0f);
	glVertex2f(-58.0f,-52.0f);
	glVertex2f(-58.0f,-52.0f);
	glVertex2f(-58.0f,-45.0f);
    glEnd();
	for(int i=0;i<8;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-83.0f,-30.0f-i*2);
        glVertex2f(-73.0f,-30.0f-i*2);
        glEnd();
    }
    //Pillar
    glLineWidth(3);
    glColor3ub(102.0f,51.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-83.0f,-30.0f);
    glVertex2f(-84.0f,-28.0f);
    glVertex2f(-83.0f,-45.0f);
    glVertex2f(-84.0f,-43.0f);
    glVertex2f(-107.0f,-45.0f);
    glVertex2f(-108.0f,-43.0f);
    glVertex2f(-73.0f,-30.0f);
    glVertex2f(-74.0f,-28.0f);
    glVertex2f(-73.0f,-45.0f);
    glVertex2f(-74.0f,-43.0f);
    glVertex2f(-57.0f,-47.0f);
    glVertex2f(-59.0f,-43.0f);
    glVertex2f(-57.0f,-53.0f);
    glVertex2f(-59.0f,-50.0f);
    glEnd();
    for(int i=0;i<6;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-64.0f-i*7,-66.0f);
        glVertex2f(-66.0f-i*7,-64.0f);
        glEnd();
    }
    for(int i=0;i<7;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-107.0f+i*7,-52.0f);
        glVertex2f(-108.0f+i*7,-50.0f);
        glEnd();
    }
    //rope
    glLineWidth(0.1);
    glColor3ub(102.0f,51.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-84.0f,-28.0f);
    glVertex2f(-84.0f,-43.0f);
    glVertex2f(-84.0f,-43.0f);
    glVertex2f(-108.0f,-43.0f);
    glVertex2f(-108.0f,-43.0f);
    glVertex2f(-108.0f,-50.0f);
    glVertex2f(-74.0f,-28.0f);
    glVertex2f(-74.0f,-43.0f);
    glVertex2f(-74.0f,-43.0f);
    glVertex2f(-59.0f,-43.0f);
    glVertex2f(-59.0f,-43.0f);
    glVertex2f(-59.0f,-50.0f);
    glEnd();
    for(int i=0;i<4;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-108.0f+i*14,-50.0f);
        glVertex2f(-101.0f+i*14,-50.0f);
        glEnd();
    }
    for(int i=0;i<6;i++)
    {
        glColor3ub(102.0f,51.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-101.0f+i*7,-50.0f);
        glVertex2f(-101.0f+i*7,-64.0f);
        glEnd();
    }
}

void building1()         //2201
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8f, 0.8f, 0.0f);
    glTranslatef(140.0f, 5.0f, 0.0f);
    //body
    if(state=='d'){glColor3ub(251.0f,246.0f,205.0f);}
    if(state=='n'){glColor3ub(221.0f,216.0f,175.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-30.0f,19.0f);
	glVertex2f(10.0f,19.0f);
	glVertex2f(10.0f,50.0f);
	glVertex2f(-30.0f,50.0f);
	glEnd();

	//bottom window
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,70.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-28.0f,21.0f);
	glVertex2f(0.0f,21.0f);
	glVertex2f(0.0f,29.0f);
	glVertex2f(-28.0f,29.0f);
	glEnd();

	//door
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(90.0f,154.0f,196.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(2.0f,19.0f);
	glVertex2f(8.0f,19.0f);
	glVertex2f(8.0f,27.0f);
	glVertex2f(2.0f,27.0f);
	glEnd();

	//door
	glLineWidth(2);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(5.0f,19.0f);
	glVertex2f(5.0f,27.0f);
	glEnd();

	//roof
    glColor3ub(202.0f,161.0f,128.0f);
    glBegin(GL_LINES);
	glVertex2f(-30.0f,31.0f);
	glVertex2f(10.0f,31.0f);
	glEnd();

	//mid window
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(90.0f,154.0f,196.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-28.0f,33.0f);
	glVertex2f(0.0f,33.0f);
	glVertex2f(0.0f,41.0f);
	glVertex2f(-28.0f,41.0f);
	glEnd();

	//top window
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,70.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-28.0f,44.0f);
	glVertex2f(0.0f,44.0f);
	glVertex2f(0.0f,48.0f);
	glVertex2f(-28.0f,48.0f);
	glEnd();

	for(int i=0;i<2;i++)
	{
    //small window left
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(2.0f,33.0f+i*11);
	glVertex2f(4.0f,33.0f+i*11);
	glVertex2f(4.0f,37.0f+i*11);
	glVertex2f(2.0f,37.0f+i*11);
	glEnd();

	//small window right
    if(state=='d'){glColor3ub(70.0f,124.0f,166.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(6.0f,33.0f+i*11);
	glVertex2f(8.0f,33.0f+i*11);
	glVertex2f(8.0f,37.0f+i*11);
	glVertex2f(6.0f,37.0f+i*11);
	glEnd();
	}

	//top
    glColor3ub(177.0f,68.0f,46.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-30.0f,50.0f);
	glVertex2f(10.0f,50.0f);
	glVertex2f(12.0f,52.0f);
	glVertex2f(-32.0f,52.0f);
	glEnd();
	glPopMatrix();
}

void building2()         //2202
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8f, 0.8f, 0.0f);
    glTranslatef(50.0f, 5.0f, 0.0f);

    glLineWidth(0.1);
    if(state=='d'){glColor3ub(122.0f,224.0f,245.0f);}
    if(state=='n'){glColor3ub(92.0f,185.0f,210.0f);}
    glBegin(GL_POLYGON);
    glVertex2f(25.0f,19.0f);
    glVertex2f(25.0f,73.0f);
    glVertex2f(55.0f,73.0f);
    glVertex2f(55.0f,19.0f);
    glEnd();
    glColor3ub(222.0f,235.0f,240.0f);
    glBegin(GL_POLYGON);
    glVertex2f(27.0f,26.0f);
    glVertex2f(27.0f,71.0f);
    glVertex2f(53.0f,71.0f);
    glVertex2f(53.0f,26.0f);
    glEnd();
    glLineWidth(0.1);
    if(state=='d'){glColor3ub(222.0f,235.0f,240.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
    glVertex2f(30.0f,19.0f);
    glVertex2f(30.0f,24.0f);
    glVertex2f(50.0f,24.0f);
    glVertex2f(50.0f,19.0f);
    glEnd();
    glColor3ub(164.0f,189.0f,198.0f);
    glBegin(GL_LINES);
    glVertex2f(30.0f,24.0f);
    glVertex2f(50.0f,24.0f);
    glEnd();
    for(int i=0;i<7;i++)
    {
        glColor3ub(164.0f,189.0f,198.0f);
        glBegin(GL_LINES);
        glVertex2f(27.0f+i*4,26.0f);
        glVertex2f(27.0f+i*4,71.0f);
        glEnd();
    }
    for(int i=0;i<16;i++)
    {
        glColor3ub(164.0f,189.0f,198.0f);
        glBegin(GL_LINES);
        glVertex2f(27.0f,71.0f-i*3);
        glVertex2f(53.0f,71.0f-i*3);
        glEnd();
    }
    for(int i=0;i<3;i++)
    {
        glColor3ub(164.0f,189.0f,198.0f);
        glBegin(GL_LINES);
        glVertex2f(30.0f+i*10,19.0f);
        glVertex2f(30.0f+i*10,24.0f);
        glEnd();
    }
    glPopMatrix();
}

void building3()         //2203
{
    glLineWidth(0.1);
    if(state=='d'){glColor3ub(84.0f,149.0f,94.0f);}
    if(state=='n'){glColor3ub(54.0f,119.0f,74.0f);}
    glBegin(GL_POLYGON);
    glVertex2f(-15.0f,19.0f);
    glVertex2f(-15.0f,60.0f);
    glVertex2f(15.0f,60.0f);
    glVertex2f(15.0f,19.0f);
    glEnd();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(state=='d'){glColor3ub(54.0f,119.0f,74.0f);}
            if(state=='n'){glColor3ub(51.0f,25.0f,25.0f);}
            glBegin(GL_POLYGON);
            glVertex2f(-11.25f+i*8.75,52.0f-j*8);
            glVertex2f(-11.25f+i*8.75,58.0f-j*8);
            glVertex2f(-6.25f+i*8.75,58.0f-j*8);
            glVertex2f(-6.25f+i*8.75,52.0f-j*8);
            glEnd();
            if(state=='d'){glColor3ub(212.0f,225.0f,230.0f);}
            if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
            glBegin(GL_POLYGON);
            glVertex2f(-10.75f+i*8.75,52.5f-j*8);
            glVertex2f(-10.75f+i*8.75,57.5f-j*8);
            glVertex2f(-6.75f+i*8.75,57.5f-j*8);
            glVertex2f(-6.75f+i*8.75,52.5f-j*8);
            glEnd();
        }
    }
    glColor3ub(101.0f,51.0f,9.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.0f,19.0f);
    glVertex2f(-3.0f,24.0f);
    glVertex2f(0.0f,24.0f);
    glVertex2f(0.0f,19.0f);
    glEnd();
    glColor3ub(91.0f,41.0f,6.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,19.0f);
    glVertex2f(0.0f,24.0f);
    glVertex2f(3.0f,24.0f);
    glVertex2f(3.0f,19.0f);
    glEnd();
}

void building4()         //2204
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8f, 0.8f, 0.0f);
    glTranslatef(-180.0f, 14.5f, 0.0f);
    //ground
    glColor3ub(137.0f,112.0f,94.0f);
    glBegin(GL_POLYGON);
	glVertex2f(70.0f,9.0f);
	glVertex2f(100.0f,9.0f);
	glVertex2f(100.0f,19.0f);
	glVertex2f(70.0f,19.0f);
	glEnd();

	glLineWidth(3);
	glColor3ub(92.0f,63.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(70.0f,19.0f);
	glVertex2f(70.0f,9.0f);
	glVertex2f(100.0f,19.0f);
	glVertex2f(100.0f,9.0f);
	glEnd();

    glColor3ub(251.0f,246.0f,205.0f);
    glBegin(GL_LINES);
	glVertex2f(68.0f,18.0f);
	glVertex2f(102.0f,18.0f);
	glEnd();

    //window
	if(state=='d'){glColor3ub(103.0f,167.0f,217.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(72.0f,10.0f);
	glVertex2f(92.0f,10.0f);
	glVertex2f(92.0f,16.0f);
	glVertex2f(72.0f,16.0f);
	glEnd();

	//door
	if(state=='d'){glColor3ub(103.0f,167.0f,217.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(94.0f,9.0f);
	glVertex2f(98.0f,9.0f);
	glVertex2f(98.0f,16.0f);
	glVertex2f(94.0f,16.0f);
	glEnd();

    for(int i=0;i<4;i++)
	{
    //body
    glColor3ub(137.0f,112.0f,94.0f);
    glBegin(GL_POLYGON);
	glVertex2f(70.0f,19.0f+i*10);
	glVertex2f(100.0f,19.0f+i*10);
	glVertex2f(100.0f,29.0f+i*10);
	glVertex2f(70.0f,29.0f+i*10);
	glEnd();

	// left middle right part
	glLineWidth(3);
	glColor3ub(92.0f,63.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(70.0f,19.0f+i*10);
	glVertex2f(70.0f,29.0f+i*10);
	glVertex2f(85.0f,19.0f+i*10);
	glVertex2f(85.0f,29.0f+i*10);
	glVertex2f(100.0f,19.0f+i*10);
	glVertex2f(100.0f,29.0f+i*10);
	glEnd();

	//roof
	glLineWidth(3);
    glColor3ub(251.0f,246.0f,205.0f);
    glBegin(GL_LINES);
	glVertex2f(68.0f,28.0f+i*10);
	glVertex2f(102.0f,28.0f+i*10);
	glEnd();

	//left window
	if(state=='d'){glColor3ub(103.0f,167.0f,217.0f);}
    if(state=='n' && i%2==0){glColor3ub(255.0f,255.0f,112.0f);}
    else{glColor3ub(103.0f,167.0f,217.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(73.0f,21.0f+i*10);
	glVertex2f(82.0f,21.0f+i*10);
	glVertex2f(82.0f,26.0f+i*10);
	glVertex2f(73.0f,26.0f+i*10);
	glEnd();

	//right window
	if(state=='d'){glColor3ub(103.0f,167.0f,217.0f);}
    if(state=='n' && i%2!=0){glColor3ub(255.0f,255.0f,112.0f);}
    else{glColor3ub(103.0f,167.0f,217.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(88.0f,21.0f+i*10);
	glVertex2f(97.0f,21.0f+i*10);
	glVertex2f(97.0f,26.0f+i*10);
	glVertex2f(88.0f,26.0f+i*10);
	glEnd();
	}
	glPopMatrix();
}

void mall()         //2205
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8f, 0.8f, 0.0f);
    glTranslatef(15.0f, 4.5f, 0.0f);
    for (int i=0;i<5;i++)
    {
        //body
        glColor3ub(70.0f,124.0f,166.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-86.0f,19.0f+i*10);
        glVertex2f(-39.0f,19.0f+i*10);
        glVertex2f(-39.0f,29.0f+i*10);
        glVertex2f(-86.0f,29.0f+i*10);
        glEnd();

        // mid body
        glColor3ub(155.0f,202.0,234.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-84.0f,21.0f+i*10);
        glVertex2f(-41.0f,21.0f+i*10);
        glVertex2f(-41.0f,27.0f+i*10);
        glVertex2f(-84.0f,27.0f+i*10);
        glEnd();

        // mid line
        glLineWidth(5);
        glColor3ub(70.0f,124.0f,166.0f);
        glBegin(GL_LINES);
        glVertex2f(-58.0f,21.0f+i*10);
        glVertex2f(-58.0f,27.0f+i*10);
        glEnd();

        // right line-1
        glLineWidth(5);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,102.0f);}
        glBegin(GL_LINES);
        glVertex2f(-51.0f,21.0f+i*10);
        glVertex2f(-51.0f,27.0f+i*10);
        glEnd();

        // right line-2
        glLineWidth(5);
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-47.0f,21.0f+i*10);
        glVertex2f(-47.0f,27.0f+i*10);
        glEnd();

        // left line-1
        glLineWidth(5);
        if(state=='d'){glColor3ub(255.0f,255.0f,255.0f);}
        if(state=='n'){glColor3ub(255.0f,255.0f,102.0f);}
        glBegin(GL_LINES);
        glVertex2f(-64.0f,21.0f+i*10);
        glVertex2f(-64.0f,27.0f+i*10);
        glEnd();

        // left line-2
        glLineWidth(5);
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-68.0f,21.0f+i*10);
        glVertex2f(-68.0f,27.0f+i*10);
        glEnd();

        if(i==4)
        {

        //top mid
        glColor3ub(70.0f,124.0f,166.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-86.0f,35.0f+i*10);
        glVertex2f(-47.0f,35.0f+i*10);
        glVertex2f(-47.0f,38.0f+i*10);
        glVertex2f(-86.0f,38.0f+i*10);
        glEnd();

        //top right
        glColor3ub(70.0f,124.0f,166.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-86.0f,29.0f+i*10);
        glVertex2f(-58.0f,29.0f+i*10);
        glVertex2f(-58.0f,35.0f+i*10);
        glVertex2f(-86.0f,45.0f+i*10);
        glEnd();

        //top left
        glColor3ub(70.0f,124.0f,166.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-86.0f,29.0f+i*10);
        glVertex2f(-39.0f,29.0f+i*10);
        glVertex2f(-39.0f,35.0f+i*10);
        glVertex2f(-86.0f,35.0f+i*10);
        glEnd();

        }
    }
    glPopMatrix();
}

void shop()         //2206
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-98.0, -6.0f, 0.0f);
    glScalef(70.0f,70.0f,0.0f);

    glColor3ub(150.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.45f,0.358f);
    glVertex2f(-0.45f,0.5f);
    glVertex2f(0.05f,0.5f);
    glVertex2f(0.05f,0.358f);
    glEnd();
    glColor3ub(0.0f,100.0f,100.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.48f,0.5f);
    glVertex2f(0.08f,0.5f);
    glVertex2f(0.08f,0.53f);
    glVertex2f(-0.48f,0.53f);
    glEnd();
    glColor3ub(230.0f,230.0f,255.0f);
    if(state=='d'){glColor3ub(230.0f,230.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
    glVertex2f(-0.42f,0.358f);
    glVertex2f(-0.42f,0.46f);
    glVertex2f(0.02f,0.46f);
    glVertex2f(0.02f,0.358f);
    glEnd();
    glColor3ub(133.0f,133.0f,150.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.31f,0.358f);
    glVertex2f(-0.31f,0.46f);
    glVertex2f(-0.2f,0.358f);
    glVertex2f(-0.2f,0.46f);
    glVertex2f(-0.09f,0.358f);
    glVertex2f(-0.09f,0.46f);
    glEnd();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-16.0, 8.0f, 0.0f);
    glScalef(0.6f,0.6f,0.0f);
    //banner
	glLineWidth(5);
	glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(-185.0f,38.0f);
	glVertex2f(-185.0f,40.0f);
	glVertex2f(-160.0f,38.0f);
	glVertex2f(-160.0f,40.0f);
	glVertex2f(-135.0f,38.0f);
	glVertex2f(-135.0f,40.0f);
	glEnd();

	if(state=='d'){glColor3ub(100.0f,100.0f,100.0f);}
    if(state=='n'){glColor3ub(20.0f,200.0f,200.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-190.0f,40.0f);
	glVertex2f(-130.0f,40.0f);
	glVertex2f(-128.0f,48.0f);
	glVertex2f(-188.0f,48.0f);
	glEnd();
    glEnable(GL_LIGHTING);//Enable Light Effect
    GLfloat global_ambient[] = {10.0f,10.0f,10.0f, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    text_8_9_BY(-187.0,42.5,shop_text,13);
    glDisable(GL_LIGHTING);//Enable Light Effect
    glPopMatrix();
}

void car_shop()          //2207
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(320.0f, 6.0f, 0.0f);
    //top
    glColor3ub(10.0f,100.0f,10.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-191.0f,36.0f);
	glVertex2f(-129.0f,36.0f);
	glVertex2f(-129.0f,38.0f);
	glVertex2f(-191.0f,38.0f);
	glEnd();

    //body
    glColor3ub(60.0f,10.0f,10.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-190.0f,13.0f);
	glVertex2f(-130.0f,13.0f);
	glVertex2f(-130.0f,36.0f);
	glVertex2f(-190.0f,36.0f);
	glEnd();

	//center
	if(state=='d'){glColor3ub(222.0f,235.0f,240.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,102.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(-186.0f,13.0f);
	glVertex2f(-134.0f,13.0f);
	glVertex2f(-134.0f,33.0f);
	glVertex2f(-186.0f,33.0f);
	glEnd();

	//left
	glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-170.0f,13.0f);
	glVertex2f(-169.0f,13.0f);
	glVertex2f(-169.0f,33.0f);
	glVertex2f(-170.0f,33.0f);
	glEnd();

	//right
	glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-151.0f,13.0f);
	glVertex2f(-150.0f,13.0f);
	glVertex2f(-150.0f,33.0f);
	glVertex2f(-151.0f,33.0f);
	glEnd();

	//middle
	glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
	glVertex2f(-186.0f,22.0f);
	glVertex2f(-134.0f,22.0f);
	glVertex2f(-134.0f,23.0f);
	glVertex2f(-186.0f,23.0f);
	glEnd();

	//banner
	glLineWidth(5);
	glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(-185.0f,38.0f);
	glVertex2f(-185.0f,40.0f);
	glVertex2f(-160.0f,38.0f);
	glVertex2f(-160.0f,40.0f);
	glVertex2f(-135.0f,38.0f);
	glVertex2f(-135.0f,40.0f);
	glEnd();

	if(state=='d'){glColor3ub(100.0f,100.0f,100.0f);}
    if(state=='n'){glColor3ub(20.0f,200.0f,200.0f);}

    glBegin(GL_POLYGON);
	glVertex2f(-190.0f,40.0f);
	glVertex2f(-130.0f,40.0f);
	glVertex2f(-128.0f,48.0f);
	glVertex2f(-188.0f,48.0f);
	glEnd();
    glEnable(GL_LIGHTING);//Enable Light Effect
    GLfloat global_ambient[] = {10.0f,10.0f,10.0f, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    text_HELVETICA(-181.0,42.5,car_shop_text,18);
    glDisable(GL_LIGHTING);//Enable Light Effect
    glPopMatrix();
}

void mini_shop_1()            //2208
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5f, 0.5f, 0.0f);
    glTranslatef(-70.0f, 20.0f, 0.0f);
    //body
    glColor3ub(250.0f,60.0f,33.0f);
    glBegin(GL_POLYGON);
	glVertex2f(110.0f,19.0f);
	glVertex2f(130.0f,19.0f);
	glVertex2f(130.0f,35.0f);
	glVertex2f(110.0f,35.0f);
	glEnd();

	//bottom
	glLineWidth(3);
    glColor3ub(200.0f,0.0f,0.0f);
    glBegin(GL_LINES);
	glVertex2f(108.0f,19.5f);
	glVertex2f(132.0f,19.5f);
	glVertex2f(110.0f,21.5f);
	glVertex2f(122.0f,21.5f);
	glVertex2f(110.0f,23.5f);
	glVertex2f(122.0f,23.5f);
	glEnd();

	//door
	glColor3ub(200.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
	glVertex2f(122.0f,19.0f);
	glVertex2f(128.0f,19.0f);
	glVertex2f(128.0f,30.0f);
	glVertex2f(122.0f,30.0f);
	glEnd();

	//window
	glColor3ub(103.0f,167.0f,217.0f);
	if(state=='d'){glColor3ub(103.0f,167.0f,217.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(112.0f,25.0f);
	glVertex2f(120.0f,25.0f);
	glVertex2f(120.0f,33.0f);
	glVertex2f(112.0f,33.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(122.0f,31.0f);
	glVertex2f(124.5f,31.0f);
	glVertex2f(124.5f,34.0f);
	glVertex2f(122.0f,34.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(125.5f,31.0f);
	glVertex2f(128.0f,31.0f);
	glVertex2f(128.0f,34.0f);
	glVertex2f(125.5f,34.0f);
	glEnd();

	//top
    glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(109.0f,35.0f);
	glVertex2f(131.0f,35.0f);
	glVertex2f(130.0f,40.0f);
	glVertex2f(110.0f,40.0f);
	glEnd();

	//banner
    glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(114.0f,40.0f);
	glVertex2f(114.0f,42.0f);
	glVertex2f(126.0f,40.0f);
	glVertex2f(126.0f,42.0);
	glEnd();

    if(state=='d'){glColor3ub(100.0f,100.0f,100.0f);}
    if(state=='n'){glColor3ub(20.0f,200.0f,200.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(110.0f,42.0f);
	glVertex2f(130.0f,42.0f);
	glVertex2f(130.0f,48.0f);
	glVertex2f(110.0f,48.0f);
	glEnd();

	glEnable(GL_LIGHTING);//Enable Light Effect
    GLfloat global_ambient[] = {10.0f,10.0f,10.0f, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    text_HELVETICA(111.5,44.0,mini_shop_1_text,10);
    glDisable(GL_LIGHTING);//Enable Light Effect

    glPopMatrix();
}

void mini_shop_2()          //2209
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5f, 0.5f, 0.0f);
    glTranslatef(-20.0f, 20.0f, 0.0f);
    //body
    glColor3ub(33.0f,100.0f,255.0f);
    glBegin(GL_POLYGON);
	glVertex2f(110.0f,19.0f);
	glVertex2f(130.0f,19.0f);
	glVertex2f(130.0f,35.0f);
	glVertex2f(110.0f,35.0f);
	glEnd();

	//bottom
	glLineWidth(3);
	glColor3ub(103.0f,167.0f,217.0f);
    glBegin(GL_LINES);
	glVertex2f(108.0f,19.5f);
	glVertex2f(132.0f,19.5f);
	glVertex2f(110.0f,21.5f);
	glVertex2f(122.0f,21.5f);
	glVertex2f(110.0f,23.5f);
	glVertex2f(122.0f,23.5f);
	glEnd();

	//door
	glColor3ub(103.0f,167.0f,217.0f);
    glBegin(GL_POLYGON);
	glVertex2f(122.0f,19.0f);
	glVertex2f(128.0f,19.0f);
	glVertex2f(128.0f,30.0f);
	glVertex2f(122.0f,30.0f);
	glEnd();

	//window
    glColor3ub(135.0f,206.0f,235.0f);
    if(state=='d'){glColor3ub(135.0f,206.0f,235.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
    glBegin(GL_POLYGON);
	glVertex2f(112.0f,25.0f);
	glVertex2f(120.0f,25.0f);
	glVertex2f(120.0f,33.0f);
	glVertex2f(112.0f,33.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(122.0f,31.0f);
	glVertex2f(124.5f,31.0f);
	glVertex2f(124.5f,34.0f);
	glVertex2f(122.0f,34.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(125.5f,31.0f);
	glVertex2f(128.0f,31.0f);
	glVertex2f(128.0f,34.0f);
	glVertex2f(125.5f,34.0f);
	glEnd();

	//top
    glColor3ub(33.0f,60.0f,200.0f);
	glBegin(GL_POLYGON);
	glVertex2f(109.0f,35.0f);
	glVertex2f(131.0f,35.0f);
	glVertex2f(130.0f,40.0f);
	glVertex2f(110.0f,40.0f);
	glEnd();

	//banner
    glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(114.0f,40.0f);
	glVertex2f(114.0f,42.0f);
	glVertex2f(126.0f,40.0f);
	glVertex2f(126.0f,42.0);
	glEnd();

    if(state=='d'){glColor3ub(100.0f,100.0f,100.0f);}
    if(state=='n'){glColor3ub(20.0f,200.0f,200.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(110.0f,42.0f);
	glVertex2f(130.0f,42.0f);
	glVertex2f(130.0f,48.0f);
	glVertex2f(110.0f,48.0f);
	glEnd();
	glEnable(GL_LIGHTING);//Enable Light Effect
    GLfloat global_ambient[] = {10.0f,10.0f,10.0f, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    text_HELVETICA(113.5,44.0,mini_shop_2_text,10);
    glDisable(GL_LIGHTING);//Enable Light Effect

    glPopMatrix();
}

void station()             //2210
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0,0.0f,0.0f);

    glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-185.0f,40.0f);
	glVertex2f(-180.0f,45.0f);
	glVertex2f(-135.0f,45.0f);
	glVertex2f(-130.0f,40.0f);
	glEnd();

	if(state=='d'){glColor3ub(255.0f,204.0f,153.0f);}
    if(state=='n'){glColor3ub(235.0f,185.0f,140.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-180.0f,19.0f);
	glVertex2f(-180.0f,40.0f);
	glVertex2f(-134.5f,40.0f);
	glVertex2f(-134.5f,19.0f);
	glEnd();

    if(state=='d'){glColor3ub(255.0f,255.0f,153.0f);}
    if(state=='n'){glColor3ub(235.0f,235.0f,140.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-182.0f,30.0f);
	glVertex2f(-182.0f,31.0f);
	glVertex2f(-133.0f,31.0f);
	glVertex2f(-133.0f,30.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-164.0f,19.0f);
	glVertex2f(-164.0f,48.0f);
	glVertex2f(-150.0f,48.0f);
	glVertex2f(-150.0f,19.0f);
	glEnd();

    glColor3ub(255.0f,153.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-166.0f,48.0f);
	glVertex2f(-166.0f,49.0f);
	glVertex2f(-148.0f,49.0f);
	glVertex2f(-148.0f,48.0f);
	glEnd();

    glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-166.0f,49.0f);
	glVertex2f(-157.0f,60.0f);
	glVertex2f(-148.0f,49.0f);
	glEnd();

	glColor3ub(255.0f,255.0f,153.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-164.0f,49.0f);
	glVertex2f(-157.0f,58.0f);
	glVertex2f(-150.0f,49.0f);
	glEnd();

    glColor3ub(255.0f,153.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-164.0f,19.0f);
	glVertex2f(-164.0f,48.0f);
	glVertex2f(-165.0f,48.0f);
	glVertex2f(-165.0f,19.0f);
	glEnd();

    glColor3ub(255.0f,153.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-149.0f,19.0f);
	glVertex2f(-149.0f,48.0f);
	glVertex2f(-150.0f,48.0f);
	glVertex2f(-150.0f,19.0f);
	glEnd();

    glColor3ub(255.0f,153.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-148.5f,19.0f);
	glVertex2f(-148.5f,21.0f);
	glVertex2f(-150.5f,21.0f);
	glVertex2f(-150.5f,19.0f);
	glEnd();

    glColor3ub(255.0f,153.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-163.5f,19.0f);
	glVertex2f(-163.5f,21.0f);
	glVertex2f(-165.5f,21.0f);
	glVertex2f(-165.5f,19.0f);
	glEnd();

	if(state=='d'){glColor3ub(102.0f,51.0f,0.0f);}
    if(state=='n'){glColor3ub(204.0f,102.0f,0.0f);}
	//middle door
	glBegin(GL_POLYGON);
	glVertex2f(-160.0f,19.0f);
	glVertex2f(-160.0f,26.0f);
	glVertex2f(-153.5f,26.0f);
	glVertex2f(-153.5f,19.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-156.75,y+26);
        }
    glEnd();

    //right side door
	glBegin(GL_POLYGON);
	glVertex2f(-146.5f,19.0f);
	glVertex2f(-146.5f,25.0f);
	glVertex2f(-142.0f,25.0f);
	glVertex2f(-142.0f,19.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-144.33,y+25);
        }
    glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-140.5f,19.0f);
	glVertex2f(-140.5f,25.0f);
	glVertex2f(-136.0f,25.0f);
	glVertex2f(-136.0f,19.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-138.33,y+25);
        }
    glEnd();

    //left side door
	glBegin(GL_POLYGON);
	glVertex2f(-177.5f,19.0f);
	glVertex2f(-177.5f,25.0f);
	glVertex2f(-173.0f,25.0f);
	glVertex2f(-173.0f,19.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-175.25,y+25);
        }
    glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-171.5f,19.0f);
	glVertex2f(-171.5f,25.0f);
	glVertex2f(-167.0f,25.0f);
	glVertex2f(-167.0f,19.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-169.3,y+25);
        }
    glEnd();

    //middle side window
    if(state=='d'){glColor3ub(153.0f,255.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-160.0f,37.0f);
	glVertex2f(-160.0f,43.0f);
	glVertex2f(-153.5f,43.0f);
	glVertex2f(-153.5f,37.0f);
	glEnd();

	glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-161.0f,36.0f);
	glVertex2f(-161.0f,37.0f);
	glVertex2f(-152.5f,37.0f);
	glVertex2f(-152.5f,36.0f);
	glEnd();

	//Right side window
    if(state=='d'){glColor3ub(153.0f,255.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-146.5f,33.0f);
	glVertex2f(-146.5f,37.0f);
	glVertex2f(-142.0f,37.0f);
	glVertex2f(-142.0f,33.0f);
	glEnd();

	glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-147.0f,33.0f);
	glVertex2f(-147.0f,32.5f);
	glVertex2f(-141.5f,32.5f);
	glVertex2f(-141.5f,33.0f);
	glEnd();

    if(state=='d'){glColor3ub(153.0f,255.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-140.0f,33.0f);
	glVertex2f(-140.0f,37.0f);
	glVertex2f(-136.0f,37.0f);
	glVertex2f(-136.0f,33.0f);
	glEnd();

    glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-140.5f,33.0f);
	glVertex2f(-140.5f,32.5f);
	glVertex2f(-135.5f,32.5f);
	glVertex2f(-135.5f,33.0f);
	glEnd();

	//left side window
    if(state=='d'){glColor3ub(153.0f,255.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-177.5f,33.0f);
	glVertex2f(-177.5f,37.0f);
	glVertex2f(-173.0f,37.0f);
	glVertex2f(-173.0f,33.0f);
	glEnd();

	glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-178.0f,33.0f);
	glVertex2f(-178.0f,32.5f);
	glVertex2f(-172.5f,32.5f);
	glVertex2f(-172.5f,33.0f);
	glEnd();

    if(state=='d'){glColor3ub(153.0f,255.0f,255.0f);}
    if(state=='n'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-171.5f,33.0f);
	glVertex2f(-171.5f,37.0f);
	glVertex2f(-167.0f,37.0f);
	glVertex2f(-167.0f,33.0f);
	glEnd();

    glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-172.0f,33.0f);
	glVertex2f(-172.0f,32.5f);
	glVertex2f(-166.5f,32.5f);
	glVertex2f(-166.5f,33.0f);
	glEnd();

	//clock
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-156.9,y+52.5);
        }
    glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
              glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-156.9,y+52.5);
        }
    glEnd();

    //sine board
    glColor3ub(220.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-162.5f,31.0f);
	glVertex2f(-162.5f,35.0f);
	glVertex2f(-151.0f,35.0f);
	glVertex2f(-151.0f,31.0f);
	glEnd();

    glEnable(GL_LIGHTING);//Enable Light Effect
    GLfloat global_ambient[] = {10.0f,10.0f,10.0f, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    text_HELVETICA(-161.3,32.0f,station_text,12);
    glDisable(GL_LIGHTING);//Enable Light Effect

    //clock stick
    glColor3ub(0.0f,0.0f,0.0f);
    glLineWidth(1.0);
    glTranslatef(-156.9f,52.0f,0.0f);
    glRotatef(station_clock_hour_move, 0.0f, 0.0f,1.0f);
    glTranslatef(156.9f,-52.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-156.9f,52.0f);
    glVertex2f(-154.9f,52.0f);
    glEnd();
    glTranslatef(-156.9f,52.0f,0.0f);
    glRotatef(station_clock_minute_move, 0.0f, 0.0f,1.0f);
    glTranslatef(156.9f,-52.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-156.9f,52.0f);
    glVertex2f(-156.9f,54.3f);
    glEnd();
    glPopMatrix();
}

void update_station_clock(int value)             //2210001
{
    station_clock_minute_move -=5.0f;
    if(station_clock_minute_move==-180)
    {
        station_clock_hour_move-=15.0f;
    }
    else if(station_clock_minute_move==-360)
    {
        station_clock_hour_move-=15.0f;
        station_clock_minute_move =0.0f;
    }
    else if(station_clock_hour_move==-90 && station_clock_minute_move==-150 && show=='n')
    {
        if(state=='d'){rise='m';}
        else if(state=='n'){rise='s';}
    }
    else if(station_clock_hour_move==-450 && station_clock_minute_move==-150 && show=='n')
    {
        if(state=='d'){rise='m';}
        else if(state=='n'){rise='s';}
    }
    else if(station_clock_hour_move==-720)
    {
        station_clock_hour_move=0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update_station_clock, 0);
}

void sun()         //2301
{
    if(show=='p')
    {
         glColor3ub(255.0f,216.0f,77.0f);
        glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+180,y+92);
        }
        glEnd();
    }
    if(show=='n')
    {
        glColor3ub(239.0f,142.0f,56.0f);
        glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+170,y+25+sun_move);
        }
        glEnd();
    }

}

void update_sun(int value)         //2301001
{

    if(state=='d' && rise!='m' && sun_move < 60.0){sun_move += 1.5;}
    else if(rise=='m' && sun_move > 0.0 ){sun_move -= 1.5;}
    else if(rise=='m' && sun_move==0){glutTimerFunc(-50,disback_night,0);}
    glutPostRedisplay();
    glutTimerFunc(20, update_sun, 0);
}

void moon()         //2401
{

        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-160,y+25+moon_move);
        }
        glEnd();

}

void update_moon(int value)        //2401001
{

    if(state=='n' && rise!='s' && moon_move < 60.0){moon_move += 1.5;}
    else if(rise=='s' && moon_move > 0.0 ){moon_move -= 1.5;}
    else if(rise=='s' && moon_move==0){glutTimerFunc(-50,disback_day,0);}
    glutPostRedisplay();
    glutTimerFunc(20, update_moon, 0);
}

void lake()  //2501
{
    if(show=='p')
    {
         //circle
    for(int j=0;j<4;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(82.0f,70.0f,70.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=22.5;
            float x = 1.7 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-192+j*91,y-26);
        }
        glEnd();
    }
    if(snow_cover>2){glColor3ub(185.0f,232.0f,234.0f);}
    else{glColor3ub(134.0f,214.0f,216.0f);}
    for(int j=0;j<4;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=22.1;
            float x = 1.7 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-192+j*91,y-26);
        }
        glEnd();
    }
    //down
    glBegin(GL_POLYGON);
    glVertex2f(192.0f,-23.0f);
    glVertex2f(-192.0f,-23.0f);
    glColor3ub(134.0f,214.0f,216.0f);
    glVertex2f(-192.0f,-100.0f);
    glVertex2f(192.0f,-100.0f);
    glEnd();
    //up
    if(snow_cover>2){glColor3ub(185.0f,232.0f,234.0f);}
    else{glColor3ub(134.0f,214.0f,216.0f);}
    glBegin(GL_POLYGON);
    glVertex2f(192.0f,50.0f);
    glVertex2f(-192.0f,50.0f);
    glVertex2f(-192.0f,33.0f);
    glVertex2f(192.0f,33.0f);
    glEnd();
    }

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,lake_move,0.0f);

    if(show=='n')
    {
    //Grass
    if(state=='d'){glColor3ub(0.0f,170.0f,0.0f);}
    if(state=='n'){glColor3ub(0.0f,140.0f,0.0f);}

	glBegin(GL_POLYGON);
	glVertex2f(192.0f,-20.0f);
	glVertex2f(-192.0f,-20.0f);
	glVertex2f(-192.0f,-100.0f);
	glVertex2f(192.0f,-100.0f);
	glEnd();
	//lake
    if(state=='d')
    {
        glColor3ub(30.0f,150.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(192.0f,-58.0f);
        glVertex2f(-192.0f,-58.0f);
        glVertex2f(-192.0f,-120.0f);
        glVertex2f(192.0f,-120.0f);
        glEnd();
    }
    if(state=='n')
    {
        glColor3ub(0.0f,114.0f,160.0f);
        glBegin(GL_POLYGON);
        glVertex2f(192.0f,-58.0f);
        glVertex2f(-192.0f,-58.0f);
        glVertex2f(-192.0f,-120.0f);
        glVertex2f(192.0f,-120.0f);
        glEnd();
    }
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=40.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-190,y-90);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y-85);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-118,y-90);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=45.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-95,y-98);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=40.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-75,y-88);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-55,y-85);
        }
    glEnd();

    //Grass or Green Circle
    if(state=='d'){glColor3ub(0.0f,170.0f,0.0f);}
    if(state=='n'){glColor3ub(0.0f,140.0f,0.0f);}

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-150,y-33.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-27,y-50);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=20.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+38,y-45);
        }
    glEnd();
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+190,y-47);
        }
    glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(190.0f,-79.0f);
	glVertex2f(38.0f,-62.0f);
	glVertex2f(45.0f,-45.0f);
	glVertex2f(192.0f,-45.0f);
	glEnd();
    }
    glPopMatrix();
}

void update_wave(int value) //2501001
{
    if(lake1=='n')
    {
        lake_move += 0.2;
        if(lake_move >10.1)
        {
            lake1='o';
        }
    }
    if(lake1=='o')
    {
        lake_move -= 0.2;
        if(lake_move <-0.1)
        {
            lake1='n';
        }
    }
    if(lake1=='s')
    {
        lake_move -= 0.2;
        if(lake_move <0.5)
        {
            lake_move =0.0;;
            lake1='n';
            return;
        }
    }
glutPostRedisplay();
glutTimerFunc(20, update_wave, 0);
}

void cloud()        //2601
{
    //glColor3ub(225.0f,246.0f,255.0f);
    if(show=='n' && state=='d' && rain_state!='y'){glColor3ub(204.0f,255.0f,255.0f);}
    if((show=='n' && rain_state=='y' && show=='n')|| (show=='n' && state=='n')){glColor3ub(200.0f,200.0f,200.0f);} //rain & night
    if(show=='p'&& snow_state=='n'){glColor3ub(255.0f,255.0f,255.0f);}
    if(show=='p' && snow_state=='y'){glColor3ub(225.0f,246.0f,255.0f);}

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+70,y+85);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+72,y+85.5);
        }
    glEnd();

        glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+74,y+86);
        }
    glEnd();

         glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+77,y+87);
        }
    glEnd();

             glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+78,y+86);
        }
    glEnd();

            glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+80,y+86);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+81,y+86.5);
        }
    glEnd();


       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+82,y+85);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+84,y+85);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+86,y+84);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+82,y+80);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+84,y+81);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+87,y+82);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+82,y+80);

        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+79,y+79);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+76,y+78);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+75,y+77);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+73,y+77);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+71,y+78);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+69,y+78);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+67,y+79);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+66,y+80);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+64,y+81);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+66,y+82);
        }
    glEnd();
           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+67,y+84);
        }
    glEnd();

           glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+73,y+82);
        }
    glEnd();
         glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+67,y+82);
        }
    glEnd();


             glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+79,y+82);
        }
    glEnd();
}

void cloud_1()        //2602
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_1_move_right,0.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_2()        //2603
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_2_move_right,0.0f,0.0f);
    glTranslatef(-80.0,10.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_3()        //2604
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_3_move_right,0.0f,0.0f);
    glTranslatef(-65.0,5.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_4()        //2605
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_4_move_right,0.0f,0.0f);
    glTranslatef(50.0,0.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_5()        //2606
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_5_move_right,0.0f,0.0f);
    glTranslatef(-160.0,13.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_6()        //2607
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_6_move_right,0.0f,0.0f);
    glTranslatef(-225.0,4.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_7()        //2608
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_7_move_right,0.0f,0.0f);
    glTranslatef(-240.0,3.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_8()        //2609
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cloud_8_move_right,0.0f,0.0f);
    glTranslatef(-150.0,3.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_9()        //2610
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4.0f,4.0f,0.0f);
    glTranslatef(-170.0,-58.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_10()        //2611
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(-70.0,0.0f,0.0f);
    cloud_9();
    glPopMatrix();
}

void cloud_11()        //2612
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(-110.0,0.0f,0.0f);
    cloud_9();
    glPopMatrix();
}

void cloud_12()        //2613
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(40.0,0.0f,0.0f);
    cloud_9();
    glPopMatrix();
}

void cloud_13()        //2614
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3.7f,3.5f,0.0f);
    glTranslatef(-150.0,-57.0f,0.0f);
    cloud();
    glPopMatrix();
}

void cloud_14()        //2615
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(-70.0,0.0f,0.0f);
    cloud_13();
    glPopMatrix();
}

void cloud_15()        //2616
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(-110.0,0.0f,0.0f);
    cloud_13();
    glPopMatrix();
}

void cloud_16()        //2617
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0f,1.0f,0.0f);
    glTranslatef(40.0,0.0f,0.0f);
    cloud_13();
    glPopMatrix();
}

void update_cloud(int value)        //2601001
{
cloud_1_move_right += 0.1;
if(cloud_1_move_right > 130.0)
{
cloud_1_move_right = -295;
}

cloud_2_move_right += 0.1;
if(cloud_2_move_right > 210.0)
{
cloud_2_move_right = -230;
}

cloud_3_move_right += 0.1;
if(cloud_3_move_right > 210.0)
{
cloud_3_move_right = -230;
}

cloud_4_move_right += 0.1;
if(cloud_4_move_right > 80.0)
{
cloud_4_move_right = -330;
}

cloud_5_move_right += 0.1;
if(cloud_5_move_right > 290.0)
{
cloud_5_move_right = -140;
}

cloud_6_move_right += 0.1;
if(cloud_6_move_right > 360.0)
{
cloud_6_move_right = -75;
}

cloud_7_move_right += 0.1;
if(cloud_7_move_right > 370.0)
{
cloud_7_move_right = -70;
}

cloud_8_move_right += 0.1;
if(cloud_8_move_right > 370.0)
{
cloud_8_move_right = -120;
}

glutPostRedisplay();
glutTimerFunc(20, update_cloud, 0);
}

void snow1()        //2701
{
    for(int j=0;j<21;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+194+j*29,y+98);
        }
        glEnd();
    }
}

void snow2()        //2702
{
    for(int j=0;j<24;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.6;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+210+j*25,y+90);
        }
        glEnd();
    }
}

void snow3()        //2703
{
    for(int j=0;j<24;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+197+j*28,y+80);
        }
        glEnd();
    }
}

void snow4()        //2704
{
    for(int j=0;j<26;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.7;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+200+j*23,y+70);
        }
        glEnd();
    }
}

void snow5()        //2705
{
    for(int j=0;j<27;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+195+j*23,y+60);
        }
        glEnd();
    }
}

void snow()        //2706
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(snow_move_x,snow_move_y ,0.0f);
    snow1();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    snow2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    snow3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    snow4();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    snow5();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-20.0f,0.0f);
    snow4();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-58.0f,0.0f);
    snow1();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-50.0f,0.0f);
    snow3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-40.0f,0.0f);
    snow5();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-80.0f,0.0f);
    snow2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-80.0f,0.0f);
    snow3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-70.0f,0.0f);
    snow5();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-118.0f,0.0f);
    snow1();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-100.0f,0.0f);
    snow4();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-180.0f,0.0f);
    snow3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-150.0f,0.0f);
    snow2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-100.0f,0.0f);
    snow5();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-148.0f,0.0f);
    snow1();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-150.0f,0.0f);
    snow2();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-150.0f,0.0f);
    snow3();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-150.0f,0.0f);
    snow4();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-150.0f,0.0f);
    snow5();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-170.0f,0.0f);
    snow5();
    glPopMatrix();

}

void snowfall_1()        //2707
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(snow_move_x,snow_move_y ,0.0f);
    glTranslatef(-192.0f,220.0f ,0.0f);
    snow();
    glPopMatrix();
}

void snowfall_2()        //2708
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(snow_move_x1,snow_move_y1 ,0.0f);
    glTranslatef(-392.0f,220.0f ,0.0f);
    snow();
    glPopMatrix();
}

void snow_shade_tree_0()         //2709
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3ub(255.0f,255.0f,255.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+185.5f,y-6.0);
        }
    glEnd();
    glPointSize(10);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+165.5f,y-6.0);
        }
    glEnd();
    glPointSize(10);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+145.5f,y-6.0);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+175.5f,y-10.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155.5f,y-14.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+140.5f,y-16.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+140.5f,y-16.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+183.5f,y-22.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+183.5f,y-22.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+183.5f,y-22.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+163.5f,y-20.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+173.5f,y-25.5);
        }
    glEnd();glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.9;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+148.5f,y-25.5);
        }
    glEnd();
    glPopMatrix();
}

void snow_shade_tree()        //2710
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    if(snow_cover>1)
        {
            snow_shade_tree_0();
    }
    if(snow_cover>2)
    {
    glTranslatef(-1.0,-1.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(1.0,1.0f,0.0f);

    glTranslatef(0.0,-1.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(0.0,1.0f,0.0f);

    glTranslatef(1.0,-1.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(-1.0,1.0f,0.0f);
    }
    if(snow_cover>3)
    {
    glTranslatef(-2.0,-2.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(2.0,2.0f,0.0f);

    glTranslatef(0.0,-2.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(0.0,2.0f,0.0f);

    glTranslatef(2.0,-2.0f,0.0f);
    snow_shade_tree_0();
    glTranslatef(-2.0,2.0f,0.0f);
    }
    //snow_shade_tree_0();
    glPopMatrix();
}

void snow_update(int value)        //2701001
{

    if(snow_state=='y')
    {
        snow_move_y -= snow_speed;
        if(snow_move_y == -200 || snow_move_y == -400)
        {
            snow_cover+=1;
        }
        if(snow_move_y < -440)
        {
            snow_move_y = 0;
        }
        if(snow_value=='n' && snow_move_y == -222)
        {
            glutTimerFunc(0, snow_update1, 0);
        }

        snow_move_x -= snow_speed;
        if(snow_move_x < -393)
        {
            snow_move_x = -192;
        }
    }
    if(snow_state=='s')
    {
        if(snow_move_x !=0)
        {
            snow_move_y -= snow_speed;
            snow_move_x -= snow_speed;

            if(snow_move_x < -395)
            {
                snow_move_x = -194;
            }
        }
        if(snow_move_y < -441)
        {
            snow_move_y=snow_move_x=0;
            return;
        }
    }

glutPostRedisplay();
glutTimerFunc(20, snow_update, 0);
}

void snow_update1(int value)         //2701001
{

    if(snow_state=='y' )
    {
        snow_value='y';
        snow_move_y1 -= 2;
        snow_move_x1 -= 2;

        if(snow_move_y1 < -440)
        {
            snow_move_y1 = 0;

        }
        if(snow_move_x1 < -203)
        {
            snow_move_x1 = -2;
        }
    }
    if(snow_state=='s')
    {
        if(snow_move_x1 !=0)
        {
            snow_move_y1 -= snow_speed;
            snow_move_x1 -= snow_speed;

            if(snow_move_x1 < -205)
            {
                snow_move_x1 = -4;
            }
        }
        if(snow_move_y1 < -441)
        {
            snow_move_y1=snow_move_x1=0;
            snow_value='n';
            return;
        }

    }

glutPostRedisplay();
glutTimerFunc(20, snow_update1, 0);
}

void snow_cloud()        //2801
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(snow_move_cloud,10.0f,0.0f);
    cloud_13();
    cloud_14();
    cloud_15();
    glTranslatef(-220.0,0.0f,0.0f);
    cloud_16();
    glPopMatrix();
}

void snow_cloud_2()        //2802
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(snow_move_cloud_2,0.0f,0.0f);
    glTranslatef(660.0,12.0f,0.0f);
    cloud_13();
    cloud_14();
    cloud_15();
    cloud_16();
    glPopMatrix();
}

void snow_cloud_update(int value)        //2801001
{
    if(snow_state=='y')
    {


    if(snow_move_cloud <260)
    {
        snow_move_cloud += 3.0;
    }

    if(snow_move_cloud_2 > -260)
    {
        snow_move_cloud_2 -= 3.0;
    }
    if(snow_move_cloud > 255 && snow_move_cloud_2 < -255 && snow_int==1)
    {
        glutTimerFunc(0, snow_update, 0);
        snow_int+=1;
        return;
    }
    }

    glutPostRedisplay();
    glutTimerFunc(20, snow_cloud_update, 0);

}

void snow_cloud_stop(int value)        //2801002
{
   if(snow_state=='s')
    {
if(snow_move_cloud > 1 && snow_move_cloud_2 < -1)
{
    snow_move_cloud -= 3.0;
    snow_move_cloud_2 += 3.0;
}


 if(snow_move_cloud == 0 && snow_move_cloud_2 == 0 && snow_int==0)
{
    snow_move_cloud= 0.0;
    snow_move_cloud_2= 0.0;
    snow_int-=1;
    return;
}
    }

glutPostRedisplay();
glutTimerFunc(20, snow_cloud_stop, 0);

}

void rain_cloud()        //2901
{
     glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(rain_move_cloud,8.0f,0.0f);
    cloud_9();
    cloud_10();
    cloud_11();
    glPopMatrix();

}

void rain_cloud_2()       //2902
{
        glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glTranslatef(rain_move_cloud_2,0.0f,0.0f);
    glTranslatef(810.0,8.0f,0.0f);
    cloud_9();
    cloud_10();
    cloud_11();
    cloud_12();
    glPopMatrix();

}

void rain_cloud_update(int value)       //2901001
{

 rain_move_cloud += 2.7;

 if(rain_move_cloud > 310)
{
    return ;
}
 rain_move_cloud_2 -= 2.7;

 if(rain_move_cloud_2 < -310)
{
    return ;
}
glutPostRedisplay();
glutTimerFunc(20, rain_cloud_update, 0);

}

void rain_cloud_stop(int value)       //2901002
{

 rain_move_cloud -= 2.7;

 if(rain_move_cloud < 50)
{
    return ;
}
 rain_move_cloud_2 += 2.7;

 if(rain_move_cloud_2 > -50)
{
    return ;
}
glutPostRedisplay();
glutTimerFunc(20, rain_cloud_stop, 0);

}

void rain()       //3001
{
    glLineWidth(2.0);
    glPointSize(3.0);
    //bottom_right
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(0.0f,rain_stop_y ,0.0f);
    glTranslatef(rain_move_x,rain_move_y ,0.0f);


       for(int j=0;j<15;j++)
    {

    for(int i=0;i<30;i++)
        {
            //glColor3ub(0.0f,0.0f,0.0f);
            glColor3ub(255.0f,255.0f,255.0f);
            glBegin(GL_LINES);
            glVertex2f(495.0f+i*20,70.0f-j*20);
            glVertex2f(493.0f+i*20,68.0f-j*20);

            glVertex2f(505.0f+i*20,60.0f-j*20);
            glVertex2f(503.0f+i*20,58.0f-j*20);

             glVertex2f(500.0f+i*20,65.0f-j*20);
            glVertex2f(498.0f+i*20,63.0f-j*20);
            glEnd();
        }

    }

    glPopMatrix();

}

void rain_update(int value)       //3101001
{

    if(rain_state=='y')
    {
        rain_move_y -= 2.0;

        if(rain_move_y < 70)
        {
            rain_move_y = 82;
        }
        rain_move_x -= 2.0;

        if(rain_move_x < -715)
        {
            rain_move_x = -708;
        }
        if(rain_move_x == -700)
        {
            //lake2 = 'y';
            glutTimerFunc(20, update_wave, 0);
        }
    }
    if(rain_state=='s')
    {
        if(rain_move_x !=0)
        {
            rain_move_y -= 2.0;
            rain_move_x -= 2.0;

            if(rain_move_x < -715)
            {
                rain_move_x = -708;
            }
        }

        if(rain_move_y < -340)
        {
            rain_move_y=rain_move_x=0;
            lake1='s';
            return;
        }
    }

glutPostRedisplay();
glutTimerFunc(20, rain_update, 0);
}

void plane()       //3201
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(plane_move,10.0f,0.0f);
    //glScalef(100.0f,100.0f,0.0f);
    //glLineWidth(0.001);
    if(show=='p'){glColor3ub(100.0f,100.0f,100.0f);}
    else
        glColor3ub(255.0f,255.0f,255.0f);
    //body low
    glBegin(GL_POLYGON);
    glVertex2f(-180.0f,80.0f);
    glVertex2f(-160.0f,80.0f);
    glVertex2f(-160.0f,79.0f);
    glVertex2f(-165.0f,78.0f);
    glVertex2f(-173.0f,78.0f);
    glVertex2f(-175.0f,79.0f);
    glVertex2f(-180.0f,80.0f);
    glEnd();
    //back wing
    glBegin(GL_POLYGON);
    glVertex2f(-185.0f,85.0f);
    glVertex2f(-186.0f,85.5f);
    glVertex2f(-188.0f,85.5f);
    glVertex2f(-184.0f,83.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-172.0f,82.0f);
    glVertex2f(-168.0f,82.0f);
    glVertex2f(-174.0f,85.0f);
    glVertex2f(-176.0f,85.5f);
    glEnd();
    if(state=='n' && show!='p')
    {
    glPointSize(2.5);
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-174.0f,85.0f);
    glEnd();
    glColor3ub(0.0f,0.0f,255.0f);
    glBegin(GL_POINTS);
    glVertex2f(-172.5f,84.0f);
    glEnd();
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-170.5f,83.0);
    glEnd();
    }

    //body high
    if(show=='p'){glColor3ub(150.0f,150.0f,150.0f);}
    else
        glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-180.0f,80.0f);
    glVertex2f(-160.0f,80.0f);
    glVertex2f(-160.0f,81.0f);
    glVertex2f(-165.0f,82.0f);
    glVertex2f(-173.0f,82.0f);
    glVertex2f(-180.0f,82.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-180.0f,82.0f);
    glVertex2f(-184.0f,86.0f);
    glVertex2f(-186.0f,87.0f);
    glVertex2f(-184.0,82.0f);
    glVertex2f(-180.0f,80.0f);
    glEnd();

    if(show=='p'){glColor3ub(100.0f,100.0f,100.0f);}
    else
        glColor3ub(255.0f,255.0f,255.0f);
    //front wing
    glBegin(GL_POLYGON);
    glVertex2f(-179.0f,81.5f);
    glVertex2f(-182.0f,81.5f);
    glVertex2f(-187.0f,77.0f);
    glVertex2f(-185.0f,77.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-172.0f,78.0f);
    glVertex2f(-168.0f,78.0f);
    glVertex2f(-174.0f,74.0f);
    glVertex2f(-176.0f,73.5f);
    glEnd();

    if(state=='n' && show!='p')
    {
    glPointSize(2.5);
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-174.0f,74.0f);
    glEnd();
    glColor3ub(0.0f,0.0f,255.0f);
    glBegin(GL_POINTS);
    glVertex2f(-172.5f,75.0f);
    glEnd();
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(-170.5f,76.0);
    glEnd();
    }

    if(show=='p'){glColor3ub(100.0f,100.0f,100.0f);}
    else
        glColor3ub(255.0f,255.0f,255.0f);
    //window
    glBegin(GL_POLYGON);
    glVertex2f(-166.0f,80.5f);
    glVertex2f(-160.0f,80.5f);
    glVertex2f(-166.0f,81.5f);
    glEnd();
    for(int i=0;i<6;i++)
    {
    glBegin(GL_POLYGON);
    glVertex2f(-168.0f-i*2,80.5f);
    glVertex2f(-167.0f-i*2,80.5f);
    glVertex2f(-167.0f-i*2,81.5f);
    glVertex2f(-168.0f-i*2,81.5f);
    glEnd();
    }

    glPopMatrix();
}

void plane_1()       //3202
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-plane_move+70,55.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f,-0.4f,0.0f);
    plane();
    glPopMatrix();
}

void update_plane(int value)       //3201001
{
    plane_move += 0.4;
    if(plane_move > 390.0)
    {
    plane_move = -30.0;
    }
glutPostRedisplay();
glutTimerFunc(20, update_plane, 0);
}

void heli_blade1()         //330101
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(heli_movex, heli_movey, 0.0f);
    glTranslatef(13.2f,66.7f,0.0f);
    glRotatef(heli_angle, 0.0f, 0.0f,1.0f);
    glTranslatef(-13.2f,-66.7f,0.0f);
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(165.0f,155.0f,155.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+13.2,y+66.7);
        }
    glEnd();
    glColor3ub(180.0f,170.0f,170.0f);
    glBegin(GL_POLYGON);
    glVertex2f(13.1f,66.6f);
    glVertex2f(13.3f,66.6f);
    glVertex2f(13.5f,65.0f);
    glVertex2f(12.9f,65.0f);
    glEnd();
    glColor3ub(180.0f,170.0f,170.0f);
    glBegin(GL_POLYGON);
    glVertex2f(13.1f,66.8f);
    glVertex2f(13.3f,66.8f);
    glVertex2f(13.5f,68.4f);
    glVertex2f(12.9f,68.4f);
    glEnd();
    glPopMatrix();
}

void heli_blade2()         //330102
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(heli_movex, heli_movey, 0.0f);
    glTranslatef(5.0f,68.0f,0.0f);
    glRotatef(heli_angle, 0.0f, 0.0f,0.0f);
    glTranslatef(-5.0f,-68.0f,0.0f);
    glLineWidth(3);
    glColor3ub(180.0f,170.0f,170.0f);
    glBegin(GL_LINES);
    glVertex2f(9.3f,68.1f);
    glVertex2f(5.1f,68.1f);
    glVertex2f(5.1f,68.1f);
    glVertex2f(0.9f,68.1f);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.2;
            float x = 4 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+5,y+68);
        }
    glEnd();
    glPopMatrix();
}

void heli_body()         //330103
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(heli_movex, heli_movey, 0.0f);
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,15.0f,15.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2;
            float x = 2 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+5,y+65);
        }
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(165.0f,155.0f,155.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = 1.5 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+2.8,y+65.3);
        }
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,15.0f,15.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.5;
            float x = 1.5 * r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+5,y+67);
        }
    glEnd();
    glColor3ub(165.0f,155.0f,155.0f);
    glBegin(GL_LINES);
    glVertex2f(5.5f,66.2f);
    glVertex2f(7.0f,66.2f);
    glVertex2f(5.5f,66.2f);
    glVertex2f(5.5f,64.0f);
    glVertex2f(5.5f,64.0f);
    glVertex2f(7.0f,64.0f);
    glVertex2f(7.0f,66.2f);
    glVertex2f(7.0f,64.0f);
    glEnd();
    glColor3ub(135.0f,125.0f,125.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5.7f,66.0f);
    glVertex2f(5.7f,65.0f);
    glVertex2f(6.8f,65.0f);
    glVertex2f(6.8f,66.0f);
    glEnd();
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(7.5f,64.0f);
    glVertex2f(14.0f,66.7f);
    glVertex2f(14.0f,67.0f);
    glVertex2f(7.5f,66.0f);
    glEnd();
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(12.5f,66.5f);
    glVertex2f(13.8f,67.0f);
    glVertex2f(14.2f,68.5f);
    glVertex2f(13.9f,68.5f);
    glEnd();
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(12.8f,66.5f);
    glVertex2f(13.7f,67.0f);
    glVertex2f(14.2f,65.5f);
    glVertex2f(13.9f,65.5f);
    glEnd();
    glLineWidth(1);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(2.5f,63.0f);
    glVertex2f(7.5f,63.0f);
    glVertex2f(2.5f,63.0f);
    glVertex2f(1.8f,63.5f);
    glVertex2f(2.5f,62.3f);
    glVertex2f(7.5f,62.3f);
    glVertex2f(2.5f,62.3f);
    glVertex2f(1.5f,62.8f);
    glVertex2f(3.9f,62.3f);
    glVertex2f(3.9f,63.5f);
    glVertex2f(6.5f,62.3f);
    glVertex2f(6.5f,63.5f);
    glEnd();
    glLineWidth(2);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(5.0f,67.5f);
    glVertex2f(5.0f,68.0f);
    glEnd();
    glPopMatrix();
}

void helicopter()        //3301
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-4.0f, -3.0f, 0.0f);
    glTranslatef(heli_movex, heli_movey, 0.0f);
    heli_blade1();
    heli_blade2();
    heli_body();
    if(state=='n' && heli_movey!=0)
    {
    glPointSize(4.0);
    glColor3ub(255.0f,255.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex2f(2.0,63.0f);
    glEnd();
    }
    glPopMatrix();
}

void helicopter_angle(int value)       //3301001
{
    heli_angle+=50.0f;
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, helicopter_angle, 0); //Notify GLUT to call update again in 25 milliseconds
}

void helicopter_movex(int value)       //3301002
{
    if(heli_movey = 12.5)
    {
        heli_movex -= 0.45;
    }
    if(heli_movex < -200.0)
    {

        heli_movex = 192;
    }
    glutPostRedisplay();
    glutTimerFunc(20, helicopter_movex, 0);
}

void helicopter_movey(int value)       //3301003
{
     if(heli_movey < 13.0)
    {
        heli_movey += 0.45;
    }
    else//(front_car_move < -20.0)
    {
        glutTimerFunc(20, helicopter_movex, 0);
        //return;
    }
    glutPostRedisplay();
    glutTimerFunc(20, helicopter_movey, 0);
}

void ship_body()       //340101
{
    glColor3ub(32.0f,32.0f,32.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-70.0f,-80.0f);
        glVertex2f(-85.0f,-60.0f);
        glVertex2f(-65.0f,-60.0f);
        glVertex2f(-62.0f,-65.0f);
         glVertex2f(65.0f,-65.0f);
        glVertex2f(40.0f,-80.0f);
        glEnd();

            glColor3ub(32.0f,32.0f,32.0f);
        glBegin(GL_POLYGON);
        glVertex2f(45.0f,-65.0f);
        glVertex2f(50.0f,-60.0f);
        glVertex2f(102.0f,-60.0f);
        glVertex2f(80.0f,-80.0f);
         glVertex2f(40.0f,-80.0f);
        glEnd();

        //low part
            glColor3ub(255.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-70.0f,-80.0f);
        glVertex2f(80.0f,-80.0f);

       glVertex2f(71.0f,-90.0f);
        glVertex2f(-63.0f,-90.0f);
        glEnd();

     //up rightg white part
          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(50.0f,-60.0f);
        glVertex2f(55.0f,-55.0f);

       glVertex2f(107.0f,-55.0f);
        glVertex2f(102.0f,-60.0f);
        glEnd();
        //antiner
           glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(82.0f,-35.0f);
        glVertex2f(82.0f,-55.0f);

       glVertex2f(80.0f,-55.0f);
        glVertex2f(80.0f,-35.0f);
        glEnd();

        //antiner 1
           glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(84.0f,-36.0f);
        glVertex2f(84.0f,-38.0f);

       glVertex2f(78.0f,-38.0f);
        glVertex2f(78.0f,-36.0f);
        glEnd();

         //antiner 2
           glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(86.0f,-39.0f);
        glVertex2f(86.0f,-41.0f);

       glVertex2f(76.0f,-41.0f);
        glVertex2f(76.0f,-39.0f);
        glEnd();

         //antiner 3
           glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(88.0f,-42.0f);
        glVertex2f(88.0f,-44.0f);

       glVertex2f(74.0f,-44.0f);
        glVertex2f(74.0f,-42.0f);
        glEnd();

        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(84.0f,-48.0f);
        glVertex2f(84.0f,-55.0f);

       glVertex2f(88.0f,-55.0f);
        glVertex2f(88.0f,-48.0f);
        glEnd();

          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(90.0f,-48.0f);
        glVertex2f(90.0f,-55.0f);

       glVertex2f(94.0f,-55.0f);
        glVertex2f(94.0f,-48.0f);
        glEnd();

        //2
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(74.0f,-48.0f);
        glVertex2f(74.0f,-55.0f);

       glVertex2f(78.0f,-55.0f);
        glVertex2f(78.0f,-48.0f);
        glEnd();

          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(72.0f,-48.0f);
        glVertex2f(72.0f,-55.0f);

       glVertex2f(68.0f,-55.0f);
        glVertex2f(68.0f,-48.0f);
        glEnd();



         //up left white part
          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-65.0f,-60.0f);
        glVertex2f(-65.0f,-40.0f);
        glVertex2f(-40.0f,-40.0f);
        glVertex2f(-40.0f,-65.0f);
        glVertex2f(-62.0f,-65.0f);
        glEnd();

          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-70.0f,-45.0f);
        glVertex2f(-35.0f,-45.0f);
         glVertex2f(-35.0f,-35.0f);
        glVertex2f(-70.0f,-35.0f);
        glEnd();

           glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

         glVertex2f(-43.0f,-35.0f);
        glVertex2f(-63.0f,-35.0f);
        glVertex2f(-63.0f,-32.0f);
        glVertex2f(-43.0f,-32.0f);
        glEnd();

              glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-68.0f,-32.0f);
        glVertex2f(-38.0f,-32.0f);

        glVertex2f(-48.0f,-20.0f);
        glVertex2f(-58.0f,-20.0f);
        glEnd();

    //antenar
         glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-54.0f,-20.0f);
        glVertex2f(-54.0f,-8.0f);
        glVertex2f(-52.0f,-8.0f);
        glVertex2f(-52.0f,-20.0f);
        glEnd();

        //antenar 1
          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-56.0f,-11.0f);
        glVertex2f(-56.0f,-9.5f);
        glVertex2f(-50.0f,-9.5f);
        glVertex2f(-50.0f,-11.0f);
        glEnd();

        //antenar 2
          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-56.0f,-14.0f);
        glVertex2f(-56.0f,-12.5f);
        glVertex2f(-50.0f,-12.5f);
        glVertex2f(-50.0f,-14.0f);
        glEnd();

        //antenar 3
          glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-56.0f,-17.0f);
        glVertex2f(-56.0f,-15.5f);
        glVertex2f(-50.0f,-15.5f);
        glVertex2f(-50.0f,-17.0f);
        glEnd();

              glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-65.0f,-60.0f);
        glVertex2f(-80.0f,-60.0f);

        glVertex2f(-80.0f,-47.0f);
        glVertex2f(-65.0f,-47.0f);
        glEnd();

        //window

        glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);

        glVertex2f(-65.0f,-42.0f);
        glVertex2f(-40.0f,-42.0f);
         glVertex2f(-40.0f,-38.0f);
        glVertex2f(-65.0f,-38.0f);
        glEnd();
    //windw_3_0
       glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-60.0f,-62.0f);
        glVertex2f(-60.0f,-48.0f);
        glVertex2f(-55.0f,-48.0f);
        glVertex2f(-55.0f,-62.0f);
        glEnd();
    //windw_3_1
        glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-52.0f,-52.0f);
        glVertex2f(-52.0f,-48.0f);
        glVertex2f(-42.0f,-48.0f);
        glVertex2f(-42.0f,-52.0f);
        glEnd();
    //windw_3_2
        glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-52.0f,-53.0f);
        glVertex2f(-52.0f,-57.0f);
        glVertex2f(-42.0f,-57.0f);
        glVertex2f(-42.0f,-53.0f);
        glEnd();
    //windw_3_3
        glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-52.0f,-58.0f);
        glVertex2f(-52.0f,-62.0f);
        glVertex2f(-42.0f,-62.0f);
        glVertex2f(-42.0f,-58.0f);
        glEnd();
        //back window
        glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-70.0f,-58.0f);
        glVertex2f(-77.0f,-58.0f);

        glVertex2f(-77.0f,-49.0f);
        glVertex2f(-70.0f,-49.0f);
        glEnd();

            glColor3ub(102.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-53,y-28);

        }
        glEnd();

}

void ship_piller()      //340102
{
    glLineWidth(2.0);
    //bottom_right
    for(int i=0;i<34;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-40.0f+i*3,-65.0f);
        glVertex2f(-40.0f+i*3,-62.0f);
        glEnd();

    }
    glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-40.0f,-62.0f);
        glVertex2f(50.0f,-62.0f);
        glEnd();
}

void ship_container()      //340103
{
    glLineWidth(0.5);

        glBegin(GL_POLYGON);
        glVertex2f(-30.0f,-40.0f);
        glVertex2f(-30.0f,-32.0f);
        glVertex2f(-10.0f,-32.0f);
        glVertex2f(-10.0f,-40.0f);
        glEnd();

         for(int i=0;i<7;i++)
    {
        glColor3ub(255.0f,255.0f,255.0f);
        glBegin(GL_LINES);
        glVertex2f(-29.5f+i*3,-33.0f);
        glVertex2f(-29.5f+i*3,-39.0f);
        glEnd();
    }


}

void ship_container_1()      //340104
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(64.0f,64.0f,64.0f);
    glTranslated(5.0f,-10.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_2()      //340105
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(204.0f,204.0f,0.0f);
    glTranslated(5.0f,-18.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_3()      //340106
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(64.0f,64.0f,64.0f);
    glTranslated(5.0f,-26.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_4()      //340107
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(204.0f,0.0f,0.0f);
    glTranslated(25.0f,-10.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_5()      //340108
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(0.0f,204.0f,204.0f);
    glTranslated(25.0f,-18.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_6()      //340109
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(204.0f,0.0f,0.0f);
    glTranslated(25.0f,-26.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_7()      //340110
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(0.0f,153.0f,76.0f);
    glTranslated(45.0f,-10.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_8()      //340111
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3ub(64.0f,64.0f,64.0f);
    glTranslated(45.0f,-18.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_9()      //340112
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(204.0f,204.0f,0.0f);
    glTranslated(45.0f,-26.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_10()      //340113
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
      glColor3ub(204.0f,0.0f,0.0f);
    glTranslated(65.0f,-10.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_11()      //340114
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(0.0f,204.0f,204.0f);
    glTranslated(65.0f,-18.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void ship_container_12()      //340115
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(0.0f,153.0f,76.0f);
    glTranslated(65.0f,-26.0f,0.0f);
    ship_container();
    glPopMatrix();
}

void  ship()       //3401
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3f,0.3f,0.0f);
    glTranslatef(-110.0,185.0f,0.0f);
     glTranslatef(ship_1_move_right, 0.0f, 0.0f);
    ship_container_1();
    ship_container_2();
    ship_container_3();
    ship_container_4();
    ship_container_5();
     ship_container_6();
     ship_container_7();
     ship_container_8();
     ship_container_9();
     ship_container_10();
     ship_container_11();
     ship_container_12();
     ship_piller();
     ship_body();
     glPopMatrix();
}

void update_ship_1(int value)      //3401001
{
ship_1_move_right += 2.4;
if(ship_1_move_right > 900.0)
{
ship_1_move_right = -800;
}
glutPostRedisplay();
glutTimerFunc(20, update_ship_1, 0);
}

void ship_2()      //3402
{
     glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5f,0.5f,0.0f);
    glColor3ub(102.0f,0.0f,0.0f);
    glTranslatef(-110.0,-110.0f,0.0f);
     glTranslatef(ship_2_move_left, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-70.0f,-80.0f);
        glVertex2f(-85.0f,-60.0f);
        glVertex2f(-25.0f,-60.0f);
        glVertex2f(-21.0f,-65.0f);
         glVertex2f(55.0f,-65.0f);
        glVertex2f(40.0f,-80.0f);
        glEnd();
        //yellow
        glColor3ub(255.0f,255.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-74.0f,-75.0f);
        glVertex2f(-78.0f,-70.0f);
        glVertex2f(50.0f,-70.0f);
        glVertex2f(45.0f,-75.0f);
        glEnd();
        //room
           glColor3ub(128.0f,128.0f,128.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-21.0f,-65.0f);
        glVertex2f(-17.0f,-55.0f);
        glVertex2f(47.0f,-55.0f);
        glVertex2f(50.0f,-65.0f);
        glEnd();

         for(int i=0;i<6;i++)
    {

      glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        glColor3ub(0.0f,0.0f,0.0f);
        for(int j=0;j<200;j++)
        {
            float pi=3.1416;
            float A=(j*2*pi)/200;
            float r=3.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-10+i*10,y-60);
        }
        glEnd();
    }
        glLineWidth(2.0);
      glColor3ub(64.0f,64.0f,64.0f);
        glBegin(GL_LINES);
        glVertex2f(-15.0f,-55.0f);
        glVertex2f(-15.0f,-10.0f);
        glEnd();

        //pal
    //left
            glColor3ub(0.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-65.0f,-50.0f);
        glVertex2f(-16.0f,-11.0f);
        glVertex2f(-20.0f,-50.0f);
        glEnd();
          glColor3ub(0.0f,204.0f,204.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-35.0f,-45.0f);
        glVertex2f(-16.0f,-11.0f);
        glVertex2f(-20.0f,-50.0f);
        glEnd();

        //right
             glColor3ub(0.0f,204.0f,204.0f);
        glBegin(GL_POLYGON);
        glVertex2f(35.0f,-50.0f);
        glVertex2f(-14.0f,-11.0f);
        glVertex2f(-10.0f,-50.0f);
        glEnd();
           glColor3ub(0.0f,102.0f,102.0f);
        glBegin(GL_POLYGON);
        glVertex2f(0.0f,-47.0f);
        glVertex2f(-14.0f,-11.0f);
        glVertex2f(-10.0f,-50.0f);
        glEnd();

         glPopMatrix();

}

void update_ship_2(int value)      //3402001
{
ship_2_move_left -= 2.0;
if(ship_2_move_left < -330.5)
{
    ship_2_move_left = 570;
}
glutPostRedisplay();
glutTimerFunc(20, update_ship_2, 0);

}

void Boat_1()      //3403
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(boat_1_move_right, 0.0f, 0.0f);

    glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(140.0f,-93.0f);
	glVertex2f(137.0f,-90.0f);
	glVertex2f(170.0f,-90.0f);
	glVertex2f(165.0f,-93.0f);
	glEnd();

	if(state=='d'  || show=='p'){glColor3ub(255.0f,255.0f,0.0f);}
    if(state=='n' && show!='p'){glColor3ub(230.0f,230.0f,50.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(137.0f,-90.0f);
	glVertex2f(137.0f,-89.0f);
	glVertex2f(165.0f,-89.0f);
	glVertex2f(165.0f,-90.0f);
	glEnd();

    glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(140.0f,-89.0f);
	glVertex2f(140.0f,-84.0f);
	glVertex2f(157.0f,-84.0f);
	glVertex2f(162.0f,-89.0f);
	glEnd();
	if(state=='d'|| show=='p'){glColor3ub(164.0f,189.0f,198.0f);}
    if(state=='n'&& show!='p'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(142.0f,-86.0f);
	glVertex2f(142.0f,-85.0f);
	glVertex2f(151.0f,-85.0f);
	glVertex2f(151.0f,-86.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(142.0f,-88.0f);
	glVertex2f(142.0f,-87.0f);
	glVertex2f(151.0f,-87.0f);
	glVertex2f(151.0f,-88.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(153.0f,-85.0f);
	glVertex2f(153.0f,-88.0f);
	glVertex2f(156.0f,-88.0f);
	glVertex2f(156.0f,-85.0f);
	glEnd();


	glColor3ub(204.0f,102.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(137.5f,-89.0f);
	glVertex2f(137.5f,-85.0f);
	glVertex2f(139.0f,-85.0f);
	glVertex2f(139.0f,-89.0f);
	glEnd();

    //upre part
	glColor3ub(255.0f,51.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(140.0f,-84.0f);
	glVertex2f(141.0f,-81.5f);
	glVertex2f(143.0f,-81.0f);
	glVertex2f(143.0f,-84.0f);
	glEnd();

	glColor3ub(255.0f,51.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(142.0f,-81.5f);
	glVertex2f(140.0f,-79.0f);
	glVertex2f(143.0f,-79.0f);
	glVertex2f(143.0f,-81.0f);
	glEnd();

	glColor3ub(255.0f,51.0f,51.0f);
	glBegin(GL_POLYGON);
	glVertex2f(140.0f,-79.0f);
	glVertex2f(155.0f,-79.0f);
	glVertex2f(157.0f,-80.0f);
	glVertex2f(155.0f,-81.0f);
	glVertex2f(144.0f,-81.0f);
	glVertex2f(143.0f,-84.0f);
	glEnd();

	glLineWidth(1.0);
    glPointSize(3.0);
    glColor3ub(255.0f,51.0f,51.0f);
    glBegin(GL_LINES);
    glVertex2f(143.0f,-84.0f);
    glVertex2f(155.0f,-81.0f);
    glEnd();

    if(state=='n' && show!='p')
    {
        glColor3ub(255.0f,255.0f,112.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(168.5f,-89.0f);
        glVertex2f(177.0f,-93.0f);
        glVertex2f(177.0f,-85.0f);
        glEnd();
    }
    glColor3ub(0.0f,0.0f,0.0f);
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glVertex2f(168.0f,-89.0f);
    glEnd();
    glPopMatrix();

}

void Boat_2()      //3404
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(boat_2_move_left, 0.0f, 0.0f);
    //lower part
       glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-90.0f,-72.0f);
	glVertex2f(-94.0f,-70.0f);
	glVertex2f(-70.0f,-70.0f);
	glVertex2f(-72.0f,-72.0f);
	glEnd();
	  glColor3ub(100.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-94.0f,-70.0f);
	glVertex2f(-94.0f,-69.0f);
	glVertex2f(-70.0f,-69.0f);
	glVertex2f(-70.0f,-70.0f);
	glEnd();

	//upper part
	glColor3ub(100.0f,100.0f,100.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-90.0f,-69.0f);
	glVertex2f(-88.0f,-64.5f);
	glVertex2f(-74.0f,-64.5f);
	glVertex2f(-73.0f,-69.0f);
	glEnd();


	//window
	if(state=='d'|| show=='p'){glColor3ub(164.0f,189.0f,198.0f);}
    if(state=='n' && show!='p'){glColor3ub(255.0f,255.0f,112.0f);}
	glBegin(GL_POLYGON);
	glVertex2f(-88.0f,-68.3f);
	glVertex2f(-88.0f,-66.3f);
	glVertex2f(-86.0f,-66.3f);
	glVertex2f(-86.0f,-68.3f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-76.0f,-68.3f);
	glVertex2f(-76.0f,-65.8f);
	glVertex2f(-74.5f,-65.8f);
	glVertex2f(-74.5f,-68.3f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-80.0f,-68.3f);
	glVertex2f(-80.0f,-65.8f);
	glVertex2f(-78.0f,-65.8f);
	glVertex2f(-78.0f,-68.3f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-84.05f,-68.3f);
	glVertex2f(-84.05f,-65.8f);
	glVertex2f(-81.95f,-65.8f);
	glVertex2f(-81.95f,-68.3f);
	glEnd();

	//light
	glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-86.6f,-64.5f);
	glVertex2f(-86.6f,-63.0f);
	glVertex2f(-87.4f,-63.0f);
	glVertex2f(-87.4f,-64.5f);
	glEnd();

	 glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            if(state=='d' || show=='p'){glColor3ub(255.0f,255.0f,255.0f);}
            if(state=='n' && show!='p'){glColor3ub(255.0f,255.0f,0.0f);}
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.6;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-87,y-62.5);
        }
    glEnd();

	glLineWidth(1.0);
    glColor3ub(255.0f,255.0f,255.0f);
    glBegin(GL_LINES);
    glVertex2f(-77.0f,-65.0f);
    glVertex2f(-77.0f,-69.0f);

    glVertex2f(-81.0f,-65.0f);
    glVertex2f(-81.0f,-69.0f);

    glVertex2f(-85.0f,-65.0f);
    glVertex2f(-85.0f,-69.0f);
  glEnd();
    //raling
    glLineWidth(1.0);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-90.0f,-69.0f);
    glVertex2f(-90.0f,-66.0f);

     glVertex2f(-93.5f,-69.0f);
    glVertex2f(-93.5f,-66.0f);

    glVertex2f(-94.0f,-67.0f);
    glVertex2f(-89.5f,-67.0f);

    glVertex2f(-94.0f,-68.0f);
    glVertex2f(-89.5f,-68.0f);
    glEnd();

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-90,y-65.8);
        }
    glEnd();

       glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,102.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-93.5,y-65.8);
        }
    glEnd();

    if(state=='n' && boat_2_move_left!=0 && show!='p')
    {
        glColor3ub(255.0f,255.0f,112.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-93.6f,-67.0f);
        glVertex2f(-102.0f,-62.0f);
        glVertex2f(-102.0f,-71.0f);
        glEnd();
    }
    glColor3ub(0.0f,0.0f,0.0f);
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glVertex2f(-93.6f,-67.0f);
    glEnd();
    glPopMatrix();
}

void Boat_11()      //3405
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-boat_1_move_right-30,75.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.55f,-0.55f,0.0f);
    Boat_1();
    glPopMatrix();
}

void Boat_21()      //3406
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(boat_21_move_right-10,100.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(2.5f,-2.5f,0.0f);
    Boat_2();
    glPopMatrix();
}

void update_boat_21(int value)      //3406001
{
boat_21_move_right += 0.8;
if(boat_21_move_right > 50.0)
{
boat_21_move_right = -420;
}
glutPostRedisplay();
glutTimerFunc(20, update_boat_21, 0);
}

void update_boat_1(int value)      //3403001
{
boat_1_move_right += 0.4;
if(boat_1_move_right > 80.0)
{
boat_1_move_right = -360;
}
glutPostRedisplay();
glutTimerFunc(20, update_boat_1, 0);
}

void update_boat_2(int value)      //3404001
{
boat_2_move_left -= .4;
if(boat_2_move_left < -130.5)
{
    return;
}
glutPostRedisplay();
glutTimerFunc(20, update_boat_2, 0);

}

void t_body1()         //350101
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(200.0f,200.0f,200.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = 8* r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-102,y+20);
        }
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,15.0f,15.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-94,y+16);
        }
    glEnd();
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-90.0f,16.0f);
    glVertex2f(-90.0f,14.0f);
    glVertex2f(-96.0f,14.0f);
    glVertex2f(-96.0f,20.0f);
    glVertex2f(-94.0f,20.0f);
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(80.0f,70.0f,70.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-94,y+16);
        }
    glEnd();
    glColor3ub(80.0f,70.0f,70.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-91.0f,16.0f);
    glVertex2f(-91.0f,14.0f);
    glVertex2f(-96.0f,14.0f);
    glVertex2f(-96.0f,19.0f);
    glVertex2f(-94.0f,19.0f);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-98,y+9);
        }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-94,y+9);
        }
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(50.0f,50.0f,50.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-91,y+11);
        }
    glEnd();
    glColor3ub(50.0f,50.0f,50.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-102.0f,9.0f);
    glVertex2f(-102.0f,12.0f);
    glVertex2f(-91.0f,12.0f);
    glVertex2f(-91.0f,9.0f);
    glEnd();
    glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-90.0f,14.0f);
    glVertex2f(-90.0f,12.0f);
    glVertex2f(-102.0f,12.0f);
    glVertex2f(-102.0f,14.0f);
    glEnd();
    glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-96.0f,19.0f);
    glVertex2f(-96.0f,14.0f);
    glVertex2f(-102.0f,14.0f);
    glVertex2f(-102.0f,19.0f);
    glEnd();
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-96.0f,20.0f);
    glVertex2f(-96.0f,19.0f);
    glVertex2f(-102.0f,19.0f);
    glVertex2f(-102.0f,20.0f);
    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            if(state=='d'|| show=='p'){glColor3ub(80.0f,70.0f,70.0f);}
            if(state=='n'&& show!='p'){glColor3ub(255.0f,255.0f,112.0f);}
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = 2 * r * sin(A);
            glVertex2f(x-99,y+15.5);
        }
    glEnd();
    glLineWidth(0.2);
    glColor3ub(100.0f,100.0f,100.0f);
    glBegin(GL_LINES);
    glVertex2f(-102.0f,21.0f);
    glVertex2f(-102.0f,14.0f);
    glEnd();
    glLineWidth(0.2);
    glColor3ub(100.0f,100.0f,100.0f);
    glBegin(GL_LINES);
    glVertex2f(-101.9f,21.0f);
    glVertex2f(-101.9f,14.0f);
    glEnd();
}

void t_body2()         //350102
{
    glColor3ub(255.0f,15.0f,15.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-102.0f,20.0f);
    glVertex2f(-102.0f,19.0f);
    glVertex2f(-124.8f,19.0f);
    glVertex2f(-124.8f,20.0f);
    glEnd();
    glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-102.0f,19.0f);
    glVertex2f(-102.0f,12.0f);
    glVertex2f(-124.8f,12.0f);
    glVertex2f(-124.8f,19.0f);
    glEnd();
    glColor3ub(50.0f,50.0f,50.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-124.8f,10.0f);
    glVertex2f(-124.8f,12.0f);
    glVertex2f(-102.0f,12.0f);
    glVertex2f(-102.0f,10.0f);
    glEnd();
    for(int j=0;j<5;j++)
    {
        glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            if(state=='d'){glColor3ub(80.0f,70.0f,70.0f);}
            if(state=='n'&& show!='p'){glColor3ub(255.0f,255.0f,112.0f);}
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-106-j*4,y+16.5);
        }
        glEnd();
    }
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-124.0f,9.0f);
    glVertex2f(-124.0f,10.0f);
    glVertex2f(-114.0f,10.0f);
    glVertex2f(-114.0f,9.0f);
    glEnd();
    for(int j=0;j<3;j++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-116-j*3,y+9);
        }
        glEnd();
    }
    glLineWidth(1);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-124.8f,20.0f);
    glVertex2f(-124.8f,10.0f);
    glEnd();
}

void t_body3()         //350103
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-23.0f, 0.0f, 0.0f);
    t_body2();
    glPopMatrix();
}

void t_body4()         //350104
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-23.0f, 0.0f, 0.0f);
    t_body3();
    glPopMatrix();
}

void trump()         //3501
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(trump_move, 0.0f, 0.0f);
    glTranslatef(-50.0f, 0.0f, 0.0f);
    if(show=='n'&&state=='n'&&trump_move!=0)
    {
    glColor3ub(255.0f,255.0f,112.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-92.0,11.0f);
    glVertex2f(-80.0,7.0f);
    glVertex2f(-80.0,15.0f);
    glEnd();
    }
    t_body1();
    t_body2();
    t_body3();
    t_body4();

    glPopMatrix();
}

void trump_1()         //3502
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(trump_1_move-100,4.5f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    trump();
    glPopMatrix();
}

void trump_update(int value)         //3501001
{
    if(show=='p')
    {
        trump_move = -100;
        trump_speed = 1.0f;
    }
    else if(show=='n')
    {
    trump_move += trump_speed;
    if(trump_move > 430)
    {
        trump_move = -100;
    }
    else if(trump_move==0)
    {
        trump_speed = 0.0f;
    }
    }
    glutPostRedisplay();
    glutTimerFunc(20, trump_update, 0);


}

void trump_1_update(int value)         //3502001
{
    if(show=='p')
    {
    trump_1_move += 1.0;
    if(trump_1_move > 600)
    {
        trump_1_move = 0.0;
        show='n';
        if(snow_state!='y'){snow_cover=0;}
        glutTimerFunc(0,disback,0);
    }
    }
    glutPostRedisplay();
    glutTimerFunc(20, trump_1_update, 0);

}

void truck_tire1()         //360101
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-77.0f, 8.0f, 0.0f);
    glScalef(1.5f, 1.5f, 0.0f);

    glTranslatef(155.0f,-16.0f,0.0f);
    glRotatef(truck_tire_rotate_left, 0.0f, 0.0f,1.0f);
    glTranslatef(-155.0f,16.0f,0.0f);

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glLineWidth(2);
	glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(154.0f,-16.0f);
	glVertex2f(156.0f,-16.0f);
	glVertex2f(155.0f,-15.0f);
	glVertex2f(155.0f,-17.0f);
	glEnd();
    glPopMatrix();
}

void truck_tire2()         //360102
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-57.0f, 8.0f, 0.0f);
    glScalef(1.5f, 1.5f, 0.0f);

    glTranslatef(155.0f,-16.0f,0.0f);
    glRotatef(truck_tire_rotate_left, 0.0f, 0.0f,1.0f);
    glTranslatef(-155.0f,16.0f,0.0f);

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glLineWidth(2);
	glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(154.0f,-16.0f);
	glVertex2f(156.0f,-16.0f);
	glVertex2f(155.0f,-15.0f);
	glVertex2f(155.0f,-17.0f);
	glEnd();
    glPopMatrix();
}

void truck_tire3()         //360103
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-50.0f, 8.0f, 0.0f);
    glScalef(1.5f, 1.5f, 0.0f);

    glTranslatef(155.0f,-16.0f,0.0f);
    glRotatef(truck_tire_rotate_left, 0.0f, 0.0f,1.0f);
    glTranslatef(-155.0f,16.0f,0.0f);

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f,255.0f,255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y-16);
        }
	glEnd();
	glLineWidth(2);
	glColor3ub(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(154.0f,-16.0f);
	glVertex2f(156.0f,-16.0f);
	glVertex2f(155.0f,-15.0f);
	glVertex2f(155.0f,-17.0f);
	glEnd();
    glPopMatrix();
}

void truck()         //3601
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(truck_move,0.0f,0.0f);
    //glScalef(100.0f,100.0f,0.0f);
    if(state=='n'&& show!='p')
    {
    glPointSize(5);
    glColor3ub(255.0f,255.0f,112.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(155.0f,-12.0f);
    glVertex2f(142.0f,-9.0f);
    glVertex2f(142.0f,-15.0f);
    glEnd();
    }
    glColor3ub(0.0f,155.0f,155.0f);
    //body
    glBegin(GL_POLYGON);
    glVertex2f(190.0f,-16.0f);
    glVertex2f(150.0f,-16.0f);
    glVertex2f(150.0f,-13.0f);
    glVertex2f(190.0f,-13.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(150.5f,-13.0f);
    glVertex2f(160.0f,-13.0f);
    glVertex2f(160.0f,-7.0f);
    glVertex2f(153.0f,-7.0f);
    glVertex2f(150.5f,-10.0f);
    glEnd();

    //box
    glColor3ub(200.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(160.5f,-13.0f);
    glVertex2f(189.5f,-13.0f);
    glVertex2f(189.5f,-7.0f);
    glVertex2f(160.5f,-7.0f);
    glEnd();

    for(int i=0;i<30;i++)
    {
        glLineWidth(1);
        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(160.5f+i*1,-13.0f);
        glVertex2f(160.5f+i*1,-7.0f);
        glEnd();
    }
    //window
    glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(151.0f,-10.5f);
    glVertex2f(159.5f,-10.5f);
    glVertex2f(159.5f,-7.5f);
    glVertex2f(153.5f,-7.5f);
    glEnd();

    truck_tire1();
    truck_tire2();
    truck_tire3();
    glPopMatrix();
}

void truck_1()         //3602
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0,22.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.9f,-0.9f,0.0f);
    truck();
    glPopMatrix();
}

void update_truck_tire(int value)         //3601001
{
    truck_tire_rotate_left +=15.0f;
    glutPostRedisplay();
    glutTimerFunc(20, update_truck_tire, 0);
}

void update_truck(int value)         //3601002
{
    truck_move -= 1.0;
    if(truck_move < -410.0)
    {
    truck_move = 80.0;
    }
glutPostRedisplay();
glutTimerFunc(20, update_truck, 0);
}

void rv_tire1()         //370101
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-177, -8.4f, 0.0f);
    glScalef(3.5f, 3.5f, 0.0f);

    glTranslatef(-1.3,0.1f,0.0f);
    glRotatef(van1_tire_rotate_right, 0.0f, 0.0f,1.0f);
    glTranslatef(1.3f,-0.1f,0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.41;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-1.3,y+0.1);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(150.0f,150.0f,150.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.23;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-1.3,y+0.1);
        }
	glEnd();
	glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(-1.3f,0.33f);
	glVertex2f(-1.3f,-0.13f);
	glVertex2f(-1.53f,0.1f);
	glVertex2f(-1.07f,0.1f);
	glEnd();
    glPopMatrix();
}

void rv_tire2()         //370102
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-157, -8.4f, 0.0f);
    glScalef(3.5f, 3.5f, 0.0f);

    glTranslatef(-4.3f,0.1f,0.0f);
    glRotatef(van1_tire_rotate_right, 0.0f, 0.0f,1.0f);
    glTranslatef(4.3f,-0.1f,0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.41;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(150.0f,150.0f,150.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.23;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(-4.3f,0.33f);
	glVertex2f(-4.3f,-0.13f);
	glVertex2f(-4.53f,0.1f);
	glVertex2f(-4.07f,0.1f);
	glEnd();
	glPopMatrix();
}

void rv_tire3()         //370103
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-150, -8.4f, 0.0f);
    glScalef(3.5f, 3.5f, 0.0f);

    glTranslatef(-4.3f,0.1f,0.0f);
    glRotatef(van1_tire_rotate_right, 0.0f, 0.0f,1.0f);
    glTranslatef(4.3f,-0.1f,0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.41;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(150.0f,150.0f,150.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.23;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(-4.3f,0.33f);
	glVertex2f(-4.3f,-0.13f);
	glVertex2f(-4.53f,0.1f);
	glVertex2f(-4.07f,0.1f);
	glEnd();
	glPopMatrix();
}

void rv()         //3701
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-van1_move-50.0f,-13.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(1.0f,-1.0f,0.0f);
    if(state=='n'&& show!='p')
    {
    glColor3ub(255.0f,255.0f,112.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-162.0f,-6.0f);
    glVertex2f(-152.5f,-3.0f);
    glVertex2f(-152.5f,-9.0f);
    glEnd();
    }
    glColor3ub(200.0f,200.0f,200.0f);
    //body
    glBegin(GL_POLYGON);
    glVertex2f(-190.0f,-8.0f);
    glVertex2f(-160.0f,-8.0f);
    glVertex2f(-159.0f,-6.0f);
    glVertex2f(-191.0f,-6.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-191.0f,-6.0f);
    glVertex2f(-159.0f,-6.0f);
    glVertex2f(-162.0f,0.0f);
    glVertex2f(-190.0f,0.0f);
    glEnd();

    //line
    glLineWidth(2.0);
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-191.0f,-6.0f);
    glVertex2f(-159.0f,-6.0f);
    glEnd();
    glColor3ub(0.0f,255.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.9f,-6.3f);
    glVertex2f(-159.1f,-6.3f);
    glEnd();
    glColor3ub(0.0f,0.0f,255.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.8f,-6.6f);
    glVertex2f(-159.2f,-6.6f);
    glEnd();

    glTranslatef(0.0f,5.6f,0.0f);
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.0f,-6.0f);
    glVertex2f(-162.0f,-6.0f);
    glEnd();
    glColor3ub(0.0f,255.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.0,-6.3f);
    glVertex2f(-162.0f,-6.3f);
    glEnd();
    glColor3ub(0.0f,0.0f,255.0f);
    glBegin(GL_LINES);
    glVertex2f(-190.0f,-6.6f);
    glVertex2f(-162.0f,-6.6f);
    glEnd();
    glTranslatef(0.0f,-5.6f,0.0f);

    //box
    glLineWidth(2.0);
    glColor3ub(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-189.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-7.0f);

    glVertex2f(-186.0f,-7.0f);
    glVertex2f(-184.0f,-7.0f);
    glVertex2f(-184.0f,-7.0f);
    glVertex2f(-184.0f,-6.0f);
    glVertex2f(-184.0f,-6.0f);
    glVertex2f(-186.0f,-6.0f);
    glVertex2f(-186.0f,-6.0f);
    glVertex2f(-186.0f,-7.0f);
    glEnd();

    glTranslatef(5.5f,1.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-189.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-7.0f);

    glVertex2f(-186.5f,-7.0f);
    glVertex2f(-185.0f,-7.0f);
    glVertex2f(-185.0f,-7.0f);
    glVertex2f(-185.0f,-6.0f);
    glVertex2f(-185.0f,-6.0f);
    glVertex2f(-186.5f,-6.0f);
    glVertex2f(-186.5f,-6.0f);
    glVertex2f(-186.5f,-7.0f);
    glEnd();
    glTranslatef(-5.5f,-1.0f,0.0f);

    glTranslatef(10.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-189.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-7.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-187.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-6.0f);
    glVertex2f(-189.0f,-7.0f);

    glVertex2f(-186.0f,-7.0f);
    glVertex2f(-184.0f,-7.0f);
    glVertex2f(-184.0f,-7.0f);
    glVertex2f(-184.0f,-6.0f);
    glVertex2f(-184.0f,-6.0f);
    glVertex2f(-186.0f,-6.0f);
    glVertex2f(-186.0f,-6.0f);
    glVertex2f(-186.0f,-7.0f);
    glEnd();
    glTranslatef(-10.0f,0.0f,0.0f);

    //window
    glBegin(GL_POLYGON);
    glVertex2f(-165.0f,-3.5f);
    glVertex2f(-161.0f,-3.5f);
    glVertex2f(-162.0f,-1.0f);
    glVertex2f(-165.0f,-1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-175.0f,-3.5f);
    glVertex2f(-171.0f,-3.5f);
    glVertex2f(-171.0f,-1.0f);
    glVertex2f(-175.0f,-1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-189.0f,-3.5f);
    glVertex2f(-180.0f,-3.5f);
    glVertex2f(-180.0f,-1.0f);
    glVertex2f(-189.0f,-1.0f);
    glEnd();

    //door
    glBegin(GL_POLYGON);
    glVertex2f(-170.0f,-7.5f);
    glVertex2f(-167.0f,-7.5f);
    glVertex2f(-167.0f,-1.5f);
    glVertex2f(-170.0f,-1.5f);
    glEnd();
    glColor3ub(200.0f,200.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-169.5f,-7.0f);
    glVertex2f(-167.5,-7.0f);
    glVertex2f(-167.5,-4.0f);
    glVertex2f(-169.5,-4.0f);
    glEnd();


    rv_tire1();
    rv_tire2();
    rv_tire3();

	glPopMatrix();
}

void rv_1()         //3702
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0,21.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.9f,-0.9f,0.0f);
    rv();
    glPopMatrix();
}

void update_rv_tire(int value)         //3701001
{
    van1_tire_rotate_right -=10.0f;
    glutPostRedisplay();
    glutTimerFunc(20, update_rv_tire, 0);
}

void update_rv(int value)         //3701001
{
    van1_move += 3.0;
    if(van1_move > 360.0)
    {
    van1_move = -120.0;
    }
glutPostRedisplay();
glutTimerFunc(20, update_rv, 0);
}

void c1_body()         //380101
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLineWidth(0.001);
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.84f,0.23f);
    glVertex2f(-0.845f,0.228f);
    glVertex2f(-0.85f,0.2f);
    glVertex2f(-0.68f,0.2f);
    glVertex2f(-0.685f,0.22f);
    glVertex2f(-0.73f,0.22f);
    glEnd();
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f,0.2f);
    glVertex2f(-0.84f,0.187f);
    glVertex2f(-0.69f,0.187f);
    glVertex2f(-0.68f,0.2f);
    glEnd();
    glColor3ub(255.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.83f,0.23f);
    glVertex2f(-0.81f,0.26f);
    glVertex2f(-0.75f,0.26f);
    glVertex2f(-0.72f,0.22f);
    glEnd();
    //window
    glColor3ub(50.0f,50.0f,50.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.825f,0.225f);
    glVertex2f(-0.803f,0.255f);
    glVertex2f(-0.755f,0.255f);
    glVertex2f(-0.733f,0.225f);
    glEnd();
    //door
    glColor3ub(200.0f,100.0f,100.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.825f,0.225f);
    glVertex2f(-0.805f,0.187f);
    glVertex2f(-0.779f,0.255f);
    glVertex2f(-0.779f,0.187f);
    glVertex2f(-0.733f,0.225f);
    glVertex2f(-0.753f,0.187f);
    glEnd();
    glPopMatrix();
}

void c1_tire1()         //380102
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.09f,0.0f,0.0f);

    glTranslatef(-0.815f,0.185f,0.0f);
    glRotatef(car1_angle, 0.0f, 0.0f,1.0f);
    glTranslatef(0.815f,-0.185f,0.0f);

	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.815,y+0.185);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(32.0f,32.0f,32.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.815,y+0.185);
        }
	glEnd();
	glColor3ub(150.0f,150.0f,150.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.815f,0.195f);
    glVertex2f(-0.815f,0.175f);
    glVertex2f(-0.825f,0.185f);
    glVertex2f(-0.805f,0.185f);
    glEnd();
	glPopMatrix();
}

void c1_tire2()         //380103
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.815f,0.185f,0.0f);
    glRotatef(car1_angle, 0.0f, 0.0f,1.0f);
    glTranslatef(0.815f,-0.185f,0.0f);

	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.815,y+0.185);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(32.0f,32.0f,32.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.815,y+0.185);
        }
	glEnd();
	glColor3ub(150.0f,150.0f,150.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.815f,0.195f);
    glVertex2f(-0.815f,0.175f);
    glVertex2f(-0.825f,0.185f);
    glVertex2f(-0.805f,0.185f);
    glEnd();
	glPopMatrix();
}

void car1()           //3801
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-18.0f,0.0f);
    glScalef(100.0f,100.0f,0.0f);

    glTranslatef(car1_move,0.0f,0.0f);
    if(state=='n'&& show!='p')
    {
    glColor3ub(255.0f,255.0f,112.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.7f,0.205f);
    glVertex2f(-0.63f,0.23f);
    glVertex2f(-0.63f,0.18f);
    glEnd();
    }
    c1_body();
    c1_tire1();
    c1_tire2();


	glPopMatrix();
}

void car1_1()         //3802
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(80,-5.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.9f,-0.9f,0.0f);
    car1();
    glPopMatrix();
}

void c2_body()            //380301
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.0f,0.0f);
    glVertex2f(-0.0f,1.0f);
    glVertex2f(-5.0f,1.0f);
    glVertex2f(-5.0f,0.0f);
    glEnd();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.0f,0.0f);
    glVertex2f(0.2f,0.0f);
    glVertex2f(0.3f,0.4f);
    glVertex2f(0.15f,0.95f);
    glVertex2f(-0.0f,1.0f);
    glEnd();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.0f,1.0f);
    glVertex2f(-1.0f,1.15f);
    glVertex2f(-1.0f,1.0f);
    glEnd();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,1.15f);
    glVertex2f(-2.0f,2.2f);
    glVertex2f(-4.0f,2.2f);
    glVertex2f(-4.6f,1.3f);
    glVertex2f(-5.0f,1.2f);
    glVertex2f(-5.0f,1.0f);
    glEnd();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5.0f,1.2f);
    glVertex2f(-5.35f,1.1f);
    glVertex2f(-5.35f,0.1f);
    glVertex2f(-5.0f,0.0f);
    glEnd();
    glColor3ub(35.0f,80.0f,200.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5.35f,0.1f);
    glVertex2f(-5.5f,0.143f);
    glVertex2f(-5.35f,0.6f);
    glEnd();
    //Window
    glColor3ub(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.2f,1.15f);
    glVertex2f(-2.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-3.0f,1.15f);
    glEnd();
    glColor3ub(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.2f,1.15f);
    glVertex2f(-3.2f,2.0f);
    glVertex2f(-3.95f,2.0f);
    glVertex2f(-4.5f,1.15f);
    glEnd();
    //door
    glColor3ub(200.0f,200.0f,200.0f);
	glBegin(GL_LINES);
	glVertex2f(-4.5f,1.15f);
	glVertex2f(-4.1f,0.48f);
	glVertex2f(-1.2f,1.15f);
	glVertex2f(-1.4f,0.48f);
	glVertex2f(-3.1f,1.15f);
	glVertex2f(-3.1f,0.0f);

	glEnd();
    glPopMatrix();
}

void c2_tire1()            //380302
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.3f,0.1f,0.0f);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);
    glTranslatef(1.3f,-0.1f,0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.41;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-1.3,y+0.1);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(150.0f,150.0f,150.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.23;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-1.3,y+0.1);
        }
	glEnd();
	glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(-1.3f,0.33f);
	glVertex2f(-1.3f,-0.13f);
	glVertex2f(-1.53f,0.1f);
	glVertex2f(-1.07f,0.1f);
	glEnd();
    glPopMatrix();
}

void c2_tire2()             //380303
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-4.3f,0.1f,0.0f);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);
    glTranslatef(4.3f,-0.1f,0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f,0.0f,0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.41;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(150.0f,150.0f,150.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.23;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-4.3,y+0.1);
        }
	glEnd();
	glColor3ub(200.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(-4.3f,0.33f);
	glVertex2f(-4.3f,-0.13f);
	glVertex2f(-4.53f,0.1f);
	glVertex2f(-4.07f,0.1f);
	glEnd();
	glPopMatrix();
}

void car2()              //3803
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3.5f,3.5f,0.0f);
    glTranslatef(0.0, -2.0f, 0.0f);
    glTranslatef(_move1, 0.0f, 0.0f);
    if(state=='n'&& show!='p')
    {
    glColor3ub(255.0f,255.0f,112.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f,0.5);
    glVertex2f(1.6f,-0.3);
    glVertex2f(1.6f,1.3);
    glEnd();
    }
    c2_body();
    c2_tire1();
    c2_tire2();

    glPopMatrix();
}

void car2_1()          //3804
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-2.0f,0.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glScalef(0.9f,-0.9f,0.0f);
    car2();
    glPopMatrix();
}

void car2angle(int value)         //3801001
{
    _angle1-=5.0f;
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(1, car2angle, 0); //Notify GLUT to call update again in 25 milliseconds
}

void car2move(int value)         //3801002
{
    _move1 += 0.2;
    if(_move1 > 70)
    {
        _move1 = -70;
    }
    glutPostRedisplay();
    glutTimerFunc(20, car2move, 0);
}

void car1move(int value)         //3801003
{
    car1_move += 0.01;
    if(car1_move > 3.9)
    {
    car1_move = -1.3;
    }
glutPostRedisplay();
glutTimerFunc(20, car1move, 0);
}

void car1angle(int value)         //3801004
{
    car1_angle -=15.0f;
    glutPostRedisplay();
    glutTimerFunc(1, car1angle, 0);
}

void lasthalf()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,-15.0f,0.0f);
    bridge_1();
    road();
    lake();
    grass();
    roadsign();
    glPopMatrix();
}

void display()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    sun();
    moon();
    cloud_1();
    cloud_2();
    cloud_3();
    cloud_4();
    cloud_5();
    cloud_6();
    cloud_7();
    cloud_8();
    lake();
    Boat_1();
    field_tree2();
    building4();
    building1();
    car_shop();
    mall();
    station();
    field_tree3();
    building2();
    mini_shop_1();
    mini_shop_side();
    mini_shop_2();
    shop();
    road();
    bridge();
    roadsign();
    footpath();
    dock();
    Dusbin();
    car1();
    car2();
    truck();
    rv();
    plane();
    helicopter();
    building3();
    lampost();
    fence();
    park_road();
    park_bench();
    park_tree();
    field_tree();
    field_tree1();
    bush();
    fence_train_top();
    Boat_2();
    traffic();
    trump();
    fence_train_bottom();
    traffic1();
    post_box_park();
    post_box_trump();
    rain();
    rain_cloud();
    rain_cloud_2();
    if(show=='p'){return;}
    glutTimerFunc(0,disback,0);
    glutSwapBuffers();
}

void display_1() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    lasthalf();
    sky();
    sun();
    glacier();
    cloud_1();
    cloud_2();
    cloud_3();
    cloud_4();
    mountain();
    cloud_5();
    cloud_6();
    cloud_7();
    cloud_8();
    ralling3();
    trump_1();
    ralling2();
    lampost_top_1();
    truck_1();
    Boat_11();
    Boat_21();
    ship();
    ship_2();
    rv_1();
    car1_1();
    car2_1();
    plane_1();
    lampost_bottom_1();
    ralling1();
    field_tree4();
    snowfall_1();
    snowfall_2();
    snow_cloud();
    snow_cloud_2();
    snow_shade_tree();
    if(show=='n'){return;}
    glutTimerFunc(0,disback_1,0);
	glutSwapBuffers();
}

void disback(int x)
{
glutDisplayFunc(display);
}

void disback_1(int x)
{
glutDisplayFunc(display_1);
}

void disback_night(int x)
{
state='n';
glutDisplayFunc(display);
}

void disback_day(int x)
{
state='d';
glutDisplayFunc(display);
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
	    if(show=='n')
	    {
	        glutTimerFunc(20, update_wave, 0);
	    }
    }
    if (button == GLUT_RIGHT_BUTTON)
	{
	    lake1='s';
    }
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	    case 't':
            if(show=='n')
            {
	        trump_speed = 1.0f;
            }
	        break;
        case 'b':
            if(show=='n')
            {
            glutTimerFunc(20, update_boat_2, 0);
            }
            break;
        case 'h':
            if(show=='n')
            {
            glutTimerFunc(20, helicopter_angle, 0);
            glutTimerFunc(20, helicopter_movey, 0);
            }
            break;
        case 'd':
            if(show=='n')
            {
            rise='s';
            }
            break;
        case 'n':
            if(show=='n')
            {
            rise='m';
            }
            break;
        case 'r':
            if(show=='n')
            {
            rain_state='y';
            glutTimerFunc(20, rain_update, 0);
            glutTimerFunc(20, rain_cloud_update, 0);
            }
            if(show=='p')
            {
            snow_state='y';
            snow_int=1;
            snow_speed = 2.0f;
            glutTimerFunc(20, snow_cloud_update, 0);
            }
            break;
        case 's':
            if(show=='n')
            {
            rain_state='s';
            glutTimerFunc(20, rain_cloud_stop, 0);
            }
            if(show=='p')
            {
            snow_int=0;
            snow_state='s';
            glutTimerFunc(20, snow_cloud_stop, 0);

            }
            break;
	}
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            //do something here
            if(show=='n')
            {
                rise='s';
            }
            break;
            case GLUT_KEY_DOWN:
                if(show=='n')
                {
                    rise='m';
                }
                break;
            case GLUT_KEY_LEFT:
                show='p';
                boat_2_move_left=0;
                glutTimerFunc(0,disback_1,0);
                break;
            case GLUT_KEY_RIGHT:
                show='n';
                if(snow_state!='y'){snow_cover=0;}
                glutTimerFunc(0,disback,0);
                break;
    }
glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 625);
    glutCreateWindow("Project");
    glutDisplayFunc(display_1);
    glutFullScreen();
    init();
    glutTimerFunc(20, trump_update, 0);//Add a timer
    glutTimerFunc(20, trump_1_update, 0);
    glutTimerFunc(20, update_truck, 0);
    glutTimerFunc(20, update_truck_tire, 0);
    glutTimerFunc(20, update_rv, 0);
    glutTimerFunc(20, update_rv_tire, 0);
    glutTimerFunc(20, update_plane, 0);
    glutTimerFunc(20, update_boat_1, 0);
    glutTimerFunc(20, car1angle, 0);
    glutTimerFunc(20, car1move, 0);
    glutTimerFunc(20, car2move, 0);
    glutTimerFunc(20, car2angle, 0);
    glutTimerFunc(20, update_cloud, 0);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_moon, 0);
    glutTimerFunc(20, update_station_clock, 0);
    glutTimerFunc(20, update_ship_1, 0);
    glutTimerFunc(20, update_ship_2, 0);
    glutTimerFunc(20, update_boat_21, 0);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}


