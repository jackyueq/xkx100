// Room: /d/mobei/tuolei.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "����Ӫ��");
	set("long", @LONG
��������ľ����Ķ��ӣ�Ҳ�Ǵ����Ӱ��Ķ��ӡ���������͸���о���
ս�ĲŻ�Զ������֮�ϡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tuolei" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"road",
	]));
	set("coor/x", -220);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
