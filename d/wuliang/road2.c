// Room: /wuliang/road2.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǽ������ڵ�������ͨ�����������Ǹ��ܴ�Ļ�԰����
���ܱ߿���ȥ����������ɽ����ʤ�ˡ�
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"east"  : __DIR__"huayuan",
		"west"  : __DIR__"zhengting",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
	]));
	set("coor/x", -70990);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}