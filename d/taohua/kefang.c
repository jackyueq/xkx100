// Room: /d/taohua/kefang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short","�ͷ�");
	set("long",@LONG
�������һ����д�����ס�޵ķ��䡣���ڳ��辫�ţ�������ԣ���
���Žࡣ����͸���紺���µ���ɫ���ƴ�Զ�������纣���һ��֣�����
�һ������������ˡ�
LONG
);
	set("exits",([
		"west" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("coor/x", 9020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}