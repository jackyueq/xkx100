// majuan.c.c ��Ȧ

inherit ROOM;

void create()
{
	set("short", "��Ȧ");
	set("long", @LONG
�ʼ���Ȧ, ��Ȼ�Ǻ����Ƽ�. һ�������������, һƥƥӢͦ��ͷ
����, ���㲻��������ԭ�������ڵ�׳ΰ����.
LONG
	);
	set("exits", ([
		"east" : __DIR__"yuhuayuan2",
	]) );
	set("objects", ([
		"/d/beijing/npc/yucongma" : 1,
	]) );
	set("coor/x", -210);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
