// Room: /d/chengdu/biaoju.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
��ǰ���������ʯʨ�ӣ��ļ俪�Ĵ���ţ������Ǵ������߸߹ҡ�
��ʱ�м�����ʦ�����������ſ��Ǽ��������Ż�����ʦ����������ȥ��
����࣬�ֵ��º���Щ��������ӣ����������ǿ���ң����顺������
�֡��ĸ����֡��������Զ�������������ھֳɶ��ֺ��ˡ�
LONG	);
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
	set("coor/x", -8060);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

