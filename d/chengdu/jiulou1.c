// Room: /d/chengdu/jiulou1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "���Ӿ�¥");
	set("long", @LONG
������ǳ�������������Ӿ�¥�����˵���ʷ�ƾã�������Ϊ����
��Ϊ����һ���ļ����ܳ�ʪ����Ե������ȿ�θ��Ƣ����ǿ�����٣���
���������ָ����ûʵĴ�������������С������ͷ�󺹵��к������м�
������ʱ�������󻶸�Ц��......
LONG );
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"chunxilu1",
		"up"   : __DIR__"jiulou2",
	]));
	set("coor/x", -8030);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

