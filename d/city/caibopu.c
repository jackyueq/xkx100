// Room: /yangzhou/caibopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�˼Ҳʲ���");
	set("long",@LONG
����ʲ����У�ֻ������ӵ������������С�����к����ˣ�����Ӧ
�Ӳ�Ͼ���������߸��м������ܣ���������Ų�ƥ��С�������������
��ѡ�����ϵĵ�Ա�ڸ����ǽ��ܡ�����������������һƥ������������
�Ȼ��ţ�ߴߴ�������໥˵�ţ�������������ƤЦ���ĵ�Ա��
LONG );
	set("exits", ([
		"south" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/gubancheng" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}