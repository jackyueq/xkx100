// Room: /d/xiangyang/jiedao.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����������������Ǯ�˵ľ�ס�����ֵ�������һЩ������
סլ����Ȼ��������ս�ң������������Ǯ��û���ߣ�Ϊ����
�����ǳ�Ǯ������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"minju1",
		"west"  : __DIR__"minju2",
		"north" : __DIR__"eastjie2",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 2,
	]));
	set("coor/x", -480);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

