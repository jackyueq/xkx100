// Room: /binghuo/shulin2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������滨��ܣ�������Ҷ����ɽ��Ұ�����⼫��֮����
��Ȼ�д���ľ�������ǰݻ�ɽ֮���ˡ�ż������һЩ�в�����Ŀ�Ĵ�
��С�ޣ�Ҳ�����ˡ�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"south"     : __DIR__"shulin1",
		"northeast" : __DIR__"shulin3",
	]));
	set("objects", ([
		"/d/lingjiu/npc/lu": 1,
	]));
	setup();
	replace_program(ROOM);
}

