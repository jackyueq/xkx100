// Room: /d/heimuya/qing.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "�����ô���");
	set("long", @LONG
���ǡ�������̡��µ������ã������õĴ�����һλ���߾��У���
���㱡�
LONG );
	set("exits", ([
		"north" : __DIR__"chlang2",
		"east"  : __DIR__"tang",
	]));
	set("objects",([
		CLASS_D("heimuya")+"/jiabu"   :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 3990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}