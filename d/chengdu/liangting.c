// Room: /d/chengdu/liangting.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
����һ��ľ�Ƶ���ͤ��ͤǰ����һ��ʯ����ʯ������������д�š�
����ͤ���������֣����������ˡ��οʹ���ڴ˴�פ��Ъ�ţ�ͤ��ֲ��
�����Ļ�ľ��������һЩ������������Ϸ��
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast" : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
		__DIR__"npc/youke" : 1,
	]));
	set("coor/x", -6060);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

