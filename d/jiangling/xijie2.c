//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳ�����һ���ϱ�����Ĵ�֡��ƺ��в�������������ȥ��
�ҡ����������ײĵĵ��̣�������һ��Ƨ����С�
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/caifan" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"xiang2",
		"south" : __DIR__"xijie3",
		"west"  : __DIR__"guancaipu",
		"north" : __DIR__"xijie1",
	]));

	set("coor/x", -1500);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}