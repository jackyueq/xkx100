// Room: /d/mobei/maowu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "Сé��");
	set("long", @LONG
�����ֲڵ�ľͷ����һ�����ӣ��������Ƥ����û���䡣������ԭ
������é�ݸ�����ľͷ�ϣ�������Сé�ݡ������һ�ж��ǽ���ģʽ��
��ľͷ�ݲݴ���Ĵ���һ���Ǹ������һ�ߵ�ǽ�ϻ����˸�С����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/liping" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"caodui",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
