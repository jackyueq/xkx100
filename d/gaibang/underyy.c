// Room: /d/gaibang/underyy.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����ܵ�");
	set("long", @LONG
������������ؤ���ܶ��Ժ�ڵĹž��µĶ�����ܶ����˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"   : "/d/yueyang/gaibangyuan",
		"north" : __DIR__"yyandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2250);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
