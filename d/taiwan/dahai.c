// /d/taiwan/dahai.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", "��");
	set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ������
�㶼û�С�����ֻ�к��˵��Ĵ�����
LONG);   
	set("outdoors", "taiwan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM) ;
}
