// Room: /d/mobei/damo.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "��Į");
	set ("long", @LONG
������һ���޼ʵ�ɳĮ�������յ������£��㼸��Ҫ�����ˡ�����
ͨ���ɹŲ�ԭ���ϱ����Ǿ��Ƿ���
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"south"     : __DIR__"lvzhou",
		"northwest" : __DIR__"mobei",
	]));
	set("coor/x", -210);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
