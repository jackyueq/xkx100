// Room: /d/huangshan/jiyu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "���㱳");
	set("long", @LONG
����̽���ɣ��������㱳�ˣ�һ�γ�Լʮ���ɣ�������ɣ�������
�գ�������Ԩ��ʯ���м���ǰ����ν���춼����·��ͨ��ָ�ľ�����һ
�Σ�ֱ��������һ·�����ſ������ɵ��춼���������㱳���پ���ǰ
��ġ����˰Ѷ��š��������춼���ˡ�
LONG
	);
	set("exits", ([ 
		"eastup" : __DIR__"tiandu",
		"west"   : __DIR__"guanyin",
		"north"  : __DIR__"erxian",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
