// /d/meizhuang/lingmu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�Ż���");
	set("long", @LONG
��һ�ߵ����ͻȻһƬ������ԭ�����ﾹȻ�ǹŴ��ϴ�������Ĺ��
�м�ͣ����һ�߹�ľ����ľ���Ϸ�������һ�Ŷ쵰һ���С��ҹ���飬
�������յ��쳣��������ľ�����з���һ���飬�鿴�����ܳ¾ɣ��ƺ�
��һλǰ���������µġ� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"didao5",
		"out"   : __DIR__"shijie",
	]));
	set("objects", ([ /* sizeof() == 1 */
		BOOK_DIR"qunxing-tu.c" : 1,
	]));

	set("coor/x", 3490);
	set("coor/y", -1460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
