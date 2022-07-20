#include<windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include<GL/glut.h>
static double x=0.0,x1=0.0,y1=0.1,z1=0.0,a1=0,y2=0,z2=0;
static double move=-60;
static bool seperate=false;
GLint flag=0;

void *currentfont;


void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void OpeningScreen()
{
    glClearColor(0.3,0.1,0.3,0);
    glClear(GL_COLOR_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1,1,1);
	drawstring(350.0,435.0,0,"*  *   VILLAGE SIMULATOR  *  *");

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.5,1.0,0.5);
	drawstring(420.0,370.0,0,"SUBMITTED   BY");

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,340.0,0," Name: Roshni Anand            USN:1BY19CS125");

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,320.0,1.0," Name: Rohith Reddy D         USN:1BY19CS124");

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,300.0,1.0," Name: Rohan Joy                 USN:1BY19CS122");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.5,1.0,0.5);
	drawstring(360.0,225.0,0,"UNDER THE GUIDANCE OF");

	glColor3f(1.0,1.0,0.5);
	drawstring(262.0,180.0,1.0," Prof. CHETHANA C");

		setFont(GLUT_BITMAP_HELVETICA_12);


	glColor3f(0.0,1.0,1.0);
	drawstring(275.0,165.0,1.0,"  Asst. Prof., Dept of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(260.0,150.0,1.0,"  BMS INSTITUTE OF TECHNOLOGY");


	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,0.5);
	drawstring(460.0,180.0,1.0,"          Prof. MUNESHWARA M S");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(520.0,165.0,1.0,"          Asst. Prof., Dept of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(500.0,150.0,1.0,"          BMS INSTITUTE OF TECHNOLOGY");


	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.5,1.0,0.5);
	drawstring(350.0,80.0,0,"~ PRESS  -ENTER-  TO CONTINUE ~");


	glFlush();
}

void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
va_list args;
char buffer[200], *p;
va_start(args, format);
vsprintf(buffer, format, args);
va_end(args);
glPushMatrix();
glTranslatef(-2.5, y, 0);
glScaled(0.003, 0.005, 0.005);
for (p = buffer; *p; p++)
glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
glPopMatrix();
}

void satellite(){
glPushMatrix();
//Core
glPushMatrix();
glColor3f(1,1,0);
glTranslatef(0,2,0);
glScaled(0.3,1,0.3);
glRotatef(90,1,0,0);
if(x<=6)
glutSolidTorus(0.5,1,30,30);
else
glutSolidCube(1);
glPopMatrix();
// Solar Panel
glPushMatrix();
glColor3f(0.2,0.2,0.2);
glTranslatef(1,2,0);
if(x>=6){
glScaled(4,1.5,0.1);
}
glScaled(0,0,0);
glRotatef(-20,1,0,0);
glutSolidCube(0.5);
glPopMatrix();
glPushMatrix();
glColor3f(0.2,0.2,0.2);
glTranslatef(-1,2,0);
if(x>=6){
glScaled(4,1.5,0.1);
}
else
glScaled(0,0,0);
glRotatef(-20,1,0,0);
glutSolidCube(0.5);
glPopMatrix();
glPopMatrix();
}

