// Room: /d/mobei/damo2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "��Į");
	set ("long", @LONG
������һ���޼ʵ�ɳĮ�������յ������£��㼸��Ҫ�����ˡ�����
ͨ���ɹŲ�ԭ���ϱ����Ǿ��Ƿ���
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"southeast":__DIR__"huanglu1",
		"northwest":__DIR__"lvzhou",
	]));
	set("coor/x", -200);
	set("coor/y", 5110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
