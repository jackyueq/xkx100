// Room: /d/heimuya/dating3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���ǡ�������̡��µ������ã������õĴ�����ʮ�����ɣ��ֻ���
һ������ʱ��ʱ�֡���������һ����(bian)��
LONG    );
	set("exits", ([
		"south"     : __DIR__"chlang1",
		"northdown" : __DIR__"guang",
	]));
	set("item_desc", ([
		"bian": "����д����������գ��������졣ǧ�����أ�һͳ���� ��\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}