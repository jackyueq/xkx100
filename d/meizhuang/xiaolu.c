// /d/meizhuang/xiaolu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����С·����������������÷������Ȼ��û��÷��ʢ���ļ��ڣ���
͸�������ܵ�÷�֣����ƺ��Ѿ��ŵ��������÷�������㣬��ʱ���Ѿ�
��������ߵ�ׯ԰���ſڣ��㰵����ӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shijie",
		"north" : __DIR__"gate",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1450);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
