// Room: /d/kunlun/xianjing.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "�����ɾ�");
	set("long", @LONG
�ſ��Ų���ǰ������ֱ�����������ţ�����һ���߷���·��������
��������������ܸ�ɽ���ƣ��ƺ�ب��������δ���˼�����������ѩ��
���ƣ��վ��������޷���Ԯ���롣
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"north" : __DIR__"cuigu",
	]));
	set("objects", ([
		__DIR__"npc/monkey" : 2,
		__DIR__"npc/bigmonkey" : random(2),
	]));
	setup();
	set("coor/x", -100000);
	set("coor/y", 20030);
	set("coor/z", 40);
	replace_program(ROOM);
}
