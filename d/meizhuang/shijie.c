// /d/meizhuang/shijie.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��ɽʯ��");
	set("long", @LONG
�����ɽ�ߵ�ʯ������ȥ��һ·�����ź��߳�ҷ����������֪����
��ת�˼����䣬ȴ����ض���÷�����ϸɺ�б��֦Ҷï�ܣ��������÷
��ʢ��֮�գ���ѩ�纣����Ȼ���Ͳ�����
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : "/d/hangzhou/gushan",
		"north"	   : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
