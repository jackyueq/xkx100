// Room: /d/huanggong/bukufang.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���ⷿ");
	set("long", @LONG
���пտն�����ǽ�ڱ����ż���ţƤ�����Σ����ϴ�������ֻ��
���������ƺ�װ���������ɳ���������ֻ��һ�����ӣ���ǰ���ſ���
ᡡ�
LONG
	);
	set("exits", ([
		"north"    : __DIR__"ciningmen",
	]));
	set("objects", ([
		__DIR__"obj/table" :1,
	]));
	set("coor/x", -220);
	set("coor/y", 5269);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}