// Room: /d/taohua/chufang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����һ����ĳ�������ҩʦ��֪ʹ����ʲô����ץ�˼�����������
����æµ�š����г������˺͵��ϵ�ζ����������ʦ����æµ�š�ż
������Щ�Բ������ʳ������ʱʣ�µ������������
LONG
	);
	set("no_clean_up", 0);

	set("objects",([
		__DIR__"obj/meat" : 1,
		__DIR__"obj/rice" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"neishi2",
		"south" : __DIR__"fanting",
	]));

	set("coor/x", 8990);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}