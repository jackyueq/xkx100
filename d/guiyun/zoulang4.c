// Room: /d/guiyun/zoulang4.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���Ǵ�����ͨ�����䳡�����ȡ������������������ۣ�����������
�ʻ��οգ���Ŀ���⣬���������˻�������������ׯ������������
LONG );
	set("exits",([
		"east"  : __DIR__"liangong",
		"west"  : __DIR__"zoulang5",
		"north" : __DIR__"zhongting",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
