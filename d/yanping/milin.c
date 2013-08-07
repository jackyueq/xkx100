// Room: /d/yanping/milin.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��Ƨ�������йٵ��ϣ���������ɭɭ����β���֡�ֻ����
��ǰ�󣬵�����������ǵص���������ʮ�ɸߵĴ���������һ�飬��ʵ
��������һ���������������գ��������ڵ�˿��Ҳ�ޡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"guandao3",
		"southeast" : __DIR__"guandao2",
	]));
	set("objects", ([
		__DIR__"npc/jianjingzei" : random(2)+1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1600);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	if (userp(this_player()))
	switch (random(3))
	{
		case 1:
			set("exits", ([
				"northwest" : __DIR__"guandao3",
				"southeast" : __FILE__,
			]));
			break;
		case 2:
			set("exits", ([
				"northwest" : __FILE__,
				"southeast" : __DIR__"guandao2",
			]));
			break;
		default:
			set("exits", ([
				"northwest" : __FILE__,
				"southeast" : __FILE__,
			]));
			break;
	}
	return;
}
