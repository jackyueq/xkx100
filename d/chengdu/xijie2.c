// Room: /d/chengdu/xijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������֣��������������ַǷ��������������αȵĵ��̣���
����ɫ�Ļ�������Ʈ��ɷ�����ޡ������и�ľ���̣���˵�����ľ����
�պ����˵á��������Ǹ��ӻ��̡�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"west"  : __DIR__"xijie1",
		"south" : __DIR__"mujiangpu",
		"north" : __DIR__"zahuopu",
	]));
	set("objects", ([
		__DIR__"npc/flowergirl" : 1,
		__DIR__"npc/chike" : 1,
	]));

	set("coor/x", -8060);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