void rocket(){
// Main top cone
glPushMatrix();
if(x>=5.5){
glTranslatef(z2,-z2,z2);
glRotatef(a1,0,1,1);
}
glPushMatrix();
glTranslatef(0,2.5,0);
glColor3f(0,0,1);
glScaled(2.2 ,1.5,2.2);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPopMatrix();
// Satelitte container
glPushMatrix();
if(x>=6.8){
glTranslatef(2,0,0);
glRotatef(x*40,0,1,0);
}
satellite();
glPopMatrix();
glPushMatrix();
if(x>=5){
glTranslatef(0,y2,y2);
glRotatef(a1,0,1,1);
}
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(0,0.0,0);
glScaled(0.3,4.3,0.3);
glRotatef(90,1,0,0);
glutSolidTorus(0.5,1,30,30);
glPopMatrix();
glPushMatrix();
glTranslatef(0,-2.2,0);
glColor3f(0,0,1);
glScaled(3,1.5,3);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPopMatrix();
// RightSide rocket
glPushMatrix();
glTranslatef(x1,-y1,z1);
glRotatef(a1,0,1,1);
glPushMatrix();
glTranslatef(0.7,1,0);
glColor3f(0,0,1);
glScaled(1.5 ,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPushMatrix();
glTranslatef(0.7,-0.2,0);
glColor3f(0,1,1);
glScaled(0.2,6.5,0.2);
glRotatef(90,1,0,0);
glutSolidTorus(0.2,1,30,30);
glPopMatrix();
glPushMatrix();
glTranslatef(0.7,-2.0,0);
glColor3f(0,0,1);
glScaled(1.5,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPopMatrix();
// LeftSide rocket
glPushMatrix();
glTranslatef(-x1,-y1,-z1);
glRotatef(-a1,0,1,1);
glPushMatrix();
glTranslatef(-0.7,1,0);
glColor3f(0,0,1);
glScaled(1.5 ,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPushMatrix();
glTranslatef(-0.7,-0.2,0);
glColor3f(0,1,1);
glScaled(0.2,6.5,0.2);
glRotatef(90,1,0,0);
glutSolidTorus(0.2,1,30,30);
glPopMatrix();
glPushMatrix();
glTranslatef(-0.7,-2.0,0);
glColor3f(0,0,1);
glScaled(1.5,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
//booster
/*
glPushMatrix();
glTranslatef(2,0,0);
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex3f(0,0,0);
glVertex3f(1,0,0);
glVertex3f(0.8,-1,0);
glVertex3f(0,0,0);
glEnd();
glPopMatrix();
*/
glPopMatrix();
}

void stars(){
for(float s1=5;s1<=100; s1+=0.4){
for(float s2=-6;s2<=6;s2+=0.5){
glPushMatrix();
glBegin(GL_POINTS);
glVertex3f(s2,s1,0);
glEnd();
glPopMatrix();
}
}
for(float s3=5.2;s3<=100; s3+=0.3){
for(float s4=-6.2;s4<=6;s4+=0.3){
glPushMatrix();
glBegin(GL_POINTS);
glVertex3f(s4,s3,0);
glEnd();
glPopMatrix();
}
}
}

// Draw rocket
void rocket(double ang)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
//glRotatef(ang,0.0f,1.0f,0.0f);
glPushMatrix();
if(ang<=2){
glRotatef(ang*30,1,0,0);
glTranslatef(0,-2+ang,0);
}
else{
glRotatef(60,1,0,0);
glTranslatef(0,0,0);
}
glScaled(0.5,0.5,0.5);
rocket();
glPopMatrix();
//Earth
glPushMatrix();
glColor3f(0,0,1);
if(x>=6.5){
glTranslatef(0,-18,-95);
glRotatef(10*x,0,1,0);
}else{
glTranslatef(0,-10-x,-10-15*x);
}
glutSolidSphere(10,100,100);
glPopMatrix();
// Create Stars
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(0,-ang,0);
stars();
glPopMatrix();
glFlush();
glutSwapBuffers();
}

void p()
{
x+=0.01;
if(x>=3){
x1+=0.1;
y1+=0.1;
z1+=0.01;
a1+=3;
}
if(x>5){
y2-=0.1;
}
if(x>5.5){
z2+=0.1;
}
rocket(x);
}

void doInit()
{
/* Background and foreground color */
glClearColor(0.0,0.0,0.0,0);
glViewport(0,0,640,480);
/* Select the projection matrix and reset it then
setup our view perspective */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
/* Select the modelview matrix, which we alter with rotatef() */
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glClearDepth(2.0f);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
stroke_output(-2.0, 1.7, "p/P-->Launch the` Rocket");
GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
GLfloat light_position3[]={0.0f,5.0f,0.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glEnable(GL_COLOR_MATERIAL);
glFlush();
glutSwapBuffers();
}

void DisplayOpening()
{
    if(flag==0)
        OpeningScreen();
    if(flag==1)
        display();
}

void menu(int id)
{
switch(id)
{
case 2:glutIdleFunc(p);
break;
case 5:exit(0);
break;
}
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{
if(key=='p')
{
glutIdleFunc(p);
}
if(key=='q'||key=='Q')
{
exit(0);
}
if(key==13)
{
    flag=1;
}
}

int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1000,480);
glutInitWindowPosition(0,0);
glutCreateWindow("rocket");
glutDisplayFunc(DisplayOpening);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glutKeyboardFunc(mykey);
glutCreateMenu(menu);
glutAddMenuEntry("Launch 'p'",1);
glutAddMenuEntry("Quit 'q'",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
doInit();
glutMainLoop();
return 0;
}
