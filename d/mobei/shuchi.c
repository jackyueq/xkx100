// Room: /d/mobei/shuchi.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "����Ӫ��");
	set("long", @LONG
��������ľ��Ĵ���ӣ�����Ӫ�ʲ��õñȽϺ����������ڱ��ϵ�
�������ý�����ϸ�����һ�Ŵ���ձ��������Ļ�м䣬�����ϵĽ�
װ����Ѫɫ�����Ѿơ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shuchi" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"road2",
	]));
	set("coor/x", -200);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
