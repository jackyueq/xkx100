// Room: /d/chengdu/zahuopu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ��
���ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��
һЩ���صĶ�����̯������һ������(zhaopai)��
LONG	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"south" : __DIR__"xijie2",
	]));
	set("objects", ([
		__DIR__"npc/boss2": 1,
	]));

	set("coor/x", -8060);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

