// /yubifeng/baozang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @long
һ̤��ʯ�ţ�һ�������䣬�����ۻ����ң����������������Ŵ�
�˿ںϲ�£����ԭ�����澹�Ǹ�����Ķ�Ѩ����������˽�ש���飬��
�鱦ʯ������������ֻ�ǽ����鱦������͸���ļ��֮�����뵱�괳
���Ĳ����ѽ����鱦����֮�󣬽�����ˮ���õ�����Ắ��������ڣ�
������Ʋ���ˮ��֮��һ�㡣
long );
	set("exits", ([
		"out" : __DIR__"shimen",
	]));
	set("objects", ([
		JEWELRY_DIR+"maoeryan" : 1,
		JEWELRY_DIR+"manao" : 1,
		JEWELRY_DIR+"biyu" : 1,
		JEWELRY_DIR+"zhenzhu" : 1,
		JEWELRY_DIR+"shanhu" : 1,
		JEWELRY_DIR+"zumulv" : 1,
		JEWELRY_DIR+"feicui" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
