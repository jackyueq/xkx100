// Room: /d/mobei/wokuotai.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "����̨Ӫ��");
	set("long", @LONG
����̨����ľ��������ӣ�Ҳ�ǽ����Ĵ󺹡���Ϊ���ʺͿ�񣬺�
���ֵܼ��ױ���Ҳ�����á�����Ӫ��Ҳʮ�����ء�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wokuotai" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"road",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
