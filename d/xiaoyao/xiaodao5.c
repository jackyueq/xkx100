// xiaodao5.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ�����ϵ������ּ�С������;�羰��֮���ģ������������
�ض������԰ٻ����ޡ���������������
LONG );
	set("exits", ([
		"south" : __DIR__"muwu1",
		"north" : __DIR__"qingcaop",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 80);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}