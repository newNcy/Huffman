#ifndef _CANVAS_H
#define _CANVAS_H
#include <cstdio>
#include <unistd.h>
#include <stdexcept>
#include <vector>
#include <sstream>
#ifdef _WIN32
#define WINDOWS
#include <windows.h>
#endif

#ifdef _WIN64
#ifndef WINDOWS
#define WINDOWS
#endif
#include <windows.h>
#endif
using std::stringstream;
using std::vector;
using pixel=int32_t;
const  int zh_w=3;
#ifdef MSYS
#undef WINDOWS
#endif

class Canvas
{
	private:
	void drawBuff(int x,int y, const char *text)
	{
			checkLocat(x,y);
			pixel * s, *p;
			s = p = &space[x+y*W];
			int i = 0;
			while(text[i] != '\0') {
				*p &= 0xff<<(sizeof(pixel)*8-8);

				if (text[i] >6 && text[i] <14) {
					*p |= ' ';
					i++;
					continue;
				}
				if (text[i] < 0) {

                    //printf("%c%c\n",text[i],text[i+1]);
                    *p |=  -text[i++];
					*p |=  (((-text[i++])<<8)&0xff00);
					*p &= 0xff00ffff;
				} else if (text[i] > 0x80) {
					*p |= (pixel)text[i++];
					*p |= (pixel)text[i++]<<8;
					*p |= (pixel)text[i++]<<16;
				}else {
                    *p |= (pixel)text[i++];
                    ;
				}


				p++;
				if(p-space == W*H) break;
				}
	}
	protected:
	/* 画板宽度 */
	int W;
	/* 画板高度 */
	int H;
	/* 画板空间 */
	pixel *space;

	/* 自身坐标  做子控件时使用 */
	int _x;
	int _y;

	/* 子控件列表 */
	vector<Canvas *> childs;

	/* 颜色 */
	char color;
#ifdef WINDOWS
	HANDLE outhd = NULL;
#endif

	public:
#ifndef WINDOWS
	static const char BLACK =0;
	static const  char RED = 1;
	static const char GREEN =2;
	static const char  BLUE =4;

	static const char  CYAN =6;
	static const char  WHITE =7;
#else
    static const char BLACK =0;
	static const  char BLUE = 1;
	static const char GREEN = 2;
	static const char RED =4;
	static const char  WHITE = RED|GREEN|BLUE;


#endif

    static const char YELLOW = RED | GREEN;
    static const char  PURPLE = RED | BLUE;
    static const char  CYAN = BLUE | GREEN;
	/* 构造 */
	Canvas(int _W,int _H) :W(_W),H(_H)
	{
		//printf("[%d:",W);
		//printf("%d]\n",H);
		_x =0;
		_y = 0;
		space = new pixel[W*H];
		clear(' ');
		background(BLACK);
		foreground(WHITE);
	}
	/* 背景颜色 */
	char & background(char b = -1)
	{
		for (int i=0;i<H;i++) {
			for (int j=0;j<W;j++) {
					pixel *p = &space[W*i+j];
					*p = (*p <<4>>4) | (pixel)b<<(sizeof(pixel)*8-4);
				}
		}
		color = (color&0x0f) | (b<<4);
	}

		/* 前景颜色 */
	char & foreground(char b = -1)
	{
		//printf("前景色:%d\n",b);
		for (int i=0;i<H;i++) {
			for (int j=0;j<W;j++) {
				pixel *p = &space[i*W+j];
				char cl = *p>>(sizeof(pixel)*8-8);
				cl = (cl &0xf0) | (b&0xf);

				*p = (*p<<8>>8) | (pixel)cl<<(sizeof(pixel)*8-8);
				}
		}
		color = (color&0xf0) | (b&0x0f);

	}

