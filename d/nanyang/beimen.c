// Room: /d/nanyang/beimen.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
�������������š������ų���ǣ�������ͩ��ɽ�������Ƿ�ţɽ��
�������롣���������ܲܲ��ڴˣ���Τ��ս�����⡣����Ϸ��ǻ����
�˵�����������ķ�ζҲ����������
LONG);
	set("exits",([
		"north"  : __DIR__"yidao3",
		"south"  : __DIR__"dajie2",
	]));
	set("objects",([
		"/d/city/npc/bing" : random(2)+1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

