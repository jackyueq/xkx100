// Room: /d/huijiang/xiagu.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short","Ͽ��");
	set("long",@LONG
������һ��Ͽ�ȣ�����ʯ�ڶ�Ȼ�����������õ����ɣ�̧ͷ���죬
ֻ����ɫ��������������Ǳ�ں�������һ�㡣Ͽ����ʯȫϵ��ڣ��ڹ�
��������·������ȥ���쳣���ۡ�
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"southeast" : __DIR__"caoyuan6",
		"north"     : __DIR__"damen",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/yang-chengxie" : 1,
	]));
	set("coor/x", -50060);
	set("coor/y", 9130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
