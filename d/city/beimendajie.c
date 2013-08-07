// Room: /yangzhou/beimendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "���Ŵ��");
	set("long", @LONG
���Žֿ�Լ��ʮ�ɣ��м��Ի������������˷������ҡ��ֱ�����ˮ
��ֱ��ͨ��ٺӡ������Ǵ���ţ��ֶ�ͨ�����֡����������ݵı���
�����š����ֶ������������µĳ�����Ժ�����������������ʵĶ���
����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hongqiao",
		"east"  : __DIR__"qionghuajie",
		"south" : __DIR__"shilijie1",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}