// Room: /d/nanshaolin/qfdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ǧ���");
	set("long", @LONG
����ǧ���������������ȣ��߱����硣���﹩���������
�𣬼��а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�ʮ��٤����
�Լ����������������ĵȡ�ֱ�������ۻ����ҡ��������е�Сľ��ֱ
ͨ��ɽ��
LONG );
	set("exits", ([
		"south" : __DIR__"kchang",
		"north" : __DIR__"shanroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

