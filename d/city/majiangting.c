// Room: majiangting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "�齫��");
	set("long", @LONG
�齫�����Ե�ʮ�ְ�����ż���ӷ����ﴫ��ϴ�Ƶ���������Ҷ�ѹ
����ɤ��˵�����ƺ�ÿȦ��Ӯ����ϵ��ʲô�Ƶġ�������������Ů���
����������������Լ��Ծ����͵��ϼ�ȥ�ɡ�
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"majiangroom1",
		"east"  : __DIR__"majiangroom2",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"majiangroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
