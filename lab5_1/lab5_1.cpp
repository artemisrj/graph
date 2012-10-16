#include <GL/glut.h>
#include <cmath>
#include <vector>
using std::vector;
class Pt2D
{
public:
GLfloat x, y;
Pt2D(){};
Pt2D( GLfloat xx, GLfloat yy )
{
x = xx;
y = yy;
};
};

vector< Pt2D > vector1;
vector< Pt2D > vector2;
int MIN = 0;
int MAX = 600;
Pt2D startP;
Pt2D preP;
Pt2D boxA;
Pt2D boxB;
Pt2D temp1;
Pt2D temp2;
bool buttonFlag = true;
//以下是Cohen-Sutherland 线段裁剪算法的实现
const GLint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8; //区域码

inline GLint round( const GLfloat a ){ return GLint( a + 0.5 );}
inline GLint inside( GLint code ){ return GLint( !code ); }

inline GLint reject( GLint code1, GLint code2 )
{ return GLint( code1 & code2 ); }
inline GLint accept( GLint code1, GLint code2 )
{ return GLint( !( code1 | code2 ) ); } //各种按位运算

GLubyte encode( Pt2D pt ) //获得外部码
{
GLubyte code = 0x00;
if( pt.x < boxA.x )
code = code | winLeftBitCode;
if( pt.x > boxB.x )
code = code | winRightBitCode;
if( pt.y < boxA.y )
code = code | winBottomBitCode;
if( pt.y > boxB.y )
code = code | winTopBitCode;
return code;
}
template< class Type >

void swap( Type* X, Type* Y ) //交换数值的模板函数
{
Type temp;
temp = *X;
*X = *Y;
*Y = temp;
}

void lineClip( Pt2D p1, Pt2D p2 ) //裁剪算法
{
GLubyte code1, code2;
bool done = false, plotLine = false;
GLfloat m;
while( !done )
{
code1 = encode( p1 );
code2 = encode( p2 );
GLint qq = accept( code1, code2 );

if( accept( code1, code2 ) )
{
done = true;
plotLine = true;
}
else if( reject( code1, code2 ) )
done = true;
else
{
if( inside( code1 ) )
{
swap( &p1, &p2 );
swap( &code1, &code2 );
}
if( p2.x != p1.x )
m = ( p2.y - p1.y ) / ( p2.x - p1.x );
if( code1 & winLeftBitCode )
{
p1.y += ( boxA.x - p1.x ) * m;
p1.x = boxA.x;
}
else if( code1 & winRightBitCode )
{
p1.y += ( boxB.x - p1.x ) * m;
p1.x = boxB.x;
}
else if( code1 & winBottomBitCode )
{
if( p2.x != p1.x )
p1.x += ( boxA.y - p1.y ) / m;
p1.y = boxA.y;
}
else if( code1 & winTopBitCode )
{
if( p2.x != p1.x )
p1.x += ( boxB.y - p1.y ) / m;
p1.y = boxB.y;
}
}
}
if( plotLine )
{
vector1.push_back( p1 );
vector2.push_back( p2 ); //裁剪后保存线段

}
}
void drawLines() //绘制所有裁剪过后的线段
{
for ( int i = 0; i < vector2.size(); ++i )
{
glColor3f( 0.0, 0.0, 1.0 );
glBegin( GL_LINES );
glVertex2i( vector1[ i ].x, vector1[ i ].y );
glVertex2i( vector2[ i ].x, vector2[ i ].y );
glEnd();
}
}
void drawLine( GLint x1, GLint y1, GLint x2, GLint y2 )
{
glBegin( GL_LINES );
glVertex2i( x1, y1 );
glVertex2i( x2, y2 );
glEnd();
}
void drawBox()
{
glColor3f( 1.0, 0.0, 0.0 );
glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
glRecti( boxA.x, boxA.y, boxB.x, boxB.y );
}



void drawRectangle( GLint x1, GLint y1, GLint x2, GLint y2 )
{
glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
glRecti( x1, y1, x2, y2 );
}


void display( void )
{
glClear( GL_COLOR_BUFFER_BIT );
glFlush();
}




void clickMouse( int btn, int state, int xn, int yn )
{

if( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
{ //左键按下：记录线段
buttonFlag = true;
startP.x = xn;
startP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
temp1.x = startP.x;
temp1.y = startP.y;
}
else if( btn == GLUT_LEFT_BUTTON && state == GLUT_UP )
{ //左键释放：绘制线段
startP.x = xn;
startP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
temp2.x = startP.x;
temp2.y = startP.y;
lineClip( temp1, temp2 );
glClear( GL_COLOR_BUFFER_BIT );
drawLines();
drawBox();
}
else if( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
{ //右键按下：记录裁剪框
glClear( GL_COLOR_BUFFER_BIT );
vector1.clear();
vector2.clear();
buttonFlag = false;
startP.x = xn;
startP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
boxA.x = startP.x;
boxA.y = startP.y;
}
else if( btn == GLUT_RIGHT_BUTTON && state == GLUT_UP )
{ //右键释放：裁剪框
startP.x = xn;
startP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
if( startP.x < boxA.x )
{
boxB.x = boxA.x;
boxA.x = startP.x;
}
else
boxB.x = startP.x;
if( startP.y < boxA.y )
{
boxB.y = boxA.y;

boxA.y = startP.y;
}
else
boxB.y = startP.y;
drawBox();
}
glFlush();
}
void moveMouse( int xn, int yn ) //鼠标按下移动时动态更新当前线段和裁剪框
{
if( buttonFlag )
{
glColor3f( 1.0, 1.0, 1.0 );
drawLine( startP.x, startP.y, preP.x, preP.y );
drawLines();
drawBox();
preP.x = xn;
preP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
glColor3f( 0.0, 1.0, 0.0 );
drawLine( startP.x, startP.y, preP.x, preP.y );
}
else
{
glColor3f( 1.0, 1.0, 1.0 );
drawRectangle( startP.x, startP.y, preP.x, preP.y );
drawLines();
preP.x = xn;
preP.y = glutGet( GLUT_WINDOW_HEIGHT ) - yn;
glColor3f( 0.0, 1.0, 0.0 );
drawRectangle( startP.x, startP.y, preP.x, preP.y );
}
glFlush();
}




void myinit()
{
glMatrixMode( GL_PROJECTION );
gluOrtho2D( MIN, MAX, MIN, MAX );
glClearColor( 1.0, 1.0, 1.0, 1.0 );

}

int main( int argc, char **argv )
{
glutInit( &argc, argv );
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize( MAX, MAX );
glutCreateWindow( "Line Clip" );
glutDisplayFunc( display );
glutMouseFunc( clickMouse );
glutMotionFunc( moveMouse );
myinit();
glutMainLoop();
return 0;
}
