// Room: /d/yanziwu/path25.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
�������·�ϣ����²��������С�ݣ���Ŀ������͸�̣���������
������Ĵ�����ζ�����룺Ŷ������ǽ��ϡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"west"     : __DIR__"path22",
		"east"     : __DIR__"garden",
	]));
	set("coor/x", 1220);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}