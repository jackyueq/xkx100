// Room: /d/mobei/lvzhou.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "����");
	set ("long", @LONG
һ��ɳĮ�е����ޣ���Ȼֻ�к�С��һ�飬������ɳĮ�е�������
����ȴ���㹻�������ڿ���ͣ����ЪЪ���ˡ�
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"damo2",
		"north"     : __DIR__"damo",
	]));
	set("coor/x", -210);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
