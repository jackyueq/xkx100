// Room: /d/tiezhang/dong3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
һ���������ɽ�����ڳ�����һ���������ס������ʯ����������
̦޺����������ʪ�ֻ�����ʯ���ƺ����˹�����ģ������ܵ�ʯ������
�ܿ�������ĺۼ�����վ�����һ�ɿ־���Ȼ�������ƺ�������ʱ��
�ᱻ��Ƭ�ڰ����ɵ���
LONG
	);
	set("exits", ([
		"out"   : __DIR__"dong2",
		"enter" : __DIR__"trdx",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1800);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
