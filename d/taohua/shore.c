// Room: /d/taohua/shore.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ɻ�ؿ������ܣ���������һ���ô�����ܳ������ҵĽ�ʯ�⣬
ʲô��û�С������濴��һ��Сɽ�������������ͨ�������ұڵ���
ɽ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northup" : __DIR__"hill",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
