// Room: /d/heimuya/dating4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���ǡ�������̡��µ��Ĵ��ã������õĴ�����ԶԶ��ȥ�������죬
���Ʋ�ʳ�˼��̻���������һ����(bian)��
LONG    );
	set("exits", ([
		"west"    : __DIR__"road1",
		"southup" : __DIR__"tian1",
	]));
	set("item_desc", ([
		"bian": "����д����������---�������ʥ��ס�ء�\n",
       	]) );
	set("no_clean_up", 0);
	set("coor/x", -3010);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}