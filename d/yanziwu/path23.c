// Room: /d/yanziwu/path23.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
�������·��������������ɽ�塣���²��������С�ݣ���Ŀ����
��͸�̣���������������Ĵ�����ζ�����룺Ŷ������ǽ��ϡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"path24",
		"southdown" : __DIR__"path22",
	]));
	set("coor/x", 1210);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}