// Room: /d/wuyi/8qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����°������շ壬��������޴���ҷ����ж��ɡ�Сͷ������
���շ壬�����ձ������Ǹ�̾�칤���컯�����䡶�������衷Ի��
������������������������¥����ˮ��䧡�Ī�Դ˵��޼Ѿ���������
�˲�������������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"   : __DIR__"mopanshi",
		"northwest" : __DIR__"pinziyan",
		"northeast" : __DIR__"7qu",
		"southwest" : __DIR__"9qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1330);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

