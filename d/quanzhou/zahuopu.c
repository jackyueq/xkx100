// Room: /d/quanzhou/zahuopu.c
// Last Modified by winder on May. 29 2001

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
		"zhaopai" : "���� list �г������buy ���ϰ幺�\n",
	]));
	set("exits", ([
		"south" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/chen" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
