// Room: /d/tiezhang/sslin2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�������������
����ա�������������Ҽ������������ڵ����������У��γ�������ɫ
�Ĺ�����ɷ�Ǻÿ������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У�
�Ҳ�����ȥ��·�ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"sslin3",
		"south" : __FILE__,
		"west"  : __DIR__"sslin1",
		"east"  : "/d/npc/m_weapon/lianqiangshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
