// Room: /d/wuyi/gengyitai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����Ϫ�ϵĸ���̨��ͻأ���㡢ʯ�������������񷤣�ԶԶ���ܿ�
���������ݡ��ഫκ����ڴλ��£���������������ġ��������ʯ��
�����С�����̨���͡���ʴ����𡱵�ʯ�̡�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"jiutanfeng",
		"northeast" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

