//RJQMENLOU1.C

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
������һ���ʯ�ң�ʯ����������������ű����ܣ�ʮ�˰������
����ȫ����������������Ѳ�ߣ��������ػ������ġ�������һ��ʯ��ֱ
ͨ¥�ϡ�
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou2",
		"east" : __DIR__"rjqyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}