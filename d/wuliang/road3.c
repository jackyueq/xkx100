// Room: /wuliang/road3.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǽ������ڵ�������ͨ������������ͨ����ɽ��С·���
�����ܱ߿���ȥ����������ɽ����ʤ�ˡ�
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"west"  : __DIR__"road5",
		"east"  : __DIR__"zhengting",
	]));
	set("objects", ([
		__DIR__"npc/yu" : 1,
	]));
	set("coor/x", -71010);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}