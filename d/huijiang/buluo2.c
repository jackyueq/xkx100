// Room: /d/huijiang/buluo2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "�ز�����");
	set("long", @LONG
�˴����������֣������б��ͨ����ԭ����Ⱥ��ţ���ڲ�ԭ�ϳ�
����Ϸ��Զ����ɽɽ����ͬ���֮���һ�����ϣ��Ѻ����һ�ж��ڵ�
ס�ˡ������Ǽ�������
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"west"      : __DIR__"zhangpeng3",
		"east"      : __DIR__"zhangpeng2",
		"south"     : __DIR__"buluo1",
		"northdown" : __DIR__"xiepo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9060);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
