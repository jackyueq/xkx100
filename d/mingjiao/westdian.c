//room: /d/mingjiao/westdian.c
inherit ROOM;

void init();

void create()
{
	set("short","���������");
	set("long", @LONG
�����������ǽӴ������ĵط������ڰ��ż������ӣ�����Χ��
�������ӡ�ǽ�����ż���Ӳ����������׳���Ա߶���һ�������������
ãã����ѩɽ��ѩ�����ࡣ
LONG);
	set("exits",([
		"east"     : __DIR__"qiandian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 1060);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}