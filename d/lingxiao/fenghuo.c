// Room: /d/lingxiao/fenghuo.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG
������ѩɽ˫��֮һ�ķ�����ķ��䡣������Ҳ������������ǵ�
������ĺۼ�������˭���ⷢй��ŭ���Ƶġ�һ���ֳֳ���������һ
�ۣ���ƫ�����ŭɫ���������ӣ�վ�����У��������⣬�����ؽ�ҧ��
�������޺��¡�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/feng" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}

