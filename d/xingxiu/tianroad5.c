// room: /d/xingxiu/tianroad5.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��Ҷ�֡�������ȥ������ңң�ɼ���
LONG );
	set("exits", ([
		"westup"   : __DIR__"tianroad6",
		"eastdown" : __DIR__"tianroad4",
		"north"    : "/d/npc/m_weapon/liandaoshi",
	]));
	set("objects", ([
		__DIR__"npc/caiyaoren" : 1, 
	]));
	set("item_desc", ([
		"cave" : "�������ɽ����Ʈ��һ�����磬�ŵ���ֱ����¡�\n"
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -52010);
	set("coor/y", 20100);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
