// Room: /d/kunlun/shangou.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ��֮�µ�һ��Сɽ����������һƬ�԰���ɽ�ڣ���������ɽ��ֱ
�����졣�����̲ݴ����������ѩ��֮����û���С�
LONG	);
	set("outdoors", "hongmei");
	set("exits", ([ /* sizeof() == 1 */
		"westup" : __DIR__"shanbi",
	]));
	set("objects",([
		__DIR__"npc/xueji" : 2,
	]));
	setup();
	set("coor/x", -98000);
	set("coor/y", 20050);
	set("coor/z", 40);
	replace_program(ROOM);
}
