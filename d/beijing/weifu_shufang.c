#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ���鷿");
	set("long", @LONG
������Τ��ү���鷿�����������������������һ���ľ������������
һ�����߸ߵĻ�ͭ��¯�����ܵ�����϶ѷ����˸����鼮�����������׿�����
���ܾ�û�˶����ˡ�
LONG );

	set("exits", ([
		"south" : __DIR__"weifu_dating",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4140);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
