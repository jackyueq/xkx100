#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ׯ������");
	set("long", @LONG
����һ�����á����Ϲ����߰˸���λ������һ�������Ϲ�����һ��
���ˡ�һ�����紵��������ͻȻ���ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"zhuang5",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 110);
	set("coor/y", 4720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
