// Room: /d/wuxi/paotai.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "Ҫ����̨");
	set("long", @LONG
���Ѿ������˳������ˣ��ٸ��ڴ������˽���Ҫ����̨�������ͭ
ɫ����������ΡȻ�������ڶ������ڿ�ֱ���Ž��档��̨�ϼ����ٱ���
��Ѳ�ӣ������㣬���ͷ��س���һ���֣�����Ͽ��뿪�������̨�·�
����һ���޴��ľ��(pai)����Զ���ܿ���������֡�
LONG );
	set("outdoors", "wuxi");
	set("item_desc", ([
		"pai" : "
������Ҫ����Բ��ʮ�ｭ�棬��ֹ����ɴ���������\n",
	]));
	set("exits", ([
		"south"  : __DIR__"road6",
	]));
	set("objects", ([
		__DIR__"npc/junshi" : 4,
	]));
	set("coor/x", 370);
	set("coor/y", -720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}