//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳ�����һ���ϱ�����Ĵ�֡��ƺ��в�������������ȥ��
�ҡ������ǳ��ţ���������Ĺ���ĵ��̣�������һ�Ҵ����ꡣ
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/guofan" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xijie2",
		"west"  : __DIR__"mubeipu",
		"north" : __DIR__"beimen",
		"east"  : __DIR__"datie",
	]));

	set("coor/x", -1500);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}