// Room: /d/mobei/hill.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "С��ɽ");
	set("long", @LONG
ֻ�����������һ������ȴ����Ƭ�������ߵ�һ���������ϱ�
�����ޱߵ��ɹŲ�ԭ��Χ��������ĳ��˼���С·�⣬���ǵͰ��Ĺ�ľ
�ԣ�����ɢ����һЩ���ѵļ���ɭɭ�İ׹Ǻ�һЩ��ȱ�Ĳ�����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guojing" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"guanmu",
	]));
	set("outdoors","mobei");

	set("coor/x", -260);
	set("coor/y", 5160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
