// Room: /d/yanping/kedian.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ɽҰ�͵�");
	set("long", @LONG
ɽҰ�͵�ʮ�ּ�ª��һ��С����̨������һƬ���������ڵ��ϣ���
���൱æ�ҡ���̨�����Ÿ�����(paizi)��
LONG );
	set("exits", ([
		"east" : __DIR__"erbapu",
	]));
	set("item_desc", ([
		"paizi" : "������ֻ��Ӧ�Ժȣ������ޡ�\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", 1490);
	set("coor/y", -4000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
