// Room: /d/mobei/buluo1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ľ�沿��");
	set("long", @LONG
��ľ�沿���ǵ����Į��ǿʢ��һ�壬����һͳ�ɹ�֮�ơ������
�����������ߣ��������������ж�������������ȥ����ԯ�š�������
�߶��ǲ������˾�ס���ɹŰ���
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/menggukid" : 2,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"menggubao1",
		"west"  : __DIR__"menggubao",
		"north" : __DIR__"yuanmen",
		"south" : __DIR__"buluo",
	]));
	set("outdoors", "mobei");
	set("coor/x", -210);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
