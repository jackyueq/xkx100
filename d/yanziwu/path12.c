// Room: /d/yanziwu/path12.c
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
		"east"   : __DIR__"path13",
		"west"   : __DIR__"path11",
	]));
	set("coor/x", 1250);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}