// Room: /d/yanziwu/path14.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����������С·����ɽ��ˮ�̵Ľ��ϣ��������ܿ������ֺ�ɫ����
�������ں���·�ϣ�������·�ߵ����Խ���̵ÿɰ���·��������ź��
������һ�������֦�������ˮ�棬������������㺡�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"path13",
		"southwest" : __DIR__"path15",
	]));
	set("coor/x", 1260);
	set("coor/y", -1230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}