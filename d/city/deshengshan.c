// Room: /city/dongmen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "��ʤɽ");
	set("long", @LONG
��ʤɽ�ǵ������ɴ��ƽ��֮�������ڵ�ɽ���Ѿ����������ܵ���
ľ��һ���ߵ����ɽ���µĿյؾ�������ȥ�ˡ��м�յĴ�Լ�Ǽ��ɼ�
�������ϵĲ�Ҳû�У����ó������˵��˻����١�
LONG );
	set("outdoors", "yangzhoue");
	set("exits", ([
		"west" : __DIR__"jiaowai1",
	]));

	set("no_clean_up", 0);
	set("coor/x", 75);
	set("coor/y", -20);
	set("coor/z", 3);
	setup();
	replace_program(ROOM);
}