// mubanlu.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "ľ��·");
	set("long", @LONG
����һ����ľ���̳ɵ�С������Ȼ���Ǻܳ�������ȴ���ó��̵�ʮ
��ϸ�ģ���һЩϸ΢�����Ҳע�⵽�ˡ���·��������һЩ�滨������
ʹ��·�����Ŀ������ĸо���
LONG );
	set("exits", ([
		"south" : __DIR__"muwu3",
		"north" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 90);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}