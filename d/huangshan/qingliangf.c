// Room: /d/huangshan/qingliangf.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����̨���о��������壬�嶥ƽ̹����һ��������ʯ�����ƺ��ӣ�
����ʱ�ڣ��ƺ�ãã�����ǡ����ӹۺ����ˣ�һ���ƿ�����ʱ���ֽ�
��������̫ƽ������̫ƽ������Ϊ������ǰ���Ǿ�ʱ��̫ƽ�ء�
LONG
	);
	set("exits", ([ 
		"eastdown" : __DIR__"qingliang",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
