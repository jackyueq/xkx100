// Room: /d/heimuya/shenggu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM; 
void create()
{
	set("short", "ʥ����");
	set("long",@LONG
������Ǻ�ľ�µ�ʥ�����ڵء�ʥ���á�������������ޣ�ɷ��Ư
����������ʥ�öԺ�ľ�����������룬һ��֮�е��а˾Ÿ��²�����
�С�
LONG );
	set("exits", ([
		"east" : __DIR__"chitang",
	]));
	set("objects", ([
//		CLASS_D("heimuya")+"/renyy" : 1,
		__DIR__"npc/shinu" : 2,
	]));       
//	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}