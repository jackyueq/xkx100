// Room: /d/mobei/xiaolu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "С·");
	set ("long", @LONG
���е�һ��С�����߰���ƽ��ʱ��Ҫ��һЩ��·�Ĺ�ľ�д�������
�հ���Ĳ�Զ��һ��ɽ��ƽ�ض���ɽ�°����������֮�У���������
�ܵ���ȥ��
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"downxuanya",
		"eastdown" : __DIR__"shulin4",
	]));
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("coor/x", -250);
	set("coor/y", 5200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
