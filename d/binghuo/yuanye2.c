// Room: /binghuo/yuanye2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ԭҰ");
	set("long", @LONG
ƽҰ��һȺ÷��¹���ڵ�ͷ�Բݣ���Ŀ�����������ǻ�ɽ��Щ��
��֮�⣬��ΧһƬƽ�������޿ɲ�֮����
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"yuanye1",
		"north"  : __DIR__"yuanye3",
	]));
	setup();
	replace_program(ROOM);
}

