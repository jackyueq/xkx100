// Room: /d/kunlun/hmszroad2.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������ɽ�ϵ����ɼ���ɽ·��ֻ�������ѵ����ɼ�÷����÷
��ʢ��ʱ����һƬ��죬����Ʈ�硣�����Ǻ�÷ɽׯ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"   : __DIR__"hmszhuang",
		"eastdown" : __DIR__"hmszroad1",
	]));
	set("outdoors", "hongmei");
	set("no_clean_up", 0);
	set("coor/x", -90020);
	set("coor/y", 10010);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
