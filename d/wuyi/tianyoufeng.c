// Room: /d/wuyi/tianyoufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "���η�");
	set("long", @LONG
���η�λ������֮�����������𣬸���Ⱥ��֮�ϡ�ÿÿ���������
���س�¶֮ʱ��ɽ�������Ű�ãã�����ƣ�������ǧ�����۶�������
�������Ī�⣬�������������ɾ����������������칬���������Ρ���
ϼ��Ի�����䲻��Ϫ���ܾ�����֮ʤ���˷��Ӧ��һҲ����ȻҲ��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"up"        : __DIR__"tianyouguan",
		"eastdown"  : __DIR__"tianyoupath1",
		"northdown" : __DIR__"tianyoupath2",
		"northeast" : __DIR__"xianyutan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

