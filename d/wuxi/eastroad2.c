// Room: /d/wuxi/eastroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·��ͨ�������������һ����֣�������û��ʲô�ӵ�������
·��ʮ�ֿ���ƽ�������������ſڣ�������˲��ࡣ���ߴ���һ������
�ʵĶ��������ϱ��Ǵ����̣�����������������Զ����������
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shuyuangate",
		"south" : __DIR__"datiepu",
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/polan" : 1,
	]));
	set("coor/x", 390);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}