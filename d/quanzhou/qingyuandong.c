// Room: /d/quanzhou/qingyuandong.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��Դ��");
	set("long", @LONG
�ӻ���Ȫ���ϣ��Ϳ���һ��ɽ�ţ����Ͽ��š���һ���졹�ĸ��֡�
�ź���һ�ۿ�¥��¥�������һ��Ի�����ҡ�������Դ�����ഫ����
������һ����������׷��һ���˺�����Ĵ��ߵ����������������ʯ
���У���������Ծ��ڶ����������ˣ�������������ɶ��������Ŵ˶�
��ɲ⣬��ͨ����������
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"huruquan",
		"northdown" : __DIR__"shanlu1",
		"westup"    : __DIR__"nantaiyan",
	]));
	set("coor/x", 1840);
	set("coor/y", -6380);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
