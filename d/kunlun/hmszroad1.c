// Room: /d/kunlun/hmszroad1.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������ɽ�ϵ����ɼ���ɽ·��ֻ�������ѵ����ɼ�÷����÷
��ʢ��ʱ����һƬ��죬����Ʈ�硣
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"westup"    : __DIR__"hmszroad2",
		"southeast" : __DIR__"bayankala",
	]));
	set("outdoors", "hongmei");
	set("no_clean_up", 0);
	set("coor/x", -90010);
	set("coor/y", 10010);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
