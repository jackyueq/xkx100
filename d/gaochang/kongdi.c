// Room: /d/gaochang/kongdi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
ͻȻ֮�䣬��ǰ��Ȼ���ʣ�����һ��Ƭ�յأ��յؾ�ͷ����������
���ţ�Ƕ�ڴ�ɽ���С�
LONG
	);

	set("outdoors", "gaochang");
	set("exits", ([
		"north" : __DIR__"shulin14",
		"east" : __DIR__"shijie1",
	]));
	set("objects", ([
		__DIR__"npc/supu" : 1,
		__DIR__"npc/aman" : 1,
	]));
	set("coor/x", -37000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}