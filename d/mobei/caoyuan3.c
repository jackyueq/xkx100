// Room: /d/mobei/caoyuan3.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
Į������Ƭ��ԭ������ƶ񤣬ֻ��������Ϊ������������Ƭ������
���ɹŸ�������֮��Ϊ����ţ��ū�������أ��Ʋ���������ɱ����ľ
����ǵ�����ǿʢ��һ�����䡣
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/heijiu" : 2,
	]));
	set("exits", ([ /* sizeof() == 3 */
		"northwest" : __DIR__"caoyuan2",
		"east"      : __DIR__"river",
		"south"     : __DIR__"mobei",
	]));
	set("outdoors","mobei");
	set("coor/x", -220);
	set("coor/y", 5150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
