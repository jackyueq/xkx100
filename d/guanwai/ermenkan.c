// /guanwai/ermenkan.c

inherit ROOM;

void create()
{
	set("short", "���ſ���");
	set("long", @LONG
�����Ĳ�·���ѵ���ʧ��ԭ������ߣ�·����ϡ������һЩǳǳ��
��ӡ��������ǰ��Ĳο����µġ���ãã��ѩ�ط����ҫ�۵����⣬��
����ͷ���ۻ���ż���м�ֻѩ�÷ɳ۶�����ת�۾���Ӱ�����ˡ�
LONG );
	set("exits", ([
		"east"       : __DIR__"mantianxing",
		"northwest"  : __DIR__"damenkan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6110);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}