#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ������
�㶼û�С�����ֻ�к��˵��Ĵ�����
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 5000);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM) ;
}