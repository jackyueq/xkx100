// /d/yixing/clzoulang2.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������Щ�����治�ϴ���������֮������ʱ��������
ŭ��ͼ�С������������̾Ƶ���ζ�������Ե����ǰ��࣬������һЩ
����Ĳи�ʣ�ˡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"clhuayuan",
		"west"  : __DIR__"clxiaowu",
		"south" : __DIR__"clzoulang1",
		"north" : __DIR__"clxiaoting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}

