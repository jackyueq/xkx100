// Room: /d/yanziwu/path13.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����������С·����ɽ��ˮ�̵Ľ��ϣ��������ܿ������ֺ�ɫ����
�������ں���·�ϣ�������·�ߵ����Խ���̵ÿɰ���·�Ͻ�����ź��
������һ�������֦�������ˮ�棬������������㺡�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"xunfeng",
		"south"     : __DIR__"path14",
		"west"      : __DIR__"path12",
	]));
	set("coor/x", 1260);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}