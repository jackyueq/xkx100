// Room: /d/wuyi/xiangshengyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
λ������Ϫ�ϵ������ң������³Ǹߡ����пչȴ����ĸ�Ӧ������
�����ҡ������ּ���������˹�������ڴˣ�Ϊ����ɽ�����Ħ��ʯ�̡�
��Ϫб���棬���������ˡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"6qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

