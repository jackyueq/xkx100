// Room: /d/kunlun/shanxi.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽϪ��");
	set("long", @LONG
������һ��СϪ������ɽ�����ѩ�������������£����ֱ�ѩ�ڻ�
��ˮ�������СϪ��Ϫˮ���¶�������֪������η�������������һ��
����֡�
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup" : __DIR__"xschongling",
		"eastup" : __DIR__"hmszhuang",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/wu" : 1,
		__DIR__"npc/weibi" : 1,
	]));
	set("outdoors", "hongmei");
	set("coor/x", -90040);
	set("coor/y", 10010);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
