// Room: /d/mobei/caoyuan.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
���纣����ɹŲ�ԭ������ޱߣ�����в�ӥ�ӹ�������������
������ߵ�ţ�򻺻����ƶ��������Ǹ�С�������泤���˹�ľ�ԡ�
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huazheng" : 1,
	]));
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"westup" : __DIR__"guanmu1",
		"south" : __DIR__"caoyuan2",
		"north" : __DIR__"caoyuan4",
	]));
	set("coor/x", -230);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
