// /d/meizhuang/zoulang3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ȵ��������ƺ��͵��˾�ͷ�������ȵ���һͷ����������շ���
��ζ�������������㣬�ߵ������Ҳ���ܲ����������������������
�ջ�ֻ�мӿ�Ų���ȥ���������� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"chufang",
		"south" : __DIR__"zoulang2",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
