// Room: /d/taohua/woshi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��䲼�õú�������������һ�������ҩʦ�ľ������������з���
һ�����٣���ʽ���ǹ��ϡ����ߵ���������ܲ�����װ�ż���һ����
Ⱦ�����ϴ���¶����֦�һ������������˼�����ζ������С���ϰ���
һ����֣��ڰ׷�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"neishi2",
	]));
	set("coor/x", 9010);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}