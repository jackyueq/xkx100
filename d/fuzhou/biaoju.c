// Room: /city/biaoju.c

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
��������ϲ豭��С��ͭ���������⣬�Ŷ��Ҷ�д�š������ھ֡�
�ĸ�������֣�������顰�ܺš�����С�֡����Ŵ����ų��ʣ�������
����װ���ӣ����������ͦ���Գ�һ��Ӣ��֮����
LONG );

	set("exits", ([
		"south" : __DIR__"xidajie",
		"enter" : __DIR__"biaojudy",
	]));
	set("objects", ([
		__DIR__"npc/chenqi" : 1,
		__DIR__"npc/baier" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6299);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
