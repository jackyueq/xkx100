// Room: /d/mobei/guanmu1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
�����߶�ʱ�ӹ�������é�ݣ�����Ǹ߸߰����Ĺ�ľ�ԡ���в���
��Ŀ����Ҳ��������ıߵľ�ɫ��ֻ��һ��С·�ڹ�ľ����ʱ��ʱ�ֵ�
����С�����ɽ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"caoyuan",
		"southwest" : __DIR__"guanmu",
	]));
	set("outdoors","mobei");
	set("coor/x", -240);
	set("coor/y", 5170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
