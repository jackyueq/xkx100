// /d/meizhuang/midao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�ص�һ·������б�����Ʋ��ϵ�������б��ֻ��������صװ�����
�࣬���ڴ���Ѿ������������ˡ�ǽ���ϵ���һյ�͵ƣ���������ɫ��
â��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao2",
		"southdown" : __DIR__"midao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1440);
	set("coor/z", -100);
	setup();
	replace_program(ROOM);
}
