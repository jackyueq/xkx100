// Room: /d/mobei/mobei.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create ()
{
	set ("short", "Į��");
	set ("long", @LONG
Į���ຮ֮�أ��絶˪����������Ƭƶ�������ϣ��ɹ���һ����
������ľ�����������򱱹�ȥ�����ɹŵĲ�ԭ�����Ϸ�������ԭ����
�ڡ�
LONG);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"damo",
		"north"     : __DIR__"caoyuan3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
