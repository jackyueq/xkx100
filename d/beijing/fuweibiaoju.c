// Room: /beijing/fuweibiaoju.c

inherit ROOM;

void create()
{
	set("short", "�����ھֱ����־�");
	set("long", @LONG
��������ϲ豭��С��ͭ���������⣬�Ŷ����Ҷ�д�š������ھ�
���ĸ�������֣�������顰�����ֺš��ĸ�С�֡����������ų��ʣ�
����������װ���ӣ����������ͦ���Գ�һ��Ӣ��֮����
LONG );

	set("exits", ([
		"north" : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/fuzhou/npc/yi" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
