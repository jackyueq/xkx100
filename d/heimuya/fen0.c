// Room: /d/heimuya/fen0.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������������̽��µ�һ���á�������Ŀ�²�Զ�����µ�һ����
����ͯ���ܰ��ƴ��á�
LONG);
	set("exits", ([
		"north" :  __DIR__"grass1",
	]));
	set("objects",([
            CLASS_D("heimuya")+"/tong" :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
