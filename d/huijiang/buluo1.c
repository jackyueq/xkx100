// Room: /d/huijiang/buluo1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "�ز�����");
	set("long", @LONG
�˴����������֣�һ��б��ֱ�������ԭ�������ڴ����ڼ�������
��֮�䣬���ߵ�һ���������ر�Ĵ�һ�㡣�ϱ�����С·ͨ������֮
�С�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"zhangpeng",
		"west"  : __DIR__"zhangpeng1",
		"north" : __DIR__"buluo2",
		"south" : __DIR__"buluo",
	]));
	set("objects", ([ /* sizeof() == 4 */
		CLASS_D("honghua")+"/zhang-jin" : 1,
	]));
	set("outdoors", "huijiang");
	set("coor/x", -50050);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
