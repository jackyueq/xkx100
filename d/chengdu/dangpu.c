// Room: /d/chengdu/dangpu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ������ (paizi)����̨�����ŵ����ϰ�������һ˫������
�۾��������´������㡣
LONG	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "��ƽ����\n",
	]));
	set("exits", ([
		"north" : __DIR__"xijie",
	]));
	set("objects" , ([
		__DIR__"npc/yanliu" : 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

