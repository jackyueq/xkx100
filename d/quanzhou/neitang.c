// Room: /d/quanzhou/neitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ҩ�̵����ã����װ���һ����ܣ�������˲���ҽ�顣����
���м�������(chair)�����������ҩ�̽Ӵ����˵ĵط���
LONG );
	set("item_desc", ([
		"chair"   : 
"һ�����ӣ�Ĩ�õúܸɾ����α�����˫�������ͼ�����������̵�����
������������צ������һ�������α�����ⷢ��������(Iron Ball)��\n",
	]));
	set("exits", ([
		"out"   : __DIR__"jishitang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
