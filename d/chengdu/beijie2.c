// Room: /d/chengdu/beijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������ʯ����ϣ��������˺ܶ࣬����������������
���ĺܣ����ǲ�ʱ���������Ĵ����е��໰��������ӵġ��������˰�
�塱���������ǲ���һ����������Ŷ��ֻ�ǿ�ͷ�����Ŷ��ѣ�������һ
�Ҷĳ����������������ϵش�����Ķ����������һ���鱦�ꡣ
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"zhubaodian",		
		"north" : __DIR__"beijie1",
		"south" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
