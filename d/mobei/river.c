// Room: /d/mobei/river.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "ˮ��");
	set ("long", @LONG
һ�����ǵ�Сˮ�������ϵ�ˮ�ݶ������˰��ߣ�ˮ����ϡ��������
������ͷţ���������������˵غ�ˮ���ƺ���˭�����������������
����һƬ������������ƶ�������Ҫ�����ˡ�
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"west"      : __DIR__"caoyuan3",
		"northeast" : __DIR__"byriver",
	]));
	set("coor/x", -210);
	set("coor/y", 5150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
