// Room: /d/huanggong/qinghedian.c
inherit ROOM;

void create()
{
	set("short", "��͵�");
	set("long", @LONG
��͵�, ���ǿ���ү�������ʺ����ŵĵط�. �ʺ�ϲ������, 
�������ǲ��ô���˵��. ������̴��������Ϊʥ��׼������һϯ����
ȫϯ. ���㰡!
LONG
	);

	set("exits", ([
		"east" : __DIR__"yushanfang",
	]));
	set("objects", ([
		__DIR__"obj/nverhong" : 2,
		__DIR__"npc/taijian" :1,
	]));

	set("coor/x", -190);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}