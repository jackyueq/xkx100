// Room: /binghuo/shulin4.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ѽ��������⵺��Բ���㣬������������֪��ͷ���߳���ʮ
���ֻ��һƬŨ�ܵĴ��֣��������죬��ɭɭ��������ա�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest" : __DIR__"yuanye1",
	]));
	set("objects", ([
		__DIR__"npc/bear": 1,
	]));
	setup();
	replace_program(ROOM);
}

