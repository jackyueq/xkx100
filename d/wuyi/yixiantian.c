// Room: /d/wuyi/yunwo.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "һ����");
	set("long", @LONG
һ����ԭ�����ң�λ�ڶ���֮�ϡ����ұ�����һ�ߣ������˿����
�ý������ϱ������£�����ɭȻ���붴�󣬶پ�����ɭɭ������ȫ����
�������£�����񹤣���ʮ��һ�����죬������硣�ഫ�˴�Ϊ����
�Ϲ��������ˣ������������ġ��ұ�������ǧ�Ƶİ�����Ҳ����
�亱������ۡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"path6",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5050);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

