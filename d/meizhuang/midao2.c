// /d/meizhuang/midao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�ص�һ·������б�����Ʋ��ϵ�������б��ǽ���ϵ���һյ�͵ƣ�
��������ɫ��â��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"shimen",
		"southdown" : __DIR__"midao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1430);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
