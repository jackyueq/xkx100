// Room: /d/yanziwu/qingfeng.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���ƺ");
	set("long", @LONG
������ź��С��ǰ�Ĳ�ƺ����ƺ������ɽ���У���ͬ�������ң���
��Сɽȱ�ڹ�ȥ����ͨȥ����ի��С·����������ˮ��С·ת�����ɽ
��ȥ������ź��С���ˡ�
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"northwest"  : __DIR__"path18",
		"southup"    : __DIR__"path19",
	]));
	set("objects", ([
	]));
	set("coor/x", 1200);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}