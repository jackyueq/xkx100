// Room: /binghuo/caodi1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
һƬƽ���Ĳݵ�һֱ�ذ����죬�����Щ����ʯ¶�����棬ͦ��
��ͷ�����ܺ���ǧ���������ĳ�ˢ��һЩ�в�����Ŀ�Ĵ���С���ڲ�
���г�û��ʮ�����ڵ����ҡ�������ȥ��ԶԶ���Կ����߸ߵĻ�ɽ��
���������»�
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : __DIR__"caodi1",
		"northwest"  : __DIR__"yuanye1",
	]));
	setup();
	replace_program(ROOM);
}

