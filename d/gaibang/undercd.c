// Room: /d/gaibang/undercd.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ƴ�����");
	set("long", @LONG
���ǳɶ���һ��ƫƧ��Ժ���ƴ��¡����ܶ����˸����������ؤ
������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"       : "/d/chengdu/ruin2",
		"northeast" : __DIR__"cdandao2",
	]));
	set("objects",([
//		CLASS_D("gaibang") + "/quan-gq" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
