// Room: /d/mobei/guanmu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "��ľ��");
	set ("long", @LONG
�����߶�ʱ�ӹ�������é�ݣ�����Ǹ߸߰����Ĺ�ľ�ԡ���в���
��Ŀ����Ҳ��������ıߵľ�ɫ��ֻ��һ��С·�ڹ�ľ����ʱ��ʱ�ֵ�
����С�����ɽ����
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"guanmu1",
		"westup"    : __DIR__"hill",
	]));
	set("coor/x", -250);
	set("coor/y", 5160);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
