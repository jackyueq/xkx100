// Room: /d/chengdu/huanhuaxi2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");
	set("long",@LONG
������Ȼ�Ѿ���������������е����⣬�Ծ���ʮ�����ȵġ���
����һƬܽ������Զɽ��������֮�У�������������ˣ���Զ�����ţ�
һ�ԴԵ����֣���һ��Ϫ������������������ȥ����������佻�Ϫ����
�����Ǳ�����ˡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"huanhuaxi1",
		"northeast" : __DIR__"beijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


