// Room: /yangzhou/xiangfenpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
���������ϣ�Ī�����ݡ�������������������������õ�һ�ҡ�
�����֡�����̡�һ�������ӣ�һ�ֻ��ӵ������˱Ƕ��������ӱ��ϰ�
�ż��澵�ӣ��м���һ��ľ��̨����������Ů���������÷۱���֬����
�м������������ںͻ��������ʲô�������������һ����ƻ�����վ
��������
LONG );
	set("exits", ([
		"north" : __DIR__"dashidongjie",
	]));
	set("objects", ([
		__DIR__"npc/daichunlin" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}