// Room: /d/chengdu/fengyuting.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
��վ��ͤ�����ͤ������ɵ��죬������һ�֡�ɽ����������¥��
�ĸо����������ǲ���˷��Ľֵ�����������������������ɽ´����
���де�������¶����һ�Ƿ���Զ������������ׯ�ص������������
̨һƬ������
LONG	);

	set("exits", ([
		"south" : __DIR__"gongqiao1",
	]));
	set("objects", ([
	    __DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

