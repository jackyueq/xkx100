// Room: /d/chengdu/nanjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����ǳɶ����ϴ�֣�˫�˺ϱ�����ͩ�ڽֱ�ʮ��һ�꣬��ʯ�̾�
��·���ɨ�øɸɾ�������Ϊ����󶼽������ǹٸ����ˣ�����������
��֮·�����Բ��������˵����¶����ġ������ǳɶ����ã������Ǹ�ȫ
��������˵�鳡�����������������µ������ˡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"tidujie",
		"west"      : __DIR__"shuchang",
		"south"     : __DIR__"nanjie",
		"north"     : __DIR__"nanjie1",
		"northwest" : __DIR__"qingyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

