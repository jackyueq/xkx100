// Room: /d/nanshaolin/kchang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ճ�");
	set("long", @LONG
���Ƿ��ú����һƬ�ճ������������µ���󲿷֡���Ϊ����ش�
ƫƧ�����������صأ�����ƽ��������ɮ�������������ǧ����
���ǰ��µ�����ǵزص
LONG );
	set("exits", ([
		"west"  : __DIR__"dzdian",
		"east"  : __DIR__"bydian",
		"north" : __DIR__"qfdian",
		"south" : __DIR__"fatang",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

