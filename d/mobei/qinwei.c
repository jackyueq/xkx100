// Room: /d/mobei/qinwei.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
����Ӫ��רΪ������ľ���������������ģ�������ľ���Զ����
�ܻ��书��ǿ�ߣ���λ��һ��ʿ��֮�ϡ��ɹ��˳�����ʵ������Ӫ����
����Щ��ǹ���û��Щʲô�ݳ޶�����
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei2" : 2,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"road2",
	]));
	set("coor/x", -190);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
