// Room: /d/chengdu/shuchang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�鳡");
	set("long", @LONG
������ȫ���������鳡��ÿ����������������ﲻ��������������
Ҫ֪������˵ɶ���ȿ�������ǽ�ϵĺ�����������Ҫ��Щ��ɽ��������
����ȡ�Ҳ�в�����������Կ�������ȤҲ����һ����
LONG	);
	set("exits", ([
		"east" : __DIR__"nanjie2",
		"west" : __DIR__"shuoshuyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

