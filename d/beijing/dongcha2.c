// Room: /beijing/dongcha2.c

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�����ڶ��������ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����
�����سǹٱ���ߺ�������ϱ��Ǵ����̣�����������������Զ����������
������������־��ڱ��ߣ�����˶�����ȥ�������������У��ƺ�ʮ��
���֡����߱���������֣����Ƕ���������ȥ��������
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east"  : __DIR__"dongmen",
		"west"  : __DIR__"dongcha1",
		"south" : __DIR__"datiepu",
		"north" : __DIR__"wangfu1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
