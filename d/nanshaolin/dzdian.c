// Room: /d/nanshaolin/dzdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�زص�");
	set("long", @LONG
���ǵزص����ز����������ز����������䣬������Ȼ�в���
������䣬������ǰ������ü��ɷ�����ֶ�����������һ��֮�£��پ�
�ľ���ս���ֲ̿��ѡ�
LONG );
	set("exits", ([
		"east" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

