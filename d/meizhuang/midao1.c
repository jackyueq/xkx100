// /d/meizhuang/midao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���谵��ʪ�ĵص����ص�������ɳ�����ͷ����һ��ʯ�š�
ǽ���ϵ���һյ�͵ƣ���������ɫ��â��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up"        : __DIR__"neishi",
		"southdown" : __DIR__"shimen",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
