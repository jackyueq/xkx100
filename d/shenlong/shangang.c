// ɽ�� /d/shenlong/shangang
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ�ڣ�Ұ�ݴ�������ʯ�ɶѣ��Եúܻ�����ʯ��������
��С���������������ʯ��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"westdown"  : __DIR__"tiandi4",
		"northdown" : __DIR__"shulin1",
		"southwest" : __DIR__"shanqiu",
	]));
	set("objects", ([
		__DIR__"npc/mangshe" : 1,
	]));

	setup();
	replace_program(ROOM);
}

