// /d/beijing/alley3.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
����һ��ʮ��Ƨ����С��ͬ����������һ�ҿ͵꣬����ԼԼ������
��֮����������Щ��ԥ��Ҫ��Ҫ��ȥ��һ���أ�������ʲôΣ�հɣ���
���߿��Գ���ͬ��
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"southeast" : __DIR__"kedian1",
		"northeast" : __DIR__"alley2",
	]));
	set("objects", ([
		"/d/village/npc/dipi" : 1,
		"/d/village/npc/punk" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
