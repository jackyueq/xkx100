#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����
LONG);   
	set("outdoors", "shenlong");
	set("no_clean_up", 0);
	set("coor/x", 2000);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM) ;
}