// Room: /d/yanziwu/path19.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
С·�������ӷ��µ�ɽ��������ʱ������ˮ���䣬�ѵ��ϵ�·ʯȾ
�ɵ�������ɫ��ɽ�����������де��ɰ��֣�̧ͷ������ʱ�з���Խ��
������������ɽ·��������һ�鲻��Ĳ�ƺ��
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"qingfeng",
		"southdown" : __DIR__"path20",
		"westup"    : __DIR__"qiuyu",
	]));
	set("coor/x", 1200);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}