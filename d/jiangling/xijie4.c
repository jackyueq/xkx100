//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳ�����һ���ϱ�����Ĵ�֡��ƺ��в�������������ȥ��
�ҡ�������һ������Ρ��ĵ��ۣ���������Ҵ�Ժ���ϱ��Ǹߴ�ĳ��š�
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/xiangnong" : random(3),
		__DIR__"npc/xiaofan" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"damen",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"kaiyuanguan",
		"north" : __DIR__"xijie3",
	]));
	set("coor/x", -1500);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
