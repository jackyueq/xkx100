// Room: /binghuo/shulin1.c
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
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"haitan",
		"north"  : __DIR__"shulin2",
	]));
	setup();
	replace_program(ROOM);
}

