// Room: /d/tiezhang/sslin5.c
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
LONG );
	set("exits", ([ 
		"west"  : __FILE__,
		"east"  : __FILE__,
		"south" : __DIR__"sslin4",
		"north" : __DIR__"dezj",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