	int & x( int _x_ = -1)
	{
		return _x_ == -1?_x:_x=_x_;
	}
	int & y(int _y_ = -1)
	{
		if (_y_ != -1) {
			return _y = _y_;
		}else {
			return _y;
		}
	}
	/* 宽 */
	int width ()
	{
		return W;
	}
	/* 高  */
	int height()
	{
		return H;
	}
	/* 获取某点  */
	pixel &valueAt(int x, int y)
	{
		checkLocat(x,y);
		return space[x + y*W];
	}
		/* 用c填充画板 */
	void clear(char c = ' ')
	{
		for (int i=0;i<H;i++) {
			for (int j=0;j<W;j++) {
					pixel *p = &space[W*i+j];
					*p = color <<(sizeof(pixel)*8-8)|c;
				}
		}

	}
	void checkLocat(int x,int y)
	{
		if (x > W -1  || y > H -1) {
			//throw std::runtime_error("out of range");
		}
	}
	/* 绘制字符 */
	void drawChar(int x,int y, char c)
	{
		drawBuff(x,y,&c);
	}

		/* 绘制数字 */
	template <typename T>
	void draw(int x,int y, const T & t)
	{
			stringstream ss;
			ss<<t;
			drawBuff(x,y,ss.str().c_str());
	}

	/* 绘制另一个canvas */
	void drawCanvas(int x, int y,Canvas &cv)
	{
		for (int i = 0; i< cv.height(); i++) {
			if (y + i > H-1) break;
			for (int j = 0; j < cv.width();j++) {
				if (x + j > W -1) break;
				valueAt(x+j,y +i) = cv.valueAt(j,i);

			}
		}
	}
	/* 颜色开始 */
	void colorStart(char cl)
	{
			//printf("%02x",cl);
			char bg = (cl&0xf0)>>4;
			char fg = (cl&0x0f);
#ifndef WINDOWS
			printf("\e[%d;%dm",40+bg,30+fg);
#else
			outhd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(outhd,bg<<4 | fg  );
#endif
	}
	/* 颜色结束 */
	void colorEnd()
	{
#ifndef WINDOWS
		printf("\e[0m");
#else
        SetConsoleTextAttribute(outhd,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
	}
	/* 空格 */
	void sp()
	{
		putchar(' ');
	}
	/* 刷新 */
	void fresh()
	{
	    _fresh();
	    //_beginthread((void*)_fresh,0,NULL);
	}
	void _fresh()
	{
	   #ifdef WINDOWS
	    if (outhd == NULL) {
            outhd = GetStdHandle(STD_OUTPUT_HANDLE);
	    }
	    SetConsoleCursorPosition(outhd,{0,0});
        CONSOLE_CURSOR_INFO info = {1,0};
        SetConsoleCursorInfo(outhd,&info);

	    #else
        printf("\e[2J\e[0;0H");
	    #endif

		/* 绘制控件 */
		for (int i = 0; i< childs.size(); i++) {
			Canvas * c = childs[i];
			//printf("第%d个控件[%d:%d]\n",i+1,c->x(),c->y());
			drawCanvas(c->x(),c->y(),*c);
		}
		int w = 0;
		for (int i=0;i<H;i++) {
			for (int j=0;j<W;j++) {
				pixel *p = &space[W*i+j];
				//printf("%lld",*p>>48);
				colorStart(*p>>(sizeof(pixel)*8-8));

				if ((space[W*i+j]&0xffff) == 0)
					sp();
				else {
                        char c1 = *p &0xff;
                        char c2 = (*p & 0xff00)>>8;
                        char c3 = (*p & 0xff0000)>>16;
                   //printf("%x:%x",c3,c2);
                    if (c3 ==0&& c2 != 0) {
                        putchar(-c1);
                        putchar(-c2);

                    }
                    else if((*p&0xff )> 0x80) {
						putchar(*p&0xff);
						putchar(*p>>8&0xff);
						putchar(*p>>16&0xff);
					}else {
						putchar(*p&0xff);
						sp();
					}

				}

					colorEnd();

				}
				putchar('\n');
		}

	}

	Canvas & add(Canvas *c)
	{
		childs.push_back(c);
		//return *this;
	}
	/* 析构函数 */
	~Canvas()
	{
		delete [] space;
	}
};

#endif
