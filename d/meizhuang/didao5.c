// /d/meizhuang/didao5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
��һ�����ӭ����ŵ�һ�ɸ��õ�������ζ����������ǰ�����
���У����ֿ�����ϣ�����㲻����ʼ�ӿ�Ų����뿴�����ﵽ����Щʲ
ô������ 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"lingmu",
		"south" : __DIR__"didao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
