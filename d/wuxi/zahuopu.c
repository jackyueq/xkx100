// Room: /d/wuxi/zahuopu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ��
���ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��
һЩ���صĶ�����̯������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"southroad1",
	]));
	set("objects", ([
		__DIR__"npc/ma": 1,
	]));
	set("coor/x", 360);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}